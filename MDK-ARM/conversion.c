#include "stm32f7xx_hal.h"
#include "adc.h"
#include "nfbm.h"
#include "measurement_functions.h"
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

extern uint32_t adc_values[15];

float calc_offset=0;
enum AdcChannel ch=Van;


float averager();
void main_flow(void);





void init_conversion(){
	
	//Offset
	
	offset.Ia=2051.129f;
	offset.Ib=2050.04f;
	offset.Ic=2050.65f;
	
	offset.In=2051.270f;
	offset.IRESa=0.0f;
	offset.IRESb=0.0f;
	offset.IRESc=0.0f;
	
	offset.IUNBa=0.0f;
	offset.IUNBb=0.0f;
	
	offset.Van=2048.936f;
	offset.Vbn=2050.661f;
	offset.Vcn=2050.0f;
	
	// Scale
	
	scale.Ia=0.055470985603544f;//0.055411955626188f;
	scale.Ib=0.055493895671476f;//0.055411955626188f;
	scale.Ic=0.055470985603544f;//0.055411955626188f;
	
	scale.In=0.005482456140351f;

	scale.IRESa=1.0f;
	scale.IRESb=1.0f;
	scale.IRESc=1.0f;
	
	scale.IUNBa=1.0f;
	scale.IUNBb=1.0f;
	
	scale.Van=0.10699f;
	scale.Vbn=0.10699f;
	scale.Vcn=0.10699f;
	

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

	rawAdc.sAdc.AB_synth=(rawAdc.sAdc.Van-rawAdc.sAdc.Vbn);
	rawAdc.sAdc.BC_synth=(rawAdc.sAdc.Vbn-rawAdc.sAdc.Vcn);
	rawAdc.sAdc.CA_synth=(rawAdc.sAdc.Vcn-rawAdc.sAdc.Van);
	
	
	//#endif	
	
	fAdc.sAdc.Ia=rawAdc.sAdc.Ia*TR.CT;
	fAdc.sAdc.Ib=rawAdc.sAdc.Ib*TR.CT;
	fAdc.sAdc.Ic=rawAdc.sAdc.Ic*TR.CT;
	fAdc.sAdc.In=rawAdc.sAdc.In*TR.CT;
	
  
	
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



float averager(){
	
	
	static uint32_t count=0;
	static float sum=0;
	static float x=0;
	
	sum+=fAdc.bufferAdc[ch];
	
	if(++count==12500){
	
		x=sum/12500.0f;
		sum=0;
		count=0;
	}
	
	return x;

}


