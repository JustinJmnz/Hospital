/*
 * Hospital.cpp
 *
 *  Created on: Apr 8, 2015
 *      Author: justin
 */
#include "stdafx.h"
#include <iostream>
#include "Hospital.h"
#include "MaleIn.h"
#include "FemaleIn.h"
#include "MaleOut.h"
#include "FemaleOut.h"
#include <fstream>
#include <sstream>
using namespace std;

void Hospital::readRecordsFile() {
	ifstream fileStream;
	fileStream.open(fileName); // Open the file stream for fileName 
	string line;
	while(getline(fileStream,line)) {
		string delimiter = ",";
		size_t pos = 0;
		pos = line.find(delimiter);
		if(pos == std::string::npos) {
			continue;
		}
		int pType = atoi(line.substr(0, pos).c_str()); // Patient type = first section of line
		switch(pType){
		case (Patient::In | Patient::Male): // if pType is 5 : MaleIn
			patients[totalPatients] = new MaleIn(line);
			break;
		case (Patient::In | Patient::Female): // if pType is 9 : FemaleIn
			patients[totalPatients] = new FemaleIn(line);
			break;
		case (Patient::Out | Patient::Male): // if pType is 6 : MaleOut
			patients[totalPatients] = new MaleOut(line);
			break;
		case (Patient::Out | Patient::Female): // if pType is 10 : FemaleOut
			patients[totalPatients] = new FemaleOut(line);
			break;
		}
		totalPatients++;
	}
	fileStream.close(); // close stream
}
void Hospital::admit(int pType){
	switch(pType){
	case (Patient::In | Patient ::Male):
		patients[totalPatients] = new MaleIn();
		totalPatients++;
		break;
	case (Patient::In | Patient::Female):
		patients[totalPatients] = new FemaleIn();
		totalPatients++;
		break;
	case (Patient::Out | Patient::Male):
		patients[totalPatients] = new MaleOut();
		totalPatients++;
		break;
	case (Patient::Out | Patient::Female):
		patients[totalPatients] = new FemaleOut();
		totalPatients++;
		break;
	}
}

void Hospital::display(int inOrOut) {
	switch(inOrOut){
	case Patient::In:
		cout << endl <<"Name\t" << "Spouse\t" << "Sex\t" << "Type\t" << "Room #\t" << "Diagnosis" << endl
			 << "--------------------------------------------------------------" << endl;
		for(int i = 0; i < totalPatients; i++){
			if(patients[i]->typeOfPatient == (Patient::In | Patient::Male) || patients[i]->typeOfPatient == (Patient::In | Patient::Female)){ // Female/Male In Patient
				patients[i]->display();
			}
		}
		break;
	case Patient::Out:
		cout << endl <<"Name\t" << "Spouse\t" << "Sex\t" << "Type\t" << "Appointment Date\t" << "Diagnosis" << endl
			 << "--------------------------------------------------------------" << endl;
		for(int i = 0; i < totalPatients; i++){
			if(patients[i]->typeOfPatient == (Patient::Out | Patient::Male) || patients[i]->typeOfPatient == (Patient::Out | Patient::Female)){ // Female/Male Out Patient
				patients[i]->display();
			}
		}
		break;
	}
}

Hospital::~Hospital() {
	delete patients;
}

Hospital::Hospital(char * hospitalName, int capacity, char * fileName) {
	this->HospitalName = hospitalName;
	this->patientCapacity = capacity > 0 ? capacity : 500; // capacity > 0 ? true : false
	this->patients = new Patient*[this->patientCapacity];
	this->fileName = fileName;
	this->totalPatients = 0;
	readRecordsFile(); // Read records file when a new Hospital is created
}