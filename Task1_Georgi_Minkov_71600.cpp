// Task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

struct Triangle
{
	float a, b, c;

	void create(float x, float y, float z)
	{
		a = x;
		b = y; 
		c = z;
	}

	void output()
	{
		cout << a << " " << b << " " << c << endl;
	}

	float perimeter()
	{
		return a + b + c;
	}
	
	float surface()
	{
		return 0.25*(sqrt(2 * (pow(a, 2)* pow(b, 2) + pow(a, 2)*pow(c, 2) + pow(b, 2)*pow(c, 2)) - (pow(a, 4) + pow(b, 4) + pow(c, 4))));
	}

	Triangle mult_k(int k)
	{
		Triangle t;
		t.create(a*k, b*k, c*k);
		return t;
	}

	Triangle minSurface(Triangle *arr, const int size)
	{
		int index = 0;
		float sur = arr[0].surface();
		for (int i = 1; i < size; i++)
			if (sur > arr[i].surface())
			{
				sur = arr[i].surface();
				index = i;
			}

		return arr[index];
	}

	Triangle maxPerimeter(Triangle *arr, const int size)
	{
		int index = 0;
		float maxPer = arr[0].perimeter();
		for (int i = 1; i < size; i++)
			if (maxPer < arr[i].perimeter())
			{
				maxPer = arr[i].perimeter();
				index = i;
			}

		return arr[index];
	}
	void newSequance(Triangle *arr, int size, Triangle *newArr)
	{
		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i].mult_k(i + 1);
		}
	}
};

void input(float &, float &, float &, const int);
int main()
{
	Triangle arr[20];
	int n;
	do
	{
		cout << "Enter n (1<=n<=20): ";
		cin >> n;
	} while (n < 1 || n>20);

	float x, y, z;
	for (int i = 0; i < n; i++)
	{
		input(x, y, z, i);
		arr[i].create(x, y, z);
	}

	Triangle t;
	cout << "Min surface, triangle with sides = ";
	t.minSurface(arr, n).output();

	cout << "\nMax perimeter, triangle with sides = ";
	t.maxPerimeter(arr, n).output();
	
	cout << "\nMULTYPLY SIDES:" << endl;
	for (int i = 0; i < n; i++)
		arr[i].mult_k(i + 1).output();

    return 0;
}

void input(float &x, float &y, float &z, const int i)
{
	do
	{
		cout << "Enter triangle N: " << i + 1 << " sides (so the triangle can exist): " << endl;
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		cout << "z = ";
		cin >> z;
	} while ((x <= 0 || y <= 0 || z <= 0) || ((x + y) <= z) || ((x + z) <= y) || ((z + y) <= x));
}
