#include "stdafx.h"
#include "ContactBookr.h"

void ContactBook::resize()
{
	if (this->capacity == 0) this->capacity = 1;
	int GAP = ceil(this->capacity * 1.7);

	Contact *buffer = new Contact[GAP];

	for (size_t i = 0; i < this->currentSize; i++)
	{
		buffer[i] = this->contacts[i];
	}

	delete[] this->contacts;

	this->contacts = buffer;
	this->capacity = GAP;
}

void ContactBook::copyElements(Contact * contacts, int currentSize, int capacity)
{
	this->contacts = new Contact[capacity];

	for (size_t i = 0; i < currentSize; i++)
	{
		this->contacts[i] = contacts[i];

		this->contactsByName.addNewElement(contacts[i].getName(), &(contacts[i]));
		this->contactsByTelNumber.addNewElement(contacts[i].getTelNumber(), &(contacts[i]));
		this->contactsByID.addNewElement(contacts[i].getID(), &(contacts[i]));
	}

	this->currentSize = currentSize;
	this->capacity = capacity;
}

void ContactBook::copyObject(const ContactBook & other)
{
	this->contacts = new Contact[other.capacity];

	for (size_t i = 0; i < other.currentSize; i++)
	{
		this->contacts[i] = other.contacts[i];

		this->contactsByName.addNewElement(other.contacts[i].getName(), &(other.contacts[i]));
		this->contactsByTelNumber.addNewElement(other.contacts[i].getTelNumber(), &(other.contacts[i]));
		this->contactsByID.addNewElement(other.contacts[i].getID(), &(other.contacts[i]));
	}

	this->currentSize = other.currentSize;
	this->capacity = other.capacity;
}

void ContactBook::destroy()
{
	if (this->contacts != nullptr) delete[] this->contacts;
}

void ContactBook::sort(userPick pick)
{
	for (size_t i = 0; i < this->currentSize; i++)
	{
		for (size_t j = 0; j < this->currentSize - i - 1; j++)
		{
			if (pick == NAME)
			{
				if (contacts[j].getName().compare(contacts[j + 1].getName()) > 0)
				{
					Contact tmp = contacts[j];
					contacts[j] = contacts[j + 1];
					contacts[j + 1] = tmp;
				}
			}
			else
			{
				if (pick == TELEPHONE_NUMBER)
				{
					if (contacts[j].getTelNumber().compare(contacts[j + 1].getTelNumber()) > 0)
					{
						Contact tmp = contacts[j];
						contacts[j] = contacts[j + 1];
						contacts[j + 1] = tmp;
					}
				}
				else
				{
					if (contacts[j].getID().compare(contacts[j + 1].getID()) > 0)
					{
						Contact tmp = contacts[j];
						contacts[j] = contacts[j + 1];
						contacts[j + 1] = tmp;
					}
				}
			}
		}
	}
}

void ContactBook::moveToRight(size_t index)
{
	for (; index < this->currentSize - 1; index++)
		this->contacts[index] = this->contacts[index + 1];

	this->currentSize--;
}

bool ContactBook::isFull() const
{
	return this->capacity == this->currentSize;
}

ContactBook::ContactBook()
{
	this->contacts = nullptr;
	this->capacity = 0;
	this->currentSize = 0;
}

ContactBook::ContactBook(Contact * contacts, int currentSize, int capacity)
{
	this->copyElements(contacts, currentSize, capacity);
}

ContactBook::ContactBook(const ContactBook & other)
{
	this->copyObject(other);
}

ContactBook::~ContactBook()
{
	this->destroy();
}

