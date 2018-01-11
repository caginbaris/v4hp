#include "protection_functions.h"
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


void fc37_init(){

	


}


void inhibition(){
	
	static uint8_t picked=0;
	static long picked_off_counter=0;
	
	if(fc37_obj1_L1_in.bs==1 && picked==0){picked=1;}
	
	picked=off_delay(fc37_obj1_L1_in.bs,picked,fs*30,&picked_off_counter);
	
	if(picked==1 && fc37_obj1_L1_in.bs==0){

			DO.bits.inhibit=0;}
	
			else{
			
			DO.bits.inhibit=1;
				
	}
	
}



void fc37_all(){
	
	
	float pick_current=0;
	static long pick_current_counter=0;

	

	pick_current=maxSelector_3p(fRMS.Ia,fRMS.Ib,fRMS.Ic);

	fc37_obj1_L1_in.bs	=	on_off_delay(	pick_current>(Sys.I_Nom_obj1*0.5f),
																			fc37_obj1_L1_in.bs,fs*0.2f, /*cau trip tip should be lower from time*/
																			&pick_current_counter);
												
	fc37_obj2_L1_in.bs=fc37_obj1_L1_in.bs;																		
																			
	

	fc37(fRMS.Ia,fc37_obj1_L1_in,&fc37_obj1_L1_out_a,EN.bits.fc37_obj1);
	fc37(fRMS.Ib,fc37_obj1_L1_in,&fc37_obj1_L1_out_b,EN.bits.fc37_obj1);
	fc37(fRMS.Ic,fc37_obj1_L1_in,&fc37_obj1_L1_out_c,EN.bits.fc37_obj1);
	
	fc37(tRMS.IRESa,fc37_obj2_L1_in,&fc37_obj2_L1_out_a,EN.bits.fc37_obj2);
	fc37(tRMS.IRESb,fc37_obj2_L1_in,&fc37_obj2_L1_out_b,EN.bits.fc37_obj2);
	fc37(tRMS.IRESc,fc37_obj2_L1_in,&fc37_obj2_L1_out_c,EN.bits.fc37_obj2);
	

	inhibition();


}






