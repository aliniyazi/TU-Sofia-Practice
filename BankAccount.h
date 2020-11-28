#pragma once
#include <string>;
#include <list>;
#include <iostream>;
#include <regex>;
#include <iterator>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;
class BankAccount
{
private:
	string id;
	string nameofclient;
	list<double> amountsPaid;
	list<double> amountsWithdrawn;
public:
	BankAccount(string id, string nameofclient)
	{
		SetId(id);
		SetNameOfClient(nameofclient);
		amountsPaid = list<double>();
		amountsWithdrawn = list<double>();
	}
	~BankAccount()
	{
		SetId(id);
		SetNameOfClient(nameofclient);
		amountsPaid = list<double>();
		amountsWithdrawn = list<double>();
	}
	string GetId()
	{
		return this->id;
	}
	string GetNameOfClient()
	{
		return this->nameofclient;
	}
private:
	void SetId(string id)
	{
		if (regex_match(id, regex("(?!^[0-9]*$)(?!^[a-zA-Z]*$)^([a-zA-Z0-9]{6})$")))
		{
			int counter = 0;
			for (auto c : id)
			{
				if (isalpha(c))
				{
					counter++;
				}
			}
			if (counter == 1)
			{
				this->id = id;
			}
			else
			{
				throw exception("Name must containts 5 diggits and 1 letter.This id contains more than 1 letter!");
			}
		}
		else
		{
			throw exception("Name must containts 5 diggits and 1 letter");
		}
	}
	void SetNameOfClient(string name)
	{
		if (name.empty())
		{
			throw exception("Name can't be Empty");
		}
		else
		{
			this->nameofclient = name;
		}


	}
public:
	string CheckAmountWithdrawn()
	{
		double sum = 0;
		string moneys;
		for (auto wd : amountsWithdrawn)
		{
			sum += wd;
			moneys += "\n";
			moneys += to_string(("%.2lf",wd));
		}

		return this->GetNameOfClient() + " Withdrawn: " + moneys + "\n" + "Total: " + to_string(sum) + "\n" + 
			"...................... \n";
	} // Printira v konzolata vsicki pari koito sim izteglil
	string WithdrawnMoney(double money)
	{
		if (money > 0)
		{
			money = ("%.f2",money);
			this->amountsWithdrawn.push_back(("%.f2",money));
			return "Succesfuly drwaned";
		}
		else
		{
			throw exception("You cannot withdrawn money below or equal 0");
		}

	}//Metod za teglena na zaem.
	string CheckAmountPaid()
	{
		double sum = 0;
		string moneys;
		for (auto wd : amountsPaid)
		{
			sum += wd;
			moneys += "\n";
			moneys += to_string(("%.2lf",wd));
		}
		/*string a = this->GetNameOfClient() + " Paid: ";*/
		return this->GetNameOfClient() + " Paid: " + moneys + "\n" + "Total: " + to_string(sum)+"\n" + 
			"...................... \n";
	}//Proveryava kolko pari sim platil na bankata.
	string PayMoney(double money)
	{
		if (money > 0)
		{
			this->amountsPaid.push_back(money);
			return "Succesfuly drwaned";
		}
		else
		{
			throw exception("You cannot pay money below or equal 0");
		}

	}//Metod za plashtane na pari.
	string Diffrence()
	{
		double paid =0;
		double drawn = 0;
		double result = 0;
		for (auto wd : amountsWithdrawn)
		{
			drawn += wd;
		}
		for (auto p : amountsPaid)
		{
			paid += p;
		}
		if (paid > drawn)
		{
			result = paid - drawn;
			return "You paid more than drawn.With diffrence: " +to_string(("%.2lf",result)) + "\n";
		}
		else if (paid < drawn)
		{
			result = drawn - paid;
			return "You drawn more than paid.With diffrence: " + to_string(("%.2lf",result)) + "\n";
		}
		else
		{
			return "You paid and drawn are same \n";
		}
	}
	void PrintAllInfoToFile(string filename,string FileForEqualMoneys)
	{
		ofstream myfile;
		myfile.open(filename,fstream::app);
		myfile << "This Bank Account belongs to : ";
		myfile << this->nameofclient;
		myfile << "\n";
		myfile << "With Id: ";
		myfile << this->id;
		myfile << "\n";
		myfile << CheckAmountPaid();
		myfile << CheckAmountWithdrawn();
		myfile << "\n";
		myfile.close();

		PrintInfoToFileIfDrawnIsEqualsToPay(FileForEqualMoneys);

	}
	void PrintInfoToFileIfDrawnIsEqualsToPay(string eqalsfilename)
	{
		if (Diffrence() == "You paid and drawn are same")
		{
			ofstream mysecondfile;
			mysecondfile.open(eqalsfilename,fstream::app);
			mysecondfile << "You are special! \n";
			mysecondfile << "This Bank Account belongs to : ";
			mysecondfile << this->nameofclient;
			mysecondfile << "\n";
			mysecondfile << "With Id: ";
			mysecondfile << this->id;
			mysecondfile << "\n";
			mysecondfile.close();
		}
		else 
		{
			cout << "Sorry we cant print you information to new file. \n";
			cout << "You paid and drawn are not equal \n";
		}
	}
};

