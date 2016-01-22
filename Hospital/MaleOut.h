/*
 * MaleOut.h
 *
 *  Created on: Apr 8, 2015
 *      Author: justin
 */

#ifndef HEADERS_MALEOUT_H_
#define HEADERS_MALEOUT_H_
#include "OutPatient.h"
#include "Male.h"
#include <iostream>
#include <string>
using namespace std;
class MaleOut : public Male, OutPatient{
public:
	MaleOut();
	MaleOut(string);
	void parse(string);
	string toString();
	void enterPatientData();
	void display();
	void writeToFile();
};



#endif /* HEADERS_MALEOUT_H_ */
