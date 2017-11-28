
#include "main.h"

#define inputNo 24
#define sammpleNo 10

union digitalInputsRaw{


struct{
	
	/*--------MRB naming----Board Naming*/
	
	uint8_t start_stop; 	//DI-1
	uint8_t Q1_cb_pos;  	//DI-2
	uint8_t Q2_cb_pos;  	//DI-3
	uint8_t Q3_cb_pos;  	//DI-4
	
	uint8_t SVC_trip; 		// DI10
	
	uint8_t Q1_open; 			//DI-12
	uint8_t Q2_open; 			//DI-14
	uint8_t Q3_open; 			//DI-16
	
	uint8_t Q1_trip; 			//DI-13
	uint8_t Q2_trip; 			//DI-15
	uint8_t Q3_trip; 			//DI-17
	
	uint8_t _51; 					//DI-18
	uint8_t _53; 					//DI-20
	uint8_t _52; 					//DI-19
	uint8_t _54; 					//DI-21
	uint8_t _56; 					//DI-23
	
	uint8_t cold_test; 		//DI-22
	uint8_t tfr_trig; 	  //DI-24
	
	uint8_t plb_sp1; 			//DI-26
	uint8_t plb_sp2; 			//DI-25
	uint8_t plb_sp3; 			//DI-28
	uint8_t plb_sp4; 			//DI-27
	uint8_t plb_sp6; 			//DI-29
	
	uint8_t reset; 				//reset.... 24th

	
	
	
}bit;



uint32_t all[inputNo]; 





};




union digitalInputs{


struct{
	
	/*--------MRB naming----Board Naming*/
	
	uint32_t start_stop:1; 	//DI-1
	uint32_t Q1_cb_pos:1;  	//DI-2
	uint32_t Q2_cb_pos:1;  	//DI-3
	uint32_t Q3_cb_pos:1;  	//DI-4
	
	uint32_t SVC_trip:1; 		// DI10
	
	uint32_t Q1_open:1; 		//DI-12
	uint32_t Q2_open:1; 		//DI-14
	uint32_t Q3_open:1; 		//DI-16
	
	uint32_t Q1_trip:1; 		//DI-13
	uint32_t Q2_trip:1; 		//DI-15
	uint32_t Q3_trip:1; 		//DI-17
	
	uint32_t _51:1; 				//DI-18
	uint32_t _53:1; 				//DI-20
	uint32_t _52:1; 				//DI-19
	uint32_t _54:1; 				//DI-21
	uint32_t _56:1; 				//DI-23
	
	uint32_t cold_test:1; 	//DI-22
	uint32_t tfr_trig:1; 	  //DI-24
	
	uint32_t plb_sp1:1; 		//DI-26
	uint32_t plb_sp2:1; 		//DI-25
	uint32_t plb_sp3:1; 		//DI-28
	uint32_t plb_sp4:1; 		//DI-27
	uint32_t plb_sp6:1; 		//DI-29
	
	uint32_t reset:1; 			//reset.... 24th

	
	
	
}bit;



uint32_t all; 


}; 












union digitalOutputs{


struct{
	
	/*--------MRB naming----Board Naming*/
	
	uint8_t trip:1; 		//DO-1
	uint8_t alarm:1;  	//DO-2
	uint8_t inhibit:1;  //DO-3
	uint8_t BF:1;  			//DO-4
	uint8_t IBF:1;			//DO-5
	uint8_t spare:1;		//DO-6	
	
	
}bits;



uint8_t all; 





};