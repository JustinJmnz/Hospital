// Hospital.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Hospital.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	bool stillUsing = true;
	Hospital SaintMary("Saint Mary General Hospital", 600, "SaintMary.csv");
	while(stillUsing){
		char choices[] = "Select Choice:\n1: Add new Patient\n2: Display All InPatients\n3: Display all OutPatients\n4: Quit\nEnter your selection:";
		cout << "Hospital Manager\n-------------\n" << choices  << endl;
		int choice;
		cin>>choice;
		switch(choice){
		case 1:
			int pType; // type of patient
			cout <<  "Enter type of Patient:\n5 = MaleIn\n6 = MaleOut\n9 = FemaleIn\n10 = FemaleOut ";
			cin >> pType; 
			switch(pType){
			case 5:
				SaintMary.admit(pType);
				break;
			case 6:
				SaintMary.admit(pType);
				break;
			case 9:
				SaintMary.admit(pType);
				break;
			case 10:
				SaintMary.admit(pType);
				break;
			default:
				cout << "Incorrect Patient" << endl;
				break;
			}
			break;
		case 2:
			SaintMary.display(1); // 1 for InPatients
			break;
		case 3:
			SaintMary.display(2); // 2 for OutPatients
			break;
		case 4:
			cout << endl <<  "Quiting" << endl;
			stillUsing = false;
			break;
		}
	}
	return 0;
}

