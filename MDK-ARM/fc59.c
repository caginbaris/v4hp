#include "protection_functions.h"
#include "nfbm.h"



struct fc59_inputParameters fc59_obj1_L1_in;
struct fc59_inputParameters fc59_obj1_L2_in;


struct fc59_outputParameters fc59_obj1_L1_out_a={0};
struct fc59_outputParameters fc59_obj1_L1_out_b={0};
struct fc59_outputParameters fc59_obj1_L1_out_c={0};

struct fc59_outputParameters fc59_obj1_L2_out_a={0};
struct fc59_outputParameters fc59_obj1_L2_out_b={0};
struct fc59_outputParameters fc59_obj1_L2_out_c={0};



void fc59_init(){

	struct fc59_inputParameters fc59_initStruct={	1.0f, /*level*/
																								0.9f, /*DropOutRatio*/
																								0.05f,/*Delay*/
																								};
	
	fc59_obj1_L1_in=fc59_initStruct;
	fc59_obj1_L1_in=fc59_initStruct;																								
																								

}



void fc59_all(){
	
	
	float fc59_rms_a=0;
	float fc59_rms_b=0;
	float fc59_rms_c=0;
	
	
		if(selectRMS.bits.fc59_obj1_L1){
		
		fc59_rms_a=fRMS.Van;
		fc59_rms_b=fRMS.Vbn;
		fc59_rms_c=fRMS.Vcn;
		
	}else{
		
		fc59_rms_a=tRMS.Ia;
		fc59_rms_b=tRMS.Ib;
		fc59_rms_c=tRMS.Ic;
		
	}
	
	
	fc59(fc59_rms_a,fc59_obj1_L1_in,&fc59_obj1_L1_out_a,EN.bits.fc59_obj1_L1);
	fc59(fc59_rms_b,fc59_obj1_L1_in,&fc59_obj1_L1_out_b,EN.bits.fc59_obj1_L1);
	fc59(fc59_rms_c,fc59_obj1_L1_in,&fc59_obj1_L1_out_c,EN.bits.fc59_obj1_L1);
	
	fc59(fc59_rms_a,fc59_obj1_L2_in,&fc59_obj1_L2_out_a,EN.bits.fc59_obj1_L2);
	fc59(fc59_rms_b,fc59_obj1_L2_in,&fc59_obj1_L2_out_b,EN.bits.fc59_obj1_L2);
	fc59(fc59_rms_c,fc59_obj1_L2_in,&fc59_obj1_L2_out_c,EN.bits.fc59_obj1_L2);
	
	
	






}

