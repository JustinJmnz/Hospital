#include "stdafx.h"
#include "FemaleIn.h"
#include <fstream>
FemaleIn::FemaleIn(string record) {
		parse(record);
}
FemaleIn::FemaleIn(){
	enterPatientData();
	writeToFile();
}
void FemaleIn::parse(string record) {	
		std::string delimiter = ",";
		size_t pos = 0;
		int index = 0;
		while ((pos = record.find(delimiter)) != std::string::npos) {
			switch(index) {
			case 0:
				typeOfPatient = Patient::Female | Patient::In;
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
				roomNumber = record.substr(0, pos);
				break;
			}
			record.erase(0, pos + delimiter.length());
			index++;
		}
}

string FemaleIn::toString() {
	string line;
	line.append("9,").append(name).append(",").append(age).append(",").append(SSN).append(",").append(insuranceName).append(",").append(insuranceNumber).append(",").append(spouseName).append(",").append(diagnosis).append(",").append(roomNumber).append(",");
	return line;
}
void FemaleIn::enterPatientData(){
	this->typeOfPatient = 9;
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
	cout << "Enter Room #: ";
}
void FemaleIn::display() {
	cout<<name<<"\t"<<spouseName<<"\tFemale\tInpatient\t"<<roomNumber<<"\t"<<diagnosis<<endl;
}

void FemaleIn::writeToFile(){
	  ofstream o;
	  o.open("SaintMary.csv", ios::out | ios::app );
	  string a = toString();
	  o << endl << a;
	  o.close();
}