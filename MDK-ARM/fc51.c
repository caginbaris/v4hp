#include "nfbm.h"
#include "protection_functions.h"




struct fc51_inputParameters fc51_obj1_in;
struct fc51_inputParameters fc51_obj2_in;


struct fc51_outputParameters fc51_obj1_out_a;
struct fc51_outputParameters fc51_obj1_out_b;
struct fc51_outputParameters fc51_obj1_out_c;


struct fc51_outputParameters fc51_obj2_out_a;
struct fc51_outputParameters fc51_obj2_out_b;
struct fc51_outputParameters fc51_obj2_out_c;







void fc51_init(){
	
	
	curve=selectCURVE.fc51_obj1;
		
	fc51_obj1_in.curve_data[0]=curve_data[curve][0];
	fc51_obj1_in.curve_data[1]=curve_data[curve][1];
	fc51_obj1_in.curve_data[2]=curve_data[curve][2];	


}



void fc51_all(){
	
	float fc51_rms_a=0;
	float fc51_rms_b=0;
	float fc51_rms_c=0;
	
	
	// fc51 obj1 Start**************************

	if(selectRMS.bits.fc51_obj1){
		
		fc51_rms_a=fRMS.Ia;
		fc51_rms_b=fRMS.Ib;
		fc51_rms_c=fRMS.Ic;
		
	}else{
		
		fc51_rms_a=tRMS.Ia;
		fc51_rms_b=tRMS.Ib;
		fc51_rms_c=tRMS.Ic;
		
	}
	
	
	
	fc51(fc51_rms_a,fc51_obj1_in,&fc51_obj1_out_a,EN.bits.fc51_obj1);
	fc51(fc51_rms_b,fc51_obj1_in,&fc51_obj1_out_b,EN.bits.fc51_obj1);
	fc51(fc51_rms_c,fc51_obj1_in,&fc51_obj1_out_c,EN.bits.fc51_obj1);
	
	
	// fc51 obj1 End**************************
	
	
	// fc51 obj2 Start************************
	
	if(selectRMS.bits.fc51_obj2){
		
		fc51_rms_a=fRMS.IRESa;
		fc51_rms_b=fRMS.IRESb;
		fc51_rms_c=fRMS.IRESc;
		
	}else{
		
		fc51_rms_a=tRMS.IRESa;
		fc51_rms_b=tRMS.IRESb;
		fc51_rms_c=tRMS.IRESc;
		
	}
	
	
	
	fc51(fc51_rms_a,fc51_obj1_in,&fc51_obj1_out_a,EN.bits.fc51_obj1);
	fc51(fc51_rms_b,fc51_obj1_in,&fc51_obj1_out_a,EN.bits.fc51_obj1);
	fc51(fc51_rms_c,fc51_obj1_in,&fc51_obj1_out_a,EN.bits.fc51_obj1);	
	
	
	// fc51 obj2 End**************************
	



}


