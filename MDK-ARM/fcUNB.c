#include "measurement_functions.h"
#include "mlib_constants.h"
#include "plib_definitions.h"
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

uint8_t detect=0;
uint8_t comp=0;
uint8_t dmy_phase=0;

float UNBa_rms=0;
float UNBb_rms=0;


struct phase_cs_in phase_cs_UNBa_comp={0};
struct phase_cs_in phase_cs_UNBb_comp={0};


float cc_buffer[2][50]={0};
float cs_buffer[2][50]={0};


void fcUNB_initial_dt(){
	
	static long time_out_counter=0;
	static uint8_t  passed=0;
	
	if(Sys.UNBdetect==1 && passed==0){
		
		passed=on_delay(1,passed,12500,&time_out_counter);

		fcUNBd_obj1_L1_out_a.Nphase=phase_cs_A_out.phase_I-(-atan2f(UNBa.c,UNBa.s)+pi-UNBpcorrection);
		fcUNBd_obj1_L1_out_b.Nphase=phase_cs_A_out.phase_I-(-atan2f(UNBb.c,UNBb.s)+pi-UNBpcorrection);
		
		fcUNBd_obj1_L1_out_a.Nmag=fRMS.IUNBa*sqrt2;
		fcUNBd_obj1_L1_out_b.Nmag=fRMS.IUNBb*sqrt2; 
		
	}
	
	if(Sys.UNBdetect==1 && passed==1){Sys.UNBdetect=0;passed=0;}
	
}



void fcUNB_init(){
	
		struct fcUNBd_inputParameters fUNBd_initStruct={	0.0f, 						/*level*/
																										  0.0f, 						/*delay*/
																										  0.02f 						/*dropout ratio*/};
		
		struct fcUNBi_inputParameters fUNBi_initStruct={	0.0f, 						/*level*/
																										  0.02f 						/*time Multiplier*/};
		
		
		
		fcUNBd_obj1_L1_in=fUNBd_initStruct;
		fcUNBi_obj1_L1_in=fUNBi_initStruct;																										



}



void fcUNB_all(){
	
	static uint8_t counter=0;
	
	static float UNBa_buffer[50];
	static float UNBb_buffer[50];
	
	float UNBa_synth=0;
	float UNBb_synth=0;
	
	static uint8_t current_checked=0;
	static long current_check_counter=0;

	
	fcUNB_initial_dt();
	
	current_checked=on_off_delay(fRMS.Ia>Sys.I_BreakerClosed_MIN,current_checked,100,&current_check_counter);
	
	if(Sys.UNBcompFlag & current_checked){
	
	//cau cs_handles part is not used
	
	UNBa_synth=(fcUNBd_obj1_L1_out_a.Nmag*sin(phase_cs_A_out.phase_I-fcUNBd_obj1_L1_out_a.Nphase));
	UNBb_synth=(fcUNBd_obj1_L1_out_b.Nmag*sin(phase_cs_A_out.phase_I-fcUNBd_obj1_L1_out_b.Nphase));	
		
	UNBa_rms=true_rms((UNBa.c-UNBa_synth),&UNBa_buffer[0],counter,50);
	UNBb_rms=true_rms((UNBb.c-UNBb_synth),&UNBb_buffer[0],counter,50);
	
	//	UNB cs components	
	#if 0	
	phase_cs_UNBa_comp.Ic=cs_generation((fAdc.sAdc.IUNBa -UNBa_synth),cos_coeffs,50,&cc_buffer[0][0]);
	phase_cs_UNBa_comp.Is=cs_generation((fAdc.sAdc.IUNBa -UNBa_synth),sin_coeffs,50,&cs_buffer[0][0]);
		
	phase_cs_UNBb_comp.Ic=cs_generation((fAdc.sAdc.IUNBb -UNBb_synth),cos_coeffs,50,&cc_buffer[1][0]);
	phase_cs_UNBb_comp.Is=cs_generation((fAdc.sAdc.IUNBb -UNBb_synth),sin_coeffs,50,&cs_buffer[1][0]);

	UNBa_rms=sqrtf(0.5f*(phase_cs_UNBa_comp.Ic*phase_cs_UNBa_comp.Ic+phase_cs_UNBa_comp.Is*phase_cs_UNBa_comp.Is));
	UNBb_rms=sqrtf(0.5f*(phase_cs_UNBb_comp.Ic*phase_cs_UNBb_comp.Ic+phase_cs_UNBb_comp.Is*phase_cs_UNBb_comp.Is));
	#endif
	}else{
		
	
	UNBa_rms=fRMS.IUNBa;
	UNBb_rms=fRMS.IUNBb;
	
	
	}
	
	if(++counter==50){counter=0;}	
	
	
	
	
	fcUNBd(UNBa_rms,fcUNBd_obj1_L1_in,&fcUNBd_obj1_L1_out_a,EN.bits.fcUNBd_obj1);
	fcUNBd(UNBb_rms,fcUNBd_obj1_L1_in,&fcUNBd_obj1_L1_out_b,EN.bits.fcUNBd_obj1);
	
	fcUNBi(UNBa_rms,fcUNBi_obj1_L1_in,&fcUNBi_obj1_L1_out_a,EN.bits.fcUNBi_obj1);
	fcUNBi(UNBb_rms,fcUNBi_obj1_L1_in,&fcUNBi_obj1_L1_out_b,EN.bits.fcUNBi_obj1);
	

}


