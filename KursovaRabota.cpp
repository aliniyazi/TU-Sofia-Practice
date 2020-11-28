// KursovaRabota.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BankAccount.h"
#include "Bank.h";
#include <string>;
#include <list>;
#include <regex>;
#include <windows.h>;

int main()
{
	try
	{
		Bank bank("DSK");
		BankAccount Home1("12345h", "Georgi Mladenov");
		BankAccount Home2("89b641", "Milen Stoqnov"); 
		BankAccount Home3("4k2652", "Dimitir Danov");
		BankAccount Home4("d96524", "Valeri Samuilov"); 
		BankAccount Home5("7531i5", "Gergana Ivanova");
		BankAccount Car1("854y75", "Georgi Mladenov"); //2
		BankAccount Car2("852v46", "Nikolay Zlatkov");
		BankAccount Car3("3e2185", "Kristiqn Atanasov");
		BankAccount Car4("63781m", "Dimitir Danov");
		BankAccount Car5("1937l5", "Milen Stoqnov"); //2
		BankAccount Excursion1("758e96", "Radina Mladova");
		BankAccount Excursion2("3185g2", "Dimitir Danov"); //3
		BankAccount Excursion3("342s68", "Svetoslav Nikolov");
		Home1.WithdrawnMoney(2563.45);
		Home1.WithdrawnMoney(138.58);
		Home1.WithdrawnMoney(563.05);
		Home1.PayMoney(318.86);
		Home1.PayMoney(1853.11);
		Home2.WithdrawnMoney(8563.05);
		Home2.WithdrawnMoney(1385.13);
		Home2.WithdrawnMoney(56.85);
		Home2.PayMoney(4856.76);
		Home2.PayMoney(2345.18);
		Home2.PayMoney(741.96);
		cout << Home1.CheckAmountPaid();
		cout << Home2.CheckAmountPaid();
		cout << Home1.CheckAmountWithdrawn();
		cout << Home2.CheckAmountWithdrawn();
		cout << Home1.Diffrence();
		cout << Home2.Diffrence();
		Home1.PrintInfoToFileIfDrawnIsEqualsToPay("BestClient.txt");
		Home2.PrintInfoToFileIfDrawnIsEqualsToPay("BestClients.txt");
		bank.AddAccount(Home1);
		bank.AddAccount(Home2);
		bank.AddAccount(Home3);
		bank.AddAccount(Home4);
		bank.AddAccount(Home5);
		bank.AddAccount(Car1);
		bank.AddAccount(Car2);
		bank.AddAccount(Car3);
		bank.AddAccount(Car4);
		bank.AddAccount(Car5);
		bank.AddAccount(Excursion1);
		bank.AddAccount(Excursion2);
		bank.AddAccount(Excursion3);
		Home1.PrintAllInfoToFile("ClientHome1.txt", "SpecialHomeClient.txt");
		

	}
	catch (exception e)
	{
		cout << e.what();
	}

}
static void CreateBank(string name)
{
	Bank bank1(name);
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
