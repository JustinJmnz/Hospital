#include "stdafx.h"
#include "FemaleOut.h"
#include <fstream>
FemaleOut::FemaleOut(string record) {
		parse(record);
}
FemaleOut::FemaleOut() {
	enterPatientData();
	writeToFile();
}
void FemaleOut::parse(string record) {	
		std::string delimiter = ",";
		size_t pos = 0;
		int index = 0;
		while ((pos = record.find(delimiter)) != std::string::npos) {
			switch(index) {
			case 0:
				typeOfPatient = Patient::Female | Patient::Out;
				break;
			case 1:
				name = record.substr(0, pos);
				break;
			case 2:
				SSN = record.substr(0, pos);
				break;
			case 3:
				insuranceName = record.substr(0, pos);
				break;
			case 4:
				insuranceNumber = record.substr(0, pos);
				break;
			case 5:
				age = record.substr(0, pos);
				break;
			case 6:
				spouseName = record.substr(0, pos);
				break;
			case 7:
				diagnosis = record.substr(0, pos);
				break;
			case 8:
				appointmentDate = record.substr(0, pos);
				break;
			}
			record.erase(0, pos + delimiter.length());
			index++;
		}
}

string FemaleOut::toString() {
	string line;
	line.append("10,").append(name).append(",").append(age).append(",").append(SSN).append(",").append(insuranceName).append(",").append(insuranceNumber).append(",").append(spouseName).append(",").append(diagnosis).append(",").append(appointmentDate).append(",");
	return line;
}
void FemaleOut::enterPatientData(){
	this->typeOfPatient = 10;
	cout << "Enter name: ";
	cin >> this->name;
	cout << "Enter Age: ";
	cin >> this->age;
	cout << "Enter SSN: ";
	cin >> this->SSN;
	cout << "Enter Insurance Name: ";
	cin >> this->insuranceName;
	cout << "Enter Insurance #: ";
	cin >> this->insuranceNumber;
	cout << "Enter Spouse Name: ";
	cin >> this->spouseName;
	cout << "Enter Diagnosis: ";
	cin >> this->diagnosis;
	cout << "Appointment Date: ";
	cin >> this->appointmentDate;
}
void FemaleOut::display() {
	cout<<name<<"\t"<<spouseName<<"\tFemale\tOutpatient\t"<<appointmentDate<<"\t"<<diagnosis<<endl;
}

void FemaleOut::writeToFile(){
	  ofstream o;
	  o.open("SaintMary.csv", ios::out | ios::app );
	  string a = toString();
	  o << endl << a;
	  o.close();
}