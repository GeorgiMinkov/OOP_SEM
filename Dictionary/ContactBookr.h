#pragma once
#include"Contact.h"
#include"Dictionary.h"
#include"SearchChoice.h"

class ContactBook
{
	Contact *contacts;
	int currentSize;
	int capacity;

	Dictionary<std::string, Contact*> contactsByName;
	Dictionary<std::string, Contact*> contactsByTelNumber;
	Dictionary<std::string, Contact*> contactsByID;

	void resize();
	void copyElements(Contact *contacts, int currentSize, int capacity);
	void copyObject(const ContactBook &other);
	void destroy();
	void sort(userPick pick);
	void moveToRight(size_t index);

	bool isFull() const;
public:
	ContactBook();
	ContactBook(Contact *contacts, int currentSize, int capacity);
	ContactBook(const ContactBook &other);
	~ContactBook();

	void addContact(const Contact &other);

	const Contact findContactByName(std::string name) const;
	const Contact findContactByTelNumber(std::string telNumber) const;
	const Contact findContactByID(std::string ID) const;

	void printByParam(userPick pick) const;
	void printByName() const;
	void printByTelNumber() const;
	void printByID() const;

	void deleteContactByName(std::string name);
	void deleteContactByTelNumber(std::string telNumber);
	void deleteContactByID(std::string ID);

	friend std::ostream &operator<<(std::ostream &out, const ContactBook &surce);
};