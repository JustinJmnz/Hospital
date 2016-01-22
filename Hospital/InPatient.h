/*
 * InPatient.h
 *
 *  Created on: Apr 8, 2015
 *      Author: justin
 */

#ifndef HEADERS_INPATIENT_H_
#define HEADERS_INPATIENT_H_
#include "Patient.h"

class InPatient : public virtual Patient {
public:
	string roomNumber;
};


#endif /* HEADERS_INPATIENT_H_ */
