#include "measurement_functions.h"
#include "protection_functions.h"
#include "nfbm.h"
#include "powerSysData.h"
#include "cs_handles.h"

#define ts 1/fs
#define N 50

struct pvp_data pvp_in={0};
struct pvp_data pvp_in_back={0};
struct pvp_data pvp_out={0};
struct pvp_data pvp_out_back={0};


struct fcPVPd_inputParameters fcPVPd_obj1_L1_in;
struct fcPVPi_inputParameters fcPVPi_obj1_L1_in;


struct fcPVPd_outputParameters fcPVPd_obj1_L1_out_a={0};
struct fcPVPd_outputParameters fcPVPd_obj1_L1_out_b={0};
struct fcPVPd_outputParameters fcPVPd_obj1_L1_out_c={0};

struct fcPVPi_outputParameters fcPVPi_obj1_L1_out_a={0};
struct fcPVPi_outputParameters fcPVPi_obj1_L1_out_b={0};
struct fcPVPi_outputParameters fcPVPi_obj1_L1_out_c={0};



void fcPVP_init(){
	
 struct fcPVPd_inputParameters fcPVPd_initStruct={	1.0f, /*level*/
																										0.05f,/*Delay*/		
																										0.9f, /*DropOutRatio*/
																								
																								};
	
	
 struct fcPVPi_inputParameters fcPVPi_initStruct={	1.0f, 							/*level*/
																										{0.0f,0.0f,0.0f}, 	/*Curve*/
																										0.02f 							/*TimeMultiplier*/};
		
	fcPVPd_obj1_L1_in=fcPVPd_initStruct;																									
	fcPVPi_obj1_L1_in=fcPVPi_initStruct;
																										
																								
	curve=selectCURVE.fcPVPi_obj1;
		
	fcPVPi_obj1_L1_in.curve_data[0]=curve_data[curve][0];
	fcPVPi_obj1_L1_in.curve_data[1]=curve_data[curve][1];
	fcPVPi_obj1_L1_in.curve_data[2]=curve_data[curve][2];



}



void fcPVP_all(){
	
	static float counter=0;
	static float peakBuffer[3][N];
	
	float peak_a;
	float peak_b;
	float peak_c;
	
	pvp_in.a=fAdc.sAdc.Ia;
	pvp_in.b=fAdc.sAdc.Ib;
	pvp_in.c=fAdc.sAdc.Ic;
	
	pvp_filter(pvp_in,&pvp_in_back,&pvp_out,&pvp_out_back,ts);
	
	peak_a=peak_detect_rms(pvp_out.a,&peakBuffer[0][0],counter,N);
	peak_b=peak_detect_rms(pvp_out.b,&peakBuffer[1][0],counter,N);
	peak_c=peak_detect_rms(pvp_out.c,&peakBuffer[2][0],counter++,N);
	
	
	fcPVPd(peak_a,fcPVPd_obj1_L1_in,&fcPVPd_obj1_L1_out_a,EN.bits.fcPVPd_obj1);
	fcPVPd(peak_b,fcPVPd_obj1_L1_in,&fcPVPd_obj1_L1_out_b,EN.bits.fcPVPd_obj1);
	fcPVPd(peak_c,fcPVPd_obj1_L1_in,&fcPVPd_obj1_L1_out_c,EN.bits.fcPVPd_obj1);
	
	fcPVPi(peak_a,fcPVPi_obj1_L1_in,&fcPVPi_obj1_L1_out_a,EN.bits.fcPVPi_obj1);
	fcPVPi(peak_b,fcPVPi_obj1_L1_in,&fcPVPi_obj1_L1_out_b,EN.bits.fcPVPi_obj1);
	fcPVPi(peak_c,fcPVPi_obj1_L1_in,&fcPVPi_obj1_L1_out_c,EN.bits.fcPVPi_obj1);
	
	
	if(counter==N){counter=0;}
	
	

}