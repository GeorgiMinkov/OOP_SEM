// HW_TASK3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstring>

using namespace std;

enum color { brown, green, orange, red, yellow };

enum YesNo { yes, no };

struct Fruit
{
	char name[32]; 
	color lc;  
	YesNo annual;
	YesNo perennial;
	YesNo tropical; 

	void input();
	void output();
};

void messegeSort(int &);
void errorMessege();
void colorChoice(color &, const int);
void yesNoChoice(YesNo &, const int);
void sortByName(Fruit **, const int);
void sortByColor(Fruit **, const int);
void sortByDuration(Fruit **, const int);
int main()
{
	int n, index;
	do
	{
		cout << "How many elements you wanna enter (>0): ";
		cin >> n;
	} while (n <= 0);

	Fruit **members;
	members = new Fruit *[n];
	
	cout << "\tINPUT\n";
	for (int i = 0; i < n; i++)
	{
		members[i] = new Fruit;
		members[i]->input();
	}

	messegeSort(index);
	if (index == 1)	sortByName(members, n);
	else 
		if (index == 2) sortByColor(members, n);
		else sortByDuration(members, n);
	
	cout << "\n\tOUTPUT\n";
	for (int i = 0; i < n; i++) members[i]->output();

	delete[]members;
    return 0;
}

void messegeSort(int &index)
{
	do
	{
		cout << "\nHow you wanna sort: 1 - by name, 2 - color, 3 - duration of fruiting ->";
		cin >> index;
	} while (index < 1 || index>3);
}

void errorMessege()
{
	cout << "One fruit can't be annual and perenial at once" << endl;
}

void colorChoice(color &lc, const int index)
{
	switch (index)
	{
	case 0: lc = color::brown; break;
	case 1: lc = color::green; break;
	case 2: lc = color::orange; break;
	case 3: lc = color::red; break;
	case 4: lc = color::yellow; break;
	}
}

void yesNoChoice(YesNo &structElements, const int index)
{
	if (index == 0) structElements = YesNo::yes;
	else structElements = YesNo::no;
}

void sortByName(Fruit **members, const int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (strcmp(members[j]->name, members[j + 1]->name) > 0)
			{
				Fruit *swap = members[j];
				members[j] = members[j + 1];
				members[j + 1] = swap;
			}
}

void sortByColor(Fruit **members, const int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (members[j]->lc >members[j + 1]->lc)
			{
				Fruit *swap = members[j];
				members[j] = members[j + 1];
				members[j + 1] = swap;
			}
}

void sortByDuration(Fruit ** members, const int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (members[j]->annual > members[j+1]->annual)
			{
				Fruit *swap = members[j];
				members[j] = members[j + 1];
				members[j + 1] = swap;
			}
}

void Fruit::input()
{
	int index;

	cout << "\nEnter fruit name: ";
	cin >> name;

	do
	{
		cout << "Enter color 0 - brown, 1 - green, 2 - orange, 3 - red, 4 - yellow : ";
		cin >> index;
	} while (index < 0 || index > 4);

	colorChoice(lc, index);

	do
	{
		cout << "Annual fruit (0 - YES, 1 - NO): ";
		cin >> index;
	} while (index < 0 || index > 1);

	yesNoChoice(annual, index);

	bool mess = false;
	do
	{
		cout << "Perenial fruit (0 - YES, 1 - NO): ";
		cin >> index;

		if (annual == index)
		{
			mess = true;
			errorMessege();
		}
		else mess = false;

	} while (index < 0 || index > 1 || mess);

	yesNoChoice(perennial, index);

	do
	{
		cout << "Tropical fruit (0 - YES, 1 - NO): ";
		cin >> index;
	} while (index < 0 || index > 1);

	yesNoChoice(tropical, index);
}

void Fruit::output()
{
	cout << "Fruit name: " << name << endl;
	cout << "Color: " << lc << endl;
	cout << "Annual: " << annual << endl;
	cout << "Perennial: " << perennial << endl;
	cout << "Tropical: " << tropical << endl << endl;
}