#include "nfbm.h"
#include "protection_functions.h"
#include "measurement_functions.h"
#include "powerSysData.h"
#include "cs_handles.h"


struct fc46d_inputParameters fc46d_obj1_L1_in;
struct fc46i_inputParameters fc46i_obj1_L1_in;



struct fc46d_outputParameters fc46d_obj1_L1_out;
struct fc46i_outputParameters fc46i_obj1_L1_out;



void fc46_init(){





}


void fc46_all(){


float sym_data=0.0f;
	
	
	if(Sys.phaseRotation){
		
	sym_data=mag_sym.I2;
	
	}else{
		
	sym_data=mag_sym.I1;	
	
	
	}
	
	
	fc46d(sym_data,fc46d_obj1_L1_in,&fc46d_obj1_L1_out,EN.bits.fc46_obj1_L1);
	fc46i(sym_data,fc46i_obj1_L1_in,&fc46i_obj1_L1_out,EN.bits.fc46_obj1_L2);







}