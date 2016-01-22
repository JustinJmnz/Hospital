#ifndef HOSPITAL_H_
#define HOSPITAL_H_
#include "Patient.h"
class Hospital{
private:
	int patientCapacity;
	int totalPatients;
	char * HospitalName;
	char * fileName;
	Patient** patients;
	void determinePatientType();
	const static char delimeter = ',';
public:
	Hospital(char*, int, char*);
	void readRecordsFile();
	void display(int);
	void admit(int);
	~Hospital();
};



#endif /* HOSPITAL_H_ */
