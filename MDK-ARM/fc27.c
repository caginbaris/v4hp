#include "nfbm.h"
#include "protection_functions.h"
#include "measurement_functions.h"
#include "powerSysData.h"
#include "cs_handles.h"



#define cs_qual_time 0.02f

struct fc27_inputParameters fc27_obj1_L1_in;
struct fc27_inputParameters fc27_obj1_L2_in;


struct fc27_outputParameters fc27_obj1_L1_out;
struct fc27_outputParameters fc27_obj1_L2_out;



void fc27_init(){





}


void fc27_all(){
	
	static uint8_t  cs_qual=0;
	static long 		cs_counter=0;
	
	float rms;
	

	
	if(Sys.currentSupervision){
	
	cs_qual=on_off_delay(
		
			(fRMS.Ia<Sys.I_BreakerClosed_MIN &&
			 fRMS.Ib<Sys.I_BreakerClosed_MIN  &&
			 fRMS.Ic<Sys.I_BreakerClosed_MIN),
			 cs_qual,
			 fs*cs_qual_time,
			 &cs_counter);
		
	}
	
	
	if(cs_qual){
	
	fc27_obj1_L1_in.cs=1;
	fc27_obj1_L2_in.cs=1;		
	
	}else{
		
	fc27_obj1_L1_in.cs=0;
	fc27_obj1_L2_in.cs=0;			
	
	}
	
	
	if(Sys.phaseRotation){
	
	rms=mag_sym.V1;
	
	}else{
	
	rms=mag_sym.V2;
	
	}
	
	
		//L1
		fc27(rms,fc27_obj1_L1_in,&fc27_obj1_L1_out,EN.bits.fc27_obj1_L1);
		//L2
		fc27(rms,fc27_obj1_L2_in,&fc27_obj1_L2_out,EN.bits.fc27_obj1_L2);

		
}




