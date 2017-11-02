#ifndef __nfbm_h
#define __nfbm_h

#include "stdint.h"

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
	
	



#endif

