// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dictionary.h"
#include"Contact.h"

int main()
{
	int arr[] = { 1 };
	int arrV[] = { 10 };

	Dictionary<int, int> dic(arr, arrV, 1, 10);
	for (size_t i = 2; i <= 15; i++)
	{
		dic.addNewElement(i, i * 10);
	}
	std::cout << dic << std::endl;
	/*	Contact contact("Georg Min", "089560", "010101101");
	contact.setName("asdasdasdasdasdasdasdasd");

	Contact contactA("Georg", "08asd60", "qweqweqwe");

	contact = contactA;
	std::cout << contact.getName();
	*/
	return 0;
}
