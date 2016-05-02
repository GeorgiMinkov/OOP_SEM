#ifndef PATIENT_H
#define PATIENT_H
#include"Date.h"

class Patient
{
private:
	char *name; // ��� ���� ����� ������� �� ��������
	Date date;
	size_t countVisit; // ���� ������ �� ���� ������
	size_t planVisit; // ��������� ������

	char *patientHistory; // ������� �� �������� �� ���� ������	

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

	//������ ����� ���������� ����������� �� ��������

	bool isVisitEqualAmount() const; //��������� ����������� ������


};

#endif // !PATIENT_H

