#include "nfbm.h"
#include "protection_functions.h"


struct fc50_inputParameters fc50N_obj1_L1_in;
struct fc50_inputParameters fc50N_obj1_L2_in;
struct fc50_inputParameters fc50N_obj1_L3_in;


struct fc50_outputParameters fc50N_obj1_L1_out;
struct fc50_outputParameters fc50N_obj1_L2_out;
struct fc50_outputParameters fc50N_obj1_L3_out;


void fc50N_init(){





}


void fc50N_all(){
	
	
	float fc50N_rms=0;

	
	// fc50N L1
	
		if(selectRMS.bits.fc50N_obj1_L1){
		
		fc50N_rms=fRMS.In;

		}else{
		
		fc50N_rms=tRMS.In;
			
		}
		
		
		fc50(fc50N_rms,fc50N_obj1_L1_in,&fc50N_obj1_L1_out,EN.bits.fc50N_obj1_L1);
		fc50(fc50N_rms,fc50N_obj1_L2_in,&fc50N_obj1_L2_out,EN.bits.fc50N_obj1_L2);
		fc50(fc50N_rms,fc50N_obj1_L3_in,&fc50N_obj1_L3_out,EN.bits.fc50N_obj1_L3);



}