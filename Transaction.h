/*
"Tavi" Tenari
CSS342
Lab5
Prof. Dimpsey
12/9/2016
*/
#pragma once
#include <string>
using namespace std;

class Transaction
{
public:
	Transaction();
	Transaction(string type, string lastName, string firstName, int id, int amount, int transId, string line);
	~Transaction();

	string getType() const;
	string getLastName() const;
	string getFirstName() const;
	int getId() const;
	int getAmount() const;
	int getTransId() const;
	string getLine() const;
	string addLine(string line);

private:
	string type;
	string lastName;
	string firstName;
	int id;
	int amount;
	int transId;
	string line;
};
