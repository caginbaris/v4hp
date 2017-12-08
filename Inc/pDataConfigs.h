#ifndef __pDataConfigs_h
#define __pDataConfigs_h

#include "stdint.h"

#define eps  0.000001f

union protectionEnableData{

struct{
	
	uint32_t obj1_50_51_N:1;
	uint32_t obj1_27_59:1;
	uint32_t obj1_46:1;
	uint32_t obj1_49:1;
	uint32_t obj1_BF:1;
	uint32_t obj1_UNB:1;
	uint32_t obj1_PVP:1;
	uint32_t obj1_37:1;
	uint32_t obj1_50s:1;
	uint32_t obj1_51s:1;
	uint32_t obj1_50Ns:1;
	uint32_t obj1_51Ns:1;
	uint32_t obj1_27:1;
	uint32_t obj1_59:1;
	
	uint32_t spare1:1;
	uint32_t spare2:1;
	
	uint32_t obj2_50_51_N:1;
	uint32_t obj2_27_59:1;
	uint32_t obj2_46:1;
	uint32_t obj2_49:1;
	uint32_t obj2_BF:1;
	uint32_t obj2_UNB:1;
	uint32_t obj2_PVP:1;
	uint32_t obj2_37:1;
	uint32_t obj2_50s:1;
	uint32_t obj2_51s:1;
	uint32_t obj2_50Ns:1;
	uint32_t obj2_51Ns:1;
	uint32_t obj2_27:1;
	uint32_t obj2_59:1;
	
	uint32_t spare3:1;
	uint32_t spare4:1;
	


}bit;

uint32_t all;



};



//0->true RMS
//---------------DW1
union mSelection{

	struct{
		
		uint32_t obj1_fc50_L1:1; 												//0
		uint32_t obj1_fc50_L2:1; 												//1
		uint32_t obj1_fc50_L3:1; 												//2
		
		uint32_t obj1_fc51:1; 													//3
		
		uint32_t obj1_fc50N_L1:1; 											//4
		uint32_t obj1_fc50N_L2:1; 											//5
		uint32_t obj1_fc50N_L3:1; 											//6
		
		uint32_t obj1_fc51N:1; 													//7
		
		uint32_t spare1:1;															//
		uint32_t spare2:1;															//
		uint32_t spare3:1;															//
		uint32_t spare4:1;															//
		uint32_t spare5:1;															//

		
		uint32_t obj2_fc50_L1:1; 												//Don't Care
		uint32_t obj2_fc50_L2:1; 												//..
		uint32_t obj2_fc50_L3:1; 												//..
		
		uint32_t obj2_fc51:1; 													//..
		
		uint32_t obj2_fc50N_L1:1; 											//..
		uint32_t obj2_fc50N_L2:1; 											//..
		uint32_t obj2_fc50N_L3:1; 											//..
		
	
		
	
		
	
	}bit;
	
	uint32_t all;	


};




extern struct fc50_inputParameters fc50_obj1_L1_in;
extern struct fc50_inputParameters fc50_obj1_L2_in;
extern struct fc50_inputParameters fc50_obj1_L3_in;

extern struct fc50_inputParameters fc50_obj2_L1_in;
extern struct fc50_inputParameters fc50_obj2_L2_in;
extern struct fc50_inputParameters fc50_obj2_L3_in;

extern struct fc50_inputParameters fc50N_obj1_L1_in;
extern struct fc50_inputParameters fc50N_obj1_L2_in;
extern struct fc50_inputParameters fc50N_obj1_L3_in;


extern struct fc51_inputParameters 	fc51_obj1_in;
extern struct fc51_inputParameters 	fc51N_obj1_in;

extern struct fc51_inputParameters 	fc51_obj2_in;
extern struct fc51_inputParameters 	fc51N_obj2_in;


extern struct fc27_inputParameters fc27_obj1_L1_in;
extern struct fc27_inputParameters fc27_obj1_L2_in;

extern struct fc59_inputParameters fc59_obj1_L1_in;
extern struct fc59_inputParameters fc59_obj1_L2_in;

extern struct fc46d_inputParameters fc46d_obj1_L1_in;
extern struct fc46i_inputParameters fc46i_obj1_L1_in;


extern struct thermal_parameters fc49_obj1_therm;
extern struct thermal_parameters fc49_obj2_therm;

extern struct fc49_inputParameters fc49_obj1_L1_in;
extern struct fc49_inputParameters fc49_obj1_L2_in;

extern struct fc49_inputParameters fc49_obj2_L1_in;
extern struct fc49_inputParameters fc49_obj2_L2_in;

extern struct fcBF_inputParameters  fcBF_in;

extern struct fc37_inputParameters fc37_obj1_L1_in;
extern struct fc37_inputParameters fc37_obj2_L1_in;

extern struct fcUNBd_inputParameters fcUNBd_obj1_L1_in;
extern struct fcUNBi_inputParameters fcUNBi_obj1_L1_in;

extern struct fcPVPd_inputParameters fcPVPd_obj1_L1_in;
extern struct fcPVPi_inputParameters fcPVPi_obj1_L1_in;





#endif
