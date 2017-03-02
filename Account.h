/*
"Tavi" Tenari
CSS342
Lab5
Prof. Dimpsey
12/9/2016
*/
#pragma once
#include <vector>
#include <string>
#include "Fund.h"
using namespace std;

class Account
{
public:
	Account();
	Account(int, string, string);
	~Account();

	int getId() const;
	void createFunds();
	Fund* getFund(int slot);
	vector<Fund> getFunds() const;
	int getFundSize() const;
	string getLastName() const;
	string getFirstName() const;

private:
	int id;
	string lastName;
	string firstName;
	vector<Fund> funds;
};

	