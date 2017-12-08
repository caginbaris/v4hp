#include "nfbm.h"
#include "UART_MasterSlave.h"
#include "measurement_functions.h"
#include "protection_functions.h"
#include "pDataConfigs.h"
#include "powerSysData.h"


union protectionEnableData pEN;

union mSelection mSelect;



void checkDataFromMaster(){
	
	


}

void pullDataFromMaster(){
	
	
	// DW data
	
	// processed @ last
	
	mSelect.all=comParams_uart.recDataBufferDW[1];
	
	
	
	
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
	
	
	
	fc59_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[24];
	fc59_obj1_L2_in.dropout_ratio=comParams_uart.recDataBufferF[24];
	//discard
	
	fc59_obj1_L1_in.level=comParams_uart.recDataBufferF[26];
	fc59_obj1_L1_in.delay=comParams_uart.recDataBufferF[27];
	
	fc59_obj1_L2_in.level=comParams_uart.recDataBufferF[28];
	fc59_obj1_L2_in.delay=comParams_uart.recDataBufferF[29];
	
	
	
	fc27_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[30];
	fc27_obj1_L2_in.dropout_ratio=comParams_uart.recDataBufferF[30];
	//discard
	
	fc27_obj1_L1_in.level=comParams_uart.recDataBufferF[32];
	fc27_obj1_L1_in.delay=comParams_uart.recDataBufferF[33];
	
	fc27_obj1_L2_in.level=comParams_uart.recDataBufferF[34];
	fc27_obj1_L2_in.delay=comParams_uart.recDataBufferF[35];
	
	
	fc46d_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[36];
	fc46d_obj1_L1_in.dropout_time=comParams_uart.recDataBufferF[37];
	
	fc46d_obj1_L1_in.level=comParams_uart.recDataBufferF[38];
	fc46d_obj1_L1_in.delay=comParams_uart.recDataBufferF[39];
	
	fc46i_obj1_L1_in.level=comParams_uart.recDataBufferF[40];
	fc46i_obj1_L1_in.time_multiplier=comParams_uart.recDataBufferF[41];
	
	
	fc49_obj1_therm.k=comParams_uart.recDataBufferF[42];
	fc49_obj1_therm.tau=comParams_uart.recDataBufferF[43];
	fc49_obj1_L1_in.alarm_level=comParams_uart.recDataBufferF[44];
	fc49_obj1_therm.Inom=comParams_uart.recDataBufferF[45];
	
	//discard
	//discard
	//discard
	
	fcBF_in.delay=comParams_uart.recDataBufferF[49];
	fcBF_in.threshold=comParams_uart.recDataBufferF[50];
	
	//discard
	//discard
	//discard
	//discard
	//discard
	
	fc37_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[56];
	//discard
	fc37_obj1_L1_in.level=comParams_uart.recDataBufferF[58];
	fc37_obj1_L1_in.delay=comParams_uart.recDataBufferF[59];
	
	
	fcUNBd_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[60];
	//discard
	fcUNBd_obj1_L1_in.level=comParams_uart.recDataBufferF[62];
	fcUNBd_obj1_L1_in.delay=comParams_uart.recDataBufferF[63];
	//spare
	
	//discard
	//discard
	fcUNBi_obj1_L1_in.level=comParams_uart.recDataBufferF[67];
	fcUNBi_obj1_L1_in.time_multiplier=comParams_uart.recDataBufferF[68];
	
	fcPVPd_obj1_L1_in.dropout_ratio=comParams_uart.recDataBufferF[69];
	//discard
	fcPVPd_obj1_L1_in.level=comParams_uart.recDataBufferF[71];
	fcPVPd_obj1_L1_in.delay=comParams_uart.recDataBufferF[72];
	
	//discard
	//discard
	fcPVPi_obj1_L1_in.level=comParams_uart.recDataBufferF[67];
	fcPVPi_obj1_L1_in.time_multiplier=comParams_uart.recDataBufferF[68]; // cau-diff curve entered
	
	//spare
	
	
	fc50_obj2_L1_in.dropout_ratio=comParams_uart.recDataBufferF[78];
	fc50_obj2_L1_in.dropout_time=comParams_uart.recDataBufferF[79];
	
	fc50_obj2_L2_in.dropout_ratio=comParams_uart.recDataBufferF[78];
	fc50_obj2_L2_in.dropout_time=comParams_uart.recDataBufferF[79];
	
	fc50_obj2_L3_in.dropout_ratio=comParams_uart.recDataBufferF[78];
	fc50_obj2_L3_in.dropout_time=comParams_uart.recDataBufferF[79];
	
	
	fc50_obj2_L1_in.level=comParams_uart.recDataBufferF[80];
	fc50_obj2_L1_in.delay=comParams_uart.recDataBufferF[81];
	
	fc50_obj2_L2_in.level=comParams_uart.recDataBufferF[82];
	fc50_obj2_L2_in.delay=comParams_uart.recDataBufferF[83];
	
	fc50_obj2_L3_in.level=comParams_uart.recDataBufferF[84];
	fc50_obj2_L3_in.delay=comParams_uart.recDataBufferF[85];
	
	//discard
	//discard
	
	fc51_obj2_in.level=comParams_uart.recDataBufferF[88];
	fc51_obj2_in.time_multiplier=comParams_uart.recDataBufferF[89];
	
	fc49_obj2_therm.k=comParams_uart.recDataBufferF[90];
	fc49_obj2_therm.tau=comParams_uart.recDataBufferF[91];
	fc49_obj2_L1_in.alarm_level=comParams_uart.recDataBufferF[92];
	fc49_obj2_therm.Inom=comParams_uart.recDataBufferF[93];
	
	//spare
	//spare
	
	
	fc37_obj2_L1_in.dropout_ratio=comParams_uart.recDataBufferF[96];
	//discard
	fc37_obj2_L1_in.level=comParams_uart.recDataBufferF[98];
	fc37_obj2_L1_in.delay=comParams_uart.recDataBufferF[99];
	
	//spare
	//spare
	//spare
	//spare

	Sys.I_Nom_obj1=comParams_uart.recDataBufferF[103];
	Sys.I_Nom_obj2=comParams_uart.recDataBufferF[104];
	
	Sys.I_BreakerClosed_MIN=comParams_uart.recDataBufferF[105];
	Sys.Xvalue=comParams_uart.pushDataBufferF[106];
	Sys.Rvalue=comParams_uart.pushDataBufferF[107];
	
	
	TR.VT_Primary  =comParams_uart.recDataBufferF[108];
	TR.VT_Secondary=comParams_uart.recDataBufferF[109];
	
	TR.CT_Primary  =comParams_uart.recDataBufferF[110];
	TR.CT_Secondary=comParams_uart.recDataBufferF[111];
	
	TR.VT_Primary  =comParams_uart.recDataBufferF[112];
	TR.VT_Secondary=comParams_uart.recDataBufferF[113];
	
	TR.UNB_Primary  =comParams_uart.recDataBufferF[114];
	TR.UNB_Secondary=comParams_uart.recDataBufferF[115];
	
	
	
	
	/*Enable Handling*/
	
	/*
	
	// fc50 
	
	EN.bits.fc50_obj1_L1= pEN.bit.obj1_50_51_N &
												pEN.bit.obj1_50s &
												(fc50_obj1_L1_in.level>eps) &
												(fc50_obj1_L1_in.delay>eps);
																								
	EN.bits.fc50_obj1_L2= pEN.bit.obj1_50_51_N &
												pEN.bit.obj1_50s &
												(fc50_obj1_L2_in.level>eps) &
												(fc50_obj1_L2_in.delay>eps);										
												
	EN.bits.fc50_obj1_L3= pEN.bit.obj1_50_51_N &
												pEN.bit.obj1_50s &
												(fc50_obj1_L3_in.level>eps) &
												(fc50_obj1_L3_in.delay>eps);


	EN.bits.fc50_obj2_L1= pEN.bit.obj2_50_51_N &
												pEN.bit.obj2_50s &
												(fc50_obj2_L1_in.level>eps) &
												(fc50_obj2_L1_in.delay>eps);
																								
	EN.bits.fc50_obj2_L2= pEN.bit.obj2_50_51_N &
												pEN.bit.obj2_50s &
												(fc50_obj2_L2_in.level>eps) &
												(fc50_obj2_L2_in.delay>eps);										
												
	EN.bits.fc50_obj2_L3= pEN.bit.obj2_50_51_N &
												pEN.bit.obj2_50s &
												(fc50_obj2_L3_in.level>eps) &
												(fc50_obj2_L3_in.delay>eps);
												
	
	//fc51	
												
	EN.bits.fc51_obj1= 	  pEN.bit.obj1_50_51_N &
												pEN.bit.obj1_50s &
												(fc51_obj1_in.level>eps) &
												(fc51_obj1_in.time_multiplier>eps);
												
	EN.bits.fc51_obj2= 	  pEN.bit.obj2_50_51_N &
												pEN.bit.obj2_50s &
												(fc51_obj2_in.level>eps) &
												(fc51_obj2_in.time_multiplier>eps);											
												
												
	// fc50N
	
	EN.bits.fc50N_obj1_L1= 	pEN.bit.obj1_50_51_N &
													pEN.bit.obj1_50Ns &
													(fc50N_obj1_L1_in.level>eps) &
													(fc50N_obj1_L1_in.delay>eps);
																								
	EN.bits.fc50N_obj1_L2= 	pEN.bit.obj1_50_51_N &
													pEN.bit.obj1_50Ns &
													(fc50N_obj1_L2_in.level>eps) &
													(fc50N_obj1_L2_in.delay>eps);										
												
	EN.bits.fc50N_obj1_L3= 	pEN.bit.obj1_50_51_N &
													pEN.bit.obj1_50s &
													(fc50N_obj1_L3_in.level>eps) &
													(fc50N_obj1_L3_in.delay>eps);		

	// fc51N
	
	EN.bits.fc51N_obj1= 	  pEN.bit.obj1_50_51_N &
													pEN.bit.obj1_51Ns &
													(fc51N_obj1_in.level>eps) &
													(fc51N_obj1_in.time_multiplier>eps);
	
	
	// fc27
	
	EN.bits.fc27_obj1_L1=   pEN.bit.obj1_27_59 &
													pEN.bit.obj1_27 &
													(fc27_obj1_L1_in.level>eps) &
													(fc27_obj1_L1_in.delay>eps);

	EN.bits.fc27_obj1_L2=   pEN.bit.obj1_27_59 &
													pEN.bit.obj1_27 &
													(fc27_obj1_L2_in.level>eps) &
													(fc27_obj1_L2_in.delay>eps);


	// fc59
	
	EN.bits.fc59_obj1_L1=   pEN.bit.obj1_27_59 &
													pEN.bit.obj1_59 &
													(fc59_obj1_L1_in.level>eps) &
													(fc59_obj1_L1_in.delay>eps);

	EN.bits.fc59_obj1_L2=   pEN.bit.obj1_27_59 &
													pEN.bit.obj1_59 &
													(fc59_obj1_L2_in.level>eps) &
													(fc59_obj1_L2_in.delay>eps);	
													
	// fc46
	
	EN.bits.fc46_obj1_L1=   pEN.bit.obj1_46 &
													(fc46d_obj1_L1_in.level>eps) &
													(fc46d_obj1_L1_in.delay>eps);

	EN.bits.fc46_obj1_L2=    pEN.bit.obj1_46 &
													(fc46i_obj1_L1_in.level>eps) &
													(fc46i_obj1_L1_in.time_multiplier>eps);	

	// fc49
	
	EN.bits.fc49_obj1_L1=  pEN.bit.obj1_49 &
												(fc49_obj1_L1_in.alarm_level>eps) &
												(fc49_obj1_L1_in.trip_level>eps);	
												
	EN.bits.fc49_obj1_L2=  pEN.bit.obj1_49 &
												(fc49_obj1_L2_in.alarm_level>eps) &
												(fc49_obj1_L2_in.trip_level>eps);			


	EN.bits.fc49_obj2_L1=  pEN.bit.obj1_49 &
												(fc49_obj2_L1_in.alarm_level>eps) &
												(fc49_obj2_L1_in.trip_level>eps);	
												
	EN.bits.fc49_obj2_L2=  pEN.bit.obj1_49 &
												(fc49_obj2_L2_in.alarm_level>eps) &
												(fc49_obj2_L2_in.trip_level>eps);
												
												
												
	// fcBF		

	EN.bits.fcBF_obj1 = pEN.bit.obj1_BF &
											(fcBF_in.delay>eps);
											
											
	// fc37
	
	EN.bits.fc37_obj1 =pEN.bit.obj1_37 &
										(fc37_obj1_L1_in.level>eps) &
										(fc37_obj1_L1_in.delay>eps);
										
										
	EN.bits.fc37_obj2 =pEN.bit.obj2_37 &
										(fc37_obj2_L1_in.level>eps) &
										(fc37_obj2_L1_in.delay>eps);
										
										
	// fcUNB
	
		EN.bits.fcUNBd_obj1 =pEN.bit.obj1_UNB &
											(fcUNBd_obj1_L1_in.level>eps) &
											(fcUNBd_obj1_L1_in.delay>eps);		

		EN.bits.fcUNBi_obj1 =pEN.bit.obj1_UNB &
											(fcUNBi_obj1_L1_in.level>eps);	

	// fcPVP
	
		EN.bits.fcPVPd_obj1= pEN.bit.obj1_PVP &
												 (fcUNBd_obj1_L1_in.level>eps) &
												 (fcUNBd_obj1_L1_in.delay>eps); 
												 
												 
		EN.bits.fcPVPi_obj1= pEN.bit.obj1_PVP &
												 (fcUNBi_obj1_L1_in.level>eps) &
												 (fcUNBi_obj1_L1_in.time_multiplier>eps);
		
		*/
		/*Enable Handling End*/										 
												 
	


	
	

	
											
											
												
												
													
	
	 
	
	
	
	
	
	
	
	
	
	


}

