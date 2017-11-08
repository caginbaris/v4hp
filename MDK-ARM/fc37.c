#include "protection_functions.h"
#include "nfbm.h"
#include "powerSysData.h"



struct fc37_inputParameters fc37_obj1_L1_in;
struct fc37_inputParameters fc37_obj2_L1_in;

struct fc37_outputParameters fc37_obj1_L1_out_a={0};
struct fc37_outputParameters fc37_obj1_L1_out_b={0};
struct fc37_outputParameters fc37_obj1_L1_out_c={0};

struct fc37_outputParameters fc37_obj2_L1_out_a={0};
struct fc37_outputParameters fc37_obj2_L1_out_b={0};
struct fc37_outputParameters fc37_obj2_L1_out_c={0};


void fc37_init(){




}



void fc37_all(){
	
	
	float rms_a=0;
	float rms_b=0;
	float rms_c=0;
	
	rms_a=fRMS.Ia;
	rms_b=fRMS.Ib;
	rms_c=fRMS.Ic;

	fc37(rms_a,fc37_obj1_L1_in,&fc37_obj1_L1_out_a,EN.bits.fc37_obj1);
	fc37(rms_b,fc37_obj1_L1_in,&fc37_obj1_L1_out_b,EN.bits.fc37_obj1);
	fc37(rms_c,fc37_obj1_L1_in,&fc37_obj1_L1_out_c,EN.bits.fc37_obj1);
	
	
	rms_a=fRMS.IRESa;
	rms_b=fRMS.IRESb;
	rms_c=fRMS.IRESc;
	
	
	fc37(rms_a,fc37_obj2_L1_in,&fc37_obj2_L1_out_a,EN.bits.fc37_obj2);
	fc37(rms_b,fc37_obj2_L1_in,&fc37_obj2_L1_out_b,EN.bits.fc37_obj2);
	fc37(rms_c,fc37_obj2_L1_in,&fc37_obj2_L1_out_c,EN.bits.fc37_obj2);
		


}


