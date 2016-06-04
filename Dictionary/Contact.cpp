#include"stdafx.h"
#include"Contact.h"

void Contact::copyObject(const Contact &other)
{
	this->name = other.name;
	this->ID = other.ID;
	this->telNumber = other.telNumber;

	this->checkAndCorrectTelNumber();
}

void Contact::checkAndCorrectTelNumber()
{
	if (this->telNumber.length() > 10)
	{
		std::cout << "Telephone number will be resize to 10 symbols\n";
		this->telNumber.resize(10);
	}
}

Contact::Contact(std::string name, std::string telNumber, std::string ID)
{
	this->name = name;
	this->ID = ID;
	this->telNumber = telNumber;

	this->checkAndCorrectTelNumber();
}

Contact::Contact(const Contact & other)
{
	this->copyObject(other);
}

Contact & Contact::operator=(const Contact & other)
{
	// TODO: =
	if (this != &other)
	{
		this->copyObject(other);
	}

	return *this;
}

void Contact::setName(std::string name)
{
	this->name = name;
}

void Contact::setTelNumber(std::string telNumber)
{
	this->telNumber = telNumber;
}

void Contact::setID(std::string ID)
{
	this->ID = ID;
}

std::string Contact::getName() const
{
	return this->name;
}

std::string Contact::getTelNumber() const
{
	return this->telNumber;
}

std::string Contact::getID() const
{
	return this->ID;
}

std::ostream & operator<<(std::ostream & out, const Contact & source)
{
	// TODO: <<
	out << source.name << " " << source.telNumber << " " << source.ID;

	return out;
}
