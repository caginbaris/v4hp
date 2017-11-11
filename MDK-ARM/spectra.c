#include "measurement_functions.h"
#include "nfbm.h"



struct spectra spect_Ia={0};
struct spectra spect_Ib={0};
struct spectra spect_Ic={0};

struct thd_data thd={0};


#define spectraLength 50

float coeffs_real[]={
1.00000000000000000000f,
0.99211472272872924804f,0.96858316659927368164f,0.92977648973464965820f,
0.87630665302276611328f,0.80901700258255004882f,0.72896862030029296875f,
0.63742399215698242187f,0.53582680225372314453f,0.42577928304672241210f,
0.30901700258255004882f,0.18738131225109100341f,0.06279052048921585083f,
-0.06279052048921585083f,-0.18738131225109100341f,-0.30901700258255004882f,
-0.42577928304672241210f,-0.53582680225372314453f,-0.63742399215698242187f,
-0.72896862030029296875f,-0.80901700258255004882f,-0.87630665302276611328f,
-0.92977648973464965820f,-0.96858316659927368164f,-0.99211472272872924804f,
-1.00000000000000000000f,-0.99211472272872924804f,-0.96858316659927368164f,
-0.92977648973464965820f,-0.87630665302276611328f,-0.80901700258255004882f,
-0.72896862030029296875f,-0.63742399215698242187f,-0.53582680225372314453f,
-0.42577928304672241210f,-0.30901700258255004882f,-0.18738131225109100341f,
-0.06279052048921585083f,0.06279052048921585083f,0.18738131225109100341f,
0.30901700258255004882f,0.42577928304672241210f,0.53582680225372314453f,
0.63742399215698242187f,0.72896862030029296875f,0.80901700258255004882f,
0.87630665302276611328f,0.92977648973464965820f,0.96858316659927368164f,
0.99211472272872924804f};

float coeffs_imag[]={
0.00000000000000000000f,
0.12533323466777801513f,0.24868988990783691406f,0.36812454462051391601f,
0.48175367712974548339f,0.58778524398803710937f,0.68454712629318237304f,
0.77051323652267456054f,0.84432792663574218750f,0.90482705831527709960f,
0.95105654001235961914f,0.98228722810745239257f,0.99802672863006591796f,
0.99802672863006591796f,0.98228722810745239257f,0.95105654001235961914f,
0.90482705831527709960f,0.84432792663574218750f,0.77051323652267456054f,
0.68454712629318237304f,0.58778524398803710937f,0.48175367712974548339f,
0.36812454462051391601f,0.24868988990783691406f,0.12533323466777801513f,
-0.00000000000000076571f,-0.12533323466777801513f,-0.24868988990783691406f,
-0.36812454462051391601f,-0.48175367712974548339f,-0.58778524398803710937f,
-0.68454712629318237304f,-0.77051323652267456054f,-0.84432792663574218750f,
-0.90482705831527709960f,-0.95105654001235961914f,-0.98228722810745239257f,
-0.99802672863006591796f,-0.99802672863006591796f,-0.98228722810745239257f,
-0.95105654001235961914f,-0.90482705831527709960f,-0.84432792663574218750f,
-0.77051323652267456054f,-0.68454712629318237304f,-0.58778524398803710937f,
-0.48175367712974548339f,-0.36812454462051391601f,-0.24868988990783691406f,
-0.12533323466777801513f};








void spectra_tick1(){
	
	
	static unsigned int count=0; 
	
	signal_spectra(fAdc.sAdc.Ia,
								&spect_Ia,
								spectraLength,
								&coeffs_real[0],
								&coeffs_imag[0],
								count++);
	
	if(count==spectraLength){count=0;}

}



void spectra_tick2(){
	
	
	static unsigned int count=0; 
	
	signal_spectra(fAdc.sAdc.Ib,
								&spect_Ib,
								spectraLength,
								&coeffs_real[0],
								&coeffs_imag[0],
								count++);
	
	if(count==spectraLength){count=0;}

}

void spectra_tick3(){
	
	
	static unsigned int count=0; 
	
	signal_spectra(fAdc.sAdc.Ib,
								&spect_Ib,
								spectraLength,
								&coeffs_real[0],
								&coeffs_imag[0],
								count++);
	
	if(count==spectraLength){count=0;}

}

void thd_all(){
	
	thd.a=signal_thd(spect_Ia);
	thd.b=signal_thd(spect_Ib);
	thd.c=signal_thd(spect_Ic);



}

