// 71600.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
#include<conio.h>

using namespace std;

struct Person
{
	char name[100];
	char lname[100];
};

struct Client
{
	Person p;
	float money;
};

void init(Client info[], char *n, char *ln, float money, int i)
{
	strcpy_s(info[i].p.name, n);
	strcpy_s(info[i].p.lname, ln);
	info[i].money = money;
}

void input(Client info[], int n)
{
	char name[100], lName[100];
	float money;
	for (int i = 0; i < n; i++)
	{
		cout << "NAME: ";
		cin >> name;

		cout << "LAST NAME: ";
		cin >> lName;
	 
		cout << "MONEY: ";
		cin >> money;

		init(info, name, lName, money, i);
		
		cout << endl;
	}
}

void print(Client info[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "FULL NAME - ";
		cout << info[i].p.name << " " << info[i].p.lname << endl;
		cout << "MONEY: " << info[i].money << endl;
		cout << endl;
	}
}

float sumM(Client info[], int n, int sum)
{
	if (n == 0) return info[n].money;

	return info[n].money + sumM(info, n - 1, sum);
}

int main()
{
	Client info[100];
	int n;
	do
	{
		cout << "ENTER n(>0) = ";
		cin >> n;
	} while (n <= 0);

	input(info, n);
	cout << endl;

	print(info, n);

	cout <<  "SUM: " << sumM(info, n - 1, 0) << endl;
    return 0;
}
