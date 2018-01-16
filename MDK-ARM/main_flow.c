


#include "main_flow.h"
#include "boardIO.h"

void main_flow(){

  //measurement
	

	
	//spectral_analysis();
	//cs_handles();
	trueRMS();
  

	// protection
	
	//DO.bits.alarm=1;
	//DO.bits.LD_ALARM =1;
	fc50_all();
//	fc50N_all();
	
	#if 0
	fc51_all();
	fc51N_all();
	

	fc27_all();
	fc59_all();
	
		
	fc46_all();
	
	fc49_all();	
	/*
	
	*/
	
	fcBF_all();
	
	fc37_all();
	
	fcUNB_all();
	
	fcPVP_all();
	
	#endif 
	//pick_trip_reset_handles();
	boardIO();
	
	
	
	
	
	
	
	
	
}