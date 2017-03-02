/*
"Tavi" Tenari
CSS342
Lab5
Prof. Dimpsey
12/9/2016
*/
#include "stdafx.h"
#include "Account.h"

const vector<string> FTYPE = { "Money Market", "Prime Money Market", "Long-term Bond", "Short-term Bond", "500 Index Fund", "Capital Value Fund", "Growth Equity Fund", "Growth Index Fund", "Value Fund", "Value Stock Index" };

Account::Account()
{
	id = 0;
	lastName = "";
	firstName = "";
	createFunds();
}

Account::Account(int id, string lastName, string firstName)
{
	this->id = id;
	this->lastName = lastName;
	this->firstName = firstName;
	createFunds();
}

Account::~Account()
{
}

int Account::getId() const
{
	return id;
}

void Account::createFunds()
{
	int size = FTYPE.size();
	for (int i = 0; i < size; i++)
	{
		Fund temp(FTYPE[i], 0);
		funds.push_back(temp);
	}
}

Fund* Account::getFund(int slot)
{
	Fund *fund;
	fund = &funds[slot];
	return fund;
}

vector<Fund> Account::getFunds() const
{
	return funds;
}

int Account::getFundSize() const
{
	int size = funds.size();
	return size;
}

string Account::getLastName() const
{
	return lastName;
}

string Account::getFirstName() const
{
	return firstName;
}
