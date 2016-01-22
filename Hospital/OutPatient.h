/*
 * OutPatient.h
 *
 *  Created on: Apr 8, 2015
 *      Author: justin
 */

#ifndef HEADERS_OUTPATIENT_H_
#define HEADERS_OUTPATIENT_H_
#include "Patient.h"
class OutPatient : public virtual Patient{
public:
	string appointmentDate;
};



#endif /* HEADERS_OUTPATIENT_H_ */
