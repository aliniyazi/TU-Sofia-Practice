#pragma once
#include <string>;
#include <list>;
#include <iostream>;
#include <regex>;
#include <iterator>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <map>
#include "BankAccount.h";
using namespace std;
class Bank
{
private:
	string name;
	list<BankAccount> accounts;
public:
	Bank(string name)
	{
		SetName(name);
		accounts = list<BankAccount>();
	}
private:
	void SetName(string name)
	{
		if (name.empty())
		{
			throw exception("Bank name cant be empty");
		}
		else
		{
			this->name = name;
		}
	}
public:
	string GetName()
	{
		return this->name;
	}
	void CheckAccounstForDuplicates()
	{
		map<string, int> Checker;
		list<string> Sort;

		for (auto a : this->accounts)
		{
			if (Checker.count(a.GetNameOfClient()) == 0)
			{
				Checker.insert(pair<string, int>(a.GetNameOfClient(), 1));
			}
			else
			{
				Checker[a.GetNameOfClient()] ++;
			}
		}
		for (auto a : Checker)
		{
			if (a.second > 1)
			{
				Sort.push_back(a.first);
			}
		}
		Sort.sort();
		for (auto a : Sort)
		{
			cout << a + " ";
		}
	}
	void AddAccount(BankAccount acount)
	{
		this->accounts.push_back(acount);
	}


};

