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
	
	offset.Ia=0.0f;
	offset.Ib=0.0f;
	offset.Ic=0.0f;
	
	offset.In=0.0f;
	offset.IRESa=0.0f;
	offset.IRESb=0.0f;
	offset.IRESc=0.0f;
	
	offset.IUNBa=0.0f;
	offset.IUNBb=0.0f;
	
	offset.Van=0.0f;
	offset.Vbn=0.0f;
	offset.Vcn=0.0f;
	
	// Scale
	
	scale.Ia=1.0f;//0.055411955626188f;
	scale.Ib=1.0f;//0.055411955626188f;
	scale.Ic=1.0f;//0.055411955626188f;
	
	scale.In=1.0f;
	scale.IRESa=1.0f;
	scale.IRESb=1.0f;
	scale.IRESc=1.0f;
	
	scale.IUNBa=1.0f;
	scale.IUNBb=1.0f;
	
	scale.Van=1.0f;
	scale.Vbn=1.0f;
	scale.Vcn=1.0f;
	
	//TR.VT=	(TR.VT_Secondary>eps) 	? 	(TR.VT_Primary/TR.VT_Secondary) : 0.0f;
	//TR.CT=	(TR.CT_Secondary>eps) 	? 	(TR.CT_Primary/TR.CT_Secondary) : 0.0f;
	//TR.RES=	(TR.RES_Secondary>eps) 	? 	(TR.RES_Primary/TR.RES_Secondary) : 0.0f;
	//TR.UNB=	(TR.UNB_Secondary>eps) 	? 	(TR.UNB_Primary/TR.RES_Secondary) : 0.0f;
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
	
	fAdc=rawAdc;
	
	HAL_GPIO_WritePin(DO_TEST_1_GPIO_Port, DO_TEST_1_Pin,GPIO_PIN_SET);
	main_flow();
	HAL_GPIO_WritePin(DO_TEST_1_GPIO_Port, DO_TEST_1_Pin,GPIO_PIN_RESET);
	conversion_completed=1;	

	conversion_completed=1;		
	//HAL_GPIO_TogglePin(DO_TEST_1_GPIO_Port, DO_TEST_1_Pin);	
	
	cycle_count_1++;
	
	calc_offset= averager();
	
	
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


