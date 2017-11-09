#include "measurement_functions.h"
#include "protection_functions.h"
#include "nfbm.h"
#include "powerSysData.h"
#include "cs_handles.h"



struct fcUNBd_inputParameters fcUNBd_obj1_L1_in;
struct fcUNBi_inputParameters fcUNBi_obj1_L1_in;


struct fcUNBd_outputParameters  fcUNBd_obj1_L1_out_a={0};
struct fcUNBd_outputParameters  fcUNBd_obj1_L1_out_b={0};

struct fcUNBi_outputParameters  fcUNBi_obj1_L1_out_a={0};
struct fcUNBi_outputParameters  fcUNBi_obj1_L1_out_b={0};


void fcUNB_initial_dt(){
	
	static float phase_diff;
	
	//should be entered and calc. for  UNB phase
  //phase_diff=(phase_cs_A_out.phase_I-)
	
	 /* Matlab if(p12(i)<0)
        
        p12(i)=p12(i)+2*pi;
        
    end
    
    if(p12(i)>=pi)
        
        p12(i)=p12(i)-2*pi;
        
    end */

}



void fcUNB_init(){



}



void fcUNB_all(){
	

	
	fcUNBd(fRMS.IUNBa,fcUNBd_obj1_L1_in,&fcUNBd_obj1_L1_out_a,EN.bits.fcUNBd_obj1);
	fcUNBd(fRMS.IUNBb,fcUNBd_obj1_L1_in,&fcUNBd_obj1_L1_out_b,EN.bits.fcUNBd_obj1);
	
	
	fcUNBi(fRMS.IUNBa,fcUNBi_obj1_L1_in,&fcUNBi_obj1_L1_out_a,EN.bits.fcUNBi_obj1);
	fcUNBi(fRMS.IUNBb,fcUNBi_obj1_L1_in,&fcUNBi_obj1_L1_out_b,EN.bits.fcUNBi_obj1);
	


}


