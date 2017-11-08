#include "protection_functions.h"
#include "nfbm.h"
#include "powerSysData.h"


struct fcUNBd_inputParameters fcUNBd_obj1_L1_in;
struct fcUNBi_inputParameters fcUNBi_obj1_L1_in;


struct fcUNBd_outputParameters  fcUNBd_obj1_L1_out_a={0};
struct fcUNBd_outputParameters  fcUNBd_obj1_L1_out_b={0};

struct fcUNBi_outputParameters  fcUNBi_obj1_L1_out_a={0};
struct fcUNBi_outputParameters  fcUNBi_obj1_L1_out_b={0};


void fcUNB_initial_dt(){



}



void fcUNB_init(){



}



void fcUNB_all(){
	

	
	fcUNBd(fRMS.IUNBa,fcUNBd_obj1_L1_in,&fcUNBd_obj1_L1_out_a,EN.bits.fcUNBd_obj1);
	fcUNBd(fRMS.IUNBb,fcUNBd_obj1_L1_in,&fcUNBd_obj1_L1_out_b,EN.bits.fcUNBd_obj1);
	
	
	fcUNBi(fRMS.IUNBa,fcUNBi_obj1_L1_in,&fcUNBi_obj1_L1_out_a,EN.bits.fcUNBi_obj1);
	fcUNBi(fRMS.IUNBb,fcUNBi_obj1_L1_in,&fcUNBi_obj1_L1_out_b,EN.bits.fcUNBi_obj1);
	


}


