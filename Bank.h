#pragma once
#include "BSTree.h"
#include "Transaction.h"
/*
"Tavi" Tenari
CSS342
Lab5
Prof. Dimpsey
12/9/2016
*/
#include "Fund.h"
#include "Account.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <String>
using namespace std;

class Bank
{
public:
	Bank();
	~Bank();

	void Read(string path);
	void Process();

	void Open(Transaction trans);
	void Deposit(Transaction trans);
	void Withdraw(Transaction trans);
	void Transfer(Transaction trans);
	void Display(Transaction trans);
	BSTree getAccounts() const;

	bool isFiveDigits(int num);
	bool isFourDigits(int num);

private:
	queue<Transaction> transactions;
	BSTree accounts;
};