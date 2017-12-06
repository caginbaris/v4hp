#include "nfbm.h"
#include "UART_MasterSlave.h"
#include "protection_functions.h"
#include "pDataConfigs.h"





void checkDataFromMaster(){
	
	


}

void pullDataFromMaster(){
	
	
	// DW data
	
	
	//F data
	
	fc50_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[0];
	fc50_obj1_L1_in.dropout_time=comParams_uart.recDataBufferF[1];
	
	fc50_obj1_L2_in.dropout_ratio=comParams_uart.recDataBufferF[0];
	fc50_obj1_L2_in.dropout_time=comParams_uart.recDataBufferF[1];
	
	fc50_obj1_L3_in.dropout_ratio=comParams_uart.recDataBufferF[0];
	fc50_obj1_L3_in.dropout_time=comParams_uart.recDataBufferF[1];
	
	
	fc50_obj1_L1_in.level=comParams_uart.recDataBufferF[2];
	fc50_obj1_L1_in.delay=comParams_uart.recDataBufferF[3];
	
	fc50_obj1_L2_in.level=comParams_uart.recDataBufferF[4];
	fc50_obj1_L2_in.delay=comParams_uart.recDataBufferF[5];
	
	fc50_obj1_L3_in.level=comParams_uart.recDataBufferF[6];
	fc50_obj1_L3_in.delay=comParams_uart.recDataBufferF[7];
	
	//discard
	//discard
	
	fc51_obj1_in.level=comParams_uart.recDataBufferF[10];
	fc51_obj1_in.time_multiplier=comParams_uart.recDataBufferF[11];
	
	
	fc50N_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[12];
	fc50N_obj1_L1_in.dropout_time=comParams_uart.recDataBufferF[13];
	
	fc50N_obj1_L2_in.dropout_ratio=comParams_uart.recDataBufferF[12];
	fc50N_obj1_L2_in.dropout_time=comParams_uart.recDataBufferF[13];
	
	fc50N_obj1_L3_in.dropout_ratio=comParams_uart.recDataBufferF[12];
	fc50N_obj1_L3_in.dropout_time=comParams_uart.recDataBufferF[13];
	
	
	fc50N_obj1_L1_in.level=comParams_uart.recDataBufferF[14];
	fc50N_obj1_L1_in.delay=comParams_uart.recDataBufferF[15];
	
	fc50N_obj1_L2_in.level=comParams_uart.recDataBufferF[16];
	fc50N_obj1_L2_in.delay=comParams_uart.recDataBufferF[17];
	
	fc50N_obj1_L3_in.level=comParams_uart.recDataBufferF[18];
	fc50N_obj1_L3_in.delay=comParams_uart.recDataBufferF[19];
	
	
	//discard
	//discard
	
	fc51N_obj1_in.level=comParams_uart.recDataBufferF[22];
	fc51N_obj1_in.time_multiplier=comParams_uart.recDataBufferF[23];
	
	fc59_obj1_L1_in.dropout_ratio=comParams_uart.pushDataBufferF[24];
	//discard
	fc59_obj1_L1_in.level=comParams_uart.pushDataBufferF[26];
	
	
	
	
	
	
	
	
	


}

