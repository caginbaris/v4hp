


#include "main_flow.h"


void main_flow(){

  //measurement
	
		
	
	spectral_analysis();
	cs_handles();
	trueRMS();


	// protection
	
	
	fc50_all();
	fc50N_all();
	
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
	
	
	pick_trip_reset_handles();
	boardIO();
	
	
	
	
	
	
	
	
	
}