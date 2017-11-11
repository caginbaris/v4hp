#include "measurement_functions.h"
#include "mlib_constants.h"
#include "protection_functions.h"
#include "nfbm.h"
#include "powerSysData.h"
#include "cs_handles.h"
#include <math.h>



struct fcUNBd_inputParameters fcUNBd_obj1_L1_in;
struct fcUNBi_inputParameters fcUNBi_obj1_L1_in;


struct fcUNBd_outputParameters  fcUNBd_obj1_L1_out_a={0};
struct fcUNBd_outputParameters  fcUNBd_obj1_L1_out_b={0};

struct fcUNBi_outputParameters  fcUNBi_obj1_L1_out_a={0};
struct fcUNBi_outputParameters  fcUNBi_obj1_L1_out_b={0};

float UNBpcorrection=0.062831853071796; //half deg @fs


void fcUNB_initial_dt(){
	
	if(Sys.UNBdetect){
		
		
		fcUNBd_obj1_L1_out_a.Nphase=phase_cs_A_out.phase_I-(-atan2f(UNBa.c,UNBa.s)+pi-UNBpcorrection);
		fcUNBd_obj1_L1_out_b.Nphase=phase_cs_A_out.phase_I-(-atan2f(UNBb.c,UNBb.s)+pi-UNBpcorrection);
		
		if(fcUNBd_obj1_L1_out_a.Nphase<0){fcUNBd_obj1_L1_out_a.Nphase=fcUNBd_obj1_L1_out_a.Nphase+2*pi;}
		if(fcUNBd_obj1_L1_out_b.Nphase<0){fcUNBd_obj1_L1_out_b.Nphase=fcUNBd_obj1_L1_out_b.Nphase+2*pi;}

		if(fcUNBd_obj1_L1_out_a.Nphase>pi){fcUNBd_obj1_L1_out_a.Nphase=fcUNBd_obj1_L1_out_a.Nphase-2*pi;}
		if(fcUNBd_obj1_L1_out_b.Nphase>pi){fcUNBd_obj1_L1_out_b.Nphase=fcUNBd_obj1_L1_out_b.Nphase-2*pi;}
		
		
		fcUNBd_obj1_L1_out_a.Nmag=fRMS.IUNBa*sqrt2;
		fcUNBd_obj1_L1_out_b.Nmag=fRMS.IUNBb*sqrt2;
		

	}
}



void fcUNB_init(){
	
		struct fcUNBd_inputParameters fUNBd_initStruct={	0.0f, 					/*level*/
																										  0.0f, 						/*delay*/
																										  0.02f 						/*dropout ratio*/};
		
		struct fcUNBi_inputParameters fUNBi_initStruct={	0.0f, 						/*level*/
																										  0.02f 						/*time Multiplier*/};
		
		
		
		fcUNBd_obj1_L1_in=fUNBd_initStruct;
		fcUNBi_obj1_L1_in=fUNBi_initStruct;																										



}



void fcUNB_all(){
	
	static uint8_t counter=0;
	
	static float UNBa_buffer[25];
	static float UNBb_buffer[25];
	
	float UNBa_synth=0;
	float UNBb_synth=0;
	
	float UNBa_rms=0;
	float UNBb_rms=0;
	
	
	if(Sys.UNBcompFlag){
		
	UNBa_synth=(fcUNBd_obj1_L1_out_a.Nmag*sin(phase_cs_A_out.phase_I+fcUNBd_obj1_L1_out_a.Nphase));
	UNBb_synth=(fcUNBd_obj1_L1_out_b.Nmag*sin(phase_cs_A_out.phase_I+fcUNBd_obj1_L1_out_a.Nphase));	
	
	UNBa_rms=true_rms((fAdc.sAdc.IUNBa-UNBa_synth),&UNBa_buffer[0],counter,25);
	UNBb_rms=true_rms((fAdc.sAdc.IUNBb-UNBb_synth),&UNBb_buffer[0],counter,25);	
		
	if(++counter==25){counter=0;}	
		
	}else{
		
	UNBa_rms=fRMS.IUNBa;
	UNBb_rms=fRMS.IUNBb;
	
	
	}
	
	
	fcUNBd(UNBa_rms,fcUNBd_obj1_L1_in,&fcUNBd_obj1_L1_out_a,EN.bits.fcUNBd_obj1);
	fcUNBd(UNBb_rms,fcUNBd_obj1_L1_in,&fcUNBd_obj1_L1_out_b,EN.bits.fcUNBd_obj1);
	
	fcUNBi(UNBa_rms,fcUNBi_obj1_L1_in,&fcUNBi_obj1_L1_out_a,EN.bits.fcUNBi_obj1);
	fcUNBi(UNBb_rms,fcUNBi_obj1_L1_in,&fcUNBi_obj1_L1_out_b,EN.bits.fcUNBi_obj1);
	


}


