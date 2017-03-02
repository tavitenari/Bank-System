/*
"Tavi" Tenari
CSS342
Lab5
Prof. Dimpsey
12/9/2016
*/
#pragma once
#include "Account.h"
using namespace std;

class Account;
class BSTree
{
private:
	struct Node
	{
		Account *pAcct = NULL;
		Node *left = NULL;
		Node *right = NULL;
	};
	Node *rootPtr;

public:
	BSTree();
	~BSTree();

	bool Insert(Account *pAcct);
	Account* Retrieve(const int &num) const;
	bool Contains(const int &num) const;
	void Display(Node *current) const;
	void Empty();
	
	bool isEmpty() const;
	int getId() const;
	Node* getRootPtr() const
	{
		return rootPtr;
	}
};
