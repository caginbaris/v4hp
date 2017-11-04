
#include "tick.h"
#include "mlib_definitions.h"



enum tickCode tick=tick1; 

void tickFunctions(){
	
	
	void (* ftick_thread)(void);
		
	ftick_thread=ftick[tick++] ;
	ftick_thread();
	
	if(tick==tick10){tick=tick1;}
	

}


void ftick1(){
	
	cs_handle_tick1();
	spectra_tick1();
	

};
void ftick2(){

	cs_handle_tick2();
	spectra_tick2();
	
};
void ftick3(){

	cs_handle_tick3();
	spectra_tick3();
	

};
void ftick4(){

	cs_handle_tick4();

};
void ftick5(){};
void ftick6(){};
void ftick7(){

	fc50_all();
	fc51_all();

	fc50N_all();
	fc51N_all();
	
	fc27_all();	


};
void ftick8(){



};
void ftick9(){};
void ftick10(){};	



