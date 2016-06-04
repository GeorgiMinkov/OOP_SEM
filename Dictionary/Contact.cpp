#include "stdafx.h"
#include "Contact.h"

void Contact::copyString(char *& destination, char * source)
{
	destination = new char[strlen(source) + 1];

	strcpy_s(destination, strlen(source) + 1, source);
}

void Contact::copyElements(const Contact & other)
{
	this->copyString(this->name, other.name);

	strcpy_s(this->number, other.number);

	this->copyString(this->id, other.id);
}

Contact::Contact()
{
	this->name = nullptr;

	strcpy_s(this->number, "");

	this->id = nullptr;
}

Contact::Contact(char * name, char number[11], char * id)
{
	this->copyString(this->name, name);

	strcpy_s(this->number, number);

	this->copyString(this->id, id);
}

Contact::Contact(const Contact & other)
{
	this->copyElements(other);
}

Contact & Contact::operator=(const Contact & other)
{
	// TODO: =
	if (this != &other)
	{
		if (this->name != nullptr) delete[] this->name;
		if (this->id != nullptr) delete[] this->id;

		copyElements(other);
	}

	return *this;
}

Contact::~Contact()
{
	delete[] this->name;

	delete[] this->id;
}

void Contact::setName(char * name)
{
	if (this->name != nullptr) delete[] this->name;
	
	this->copyString(this->name, name);
}

void Contact::setNumber(const char number[11])
{
	strcpy_s(this->number, number);
}

void Contact::setID(char * id)
{
	if (this->id != nullptr) delete[] this->id;

	this->copyString(this->id, id);
}

char * Contact::getName() const
{
	return this->name;
}

char * Contact::getNumber() const
{
	char *number = new char[11];
	strcpy_s(number, 11, this->number);

	return number;
}

char * Contact::getID() const
{
	return this->id;
}
