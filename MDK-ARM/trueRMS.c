#include "measurement_functions.h"
#include "nfbm.h"

#define rmsChannelNo 15
#define bufferLength 50

struct AdcData tRMS={0};
union uAdc  backRMS={0};
float bufferRMS[channelNo][bufferLength]={0};


void trueRMS(void){

	static uint8_t counter=0; 
	uint8_t i;
	
	for(i=0;i<rmsChannelNo;i++){
	
		backRMS.bufferAdc[i]=true_rms(fAdc.bufferAdc[i],&bufferRMS[i][0],counter,bufferLength);
	
	}
	
	if(++counter==bufferLength){counter=0;}
	
	tRMS=backRMS.sAdc;
		
	
}



