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



struct digital_inputs{
	
	uint32_t _1:1;
	uint32_t _2:1;
	uint32_t _3:1;
	uint32_t _4:1;
	uint32_t _5:1;
	uint32_t _6:1;
	uint32_t _7:1;
	uint32_t _8:1;
	uint32_t _9:1;
	uint32_t _10:1;
	uint32_t _11:1;
	uint32_t _12:1;
	uint32_t _13:1;
	uint32_t _14:1;
	uint32_t _15:1;
	uint32_t _16:1;
	uint32_t _17:1;
	uint32_t _18:1;
	uint32_t _19:1;
	uint32_t _20:1;
	uint32_t _21:1;
	uint32_t _22:1;
	uint32_t _23:1;
	uint32_t _24:1;
	uint32_t _25:1;
	uint32_t _26:1;
	uint32_t _27:1;
	uint32_t _28:1;
	uint32_t _29:1;
	uint32_t _30:1;
	uint32_t _31:1;
	uint32_t _32:1;
	

};


struct digital_outputs{
	
	
	uint32_t _1:1;
	uint32_t _2:1;
	uint32_t _3:1;
	uint32_t _4:1;
	uint32_t _5:1;
	uint32_t _6:1;
	uint32_t _7:1;
	uint32_t _8:1;
	uint32_t _9:1;
	uint32_t _10:1;
	uint32_t _11:1;
	uint32_t _12:1;
	uint32_t _13:1;
	uint32_t _14:1;
	uint32_t _15:1;
	uint32_t _16:1;
	
	uint32_t FR1:1;
	uint32_t FR2:1;
	uint32_t FR3:1;
	uint32_t FR4:1;
	uint32_t FR5:1;
	uint32_t FR6:1;
	
	
	uint32_t test1:1;
	uint32_t test2:1;
	
	uint32_t LD_trip:1;
	uint32_t LD_run:1;
	uint32_t LD_alarm:1;
	
	
	
	

};	


extern struct digital_inputs  DI;
extern struct digital_outputs DO;
	
union pFunctionEnable{
	
	struct{
		
		uint32_t fc50_obj1_L1:1	;
		uint32_t fc50_obj1_L2:1	;
		uint32_t fc50_obj1_L3:1	;
		
		uint32_t fc50_obj2_L1:1	;
		uint32_t fc50_obj2_L2:1	;
		uint32_t fc50_obj2_L3:1	;
		
		
		uint32_t fc51_obj1:1	;
		uint32_t fc51_obj2:1	;
		
		
		uint32_t fc50N_obj1_L1:1	;
		uint32_t fc50N_obj1_L2:1	;
		uint32_t fc50N_obj1_L3:1	;
		
		uint32_t fc51N_obj1:1	;
		
		uint32_t fc27_obj1_L1:1	;
		uint32_t fc27_obj1_L2:1	;	
		
		uint32_t fc59_obj1_L1:1	;
		uint32_t fc59_obj1_L2:1	;	
		
		uint32_t fc46_obj1_L1:1	;
		uint32_t fc46_obj1_L2:1	;	
		
		
		
		
	}bits;
	
	uint32_t all;
	
	
	
	
	};

	
extern union pFunctionEnable EN;
	
	
union rms_selection{
		
		struct{
		
		uint32_t fc50_obj1_L1:1	;
		uint32_t fc50_obj1_L2:1	;
		uint32_t fc50_obj1_L3:1	;
		
		uint32_t fc50_obj2_L1:1	;
		uint32_t fc50_obj2_L2:1	;
		uint32_t fc50_obj2_L3:1	;
			
		uint32_t fc51_obj1:1	;
		uint32_t fc51_obj2:1	;	

		uint32_t fc50N_obj1_L1:1	;
		uint32_t fc50N_obj1_L2:1	;
		uint32_t fc50N_obj1_L3:1	;

		uint32_t fc51N_obj1:1	;		

		uint32_t fc27_obj1_L1:1	; // no use
		uint32_t fc27_obj1_L2:1	;	// no use
			
		uint32_t fc59_obj1_L1:1	;
		uint32_t fc59_obj1_L2:1	;		
		
		
		uint32_t fc46_obj1_L1:1	; // no use
		uint32_t fc46_obj1_L2:1	;	// no use
			
			
			
			
				
		
			
			
		
	}bits;
	
	uint32_t all;
	
	
	
	
	};

	
extern union rms_selection selectRMS;
	
	
	
	
	
	
	
	
	
struct curve_selection{
		
		
		
		uint32_t fc51_obj1:4	;
		uint32_t fc51_obj2:4	;
		uint32_t fc51N_obj1:4	;

		

	
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





#endif

