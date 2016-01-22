/*
 * Patient.h
 *
 *  Created on: Apr 8, 2015
 *      Author: justin
 */

#ifndef HEADERS_PATIENT_H_
#define HEADERS_PATIENT_H_
#include <iostream>
using namespace std;

class Patient{
public:
	Patient(){}
	const static int In = 1;
	const static int Out = 2;
	const static int Male = 4;
	const static int Female = 8;
	string name;
	string SSN;
	string insuranceName;
	string insuranceNumber;
	string age;
	string spouseName;
	string diagnosis;
	int typeOfPatient;
	virtual void parse(string record) = 0;
	virtual string toString() = 0;
	virtual void enterPatientData() = 0;
	virtual void display() = 0;
};



#endif /* HEADERS_PATIENT_H_ */
