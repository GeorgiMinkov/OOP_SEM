#ifndef DOCTOR_H
#define DOCTOR_H
#include"Patient.h"

class Doctor
{
private:
	char *doctorName;
	Patient *patients;
	size_t patientsAmount;

public:
	Doctor();
	Doctor(char*, Patient[], size_t);
	~Doctor();

	void setDoctorName(char *);
	void setPatients(Patient*, size_t);

	const float avarageHospitalization() const;
	void listOfPatientWithMoreHospitalizationThanPlanned() const;

	Patient *getPatient() const;
	size_t getPatientsAmount() const;
};
#endif // !DOCTOR_H

