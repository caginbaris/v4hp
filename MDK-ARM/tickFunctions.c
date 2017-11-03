
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

};
void ftick2(){

	cs_handle_tick2();
	
};
void ftick3(){

	cs_handle_tick3();

};
void ftick4(){

	cs_handle_tick4();

};
void ftick5(){};
void ftick6(){};
void ftick7(){};
void ftick8(){};
void ftick9(){};
void ftick10(){};	



