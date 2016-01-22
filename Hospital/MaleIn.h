/*
 * MaleIn.h
 *
 *  Created on: Apr 8, 2015
 *      Author: justin
 */

#ifndef HEADERS_MALEIN_H_
#define HEADERS_MALEIN_H_
#include "InPatient.h"
#include "Male.h"
#include <iostream>
#include <string>

using namespace std;

class MaleIn : public Male, InPatient{
public:
	MaleIn();
	MaleIn(string);
	void parse(string);
	string toString();
	void enterPatientData();
	void display();
	void writeToFile();
};



#endif /* HEADERS_MALEIN_H_ */
