/*
 * FemaleOut.h
 *
 *  Created on: Apr 8, 2015
 *      Author: justin
 */

#ifndef HEADERS_FEMALEOUT_H_
#define HEADERS_FEMALEOUT_H_
#include "OutPatient.h"
#include "Female.h"
#include <iostream>
#include <string>
using namespace std;
class FemaleOut : public Female, OutPatient{
public:
	FemaleOut();
	FemaleOut(string);
	void parse(string);
	string toString();
	void enterPatientData();
	void display();
	void writeToFile();
};


#endif /* HEADERS_FEMALEOUT_H_ */
