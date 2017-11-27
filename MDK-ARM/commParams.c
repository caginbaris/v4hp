
#include "SPI_MasterSlave.h"
#include "UART_MasterSlave.h"

#include "test_commParams.h"
#include "plib_handles.h"
#include "externalData.h"


//****test Parameters For Register Read****//

enum commTestDW testParamDW=DW_0;
enum commTestF testParamF=F_0;


uint32_t testDW[READ_TOTAL_REGISTER_SIZE + 1]={0};
uint32_t testEntryDW=0;

uint32_t testF[READ_TOTAL_REGISTER_SIZE + 1]={0};
uint32_t testEntryF=0;

//****test Parameters For Register Read****//

union ToWord pick_words={0};
union ToWord trip_words={0};


void pushDataToMaster(){
	
	
	
	#if  COMM_testEnable 
	
	testDW[testParamDW]=testEntryDW;
	comParams.pushDataBufferDW[testParamDW]=testDW[testParamDW];
	
	testF[testParamF]=testEntryF;
	comParams.pushDataBufferDW[testParamF]=testDW[testParamF];
	
	
	
	#else
	
	pick_words.w_str=pick;
	
	comParams.pushDataBufferDW[0]=pick_words.w_arr[0];
	comParams.pushDataBufferDW[1]=pick_words.w_arr[1];
	comParams.pushDataBufferDW[2]=pick_words.w_arr[2];
	
	
	
	
	
	
	
	
	
	#endif
	
}


void pullDataFromMaster(){
	

	
}



