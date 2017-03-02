/*
"Tavi" Tenari
CSS342
Lab5
Prof. Dimpsey
12/9/2016
*/
#include "stdafx.h"
#include "Bank.h"

const vector<string> FTYPE = { "Money Market", "Prime Money Market", "Long-term Bond", "Short-term Bond", "500 Index Fund", "Capital Value Fund", "Growth Equity Fund", "Growth Index Fund", "Value Fund", "Value Stock Index" };

Bank::Bank()
{
}

Bank::~Bank()
{
}

void Bank::Read(string path)
{
	ifstream inFile(path);
	string line;
	while (getline(inFile, line))
	{
		vector<string> tokens;

		stringstream lineStream(line);
		string token;
		while (getline(lineStream, token, ' '))
		{
			tokens.push_back(token);
		}
		if (tokens[0] == "O")
		{
			Transaction trans("Open", tokens[1], tokens[2], stoi(tokens[3]), 0, 0, "");
			transactions.push(trans);
		}
		else if (tokens[0] == "W")
		{
			Transaction trans("Withdraw", "", "", stoi(tokens[1]), stoi(tokens[2]), 0, line);
			transactions.push(trans);
		}
		else if (tokens[0] == "D")
		{
			Transaction trans("Deposit", "", "", stoi(tokens[1]), stoi(tokens[2]), 0, line);
			transactions.push(trans);
		}
		else if (tokens[0] == "T")
		{
			Transaction trans("Transfer", "", "", stoi(tokens[1]), stoi(tokens[2]), stoi(tokens[3]), line);
			transactions.push(trans);
		}
		else if (tokens[0] == "H")
		{
			Transaction trans("Display", "", "", stoi(tokens[1]), 0, 0, line);
			transactions.push(trans);
		}
	}
}

void Bank::Process()
{
	while (transactions.size() > 0)
	{
		Transaction trans = transactions.front();
		transactions.pop();

		if (trans.getType() == "Open")
		{
			Open(trans);
		}
		else if (trans.getType() == "Deposit") 
		{
			Deposit(trans);
		}
		else if (trans.getType() == "Withdraw")
		{
			Withdraw(trans);
		}
		else if (trans.getType() == "Transfer")
		{
			Transfer(trans);
		}
		else if (trans.getType() == "Display")
		{
			Display(trans);
		}
	}
}

void Bank::Open(Transaction trans)
{
	if (isFourDigits(trans.getId()))
	{
		if (!(accounts.Contains(trans.getId())))
		{
			Account opened(trans.getId(), trans.getLastName(), trans.getFirstName());
			Account *ins = new Account;
			*ins = opened;
			accounts.Insert(ins);
		}
		else
		{
			cerr << "ERROR: Open failed: Account " << trans.getId() << " already in use" << endl;
		}
	}
	else
	{
		cerr << "ERROR: Open failed: " << trans.getId() << " is an invalid Account number" << endl;
	}
}

void Bank::Deposit(Transaction trans)
{
	int accId = trans.getId() / 10;
	int fundSlot = trans.getId() % 10;

	if (accounts.Contains(accId))
	{
		Account *temp = accounts.Retrieve(accId);
		temp->getFund(fundSlot)->addBalance(trans.getAmount());
		temp->getFund(fundSlot)->addTrans(trans);
	}
	else
	{
		cerr << "ERROR: Deposit failed: Account does not exist" << endl;
	}
}

