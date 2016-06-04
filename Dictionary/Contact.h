#pragma once
#include<cstring>

class Contact
{
	char *name;
	char number[11];
	char *id;

	void copyString(char *& destination, char *source);
	void copyElements(const Contact &other);

public:
	Contact();
	Contact(char *name, char number[11], char *id);
	Contact(const Contact &other);
	Contact &operator=(const Contact &other);
	~Contact();

	void setName(char *name);
	void setNumber(const char number[11]);
	void setID(char *id);

	char * getName() const;
	char * getNumber() const;
	char * getID() const;
};