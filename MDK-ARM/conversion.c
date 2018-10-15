#include "stm32f7xx_hal.h"
#include "adc.h"
#include "nfbm.h"
#include "mlib_definitions.h"
#include "pDataConfigs.h"
#include "conversion.h"

volatile uint8_t conversion_completed=0;

volatile uint32_t cycle_count_1=0;
volatile uint32_t cycle_count_2=0;

union uAdc rawAdc={0};
union uAdc fAdc={0};
struct AdcData offset={0};
struct AdcData scale={0};
struct TurnRatios TR;
struct prefilter_oc_parameters oc[15]={0};	

extern uint32_t adc_values[15];

float calc_offset=0;
enum AdcChannel ch=Van;





void main_flow(void);





void init_conversion(){
	
	//Offset
	
	offset.Ia=2051.0f;//CTB4 2051.129f; 
	offset.Ib=2051.0f;//CTB4 2050.04f;
	offset.Ic=2051.0f;//CTB4 2050.65f;
	
	offset.In=2051.270f;
	
	offset.IRESa=2050.0f;
	offset.IRESb=2050.0f;
	offset.IRESc=2050.0f;
	
	offset.IUNBa=2050.0f;
	offset.IUNBb=2050.0f;
	
	offset.Van=2048.936f;
	offset.Vbn=2050.661f;
	offset.Vcn=2050.0f;
	
	
	
	// Scale
	
	scale.Ia=0.055470985603544f;//0.055411955626188f;
	scale.Ib=0.055493895671476f;//0.055411955626188f;
	scale.Ic=0.055470985603544f;//0.055411955626188f;
	
	scale.In=0.005482456140351f;


	
	scale.IUNBa=0.005507f;
	scale.IUNBb=0.005507f;
	
	scale.Van=0.10699f;
	scale.Vbn=0.10699f;
	scale.Vcn=0.106399998f;
	
	scale.IRESa=0.005502f; 
	scale.IRESb=0.005502f; 
	scale.IRESc=0.005502f; 
	
	TR.VT=345;
	TR.CT=500;
	TR.UNB=5;
	TR.RES=80;
	
}





void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	

	

if(hadc->Instance==ADC1){ 
	
	
	
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


	
	
	//#endif	
	
	fAdc.sAdc.Ia=prefilter_oc(rawAdc.sAdc.Ia*TR.CT,&oc[Ia]);
	fAdc.sAdc.Ib=prefilter_oc(rawAdc.sAdc.Ib*TR.CT,&oc[Ib]);
	fAdc.sAdc.Ic=prefilter_oc(rawAdc.sAdc.Ic*TR.CT,&oc[Ic]);
	fAdc.sAdc.In=prefilter_oc(rawAdc.sAdc.In*TR.CT,&oc[In]);
	
	fAdc.sAdc.IRESa=prefilter_oc(rawAdc.sAdc.IRESa*TR.RES,&oc[IRESa]);
  fAdc.sAdc.IRESb=prefilter_oc(rawAdc.sAdc.IRESb*TR.RES,&oc[IRESb]);
	fAdc.sAdc.IRESc=prefilter_oc(rawAdc.sAdc.IRESc*TR.RES,&oc[IRESc]);
	
	fAdc.sAdc.Van=prefilter_oc(rawAdc.sAdc.Van*TR.VT,&oc[Van]);
	fAdc.sAdc.Vbn=prefilter_oc(rawAdc.sAdc.Vbn*TR.VT,&oc[Vbn]);
	fAdc.sAdc.Vcn=prefilter_oc(rawAdc.sAdc.Vcn*TR.VT,&oc[Vcn]);
	
	fAdc.sAdc.IUNBa=prefilter_oc(rawAdc.sAdc.IUNBa*TR.UNB,&oc[IUNBa]);
	fAdc.sAdc.IUNBb=prefilter_oc(rawAdc.sAdc.IUNBb*TR.UNB,&oc[IUNBb]); 	
	
	fAdc.sAdc.AB_synth=(fAdc.sAdc.Van-fAdc.sAdc.Vbn);
	fAdc.sAdc.BC_synth=(fAdc.sAdc.Vbn-fAdc.sAdc.Vcn);
	fAdc.sAdc.CA_synth=(fAdc.sAdc.Vcn-fAdc.sAdc.Van);
	

	
	//fAdc=rawAdc;
	
	HAL_GPIO_WritePin(DO_TEST_1_GPIO_Port, DO_TEST_1_Pin,GPIO_PIN_SET);
	main_flow();
	HAL_GPIO_WritePin(DO_TEST_1_GPIO_Port, DO_TEST_1_Pin,GPIO_PIN_RESET);
	conversion_completed=1;	

	
	//HAL_GPIO_TogglePin(DO_TEST_1_GPIO_Port, DO_TEST_1_Pin);	
	
	cycle_count_1++;
	
	//calc_offset= averager();
	
	
	}


}






