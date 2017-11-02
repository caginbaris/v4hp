#include "stm32f7xx_hal.h"
#include "adc.h"
#include "nfbm.h"
#include "mlib_definitions.h"

union uAdc rawAdc={0};
union uAdc fAdc={0};

struct AdcData offset={0};
struct AdcData scale={0};

static uint32_t adc_values[15]={0};

static uint8_t adcTick=0;
static float dbuffer[12][9]={0};

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
	
	for	(i=0;i<12;i++){
		
	fAdc.bufferAdc[i]=prefilter(rawAdc.bufferAdc[i],&dbuffer[i][0],9);
	
	}
	
	if(++adcTick==10){	adcTick=0;}
	
	}


}


