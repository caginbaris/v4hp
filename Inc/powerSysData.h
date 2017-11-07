
#ifndef POWERSYSDATA_H
#define POWERSYSDATA_H

#include <stdint.h>

struct PowerSysData{
	
	

  float I_BreakerClosed_MIN;
	uint32_t currentSupervision:1;	
	uint32_t phaseRotation:1;	
	
	

	


};

extern struct PowerSysData Sys;




#endif


