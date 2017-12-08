
#ifndef POWERSYSDATA_H
#define POWERSYSDATA_H

#include <stdint.h>

struct PowerSysData{
	
	
	float I_Nom_obj1;          
	float I_Nom_obj2;		 
  float I_BreakerClosed_MIN;            //fc27,fcBF
	float Xvalue;
	float Rvalue;
	
	uint32_t currentSupervision:1;				//fc27
	uint32_t CBSupervision:1;							//fcBF
	uint32_t phaseRotation:1;	
	
	uint32_t UNBdetect:1;
	uint32_t UNBcompFlag:1;
	
	

	


};

extern struct PowerSysData Sys;




#endif


