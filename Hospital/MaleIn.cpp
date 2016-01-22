#include "stdafx.h"
#include "MaleIn.h"
#include <fstream>
MaleIn::MaleIn(string record) {
		parse(record);
}
MaleIn::MaleIn(){
	enterPatientData();
	writeToFile();
}

void MaleIn::parse(string record) {	
		std::string delimiter = ",";
		size_t pos = 0;
		int index = 0;
		while ((pos = record.find(delimiter)) != std::string::npos) {
			switch(index) {
			case 0:
				typeOfPatient = Patient::Male | Patient::In;
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

string MaleIn::toString() {
	string line;
	line.append("5,").append(name).append(",").append(age).append(",").append(SSN).append(",").append(insuranceName).append(",").append(insuranceNumber).append(",").append(spouseName).append(",").append(diagnosis).append(",").append(roomNumber).append(",");
	return line;
}
void MaleIn::enterPatientData(){
	this->typeOfPatient = 5;
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
	cin >> this->roomNumber;
}
void MaleIn::display() {
	cout<<name<<"\t"<<spouseName<<"\t\tMale\tInpatient\t"<<roomNumber<<"\t"<<diagnosis<<endl;
}
void MaleIn::writeToFile(){
	  ofstream o;
	  o.open("SaintMary.csv", ios::out | ios::app );
	  string a = toString();
	  o << endl << a;
	  o.close();
}