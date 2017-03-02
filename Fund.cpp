/*
"Tavi" Tenari
CSS342
Lab5
Prof. Dimpsey
12/9/2016
*/
#include "stdafx.h"
#include "Fund.h"

Fund::Fund()
{
	type = "";
	balance = 0;
}

Fund::Fund(string type, int balance)
{
	this->type = type;
	this->balance = balance;
}

void Fund::setType(string type)
{
	this->type = type;
}

void Fund::setBalance(int num)
{
	this->balance = num;
}

void Fund::addBalance(int num)
{
	this->balance += num;
}

void Fund::subtractBalance(int num)
{
	this->balance -= num;
}

void Fund::addTrans(const Transaction &trans)
{
	history.push_back(trans);
}

vector<Transaction> Fund::getHistory() const
{
	return history;
}

int Fund::getBalance() const
{
	return balance;
}

Fund::~Fund()
{
}
