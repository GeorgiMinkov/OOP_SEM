// homewortTask2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
#include"Date.h"
#include"Patient.h"
#include"Doctor.h"

using namespace std;

int main()
{
	int amount;
	
	do
	{
		cout << "Enter amount(>0) of patients for Doctor X: ";
		cin >> amount;
		cin.ignore();
	} while (amount <= 0);

	Patient *patients = new Patient[amount];

	for (size_t i = 0; i < amount; i++)
	{
		char name[1000];
		cout << "Enter name for patient N:" << i + 1 << " : ";
		cin.getline(name, 1000);

		int day, month, year;
		do
		{
			cout << "Enter birth day(>0): ";
			cin >> day;
		} while (day <= 0);

		do
		{
			cout << "Enter birth month(>0 && <13): ";
			cin >> month;
		} while (month <= 0 || month > 12);

		do
		{
			cout << "Enter birth year: ";
			cin >> year;
		} while (year <= 0);

		int planVisit, countVisit;
		do
		{
			cout << "Enter planVisit(>=0): ";
			cin >> planVisit;
		} while (planVisit < 0);
		do
		{
			cout << "Enter amount(>=0) of current visits: ";
			cin >> countVisit;
			cin.ignore();
		} while (countVisit < 0);

		char patientHistory[10000];
		cout << "Enter patient history: ";
		cin.getline(patientHistory, 10000);

		cout << endl;
		patients[i].setName(name);
		patients[i].setPatientHistory(patientHistory);
		patients[i].setDate(Date(day, month, year));
		patients[i].setPlanVisit(planVisit);
		patients[i].setCountVisit(countVisit);
		//patients[i] = Patient(name, Date(day, month, year), countVisit, planVisit, patientHistory);
	}
	//Doctor doctorX("Doctor X", patients, 5);
	Doctor doctorX;
	doctorX.setDoctorName("Doctor X");
	doctorX.setPatients(patients, amount);
	int check = 1;

	while(check != 4)
	{
		do
		{
			cout << "What ifnormation you need for Doctor X: " << endl;
			cout << "1 - Patients info" << endl;
			cout << "2 - Avarage Hospitalization" << endl;
			cout << "3 - List of patient with more hospitalization than planned" << endl;
			cout << "4 - QUIT" << endl;
			cin >> check;
		} while (check < 1 || check > 4);
		switch (check)
		{
		case 1: 
		{
			Patient *tmpPatients = doctorX.getPatient();
			for (size_t i = 0; i < doctorX.getPatientsAmount(); ++i)
			{
				cout << "Patient name: " << tmpPatients[i].getName() << endl;
				cout << "Patient birth day: " << tmpPatients[i].getDate().getDay() << " " << tmpPatients[i].getDate().getMonth() << " " << tmpPatients[i].getDate().getYear() << endl;
				cout << "Patient visits: " << tmpPatients[i].getCountVisit() << endl;
				cout << "Patient planned visits" << tmpPatients[i].getPlanVisit() << endl;
				cout << "Patient history: " << tmpPatients[i].getPatentHistory() << endl;
			}
			//delete[] tmpPatients;
		} break;
		case 2: cout << "Avarage: " << doctorX.avarageHospitalization() << endl; break;
		case 3: doctorX.listOfPatientWithMoreHospitalizationThanPlanned(); break;
		default: cout << "HAVE A NICE DAY\n"; break;
		}
	}

	delete[] patients;
    return 0;
}

Date::Date(size_t day, size_t month, size_t year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date()
{
}

Date & Date::operator=(const Date & other)
{
	if (this != &other)
	{
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}

	return *this;
}

void Date::setDay(size_t day)
{
	this->day = day;
}

void Date::setMonth(size_t month)
{
	this->month = month;
}

void Date::setYear(size_t year)
{
	this->year = year;
}

size_t Date::getDay() const
{
	return this->day;
}

size_t Date::getMonth() const
{
	return this->month;
}

size_t Date::getYear() const
{
	return this->year;
}

//Patient
Patient::Patient()
{
	this->name = new char[2];
	strcpy_s(this->name, 2, "");

	this->date = Date();

	this->countVisit = 0;
	this->planVisit = 0;

	this->patientHistory = new char[2];
	strcpy_s(this->patientHistory, 2, "");
}

Patient::Patient(char *name, Date date, size_t countVisit, size_t planVisit, char *patientHistory)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	
	this->date = date;

	this->countVisit = countVisit;
	this->planVisit = planVisit;

	this->patientHistory = new char[strlen(patientHistory) + 1];
	strcpy_s(this->patientHistory, strlen(patientHistory) + 1, patientHistory);
}