void ContactBook::addContact(const Contact & other)
{
	if (this->isFull())
	{
		this->resize();

		this->contacts[this->currentSize] = other;

		this->contactsByName.addNewElement(other.getName(), &(this->contacts[this->currentSize]));
		this->contactsByTelNumber.addNewElement(other.getTelNumber(), &(this->contacts[this->currentSize]));
		this->contactsByID.addNewElement(other.getID(), &(this->contacts[this->currentSize]));

		this->currentSize++;
	}
	else
	{
		this->contacts[this->currentSize] = other;

		this->contactsByName.addNewElement(other.getName(), &(this->contacts[this->currentSize]));
		this->contactsByTelNumber.addNewElement(other.getTelNumber(), &(this->contacts[this->currentSize]));
		this->contactsByID.addNewElement(other.getID(), &(this->contacts[this->currentSize]));

		this->currentSize++;

	}
}

const Contact ContactBook::findContactByName(std::string name) const
{
	return *(this->contactsByName.searchByKey(name));
}

const Contact ContactBook::findContactByTelNumber(std::string telNumber) const
{
	return *(this->contactsByTelNumber.searchByKey(telNumber));
}

const Contact ContactBook::findContactByID(std::string ID) const
{
	return *(this->contactsByID.searchByKey(ID));
}

void ContactBook::printByParam(userPick pick) const
{
	switch (pick)
	{
	case NAME: this->printByName();
		break;
	case TELEPHONE_NUMBER: this->printByTelNumber();
		break;
	case ID: this->printByID();
		break;
	default: std::cout << "Incorrect pick\n";
		break;
	}
}

void ContactBook::printByName() const
{
	ContactBook tmp(*this);

	tmp.sort(NAME);

	std::cout << tmp;
}

void ContactBook::printByTelNumber() const
{
	ContactBook tmp(*this);

	tmp.sort(TELEPHONE_NUMBER);

	std::cout << tmp;
}

void ContactBook::printByID() const
{
	ContactBook tmp(*this);

	tmp.sort(ID);

	std::cout << tmp;
}


void ContactBook::deleteContactByName(std::string name)
{
	bool check = false;
	for (size_t i = 0; i < this->currentSize && !check; i++)
	{
		if (this->contacts[i].getName().compare(name) == 0)
		{
			this->moveToRight(i);
			check = true;

			this->contactsByID.deleteByKey(this->contacts[i].getID()); // ÄÀ ÑÅ ÌÀÕÀ ËÈ È ÒÓÊ
			this->contactsByName.deleteByKey(this->contacts[i].getName());
			this->contactsByTelNumber.deleteByKey(this->contacts[i].getTelNumber());
		}
	}
}

void ContactBook::deleteContactByTelNumber(std::string telNumber)
{
	bool check = false;
	for (size_t i = 0; i < this->currentSize && !check; i++)
	{
		if (this->contacts[i].getTelNumber().compare(telNumber) == 0)
		{
			this->moveToRight(i);
			check = true;
			
			this->contactsByID.deleteByKey(this->contacts[i].getID()); // ÄÀ ÑÅ ÌÀÕÀ ËÈ È ÒÓÊ
			this->contactsByName.deleteByKey(this->contacts[i].getName());
			this->contactsByTelNumber.deleteByKey(this->contacts[i].getTelNumber());
		}
	}
}

void ContactBook::deleteContactByID(std::string ID)
{
	bool check = false;
	for (size_t i = 0; i < this->currentSize && !check; i++)
	{
		if (this->contacts[i].getID().compare(ID) == 0)
		{
			this->moveToRight(i);
			check = true;

			this->contactsByID.deleteByKey(this->contacts[i].getID()); // ÄÀ ÑÅ ÌÀÕÀ ËÈ È ÒÓÊ
			this->contactsByName.deleteByKey(this->contacts[i].getName());
			this->contactsByTelNumber.deleteByKey(this->contacts[i].getTelNumber());
		}
	}
}

std::ostream &operator<<(std::ostream &out, const ContactBook &source)
{
	for (size_t i = 0; i < source.currentSize; i++)
		out << "N|" << i + 1 << "| " << source.contacts[i] << std::endl;

	return out;
}