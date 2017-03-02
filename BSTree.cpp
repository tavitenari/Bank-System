/*
"Tavi" Tenari
CSS342
Lab5
Prof. Dimpsey
12/9/2016
*/
#include "stdafx.h"
#include "BSTree.h"
#include <iostream>
using namespace std;

const vector<string> FTYPE = { "Money Market", "Prime Money Market", "Long-term Bond", "Short-term Bond", "500 Index Fund", "Capital Value Fund", "Growth Equity Fund", "Growth Index Fund", "Value Fund", "Value Stock Index" };

BSTree::BSTree()
{
	rootPtr = NULL;
}

BSTree::~BSTree()
{
}

bool BSTree::Insert(Account *pAcct)
{
	Node *temp = new Node;
	if (rootPtr == NULL)
	{
		temp->pAcct = pAcct;
		rootPtr = temp;
		return true;
	}
	temp = rootPtr;
	
	Node *tempFollower = new Node;
	while (!(temp == NULL))
	{
		if ((pAcct->getId()) < (temp->pAcct->getId()))
		{
			tempFollower = temp;
			temp = temp->left;
		}
		else if ((pAcct->getId()) > (temp->pAcct->getId()))
		{
			tempFollower = temp;
			temp = temp->right;
		}
	}
	Node* temp2 = new Node;
	temp2->pAcct = pAcct;
	if (pAcct->getId() < tempFollower->pAcct->getId())
	{
		tempFollower->left = temp2;
	}
	else if (pAcct->getId() > tempFollower->pAcct->getId())
	{
		tempFollower->right = temp2;
	}
	return true;
}

Account* BSTree::Retrieve(const int &num) const
{
	Node *temp = new Node;
	temp = rootPtr;
	while (temp->pAcct->getId() != num)
	{
		if (temp->pAcct->getId() < num)
		{
			temp = temp->right;
		}
		else if (temp->pAcct->getId() > num)
		{
			temp = temp->left;
		}
	}
	return temp->pAcct;
}

bool BSTree::Contains(const int & num) const
{
	if (rootPtr != NULL)
	{
		Node *temp = new Node;
		temp = rootPtr;
		while ((temp->pAcct->getId() != num))
		{
			if (temp->pAcct->getId() < num)
			{
				if (temp->right != NULL)
				{
					temp = temp->right;
				}
				else
				{
					return false;
				}
			}
			else if (temp->pAcct->getId() > num)
			{
				if (temp->left != NULL)
				{
					temp = temp->left;
				}
				else
				{
					return false;
				}
			}
		}
		return true;
	}
	else 
	{
		return false;
	}
}

void BSTree::Display(Node *current) const
{
	if (current != NULL)
	{
		Display(current->left);
		cout << " " << current->pAcct->getFirstName() << " " << current->pAcct->getLastName() << " " << "Account ID: " << current->pAcct->getId() << endl;
		for (int i = 0; i < FTYPE.size(); i++)
		{
			cout << "    " << FTYPE[i] << ": $" << current->pAcct->getFund(i)->getBalance() << endl;
		}
		cout << endl;
		Display(current->right);
	}
}

void BSTree::Empty()
{
	rootPtr = NULL;
}

bool BSTree::isEmpty() const
{
	return (rootPtr == NULL);
}

int BSTree::getId() const
{
	return rootPtr->pAcct->getId();
}

