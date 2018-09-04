#include "plib_definitions.h"
#include "nfbm.h"
#include "powerSysData.h"
#include "boardIO.h"


struct fc37_inputParameters fc37_obj1_L1_in;
struct fc37_inputParameters fc37_obj2_L1_in;

struct fc37_outputParameters fc37_obj1_L1_out_a={0};
struct fc37_outputParameters fc37_obj1_L1_out_b={0};
struct fc37_outputParameters fc37_obj1_L1_out_c={0};

struct fc37_outputParameters fc37_obj2_L1_out_a={0};
struct fc37_outputParameters fc37_obj2_L1_out_b={0};
struct fc37_outputParameters fc37_obj2_L1_out_c={0};


uint8_t current_checked=0;

/*


*/


void fc37_init(){

			struct fc37_inputParameters fc37_initStruct={	1.0f, /*level*/
																								0.9f, /*DropOutRatio*/
																								0.05f,/*Delay*/};
	
		fc37_obj1_L1_in=fc37_initStruct;
		fc37_obj2_L1_in=fc37_initStruct;
		


}






void fc37_all(){
	
	float pick_current=0;
	uint8_t cb_pos=1;
	uint8_t EN_all=1;
	
	static long pick_current_counter=0;
	static long inhibit_counter=0;
	
	
	static uint8_t inhibit_enabled=0;
	
	

	
 /*************inhibit part-start**********/
	
	pick_current=maxSelector_3p(fRMS.Ia,fRMS.Ib,fRMS.Ic);
	
	if(Sys.CTB4 ){	cb_pos=DI.bit.Q3_cb_pos;}
	if(Sys.CTB5	){	cb_pos=DI.bit.Q1_cb_pos;}
	if(Sys.CTB6	){	cb_pos=DI.bit.Q2_cb_pos;}
 
	current_checked	=	on_delay(	 (pick_current>(Sys.I_Nom_obj1*0.5f)),
															 current_checked,
															 fs*0.026f,
															 &pick_current_counter);
	
	if(current_checked){inhibit_enabled =1;DO.bits.current_checked=1;}else{DO.bits.current_checked=0;}
	if(DO.bits.inhibit){inhibit_enabled =0;}
	
	DO.bits.inhibit=off_delay((inhibit_enabled==1 && current_checked==0),DO.bits.inhibit,fs*30,&inhibit_counter); 
	
	/*************inhibit part-end**********/
		
	EN_all=(cb_pos|current_checked);	

	

	fc37(fRMS.Ia,EN_all,fc37_obj1_L1_in,&fc37_obj1_L1_out_a,EN.bits.fc37_obj1);
	fc37(fRMS.Ib,EN_all,fc37_obj1_L1_in,&fc37_obj1_L1_out_b,EN.bits.fc37_obj1);
	fc37(fRMS.Ic,EN_all,fc37_obj1_L1_in,&fc37_obj1_L1_out_c,EN.bits.fc37_obj1);
	
	fc37(tRMS.IRESa,EN_all,fc37_obj2_L1_in,&fc37_obj2_L1_out_a,EN.bits.fc37_obj2);
	fc37(tRMS.IRESb,EN_all,fc37_obj2_L1_in,&fc37_obj2_L1_out_b,EN.bits.fc37_obj2);
	fc37(tRMS.IRESc,EN_all,fc37_obj2_L1_in,&fc37_obj2_L1_out_c,EN.bits.fc37_obj2);
	

	


}






