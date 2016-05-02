#ifndef PATIENT_H
#define PATIENT_H
#include"Date.h"

class Patient
{
private:
	char *name; // ако нещо бъгва направи го статичен
	Date date;
	size_t countVisit; // общо визити за една година
	size_t planVisit; // планирани визити

	char *patientHistory; // история на пациента за една година	

public:
	Patient(); 
	Patient(char*, Date, size_t, size_t, char*);
	Patient& operator= (const Patient &other);
	~Patient();

	void setName(char *);
	void setDate(Date);
	void setCountVisit(size_t);
	void setPlanVisit(size_t);
	void setPatientHistory(char *);

	char *getName() const;
	Date getDate() const;
	size_t getCountVisit() const;
	size_t getPlanVisit() const;
	char *getPatentHistory() const;

	//функци които проверяват състоянието на пациента

	bool isVisitEqualAmount() const; //проверява направените визити


};

#endif // !PATIENT_H

