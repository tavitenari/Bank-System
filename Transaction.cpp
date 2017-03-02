/*
"Tavi" Tenari
CSS342
Lab5
Prof. Dimpsey
12/9/2016
*/
#include "stdafx.h"
#include "Transaction.h"

Transaction::Transaction()
{
	type = "";
	lastName = "";
	firstName = "";
	id = 0;
	transId = 0;
	amount = 0;
	line = "";
}

Transaction::Transaction(string type, string lastName, string firstName, int id, int amount, int transId, string line)
{
	this->type = type;
	this->lastName = lastName;
	this->firstName = firstName;
	this->id = id;
	this->transId = transId;
	this->amount = amount;
	this->line = line;
}

Transaction::~Transaction()
{
}

string Transaction::getType() const
{
	return type;
}

string Transaction::getLastName() const
{
	return lastName;
}

string Transaction::getFirstName() const
{
	return firstName;
}

int Transaction::getId() const
{
	return id;
}

int Transaction::getAmount() const
{
	return amount;
}

int Transaction::getTransId() const
{
	return transId;
}

string Transaction::getLine() const
{
	return line;
}

string Transaction::addLine(string line)
{
	return this->line += line;
}
