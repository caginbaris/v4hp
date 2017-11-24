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
			
		pick.fc50_obj1_L1_out_a=off_delay(fc50_obj1_L1_out_a.pick_up, pick.fc50_obj1_L1_out_a, pickHold, &pick_buffer[count++]);
		pick.fc50_obj1_L1_out_b=off_delay(fc50_obj1_L1_out_b.pick_up, pick.fc50_obj1_L1_out_b, pickHold, &pick_buffer[count++]);	
		pick.fc50_obj1_L1_out_c=off_delay(fc50_obj1_L1_out_c.pick_up, pick.fc50_obj1_L1_out_c, pickHold, &pick_buffer[count++]);

		pick.fc50_obj1_L2_out_a=off_delay(fc50_obj1_L2_out_a.pick_up, pick.fc50_obj1_L2_out_a, pickHold, &pick_buffer[count++]);
		pick.fc50_obj1_L2_out_b=off_delay(fc50_obj1_L2_out_b.pick_up, pick.fc50_obj1_L2_out_b, pickHold, &pick_buffer[count++]);	
		pick.fc50_obj1_L2_out_c=off_delay(fc50_obj1_L2_out_c.pick_up, pick.fc50_obj1_L2_out_c, pickHold, &pick_buffer[count++]);
		
		pick.fc50N_obj1_L1_out=off_delay(fc50N_obj1_L1_out.pick_up, pick.fc50N_obj1_L1_out, pickHold, &pick_buffer[count++]);
		
  	break;
		
  	case 1:
			
		pick.fc50_obj1_L3_out_a=off_delay(fc50_obj1_L3_out_a.pick_up, pick.fc50_obj1_L3_out_a, pickHold, &pick_buffer[count++]);
		pick.fc50_obj1_L3_out_b=off_delay(fc50_obj1_L3_out_b.pick_up, pick.fc50_obj1_L3_out_b, pickHold, &pick_buffer[count++]);	
		pick.fc50_obj1_L3_out_c=off_delay(fc50_obj1_L3_out_c.pick_up, pick.fc50_obj1_L3_out_c, pickHold, &pick_buffer[count++]);
		
		pick.fc50_obj2_L1_out_a=off_delay(fc50_obj2_L1_out_a.pick_up, pick.fc50_obj2_L1_out_a, pickHold, &pick_buffer[count++]);
		pick.fc50_obj2_L1_out_b=off_delay(fc50_obj2_L1_out_b.pick_up, pick.fc50_obj2_L1_out_b, pickHold, &pick_buffer[count++]);	
		pick.fc50_obj2_L1_out_c=off_delay(fc50_obj2_L1_out_c.pick_up, pick.fc50_obj2_L1_out_c, pickHold, &pick_buffer[count++]);

		pick.fc50N_obj1_L2_out=off_delay(fc50N_obj1_L2_out.pick_up, pick.fc50N_obj1_L2_out, pickHold, &pick_buffer[count++]);
			
  	break;
		
		case 2:
			
		pick.fc50_obj2_L2_out_a=off_delay(fc50_obj2_L2_out_a.pick_up, pick.fc50_obj2_L2_out_a, pickHold, &pick_buffer[count++]);
		pick.fc50_obj2_L2_out_b=off_delay(fc50_obj2_L2_out_b.pick_up, pick.fc50_obj2_L2_out_b, pickHold, &pick_buffer[count++]);	
		pick.fc50_obj2_L2_out_c=off_delay(fc50_obj2_L2_out_c.pick_up, pick.fc50_obj2_L2_out_c, pickHold, &pick_buffer[count++]);
			
		pick.fc50_obj2_L3_out_a=off_delay(fc50_obj2_L3_out_a.pick_up, pick.fc50_obj2_L3_out_a, pickHold, &pick_buffer[count++]);
		pick.fc50_obj2_L3_out_b=off_delay(fc50_obj2_L3_out_b.pick_up, pick.fc50_obj2_L3_out_b, pickHold, &pick_buffer[count++]);	
		pick.fc50_obj2_L3_out_c=off_delay(fc50_obj2_L3_out_c.pick_up, pick.fc50_obj2_L3_out_c, pickHold, &pick_buffer[count++]);
		
		pick.fc50N_obj1_L3_out=off_delay(fc50N_obj1_L3_out.pick_up, pick.fc50N_obj1_L3_out, pickHold, &pick_buffer[count++]);
			
		break;
		
		case 3:
			
		pick.fc51_obj1_out_a=off_delay(fc51_obj1_out_a.pick_up, pick.fc51_obj1_out_a,pickHold,&pick_buffer[count++]);
		pick.fc51_obj1_out_b=off_delay(fc51_obj1_out_b.pick_up, pick.fc51_obj1_out_b,pickHold,&pick_buffer[count++]);	
		pick.fc51_obj1_out_c=off_delay(fc51_obj1_out_c.pick_up, pick.fc51_obj1_out_c,pickHold,&pick_buffer[count++]);
		
		pick.fc51_obj2_out_a=off_delay(fc51_obj2_out_a.pick_up, pick.fc51_obj2_out_a,pickHold,&pick_buffer[count++]);
		pick.fc51_obj2_out_b=off_delay(fc51_obj2_out_b.pick_up, pick.fc51_obj2_out_b,pickHold,&pick_buffer[count++]);	
		pick.fc51_obj2_out_c=off_delay(fc51_obj2_out_c.pick_up, pick.fc51_obj2_out_c,pickHold,&pick_buffer[count++]);
			
		pick.fc51N_obj1_out=off_delay(fc51N_obj1_out.pick_up, pick.fc51N_obj1_out,pickHold,&pick_buffer[count++]);
			
		
		break;
		
		
		case 4:
			
		pick.fc27_obj1_L1_out=off_delay(fc27_obj1_L1_out.pick_up, pick.fc27_obj1_L1_out,pickHold,&pick_buffer[count++]);
		pick.fc27_obj1_L2_out=off_delay(fc27_obj1_L2_out.pick_up, pick.fc27_obj1_L2_out,pickHold,&pick_buffer[count++]);
		
		pick.fc59_obj1_L1_out_a=off_delay(fc59_obj1_L1_out_a.pick_up, pick.fc59_obj1_L1_out_a,pickHold,&pick_buffer[count++]);
		pick.fc59_obj1_L1_out_b=off_delay(fc59_obj1_L1_out_b.pick_up, pick.fc59_obj1_L1_out_b,pickHold,&pick_buffer[count++]);
		pick.fc59_obj1_L1_out_c=off_delay(fc59_obj1_L1_out_c.pick_up, pick.fc59_obj1_L1_out_c,pickHold,&pick_buffer[count++]);
		
		pick.fc59_obj1_L2_out_a=off_delay(fc59_obj1_L2_out_a.pick_up, pick.fc59_obj1_L2_out_a,pickHold,&pick_buffer[count++]);
		pick.fc59_obj1_L2_out_b=off_delay(fc59_obj1_L2_out_b.pick_up, pick.fc59_obj1_L2_out_b,pickHold,&pick_buffer[count++]);
		pick.fc59_obj1_L2_out_c=off_delay(fc59_obj1_L2_out_c.pick_up, pick.fc59_obj1_L2_out_c,pickHold,&pick_buffer[count++]);

			
		break;
		
		
		case 5:
			
		pick.fc46d_obj1_L1_out=off_delay(fc46d_obj1_L1_out.pick_up, pick.fc46d_obj1_L1_out,pickHold,&pick_buffer[count++]);
		pick.fc46i_obj1_L1_out=off_delay(fc46i_obj1_L1_out.pick_up, pick.fc46i_obj1_L1_out,pickHold,&pick_buffer[count++]);
			
		pick.fc49_obj1_L1_out_a=off_delay(fc49_obj1_L1_out_a.alarm, pick.fc49_obj1_L1_out_a,pickHold,&pick_buffer[count++]);
		pick.fc49_obj1_L1_out_b=off_delay(fc49_obj1_L1_out_b.alarm, pick.fc49_obj1_L1_out_b,pickHold,&pick_buffer[count++]);
		pick.fc49_obj1_L1_out_c=off_delay(fc49_obj1_L1_out_c.alarm, pick.fc49_obj1_L1_out_c,pickHold,&pick_buffer[count++]);
		
		pick.fc49_obj1_L2_out_a=off_delay(fc49_obj1_L2_out_a.alarm, pick.fc49_obj1_L2_out_a,pickHold,&pick_buffer[count++]);
		pick.fc49_obj1_L2_out_b=off_delay(fc49_obj1_L2_out_b.alarm, pick.fc49_obj1_L2_out_b,pickHold,&pick_buffer[count++]);
		pick.fc49_obj1_L2_out_c=off_delay(fc49_obj1_L2_out_c.alarm, pick.fc49_obj1_L2_out_c,pickHold,&pick_buffer[count++]);
			
		
		break;
		
		
		case 6:
			
		pick.fc49_obj2_L1_out_a=off_delay(fc49_obj2_L1_out_a.alarm, pick.fc49_obj2_L1_out_a,pickHold,&pick_buffer[count++]);
		pick.fc49_obj2_L1_out_b=off_delay(fc49_obj2_L1_out_b.alarm, pick.fc49_obj2_L1_out_b,pickHold,&pick_buffer[count++]);
		pick.fc49_obj2_L1_out_c=off_delay(fc49_obj2_L1_out_c.alarm, pick.fc49_obj2_L1_out_c,pickHold,&pick_buffer[count++]);
		
		pick.fc49_obj2_L2_out_a=off_delay(fc49_obj2_L2_out_a.alarm, pick.fc49_obj2_L2_out_a,pickHold,&pick_buffer[count++]);
		pick.fc49_obj2_L2_out_b=off_delay(fc49_obj2_L2_out_b.alarm, pick.fc49_obj2_L2_out_b,pickHold,&pick_buffer[count++]);
		pick.fc50_obj2_L3_out_c=off_delay(fc49_obj2_L2_out_c.alarm, pick.fc49_obj2_L2_out_c,pickHold,&pick_buffer[count++]);
		
		
		pick.fcBF_out=off_delay(fcBF_out.pick_up,pick.fcBF_out,pickHold,&pick_buffer[count++]);
		
			
		break;
		
		case 7:
			
		pick.fc37_obj1_L1_out_a=off_delay(fc37_obj1_L1_out_a.pick_up,pick.fc37_obj1_L1_out_a,pickHold,&pick_buffer[count++]);
		pick.fc37_obj1_L1_out_b=off_delay(fc37_obj1_L1_out_b.pick_up,pick.fc37_obj1_L1_out_b,pickHold,&pick_buffer[count++]);
		pick.fc37_obj1_L1_out_c=off_delay(fc37_obj1_L1_out_c.pick_up,pick.fc37_obj1_L1_out_c,pickHold,&pick_buffer[count++]);
		
		pick.fc37_obj2_L1_out_a=off_delay(fc37_obj2_L1_out_a.pick_up,pick.fc37_obj2_L1_out_a,pickHold,&pick_buffer[count++]);
		pick.fc37_obj2_L1_out_b=off_delay(fc37_obj2_L1_out_b.pick_up,pick.fc37_obj2_L1_out_b,pickHold,&pick_buffer[count++]);
		pick.fc37_obj2_L1_out_c=off_delay(fc37_obj2_L1_out_c.pick_up,pick.fc37_obj2_L1_out_c,pickHold,&pick_buffer[count++]);
		
		
		break;
		
		
		case 8:
			
		pick.fcUNBd_obj1_L1_out_a=off_delay(fcUNBd_obj1_L1_out_a.pick_up,pick.fcUNBd_obj1_L1_out_a,pickHold,&pick_buffer[count++]);
		pick.fcUNBd_obj1_L1_out_b=off_delay(fcUNBd_obj1_L1_out_b.pick_up,pick.fcUNBd_obj1_L1_out_b,pickHold,&pick_buffer[count++]);
		
		pick.fcUNBi_obj1_L1_out_a=off_delay(fcUNBi_obj1_L1_out_a.pick_up,pick.fcUNBi_obj1_L1_out_a,pickHold,&pick_buffer[count++]);
		pick.fcUNBi_obj1_L1_out_b=off_delay(fcUNBi_obj1_L1_out_b.pick_up,pick.fcUNBi_obj1_L1_out_b,pickHold,&pick_buffer[count++]);
	
		
		break;
		
		
		case 9:
			
		pick.fcPVPd_obj1_L1_out_a=off_delay(fcPVPd_obj1_L1_out_a.pick_up,pick.fcPVPd_obj1_L1_out_a,pickHold,&pick_buffer[count++]);
		pick.fcPVPd_obj1_L1_out_b=off_delay(fcPVPd_obj1_L1_out_b.pick_up,pick.fcPVPd_obj1_L1_out_b,pickHold,&pick_buffer[count++]);
		pick.fcPVPd_obj1_L1_out_c=off_delay(fcPVPd_obj1_L1_out_c.pick_up,pick.fcPVPd_obj1_L1_out_c,pickHold,&pick_buffer[count++]);
		
		pick.fcPVPi_obj1_L1_out_a=off_delay(fcPVPi_obj1_L1_out_a.pick_up,pick.fcPVPi_obj1_L1_out_a,pickHold,&pick_buffer[count++]);
		pick.fcPVPi_obj1_L1_out_b=off_delay(fcPVPi_obj1_L1_out_b.pick_up,pick.fcPVPi_obj1_L1_out_b,pickHold,&pick_buffer[count++]);
		pick.fcPVPi_obj1_L1_out_c=off_delay(fcPVPi_obj1_L1_out_c.pick_up,pick.fcPVPi_obj1_L1_out_c,pickHold,&pick_buffer[count++]);
		
		count=0;
	
		break;
		
		
  }
	

	


	
	
	if(++pick_up_counter==10){pick_up_counter=0;}






}