void Bank::Withdraw(Transaction trans)
{
	int accId = trans.getId() / 10;
	int fundSlot = trans.getId() % 10;

	if (accounts.Contains(accId))
	{
		Account* temp = accounts.Retrieve(accId);
		if (temp->getFund(fundSlot)->getBalance() >= trans.getAmount())
		{
			temp->getFund(fundSlot)->subtractBalance(trans.getAmount());
			temp->getFund(fundSlot)->addTrans(trans);
		}
		else if (fundSlot == 0)
		{
			if ((temp->getFund(0)->getBalance() + temp->getFund(1)->getBalance()) >= trans.getAmount())
			{
				temp->getFund(1)->subtractBalance(trans.getAmount() - temp->getFund(0)->getBalance());
				temp->getFund(1)->addTrans(trans);
				temp->getFund(0)->setBalance(0);
				temp->getFund(0)->addTrans(trans);
			}
			else
			{
				trans.addLine(" (Failed)");
				temp->getFund(fundSlot)->addTrans(trans);
				cerr << "ERROR: Withdrawal failed: Account " << trans.getId() << " has insuffcient funds to withdraw $" << trans.getAmount() << endl;
			}
		}
		else if (fundSlot == 1)
		{
			if ((temp->getFund(1)->getBalance() + temp->getFund(0)->getBalance()) >= trans.getAmount())
			{
				temp->getFund(0)->subtractBalance(trans.getAmount() - temp->getFund(1)->getBalance());
				temp->getFund(0)->addTrans(trans);
				temp->getFund(1)->setBalance(0);
				temp->getFund(1)->addTrans(trans);
			}
			else
			{
				trans.addLine(" (Failed)");
				temp->getFund(fundSlot)->addTrans(trans);
				cerr << "ERROR: Withdrawal failed: Account " << trans.getId() << " has insuffcient funds to withdraw $" << trans.getAmount() << endl;
			}
		}
		else if (fundSlot == 2)
		{
			if ((temp->getFund(2)->getBalance() + temp->getFund(3)->getBalance()) >= trans.getAmount())
			{
				temp->getFund(3)->subtractBalance(trans.getAmount() - temp->getFund(2)->getBalance());
				temp->getFund(3)->addTrans(trans);
				temp->getFund(2)->setBalance(0);
				temp->getFund(2)->addTrans(trans);
			}
			else
			{
				trans.addLine(" (Failed)");
				temp->getFund(fundSlot)->addTrans(trans);
				cerr << "ERROR: Withdrawal failed: Account " << trans.getId() << " has insuffcient funds to withdraw $" << trans.getAmount() << endl;
			}
		}
		else if (fundSlot == 3)
		{
			if ((temp->getFund(3)->getBalance() + temp->getFund(2)->getBalance()) >= trans.getAmount())
			{
				temp->getFund(2)->subtractBalance(trans.getAmount() - temp->getFund(3)->getBalance());
				temp->getFund(2)->addTrans(trans);
				temp->getFund(3)->setBalance(0);
				temp->getFund(3)->addTrans(trans);
			}
			else
			{
				trans.addLine(" (Failed)");
				temp->getFund(fundSlot)->addTrans(trans);
				cerr << "ERROR: Withdrawal failed: Account " << trans.getId() << " has insuffcient funds to withdraw $" << trans.getAmount() << endl;
			}
		}
		else
		{
			trans.addLine(" (Failed)");
			temp->getFund(fundSlot)->addTrans(trans);
			cerr << "ERROR: Withdrawal failed: Account " << trans.getId() << " has insuffcient funds to withdraw $" << trans.getAmount() << endl;
		}
	}
	else
	{
		cerr << "ERROR: Withdrawal failed: Account does not exist" << endl;
	}
}

void Bank::Transfer(Transaction trans)
{
	int accId = trans.getId() / 10;
	int accFundSlot = trans.getId() % 10;
	int transAccId = trans.getTransId() / 10;
	int transAccFundSlot = trans.getTransId() % 10;
	if ((accounts.Contains(accId)) && (accounts.Contains(transAccId)))
	{
		Account *temp = accounts.Retrieve(accId);
		Account *temp2 = accounts.Retrieve(transAccId);
		if (temp->getFund(accFundSlot)->getBalance() >= trans.getAmount())
		{
			temp->getFund(accFundSlot)->subtractBalance(trans.getAmount());
			temp->getFund(accFundSlot)->addTrans(trans);
			temp2->getFund(transAccFundSlot)->addBalance(trans.getAmount());
			temp2->getFund(transAccFundSlot)->addTrans(trans);
		}
		else
		{
			trans.addLine(" (Failed)");
			temp->getFund(accFundSlot)->addTrans(trans);
			temp2->getFund(transAccFundSlot)->addTrans(trans);
			cerr << "ERROR: Transfer failed: Account " << temp->getId() << " has insufficient funds to transfer $" << trans.getAmount() << endl;
		}
	}
	else
	{
		cerr << "ERROR: Transfer failed: One, or both, of the account(s) do(es) not exist." << endl;
	}
}

void Bank::Display(Transaction trans)
{
	if (isFiveDigits(trans.getId()))
	{
		int accId = trans.getId() / 10;
		int fundSlot = trans.getId() % 10;
		Account* temp = accounts.Retrieve(accId);
		cout << "Transaction History for " << temp->getFirstName() << " " << temp->getLastName() << " " << FTYPE[fundSlot] << ": $" << temp->getFund(fundSlot)->getBalance() << endl;
		vector<Transaction> history = temp->getFund(fundSlot)->getHistory();
		for (int i = 0; i < history.size(); i++)
		{
			cout << " " << history[i].getLine() << endl;
		}
	}
	else if (isFourDigits(trans.getId()))
	{
		Account* temp = accounts.Retrieve(trans.getId());
		cout << "Transaction History for " << temp->getFirstName() << " " << temp->getLastName() << " by fund:" << endl;
		for (int i = 0; i < FTYPE.size(); i++)
		{
			vector<Transaction> history = temp->getFund(i)->getHistory();
			if (history.size() != 0)
			{
				cout << FTYPE[i] << ": $" << temp->getFund(i)->getBalance() << endl;
				for (int j = 0; j <history.size(); j++)
				{
					cout << " " << history[j].getLine() << endl;
				}
			}
		}
	}
	else
	{
		cerr << "ERROR: Display failed: Invalid account number." << endl;
	}
}

BSTree Bank::getAccounts() const
{
	return accounts;
}

bool Bank::isFiveDigits(int num)
{
	return ((num / 1000 >= 10) && (num / 1000 < 100));
}

bool Bank::isFourDigits(int num)
{
	return ((num / 1000 >= 1) && (num / 1000 < 10));
}
