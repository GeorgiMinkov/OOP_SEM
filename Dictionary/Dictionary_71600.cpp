// Dictionary_71600.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"ContactBookr.h"

int main()
{
	int arrK[] = { 1 };
	int arrV[] = { 10 };
	std::string *arrSK = nullptr;
	std::string *arrSV = {};

	//Dictionary<int, int> test (arrK, arrV, 1, 10);

	Dictionary<std::string, std::string> testW;//  огато н€ма елементи сорировката не работи
	testW.addNewElement("ASDASD", "QWEQWEQWE");
	testW.addNewElement("ASaDASD", "QWEQWEQWE");
	testW.addNewElement("ASDaASD", "QWEQWEQWE");
	//for (size_t i = 2; i < 10; i++)
	//	test.addNewElement(i, i * 10);
	//std::cout << test << std::endl;
	//std::cout << testW << std::endl;

	Contact testContact[3] = { Contact("GG", "1234101213", "9589554400"), Contact("ZZ", "1234563", "9589554400"), Contact("AA", "564455", "9556554400") };
	Contact testContact1( "GG", "1234101213", "9589554400" );

	std::cout << "\n___________: \n";

	ContactBook testCB(testContact, 3, 10), test;

	for (size_t i = 0; i < 5; i++)
		test.addContact(testContact1);

	testCB.deleteContactByName("00");
	std::cout << testCB << std::endl;
	std::cout << "|||||||||||||||||||||||||||||||||" << std::endl;
	testCB.deleteContactByName("GG");
	std::cout << testCB << std::endl;

	
	return 0;
}

