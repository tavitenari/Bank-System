/*
"Tavi" Tenari
CSS342
Lab5
Prof. Dimpsey
12/9/2016
*/
#pragma once
#include <string>
#include <vector>
#include "Transaction.h"
using namespace std;

class Fund
{
public:
	Fund();
	Fund(string type, int balance);
	~Fund();

	void setType(string type);
	void setBalance(int num);
	void addBalance(int num);
	void subtractBalance(int num);
	void addTrans(const Transaction &trans);
	vector<Transaction> getHistory() const;
	int getBalance() const;

private:
	string type;
	int balance;
	vector<Transaction> history;
};
