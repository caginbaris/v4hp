#ifndef __alarms_h
#define __alarms_h

#include "stdint.h"

union alarm_indications{

	struct{

	uint8_t voltage_phase_seq:1;
	uint8_t current_phase_seq:1;
	uint8_t unbalance:1;
	
	}bit;
	
	uint8_t all;

};

extern struct fcUNBd_inputParameters fcUNBd_obj1_L1_in;

#endif