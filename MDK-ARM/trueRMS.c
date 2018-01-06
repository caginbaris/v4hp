#include "measurement_functions.h"
#include "nfbm.h"

#define rmsChannelNo 15
#define bufferLength 50

struct AdcData tRMS={0};
union uAdc  backRMS={0};
float bufferRMS[rmsChannelNo][bufferLength]={0};


void trueRMS(void){

	static uint8_t counter=0; 
	

	
	backRMS.bufferAdc[Vab]=true_rms(fAdc.bufferAdc[Vab],&bufferRMS[Vab][0],counter,bufferLength);
	backRMS.bufferAdc[Vbc]=true_rms(fAdc.bufferAdc[Vbc],&bufferRMS[Vbc][0],counter,bufferLength);
	backRMS.bufferAdc[Vca]=true_rms(fAdc.bufferAdc[Vca],&bufferRMS[Vca][0],counter,bufferLength);
	
	backRMS.bufferAdc[Ia]=true_rms(fAdc.bufferAdc[Ia],&bufferRMS[Ia][0],counter,bufferLength);
	backRMS.bufferAdc[Ib]=true_rms(fAdc.bufferAdc[Ib],&bufferRMS[Ib][0],counter,bufferLength);
	backRMS.bufferAdc[Ic]=true_rms(fAdc.bufferAdc[Ic],&bufferRMS[Ic][0],counter,bufferLength);
	backRMS.bufferAdc[In]=true_rms(fAdc.bufferAdc[In],&bufferRMS[In][0],counter,bufferLength);
	
	backRMS.bufferAdc[IRESa]=true_rms(fAdc.bufferAdc[IRESa],&bufferRMS[IRESa][0],counter,bufferLength);
	backRMS.bufferAdc[IRESb]=true_rms(fAdc.bufferAdc[IRESb],&bufferRMS[IRESb][0],counter,bufferLength);
	backRMS.bufferAdc[IRESc]=true_rms(fAdc.bufferAdc[IRESc],&bufferRMS[IRESc][0],counter,bufferLength);
	
	if(++counter==bufferLength){counter=0;}
	
	tRMS=backRMS.sAdc;
		
	
}



