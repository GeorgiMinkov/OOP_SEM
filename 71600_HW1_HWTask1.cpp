// HomeW_Task.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstring>

using namespace std;

struct Destination
{
	char city[32];
	int kilometers;
};

void readyInit(Destination &, Destination &);
void outputReadyInit(const Destination, const Destination);

void nullInit(Destination[], const int);

void input(Destination[], const int);
void init(Destination[], const int, char[], const int);
void generalOutput(Destination[], const int);

bool check(char[], int);
void message();
int main()
{
	Destination Plovdiv, Varna;

	readyInit(Plovdiv, Varna);
	outputReadyInit(Plovdiv, Varna);

	Destination arrayInfo[30];
	const int n = 30, five = 5;
	nullInit(arrayInfo, n);

	input(arrayInfo, five);
	generalOutput(arrayInfo, five);
    return 0;
}

void readyInit(Destination &Plovdiv, Destination &Varna)
{
	 Plovdiv = {
		"Plovdiv",
		165,
	}, Varna =
	{
		"Varna",
		469,
	};
}

void outputReadyInit(const Destination Plovdiv, const Destination Varna)
{
	cout << "\tReady initialize output:" << endl;

	cout << "Destination \t|\tkilometers" << endl;
	cout << Plovdiv.city << "\t\t|\t" << Plovdiv.kilometers << endl;
	cout << Varna.city << "\t\t|\t" << Varna.kilometers << endl;

}

void nullInit(Destination arrayInfo[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		memset(&arrayInfo[i].city, NULL, 32);
		arrayInfo[i].kilometers = 0;
	}
}

void input(Destination arrInfo[], const int n)
{
	char *name = new char[32];
	int *kilometers = new int;

	cout << "\n\tINPUT - 5 items:" << endl;

	for (int i = 0; i < n; i++)
	{

		cout << "Enter name of city N: " << i + 1 << " : ";
		cin >> name;

		do
		{
			cout << "Enter kilometers(>0): ";
			cin >> *kilometers;
		} while (*kilometers < 0 || !check(name, *kilometers));
	
		init(arrInfo, i, name, *kilometers);

		cout << endl;
	}
	delete[]name;
	delete kilometers;
}

void init(Destination arrInfo[], const int i, char name[], const int kilometers)
{
	strcpy_s(arrInfo[i].city, name);

	arrInfo[i].kilometers = kilometers;
}

void generalOutput(Destination arrInfo[], const int n)
{
	cout << "\n\t\tOUTPUT:" << endl;
	cout << "Destination \t|\tkilometers" << endl;

	for (int i = 0; i < n; i++)
		cout << arrInfo[i].city << "\t\t|\t" << arrInfo[i].kilometers << endl;
	
	cout << endl;
}

bool check(char city[], int kilometers)
{
	if (strcmp(city, "Sofia") == 0 || strcmp(city, "sofia") == 0 || strcmp(city, "SOFIA") == 0)
	{
		if (kilometers == 0) return true;
		else
		{
			message();
			return false;
		}
	}
	else
	{
		if (kilometers == 0) return false;
		else return true;
	}
}

void message()
{
	cout << "YOU ENTERED SOFIA SO IT CAN'T BE MORE OR LESS THAN 0" << endl;
}
