#include "nfbm.h"
#include "protection_functions.h"





struct fc27_inputParameters fc27_obj1_L1_in;
struct fc27_inputParameters fc27_obj1_L2_in;


struct fc27_outputParameters fc27_obj1_L1_out_a;
struct fc27_outputParameters fc27_obj1_L1_out_b;
struct fc27_outputParameters fc27_obj1_L1_out_c;

struct fc27_outputParameters fc27_obj1_L2_out_a;
struct fc27_outputParameters fc27_obj1_L2_out_b;
struct fc27_outputParameters fc27_obj1_L2_out_c;


void fc27_init(){





}


void fc27_all(){

	float fc27_rms_a=0;
	float fc27_rms_b=0;
	float fc27_rms_c=0;
	
	
	// which voltage entry
	
		/* 
	
	if(selectRMS.bits.fc27_obj1_L1){
		
			fc27_rms_a=fRMS.Van;
			fc27_rms_b=fRMS.Vbn;
			fc27_rms_c=fRMS.Vcn;			

		}else{
		
			fc27_rms_a=tRMS.Van;
			fc27_rms_b=tRMS.Vbn;
			fc27_rms_c=tRMS.Vcn;
			
		} */
		
		
		
		fc27(fc27_rms_a,fc27_obj1_L1_in,&fc27_obj1_L1_out_a,EN.bits.fc27_obj1_L1);
		fc27(fc27_rms_b,fc27_obj1_L1_in,&fc27_obj1_L1_out_b,EN.bits.fc27_obj1_L1);
		fc27(fc27_rms_c,fc27_obj1_L1_in,&fc27_obj1_L1_out_c,EN.bits.fc27_obj1_L1);
		
		
		
	// which voltage entry
	
		/* 
	
	if(selectRMS.bits.fc27_obj1_L1){
		
			fc27_rms_a=fRMS.Van;
			fc27_rms_b=fRMS.Vbn;
			fc27_rms_c=fRMS.Vcn;			

		}else{
		
			fc27_rms_a=tRMS.Van;
			fc27_rms_b=tRMS.Vbn;
			fc27_rms_c=tRMS.Vcn;
			
		} */
		
		
		fc27(fc27_rms_a,fc27_obj1_L2_in,&fc27_obj1_L2_out_a,EN.bits.fc27_obj1_L2);
		fc27(fc27_rms_b,fc27_obj1_L2_in,&fc27_obj1_L2_out_b,EN.bits.fc27_obj1_L2);
		fc27(fc27_rms_c,fc27_obj1_L2_in,&fc27_obj1_L2_out_c,EN.bits.fc27_obj1_L2);
		
		
		

		
		





}




