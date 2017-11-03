#include "stm32f7xx_hal.h"
#include "adc.h"
#include "nfbm.h"
#include "measurement_functions.h"
#include "conversion.h"


uint8_t conversion_completed=0;

union uAdc rawAdc={0};
union uAdc fAdc={0};

struct AdcData offset={0};
struct AdcData scale={0};

static uint32_t adc_values[15]={0};

static float dbuffer[channelNo][filterDepth]={0};








void init_conversion(){
	
	//Offset
	
	offset.Ia=2048.0f;
	offset.Ib=2048.0f;
	offset.Ic=2048.0f;
	
	offset.In=2048.0f;
	offset.IRESa=2048.0f;
	offset.IRESb=2048.0f;
	offset.IRESc=2048.0f;
	
	offset.IUNBa=2048.0f;
	offset.IUNBb=2048.0f;
	
	offset.Van=2048.0f;
	offset.Vbn=2048.0f;
	scale.Vcn=2048.0f;
	
	// Scale
	
	scale.Ia=1.0f;
	scale.Ib=1.0f;
	scale.Ic=1.0f;
	
	scale.In=1.0f;
	scale.IRESa=1.0f;
	scale.IRESb=1.0f;
	scale.IRESc=1.0f;
	
	scale.IUNBa=1.0f;
	scale.IUNBb=1.0f;
	
	scale.Van=1.0f;
	scale.Vbn=1.0f;
	scale.Vcn=1.0f;


}





void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	
uint8_t i;

if(hadc->Instance==ADC1){ 
	
	//HAL_GPIO_TogglePin(DO_TEST_1_GPIO_Port, DO_TEST_1_Pin);
	
	rawAdc.sAdc.Van=			(adc_values[Van]		-	offset.Van)			*scale.Van;
	rawAdc.sAdc.Ia=				(adc_values[Ia]			-	offset.Ia)			*scale.Ia;
	rawAdc.sAdc.IUNBa=		(adc_values[IUNBa]	-	offset.IUNBa)		*scale.IUNBa;
	
	rawAdc.sAdc.Vbn=			(adc_values[Vbn]-offset.Vbn)					*scale.Vbn;
	rawAdc.sAdc.Ib=				(adc_values[Ib]-offset.Ib)						*scale.Ib;
	rawAdc.sAdc.IUNBb=		(adc_values[IUNBb]-offset.IUNBb)			*scale.IUNBb;
	
	rawAdc.sAdc.Vcn=			(adc_values[Vcn]-offset.Vcn)					*scale.Vcn;
	rawAdc.sAdc.Ic=				(adc_values[Ic]-offset.Ic)						*scale.Ic;
	
	rawAdc.sAdc.IRESa=		(adc_values[IRESa]-offset.IRESa)			*scale.IRESa;
	rawAdc.sAdc.In=				(adc_values[In]-offset.In)						*scale.In;
	
	rawAdc.sAdc.IRESb=		(adc_values[IRESb]-offset.IRESb)			*scale.IRESb;
	rawAdc.sAdc.IRESc=		(adc_values[IRESc]-offset.IRESc)			*scale.IRESc;
	
	for	(i=0;i<channelNo;i++){
		
	fAdc.bufferAdc[i]=prefilter(rawAdc.bufferAdc[i],&dbuffer[i][0],filterDepth);
	
	}
	
	conversion_completed=1;
	
	}


}


