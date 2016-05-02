// Task2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<iomanip>

using namespace std;

struct Planet
{
	char *namePlanet;
	double diameter, weight, distance;

	void input();
	void output();
	double calculate();
	void deleteMemory();
};


//FUNCTIONS
Planet biggestDiameter(Planet*, const int);
Planet smallestWeight(Planet*, const int);
Planet sunDistanceCalculateMax(Planet *, const int);
Planet sunDistanceCalculateMin(Planet *, const int);

int main()
{
	int n;
	do
	{
		cout << "Enter element (>0): ";
		cin >> n;
	} while (n <= 0);

	Planet *element = new Planet[n];

	cout << "\tINPUT:\n";
	for (int i = 0; i < n; i++) element[i].input();

	cout << "\n\tOUTPUT\n";
	for (int i = 0; i < n; i++) element[i].output();
	
	cout << "\nPlanet with biggest diameter: " << biggestDiameter(element, n).namePlanet << endl;
	
	cout << "\nPlanet with smallest weight: " << smallestWeight(element, n).namePlanet << endl;

	cout << "\nPlanet on which light reaches final: " << sunDistanceCalculateMax(element, n).namePlanet << endl;

	cout << "\nPlanet on which light reaches first: " << sunDistanceCalculateMin(element, n).namePlanet << endl;

	//delete dynamic
	for (int i = 0; i < n; i++) element[i].deleteMemory();
	delete[] element;
    return 0;
}

void Planet::input()
{
	namePlanet = new char[1000];
	cout << "\nEnter planet name: ";
	cin >> namePlanet;

	do
	{
		cout << "Enter distance(>0), diameter(>0), weight(>0) = ";
		cin >> distance >> diameter >> weight;
	} while (distance <= 0 || diameter <= 0 || weight <= 0);
}

void Planet::output()
{
	cout << "NAME: " << namePlanet << endl;
	cout << "Distance: " << distance << ", diameter: " << diameter << ", weight: " << weight << endl;
}

double Planet::calculate()
{
	const double sunSpeed = 299792;
	return distance / sunSpeed;
}

void Planet::deleteMemory()
{
	delete[] namePlanet;
}

Planet biggestDiameter(Planet *planets, const int n)
{
	int index = 0;
	int maxDiam = planets[index].diameter;

	for (int i = 1; i < n; i++)
		if (maxDiam < planets[i].diameter)
		{
			index = i;
			maxDiam = planets[i].diameter;
		}

	return planets[index];
}

Planet smallestWeight(Planet *planets, const int n)
{
	int index = 0;
	double minWeight = planets[index].weight;

	for (int i = 1; i < n; i++)
		if (minWeight > planets[i].weight)
		{
			index = i;
			minWeight = planets[i].weight;
		}

	
	return planets[index];
}

Planet sunDistanceCalculateMax(Planet *planets, const int n)
{	
	int index = 0;
	double maxCalc = planets[index].calculate();

	for (int i = 1; i < n; i++)
		if (maxCalc < planets[i].calculate())
		{
			index = i;
			maxCalc = planets[i].calculate();
		}

	return planets[index];
}

Planet sunDistanceCalculateMin(Planet *planets, const int n)
{
	int index = 0;
	double minCalc = planets[index].calculate();

	for (int i = 1; i < n; i++)
		if (minCalc > planets[i].calculate())
		{
			minCalc = planets[i].calculate();
			index = i;
		}

	return planets[index];
}