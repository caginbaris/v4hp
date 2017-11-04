#include "nfbm.h"
#include "protection_functions.h"


struct fc51_inputParameters 	fc51N_obj1_in;
struct fc51_outputParameters 	fc51N_obj1_out;

void fc51N_init(){

	curve=selectCURVE.fc51N_obj1;
		
	fc51N_obj1_in.curve_data[0]=curve_data[curve][0];
	fc51N_obj1_in.curve_data[1]=curve_data[curve][1];
	fc51N_obj1_in.curve_data[2]=curve_data[curve][2];	


}

	
	
void fc51N_all(){

	float fc51N_rms=0;

	
	
	// fc51N obj1 Start**************************

	if(selectRMS.bits.fc51_obj1){
		
		fc51N_rms=fRMS.Ia;

	}else{
		
		fc51N_rms=tRMS.Ia;

	}
	
	fc51(fc51N_rms,fc51N_obj1_in,&fc51N_obj1_out,EN.bits.fc51N_obj1);
	
	// fc51N obj1 End**************************
	
	
	
	




}


