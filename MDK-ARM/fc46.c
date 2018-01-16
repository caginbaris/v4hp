#include "nfbm.h"
#include "protection_functions.h"
#include "measurement_functions.h"
#include "powerSysData.h"
#include "cs_handles.h"


struct fc46d_inputParameters fc46d_obj1_L1_in;
struct fc46i_inputParameters fc46i_obj1_L1_in;



struct fc46d_outputParameters fc46d_obj1_L1_out={0};
struct fc46i_outputParameters fc46i_obj1_L1_out={0};



void fc46_init(){
	
	
		struct fc46d_inputParameters fc46d_initStruct={ 1.0f,/*level*/
																										0.04,/*delay*/
																										1.1f,/*dropoutRatio*/				
																										0.02 /*dropoutTime*/	};
		
																									
		struct fc46i_inputParameters fc46i_initStruct={ 1.0f,/*level*/
																										{0.0f,0.0f,0.0f},/*curveData*/
																										0.04f/*timeMultiplier*/};
		
		fc46d_obj1_L1_in=fc46d_initStruct;																									
		fc46i_obj1_L1_in=fc46i_initStruct;
																										
		
		
		fc46i_obj1_L1_in.curve_data[0]=curve_data[IEC_normal_inverse][0];
		fc46i_obj1_L1_in.curve_data[1]=curve_data[IEC_normal_inverse][1];
		fc46i_obj1_L1_in.curve_data[2]=curve_data[IEC_normal_inverse][2];																								
																										

}


void fc46_all(){


float sym_data=0.0f;
	
	
	if(Sys.phaseRotation){
		
	sym_data=mag_sym.I1;
	
	}else{
		
	sym_data=mag_sym.I2;	
	
	
	}
	
	
	fc46d(sym_data,fc46d_obj1_L1_in,&fc46d_obj1_L1_out,EN.bits.fc46_obj1_L1);
	fc46i(sym_data,fc46i_obj1_L1_in,&fc46i_obj1_L1_out,EN.bits.fc46_obj1_L2);







}
