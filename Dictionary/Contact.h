#pragma once
#include<iostream>
#include<string>
#include<cmath>

class Contact
{
	std::string name;
	std::string telNumber;
	std::string ID;

	void copyObject(const Contact &other);
	void checkAndCorrectTelNumber();
public:
	Contact(std::string name = "", std::string telNumber = "", std::string ID = "");
	Contact(const Contact &other);
	Contact &operator=(const Contact &other);
	
	void setName(std::string name);
	void setTelNumber(std::string telNumber);
	void setID(std::string ID);

	std::string getName() const;
	std::string getTelNumber() const;
	std::string getID() const;

	friend std::ostream &operator<<(std::ostream &out, const Contact &source);
};