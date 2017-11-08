#include "protection_functions.h"
#include "nfbm.h"
#include "powerSysData.h"



struct fcBF_inputParameters  fcBF_in;
struct fcBF_outputParameters fcBF_out={0};



void fcBF_init(){
	
struct fcBF_inputParameters fcBF_initStruct={
	
	
	0.0f,	/*rmaA*/
	0.0f,	/*rmsB*/
	0.0f,	/*rmsC*/
	
	0.0f,	/*threshold*/
	0.05f,	/*delay*/
	0, 		/*trip inp*/
	0,		/*cb_pos inp*/
	0,		/*CB_pos_check*/

};	

fcBF_in=fcBF_initStruct;

fcBF_in.threshold=Sys.I_BreakerClosed_MIN;
fcBF_in.CB_pos_check=Sys.CBSupervision; /*CB pos input control*/



}


void fcBF_all(){
	
	fcBF_in.rmsA=fRMS.Ia;
	fcBF_in.rmsB=fRMS.Ib;
	fcBF_in.rmsC=fRMS.Ic;
	
	
	fcBF_in.CB_pos=0;			/*Breaker Input*/
	fcBF_in.trip_input=0;	/*Trip Input*/
	
	
	fcBF(fcBF_in,&fcBF_out,EN.bits.fcBF_obj1);
	




}








