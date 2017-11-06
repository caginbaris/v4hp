
#ifndef POWERSYSDATA_H
#define POWERSYSDATA_H

#include <stdint.h>

struct PowerSysData{

  float I_BreakerClosed_MIN;
	uint32_t current_supervision:1;	

	


};

extern struct PowerSysData Sys;




#endif


