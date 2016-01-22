/*
 * FemaleIn.h
 *
 *  Created on: Apr 8, 2015
 *      Author: justin
 */

#ifndef HEADERS_FEMALEIN_H_
#define HEADERS_FEMALEIN_H_
#include "InPatient.h"
#include "Female.h"
#include <iostream>
#include <string>
using namespace std;
class FemaleIn : public Female, InPatient{
public:
	FemaleIn();
	FemaleIn(string);
	void parse(string);
	string toString();
	void enterPatientData();
	void display();
	void writeToFile();
};



#endif /* HEADERS_FEMALEIN_H_ */
