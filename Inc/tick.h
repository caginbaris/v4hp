#ifndef __tick_h
#define __tick_h


void ftick1(void);
void ftick2(void);
void ftick3(void);
void ftick4(void);
void ftick5(void);
void ftick6(void);
void ftick7(void);
void ftick8(void);
void ftick9(void);
void ftick10(void);

void (*ftick[])(void)={

ftick1,
ftick2,
ftick3,
ftick4,
ftick5,
ftick6,
ftick7,
ftick8,
ftick9,
ftick10	
	
};


enum tickCode{

tick1,
tick2,
tick3,
tick4,
tick5,
tick6,
tick7,
tick8,
tick9,
tick10	

};


void cs_handle_tick1();
void cs_handle_tick2();
void cs_handle_tick3();
void cs_handle_tick4();

void spectra_tick1();
void spectra_tick2();
void spectra_tick3();


void fc50_all();
void fc51_all();
void fc50N_all();
void fc51N_all();
void fc27_all();
void fc59_all();
void fc46_all();
void fc49_all();
void fcBF_all();
void fc37_all();
void fcUNB_all();
void fcPVP_all();




#endif






