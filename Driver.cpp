/*
"Tavi" Tenari
CSS342
Lab5
Prof. Dimpsey
12/9/2016
*/
#include "stdafx.h"
#include "BSTree.h"
#include "Account.h"
#include "Bank.h"

Bank bnk;

int main(int argc, char* argv[])
{	
	bnk.Read(argv[1]);
	bnk.Process();
	cout << "\n";
	cout << "Processing Done. Final Balances:" << endl;
	bnk.getAccounts().Display(bnk.getAccounts().getRootPtr());

	system("pause");
	return 0;
}