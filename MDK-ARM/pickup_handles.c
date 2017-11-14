#include "nfbm.h"
#include "plib_handles.h"
#include "protection_functions.h"

#define totalPick 67
#define pickHold 10

struct plib_handles pick={0};
static long pick_buffer[totalPick]={0};



void pick_up_handles(){
	
	static uint8_t pick_up_counter=0;
	uint8_t count=0;
	
	
	switch (pick_up_counter)
  {
  	case 0:
			
		pick.fc50_obj1_L1_out_a=off_delay(fc50_obj1_L1_out_a.pick_up, pick.fc50_obj1_L1_out_a, pickHold, &pick_buffer[0]);
		pick.fc50_obj1_L1_out_b=off_delay(fc50_obj1_L1_out_b.pick_up, pick.fc50_obj1_L1_out_b, pickHold, &pick_buffer[1]);	
		pick.fc50_obj1_L1_out_c=off_delay(fc50_obj1_L1_out_c.pick_up, pick.fc50_obj1_L1_out_c, pickHold, &pick_buffer[2]);

		pick.fc50_obj1_L2_out_a=off_delay(fc50_obj1_L2_out_a.pick_up, pick.fc50_obj1_L2_out_a, pickHold, &pick_buffer[3]);
		pick.fc50_obj1_L2_out_b=off_delay(fc50_obj1_L2_out_b.pick_up, pick.fc50_obj1_L2_out_b, pickHold, &pick_buffer[4]);	
		pick.fc50_obj1_L2_out_c=off_delay(fc50_obj1_L2_out_c.pick_up, pick.fc50_obj1_L2_out_c, pickHold, &pick_buffer[5]);
		
		pick.fc50N_obj1_L1_out=off_delay(fc50N_obj1_L1_out.pick_up, pick.fc50N_obj1_L1_out, pickHold, &pick_buffer[6]);
		
  	break;
		
  	case 1:
			
		pick.fc50_obj1_L3_out_a=off_delay(fc50_obj1_L3_out_a.pick_up, pick.fc50_obj1_L3_out_a, pickHold, &pick_buffer[7]);
		pick.fc50_obj1_L3_out_b=off_delay(fc50_obj1_L3_out_b.pick_up, pick.fc50_obj1_L3_out_b, pickHold, &pick_buffer[8]);	
		pick.fc50_obj1_L3_out_c=off_delay(fc50_obj1_L3_out_c.pick_up, pick.fc50_obj1_L3_out_c, pickHold, &pick_buffer[9]);
		
		pick.fc50_obj2_L1_out_a=off_delay(fc50_obj2_L1_out_a.pick_up, pick.fc50_obj2_L1_out_a, pickHold, &pick_buffer[10]);
		pick.fc50_obj2_L1_out_b=off_delay(fc50_obj2_L1_out_b.pick_up, pick.fc50_obj2_L1_out_b, pickHold, &pick_buffer[11]);	
		pick.fc50_obj2_L1_out_c=off_delay(fc50_obj2_L1_out_c.pick_up, pick.fc50_obj2_L1_out_c, pickHold, &pick_buffer[12]);

		pick.fc50N_obj1_L2_out=off_delay(fc50N_obj1_L2_out.pick_up, pick.fc50N_obj1_L2_out, pickHold, &pick_buffer[13]);
			
  	break;
		
		case 2:
			
		pick.fc50_obj2_L2_out_a=off_delay(fc50_obj2_L2_out_a.pick_up, pick.fc50_obj2_L2_out_a, pickHold, &pick_buffer[14]);
		pick.fc50_obj2_L2_out_b=off_delay(fc50_obj2_L2_out_b.pick_up, pick.fc50_obj2_L2_out_b, pickHold, &pick_buffer[15]);	
		pick.fc50_obj2_L2_out_c=off_delay(fc50_obj2_L2_out_c.pick_up, pick.fc50_obj2_L2_out_c, pickHold, &pick_buffer[16]);
			
		pick.fc50_obj2_L3_out_a=off_delay(fc50_obj2_L3_out_a.pick_up, pick.fc50_obj2_L3_out_a, pickHold, &pick_buffer[17]);
		pick.fc50_obj2_L3_out_b=off_delay(fc50_obj2_L3_out_b.pick_up, pick.fc50_obj2_L3_out_b, pickHold, &pick_buffer[18]);	
		pick.fc50_obj2_L3_out_c=off_delay(fc50_obj2_L3_out_c.pick_up, pick.fc50_obj2_L3_out_c, pickHold, &pick_buffer[19]);
		
		pick.fc50N_obj1_L3_out=off_delay(fc50N_obj1_L3_out.pick_up, pick.fc50N_obj1_L3_out, pickHold, &pick_buffer[20]);
			
		break;
		
		case 3:
			
		pick.fc51_obj1_out_a=off_delay(fc51_obj1_out_a.pick_up, pick.fc51_obj1_out_a,pickHold,&pick_buffer[21]);
		pick.fc51_obj1_out_b=off_delay(fc51_obj1_out_b.pick_up, pick.fc51_obj1_out_b,pickHold,&pick_buffer[22]);	
		pick.fc51_obj1_out_c=off_delay(fc51_obj1_out_c.pick_up, pick.fc51_obj1_out_c,pickHold,&pick_buffer[23]);
		
		pick.fc51_obj2_out_a=off_delay(fc51_obj2_out_a.pick_up, pick.fc51_obj2_out_a,pickHold,&pick_buffer[24]);
		pick.fc51_obj2_out_b=off_delay(fc51_obj2_out_b.pick_up, pick.fc51_obj2_out_b,pickHold,&pick_buffer[25]);	
		pick.fc51_obj2_out_c=off_delay(fc51_obj2_out_c.pick_up, pick.fc51_obj2_out_c,pickHold,&pick_buffer[26]);
			
		pick.fc51N_obj1_out=off_delay(fc51N_obj1_out.pick_up, pick.fc51N_obj1_out,pickHold,&pick_buffer[27]);
			
		
		break;
		
		
		case 4:
			
		pick.fc27_obj1_L1_out=off_delay(fc27_obj1_L1_out.pick_up, pick.fc27_obj1_L1_out,pickHold,&pick_buffer[28]);
		pick.fc27_obj1_L2_out=off_delay(fc27_obj1_L2_out.pick_up, pick.fc27_obj1_L2_out,pickHold,&pick_buffer[29]);
		
		pick.fc59_obj1_L1_out_a=off_delay(fc59_obj1_L1_out_a.pick_up, pick.fc59_obj1_L1_out_a,pickHold,&pick_buffer[30]);
		pick.fc59_obj1_L1_out_b=off_delay(fc59_obj1_L1_out_b.pick_up, pick.fc59_obj1_L1_out_b,pickHold,&pick_buffer[31]);
		pick.fc59_obj1_L1_out_c=off_delay(fc59_obj1_L1_out_c.pick_up, pick.fc59_obj1_L1_out_c,pickHold,&pick_buffer[32]);
		
		pick.fc59_obj1_L2_out_a=off_delay(fc59_obj1_L2_out_a.pick_up, pick.fc59_obj1_L2_out_a,pickHold,&pick_buffer[33]);
		pick.fc59_obj1_L2_out_b=off_delay(fc59_obj1_L2_out_b.pick_up, pick.fc59_obj1_L2_out_b,pickHold,&pick_buffer[34]);
		pick.fc59_obj1_L2_out_c=off_delay(fc59_obj1_L2_out_c.pick_up, pick.fc59_obj1_L2_out_c,pickHold,&pick_buffer[35]);

			
		break;
		
		
		case 5:
			
		pick.fc46d_obj1_L1_out=off_delay(fc46d_obj1_L1_out.pick_up, pick.fc46d_obj1_L1_out,pickHold,&pick_buffer[36]);
		pick.fc46i_obj1_L1_out=off_delay(fc46i_obj1_L1_out.pick_up, pick.fc46i_obj1_L1_out,pickHold,&pick_buffer[37]);
			
		pick.fc49_obj1_L1_out_a=off_delay(fc49_obj1_L1_out_a.alarm, pick.fc49_obj1_L1_out_a,pickHold,&pick_buffer[38]);
		pick.fc49_obj1_L1_out_b=off_delay(fc49_obj1_L1_out_b.alarm, pick.fc49_obj1_L1_out_b,pickHold,&pick_buffer[39]);
		pick.fc49_obj1_L1_out_c=off_delay(fc49_obj1_L1_out_c.alarm, pick.fc49_obj1_L1_out_c,pickHold,&pick_buffer[40]);
		
		pick.fc49_obj1_L2_out_a=off_delay(fc49_obj1_L2_out_a.alarm, pick.fc49_obj1_L2_out_a,pickHold,&pick_buffer[41]);
		pick.fc49_obj1_L2_out_b=off_delay(fc49_obj1_L2_out_b.alarm, pick.fc49_obj1_L2_out_b,pickHold,&pick_buffer[42]);
		pick.fc49_obj1_L2_out_c=off_delay(fc49_obj1_L2_out_c.alarm, pick.fc49_obj1_L2_out_c,pickHold,&pick_buffer[43]);
			
		
		break;
		
		
		case 6:
			
		pick.fc49_obj2_L1_out_a=off_delay(fc49_obj2_L1_out_a.alarm, pick.fc49_obj2_L1_out_a,pickHold,&pick_buffer[44]);
		pick.fc49_obj2_L1_out_b=off_delay(fc49_obj2_L1_out_b.alarm, pick.fc49_obj2_L1_out_b,pickHold,&pick_buffer[45]);
		pick.fc49_obj2_L1_out_c=off_delay(fc49_obj2_L1_out_c.alarm, pick.fc49_obj2_L1_out_c,pickHold,&pick_buffer[46]);
		
		pick.fc49_obj2_L2_out_a=off_delay(fc49_obj2_L2_out_a.alarm, pick.fc49_obj2_L2_out_a,pickHold,&pick_buffer[47]);
		pick.fc49_obj2_L2_out_b=off_delay(fc49_obj2_L2_out_b.alarm, pick.fc49_obj2_L2_out_b,pickHold,&pick_buffer[48]);
		pick.fc50_obj2_L3_out_c=off_delay(fc49_obj2_L2_out_c.alarm, pick.fc49_obj2_L2_out_c,pickHold,&pick_buffer[49]);
		
		
		pick.fcBF_out=off_delay(fcBF_out.pick_up,pick.fcBF_out,pickHold,&pick_buffer[50]);
		
			
		break;
		
		case 7:
			
		pick.fc37_obj1_L1_out_a=off_delay(fc37_obj1_L1_out_a.pick_up,pick.fc37_obj1_L1_out_a,pickHold,&pick_buffer[51]);
		pick.fc37_obj1_L1_out_b=off_delay(fc37_obj1_L1_out_b.pick_up,pick.fc37_obj1_L1_out_b,pickHold,&pick_buffer[52]);
		pick.fc37_obj1_L1_out_c=off_delay(fc37_obj1_L1_out_c.pick_up,pick.fc37_obj1_L1_out_c,pickHold,&pick_buffer[53]);
		
		pick.fc37_obj2_L1_out_a=off_delay(fc37_obj2_L1_out_a.pick_up,pick.fc37_obj2_L1_out_a,pickHold,&pick_buffer[54]);
		pick.fc37_obj2_L1_out_b=off_delay(fc37_obj2_L1_out_b.pick_up,pick.fc37_obj2_L1_out_b,pickHold,&pick_buffer[55]);
		pick.fc37_obj2_L1_out_c=off_delay(fc37_obj2_L1_out_c.pick_up,pick.fc37_obj2_L1_out_c,pickHold,&pick_buffer[56]);
		
		
		break;
		
		
		case 8:
			
		pick.fcUNBd_obj1_L1_out_a=off_delay(fcUNBd_obj1_L1_out_a.pick_up,pick.fcUNBd_obj1_L1_out_a,pickHold,&pick_buffer[57]);
		pick.fcUNBd_obj1_L1_out_b=off_delay(fcUNBd_obj1_L1_out_b.pick_up,pick.fcUNBd_obj1_L1_out_b,pickHold,&pick_buffer[58]);
		
		pick.fcUNBi_obj1_L1_out_a=off_delay(fcUNBi_obj1_L1_out_a.pick_up,pick.fcUNBi_obj1_L1_out_a,pickHold,&pick_buffer[59]);
		pick.fcUNBi_obj1_L1_out_b=off_delay(fcUNBi_obj1_L1_out_b.pick_up,pick.fcUNBi_obj1_L1_out_b,pickHold,&pick_buffer[60]);
	
		
		break;
		
		
		case 9:
			
		pick.fcPVPd_obj1_L1_out_a=off_delay(fcPVPd_obj1_L1_out_a.pick_up,pick.fcPVPd_obj1_L1_out_a,pickHold,&pick_buffer[61]);
		pick.fcPVPd_obj1_L1_out_b=off_delay(fcPVPd_obj1_L1_out_b.pick_up,pick.fcPVPd_obj1_L1_out_b,pickHold,&pick_buffer[62]);
		pick.fcPVPd_obj1_L1_out_c=off_delay(fcPVPd_obj1_L1_out_c.pick_up,pick.fcPVPd_obj1_L1_out_c,pickHold,&pick_buffer[63]);
		
		pick.fcPVPi_obj1_L1_out_a=off_delay(fcPVPi_obj1_L1_out_a.pick_up,pick.fcPVPi_obj1_L1_out_a,pickHold,&pick_buffer[64]);
		pick.fcPVPi_obj1_L1_out_b=off_delay(fcPVPi_obj1_L1_out_b.pick_up,pick.fcPVPi_obj1_L1_out_b,pickHold,&pick_buffer[65]);
		pick.fcPVPi_obj1_L1_out_c=off_delay(fcPVPi_obj1_L1_out_c.pick_up,pick.fcPVPi_obj1_L1_out_c,pickHold,&pick_buffer[66]);
		
	
		break;
		
		
  }
	

	


	
	
	if(++pick_up_counter==10){pick_up_counter=0;}






}
