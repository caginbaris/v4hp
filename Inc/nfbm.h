#ifndef __nfbm_h
#define __nfbm_h

#include "stdint.h"


#define channelNo 12


struct AdcData{
	
	float Van; 	//AN-1
	float Ia;		//AN-2
	float IUNBa;//AN-11
	
	float Vbn;	//AN-3
	float Ib;		//AN-4
	float IUNBb;//AN-12
	
	float Vcn;	//AN-5
	float Ic;		//AN-6
	
	float IRESa;//AN-8
	float In;		//AN-7
	
	float IRESb;//AN-9
	float IRESc;//AN-10
	
	float AB_synth;
	float BC_synth;
	float CA_synth;


}; 


extern struct AdcData tRMS;
extern struct AdcData fRMS;


union uAdc
{
  struct AdcData sAdc;
	float bufferAdc[12];
		
};

extern union uAdc rawAdc;
extern union uAdc fAdc;


enum AdcChannel{

	Van=0,
	Ia=1,
	IUNBa=2,
	
	Vbn=3,
	Ib=4,
	IUNBb=5,
	
	Vcn=6,
	Ic=7,
	
	IRESa=9,
	In=10,
	
	IRESb=12,
	IRESc=13

};




	
	




	
union pFunctionEnable{
	
	struct{
		
		uint32_t fc50_obj1_L1	;
		uint32_t fc50_obj1_L2	;
		uint32_t fc50_obj1_L3	;
		
		uint32_t fc50_obj2_L1	;
		uint32_t fc50_obj2_L2	;
		uint32_t fc50_obj2_L3;
		
		
		uint32_t fc51_obj1	;
		uint32_t fc51_obj2	;
		
		
		uint32_t fc50N_obj1_L1	;
		uint32_t fc50N_obj1_L2	;
		uint32_t fc50N_obj1_L3	;
		
		uint32_t fc51N_obj1	;
		
		uint32_t fc27_obj1_L1;
		uint32_t fc27_obj1_L2	;	
		
		uint32_t fc59_obj1_L1	;
		uint32_t fc59_obj1_L2	;	
		
		uint32_t fc46_obj1_L1	;
		uint32_t fc46_obj1_L2	;	
		
		uint32_t fc49_obj1_L1	; 
		uint32_t fc49_obj1_L2;	
		
		uint32_t fc49_obj2_L1	; 
		uint32_t fc49_obj2_L2	;	
		
		uint32_t fcBF_obj1	;	
		
		uint32_t fc37_obj1	;
		uint32_t fc37_obj2	;

		uint32_t fcUNBd_obj1	;
		uint32_t fcUNBi_obj1	;	
		
		
		uint32_t fcPVPd_obj1	;
		uint32_t fcPVPi_obj1	;	
		
	}bits;
	
	uint32_t all;
	
	
	
	
	};

	
extern union pFunctionEnable EN;
	
	
union rms_selection{
		
		struct{
		
		uint32_t fc50_obj1_L1	;
		uint32_t fc50_obj1_L2	;
		uint32_t fc50_obj1_L3	;
		
		uint32_t fc50_obj2_L1	;
		uint32_t fc50_obj2_L2	;
		uint32_t fc50_obj2_L3	;
			
		uint32_t fc51_obj1:1	;
		uint32_t fc51_obj2:1	;	

		uint32_t fc50N_obj1_L1:1	;
		uint32_t fc50N_obj1_L2:1	;
		uint32_t fc50N_obj1_L3:1	;

		uint32_t fc51N_obj1:1	;		

		uint32_t fc27_obj1_L1	; // no use
		uint32_t fc27_obj1_L2	;	// no use
			
		uint32_t fc59_obj1_L1	;
		uint32_t fc59_obj1_L2;		
		
		uint32_t fc46_obj1_L1	; // no use
		uint32_t fc46_obj1_L2	;	// no use
		
		uint32_t fc49_obj1_L1	; // no use
		uint32_t fc49_obj1_L2	;	// no use
		
		uint32_t fcBF_obj1	;		// no use
		
		uint32_t fc37_obj1	; 	// no use
		uint32_t fc37_obj2	;		// no use	
		
		
		uint32_t fcUNBd_obj1	; //no use
		uint32_t fcUNBi_obj1	;	//no use
		
		uint32_t fcPVPd_obj1	; //no use
		uint32_t fcPVPi_obj1	;	//no use
			
			
			
			
				
		
			
			
		
	}bits;
	
	uint32_t all;
	
	
	
	
	};

	
extern union rms_selection selectRMS;
	
	
	
	
	
	
	
	
	
struct curve_selection{
		
		
		
		uint32_t fc51_obj1	;
		uint32_t fc51_obj2	;
		uint32_t fc51N_obj1	;
		uint32_t fc46i_obj1	;
		uint32_t fcUNBi_obj1	;
		uint32_t fcPVPi_obj1	;
		

		

	
	};

	
extern struct curve_selection selectCURVE;
	
	
	
	
	
	
	

enum curve_entry{
	
	IEC_inverse,
	IEC_very_inverse,
	IEC_extremely_inverse,
	IEC_long_inverse,
	
	ANSI_inverse,
	ANSI_short_inverse,
	ANSI_long_inverse,
	ANSI_moderately_inverse,
	ANSI_very_inverse,
	ANSI_extremely_inverse,
	ANSI_definite_inverse
	
	
};


extern enum curve_entry curve;
extern float curve_data[11][3];




struct powerParameters{

	float a;
	float b;
	float c;
	
	float ab;
	float bc;
	float ca;
	
	float total;
	

};

extern struct powerParameters P;
extern struct powerParameters Q;




#endif

