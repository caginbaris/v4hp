#include "nfbm.h"
#include "SPI_MasterSlave.h"
#include "UART_MasterSlave.h"

#include "mlib_definitions.h"
#include "plib_handles.h"
#include "boardIO.h"
#include "externalData.h"

#include "test_commParams.h"

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
	
	
	//MEM AREA-1
	
	
	//Integer Parameters
	
	pick_words.w_str=pick;
	
	/*2*/comParams.pushDataBufferDW[0]=pick_words.w_arr[0];
	/*4*/comParams.pushDataBufferDW[1]=pick_words.w_arr[1];
	/*6*/comParams.pushDataBufferDW[2]=pick_words.w_arr[2];
	
	trip_words.w_str=trip;
	
	/*8*/ comParams.pushDataBufferDW[3]=trip_words.w_arr[0];
	/*10*/comParams.pushDataBufferDW[4]=trip_words.w_arr[1];
	/*12*/comParams.pushDataBufferDW[5]=trip_words.w_arr[2];
	
	/*14*/comParams.pushDataBufferDW[6]=0; 				//tripping hist enerterd 1 or more seq
	
	/*16*/comParams.pushDataBufferDW[7]=0; 				// Board Status
	
	/*18*/comParams.pushDataBufferDW[8]=DI.all; 	// Input Status
	/*20*/comParams.pushDataBufferDW[9]=DO.all; 	// Output Status
	
	/*22*/comParams.pushDataBufferDW[10]=0; 			// Spare
	/*24*/comParams.pushDataBufferDW[11]=0; 			// Spare
	/*26*/comParams.pushDataBufferDW[12]=0; 			// Spare
	/*28*/comParams.pushDataBufferDW[13]=0; 			// Spare
	
	//Real Parameters
	
	/*30*/comParams.pushDataBufferF[0]=tRMS.Ia; 	// Ia true RMS
	/*32*/comParams.pushDataBufferF[1]=tRMS.Ib; 	// Ib true RMS
	/*34*/comParams.pushDataBufferF[2]=tRMS.Ic; 	// Ic true RMS
	
	/*36*/comParams.pushDataBufferF[3]=fRMS.Ia; 	// Ia fund RMS
	/*38*/comParams.pushDataBufferF[4]=fRMS.Ib; 	// Ib fund RMS
	/*40*/comParams.pushDataBufferF[5]=fRMS.Ic; 	// Ic fund RMS
	
	/*42*/comParams.pushDataBufferF[6]=P.total; 	// Ptotal
	
	/*44*/comParams.pushDataBufferF[7]=Q.ab; 			// Qab
	/*46*/comParams.pushDataBufferF[8]=Q.bc; 			// Qbc
	/*48*/comParams.pushDataBufferF[9]=Q.ca; 			// Qca
	/*50*/comParams.pushDataBufferF[10]=Q.total;	// Qca
	
	/*52*/comParams.pushDataBufferF[11]=spect_Ia.foutMag[1]; 	// H2-A
	/*54*/comParams.pushDataBufferF[12]=spect_Ib.foutMag[1]; 	// H2-B
	/*56*/comParams.pushDataBufferF[13]=spect_Ic.foutMag[1]; 	// H2-C
	
	/*58*/comParams.pushDataBufferF[14]=spect_Ia.foutMag[2];	// H3-A
	/*60*/comParams.pushDataBufferF[15]=spect_Ib.foutMag[2]; 	// H3-B
	/*62*/comParams.pushDataBufferF[16]=spect_Ic.foutMag[2]; 	// H3-C
	
	/*64*/comParams.pushDataBufferF[17]=spect_Ia.foutMag[3]; 	// H4-A
	/*66*/comParams.pushDataBufferF[18]=spect_Ib.foutMag[3]; 	// H4-B
	/*68*/comParams.pushDataBufferF[19]=spect_Ic.foutMag[3]; 	// H4-C
	
	/*70*/comParams.pushDataBufferF[20]=spect_Ia.foutMag[4]; 	// H5-A
	/*72*/comParams.pushDataBufferF[21]=spect_Ib.foutMag[4]; 	// H5-B
	/*74*/comParams.pushDataBufferF[22]=spect_Ic.foutMag[4]; 	// H5-C
	
	/*76*/comParams.pushDataBufferF[23]=spect_Ia.foutMag[5]; 	// H6-A
	/*78*/comParams.pushDataBufferF[24]=spect_Ib.foutMag[5]; 	// H6-B
	/*80*/comParams.pushDataBufferF[25]=spect_Ic.foutMag[5]; 	// H6-C
	
	/*82*/comParams.pushDataBufferF[26]=spect_Ia.foutMag[6]; 	// H7-A
	/*84*/comParams.pushDataBufferF[27]=spect_Ib.foutMag[6]; 	// H7-B
	/*86*/comParams.pushDataBufferF[28]=spect_Ic.foutMag[6]; 	// H7-C
	
	/*88*/comParams.pushDataBufferF[29]=spect_Ia.foutMag[7]; 	// H8-A
	/*90*/comParams.pushDataBufferF[30]=spect_Ib.foutMag[7]; 	// H8-B
	/*92*/comParams.pushDataBufferF[31]=spect_Ic.foutMag[7]; 	// H8-C
	
	/*94*/comParams.pushDataBufferF[32]=spect_Ia.foutMag[8]; 	// H9-A
	/*96*/comParams.pushDataBufferF[33]=spect_Ib.foutMag[8]; 	// H9-B
	/*98*/comParams.pushDataBufferF[34]=spect_Ic.foutMag[8];	// H9-C
	
	/*100*/comParams.pushDataBufferF[35]=spect_Ia.foutMag[9]; 	// H10-A
	/*102*/comParams.pushDataBufferF[36]=spect_Ib.foutMag[9]; 	// H10-B
	/*104*/comParams.pushDataBufferF[37]=spect_Ic.foutMag[9]; 	// H10-C
	
	/*106*/comParams.pushDataBufferF[38]=spect_Ia.foutMag[10]; // H11-A
	/*108*/comParams.pushDataBufferF[39]=spect_Ib.foutMag[10]; // H11-B
	/*110*/comParams.pushDataBufferF[40]=spect_Ic.foutMag[10]; // H11-C
	
	/*112*/comParams.pushDataBufferF[41]=spect_Ia.foutMag[11]; // H12-A
	/*114*/comParams.pushDataBufferF[42]=spect_Ib.foutMag[11]; // H12-B
	/*116*/comParams.pushDataBufferF[43]=spect_Ic.foutMag[11]; // H12-C
	
	/*118*/comParams.pushDataBufferF[44]=spect_Ia.foutMag[12]; // H13-A
	/*120*/comParams.pushDataBufferF[45]=spect_Ib.foutMag[12]; // H13-B
	/*122*/comParams.pushDataBufferF[46]=spect_Ic.foutMag[12]; // H13-C
	
	//MEM AREA-2
	
	/*126*/comParams.pushDataBufferF[47]=thd.a; 			//thd Ia
	/*128*/comParams.pushDataBufferF[48]=thd.b;				//thd Ib
	/*130*/comParams.pushDataBufferF[49]=thd.c;				//thd Ic
	
	/*132*/comParams.pushDataBufferF[50]=mag_sym.V1; 	//Vpos
	/*134*/comParams.pushDataBufferF[51]=mag_sym.V2; 	//Vneg
	
	/*136*/comParams.pushDataBufferF[52]=mag_sym.I1; 	//Ipos
	/*138*/comParams.pushDataBufferF[53]=mag_sym.I2;	//Ineg
	
	/*140*/comParams.pushDataBufferF[54]=(mag_sym.V1>1.0f) ? (mag_sym.V2/mag_sym.V1):0.0f ; //UNB Ratio V
	/*142*/comParams.pushDataBufferF[55]=(mag_sym.I1>1.0f) ? (mag_sym.I2/mag_sym.I1):0.0f ; //UNB Ratio I
	
	/*144*/comParams.pushDataBufferF[56]=0.0f ; //Spare
	
	/*146*/comParams.pushDataBufferF[57]=fRMS.Van; 		//RMS Van
	/*148*/comParams.pushDataBufferF[58]=fRMS.Vbn;		//RMS Vbn
	/*150*/comParams.pushDataBufferF[59]=fRMS.Vcn;		//RMS Vcn
	
	/*152*/comParams.pushDataBufferF[60]=fRMS.AB_synth;//RMS Vab
	/*154*/comParams.pushDataBufferF[61]=fRMS.AB_synth;//RMS Vbc
	/*156*/comParams.pushDataBufferF[62]=fRMS.AB_synth;//RMS Vca
	
	/*158*/
	
	
	
	
	#endif
	
}


void pullDataFromMaster(){
	

	
}




