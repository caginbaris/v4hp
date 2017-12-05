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
	


	fc37(fRMS.Ia,fc37_obj1_L1_in,&fc37_obj1_L1_out_a,EN.bits.fc37_obj1);
	fc37(fRMS.Ib,fc37_obj1_L1_in,&fc37_obj1_L1_out_b,EN.bits.fc37_obj1);
	fc37(fRMS.Ic,fc37_obj1_L1_in,&fc37_obj1_L1_out_c,EN.bits.fc37_obj1);
	
	fc37(tRMS.IRESa,fc37_obj2_L1_in,&fc37_obj2_L1_out_a,EN.bits.fc37_obj2);
	fc37(tRMS.IRESb,fc37_obj2_L1_in,&fc37_obj2_L1_out_b,EN.bits.fc37_obj2);
	fc37(tRMS.IRESc,fc37_obj2_L1_in,&fc37_obj2_L1_out_c,EN.bits.fc37_obj2);
		


}