Patient & Patient::operator=(const Patient & other)
{
	// TODO: insert return statement here
	if (this != &other)
	{
		if (this->name != NULL) delete[] this->name;
		if (this->patientHistory != NULL) delete[] this->patientHistory;

		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);

		this->patientHistory = new char[strlen(other.patientHistory) + 1];
		strcpy_s(this->patientHistory, strlen(other.patientHistory) + 1, other.patientHistory);

		this->date = other.date;
		this->countVisit = other.countVisit;
		this->planVisit = other.planVisit;
	}

	return *this;
}

Patient::~Patient()
{
	//delete[] name;
	//delete[] patientHistory;
}

void Patient::setName(char *name)
{
	//if (this->name != NULL) delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Patient::setDate(Date date)
{
	this->date = date;
}

void Patient::setCountVisit(size_t countVisit)
{
	this->countVisit = countVisit;
}

void Patient::setPlanVisit(size_t planVisit)
{
	this->planVisit = planVisit;
}

void Patient::setPatientHistory(char *patientHistory)
{
	//if (this->patientHistory != NULL) delete[] this->patientHistory;

	this->patientHistory = new char[strlen(patientHistory) + 1];
	strcpy_s(this->patientHistory, strlen(patientHistory) + 1, patientHistory);
}

char * Patient::getName() const
{
	return this->name;
}

Date Patient::getDate() const
{
	return this->date;
}

size_t Patient::getCountVisit() const
{
	return this->countVisit;
}

size_t Patient::getPlanVisit() const
{
	return this->planVisit;
}

char * Patient::getPatentHistory() const
{
	return this->patientHistory;
}

bool Patient::isVisitEqualAmount() const
{
	return this->countVisit == this->planVisit ? true : false;
}

//DOCTOR
Doctor::Doctor()
{
	this->doctorName = new char[1];
	strcpy_s(this->doctorName, 2, "");

	this->patientsAmount = 0;
	this->patients = new Patient[0];
}

Doctor::Doctor(char *doctorName, Patient patients[], size_t patientsAmount)
{
	this->doctorName = new char[strlen(doctorName) + 1];
	strcpy_s(this->doctorName, strlen(doctorName) + 1, doctorName);

	this->patientsAmount = patientsAmount;

	for (size_t i = 0; i < patientsAmount; ++i)
		this->patients[i] = patients[i];
}

Doctor::~Doctor()
{
	delete[] this->doctorName;
	delete[] this->patients;
}

void Doctor::setDoctorName(char *name)
{
	//if (this->doctorName != NULL) delete[] this->doctorName;

	this->doctorName = new char[strlen(name) + 1];
	strcpy_s(this->doctorName, strlen(name) + 1, name);
}

void Doctor::setPatients(Patient *patients, size_t amount)
{
	this->patientsAmount = amount;

	//if (this->patients != NULL) delete[] this->patients;

	this->patients = new Patient[amount];

	for (size_t i = 0; i < amount; ++i)
		this->patients[i] = patients[i];
}

const float Doctor::avarageHospitalization() const
{
	float sum = 0;
	for (size_t i = 0; i < this->patientsAmount; ++i)
		sum += this->patients[i].getCountVisit();

	return sum / 356;
}

void Doctor::listOfPatientWithMoreHospitalizationThanPlanned() const
{
	bool check = false;
	for (size_t i = 0; i < this->patientsAmount; ++i)
	{
		if (!this->patients[i].isVisitEqualAmount())
		{
			cout << "Patient: " << this->patients[i].getName() << endl;
			check = true;
		}
	}

	if (!check) cout << "No Patient with more hospitalizations than planned!" << endl;
}

Patient * Doctor::getPatient() const
{
	return this->patients;
}

size_t Doctor::getPatientsAmount() const
{
	return this->patientsAmount;
}

