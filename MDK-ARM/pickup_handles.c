#include "nfbm.h"
#include "plib_handles.h"
#include "protection_functions.h"

#define totalPick 67
#define pickHold 10

struct plib_handles pick={0};
struct plib_handles trip={0};

static long pick_buffer[totalPick]={0};



void pick_up_handles(){
	
	static uint8_t pick_up_counter=0;
	
	
	
	switch (pick_up_counter)
  {
  	case 0:
			
		pick.fc50_obj1_L1_out_a=off_delay(fc50_obj1_L1_out_a.pick_up, pick.fc50_obj1_L1_out_a, pickHold, &pick_buffer[0]);/**/trip.fc50_obj1_L1_out_a=fc50_obj1_L1_out_a.trip_latch;
		pick.fc50_obj1_L1_out_b=off_delay(fc50_obj1_L1_out_b.pick_up, pick.fc50_obj1_L1_out_b, pickHold, &pick_buffer[1]);/**/trip.fc50_obj1_L1_out_b=fc50_obj1_L1_out_b.trip_latch;	
		pick.fc50_obj1_L1_out_c=off_delay(fc50_obj1_L1_out_c.pick_up, pick.fc50_obj1_L1_out_c, pickHold, &pick_buffer[2]);/**/trip.fc50_obj1_L1_out_c=fc50_obj1_L1_out_c.trip_latch;

		pick.fc50_obj1_L2_out_a=off_delay(fc50_obj1_L2_out_a.pick_up, pick.fc50_obj1_L2_out_a, pickHold, &pick_buffer[3]);/**/trip.fc50_obj1_L2_out_a=fc50_obj1_L2_out_a.trip_latch;
		pick.fc50_obj1_L2_out_b=off_delay(fc50_obj1_L2_out_b.pick_up, pick.fc50_obj1_L2_out_b, pickHold, &pick_buffer[4]);/**/trip.fc50_obj1_L2_out_b=fc50_obj1_L2_out_b.trip_latch;	
		pick.fc50_obj1_L2_out_c=off_delay(fc50_obj1_L2_out_c.pick_up, pick.fc50_obj1_L2_out_c, pickHold, &pick_buffer[5]);/**/trip.fc50_obj1_L2_out_c=fc50_obj1_L2_out_c.trip_latch;
		
		pick.fc50N_obj1_L1_out=off_delay(fc50N_obj1_L1_out.pick_up, pick.fc50N_obj1_L1_out, pickHold, &pick_buffer[6]);/**/trip.fc50N_obj1_L1_out=fc50N_obj1_L1_out.trip_latch;
		
  	break;
		
  	case 1:
			
		pick.fc50_obj1_L3_out_a=off_delay(fc50_obj1_L3_out_a.pick_up, pick.fc50_obj1_L3_out_a, pickHold, &pick_buffer[7]);/**/trip.fc50_obj1_L3_out_a=fc50_obj1_L3_out_a.trip_latch;
		pick.fc50_obj1_L3_out_b=off_delay(fc50_obj1_L3_out_b.pick_up, pick.fc50_obj1_L3_out_b, pickHold, &pick_buffer[8]);/**/trip.fc50_obj1_L3_out_b=fc50_obj1_L3_out_b.trip_latch;	
		pick.fc50_obj1_L3_out_c=off_delay(fc50_obj1_L3_out_c.pick_up, pick.fc50_obj1_L3_out_c, pickHold, &pick_buffer[9]);/**/trip.fc50_obj1_L3_out_c=fc50_obj1_L3_out_c.trip_latch;	
		
		pick.fc50_obj2_L1_out_a=off_delay(fc50_obj2_L1_out_a.pick_up, pick.fc50_obj2_L1_out_a, pickHold, &pick_buffer[10]);/**/trip.fc50_obj2_L1_out_a=fc50_obj2_L1_out_a.trip_latch;	
		pick.fc50_obj2_L1_out_b=off_delay(fc50_obj2_L1_out_b.pick_up, pick.fc50_obj2_L1_out_b, pickHold, &pick_buffer[11]);/**/trip.fc50_obj2_L1_out_b=fc50_obj2_L1_out_b.trip_latch;		
		pick.fc50_obj2_L1_out_c=off_delay(fc50_obj2_L1_out_c.pick_up, pick.fc50_obj2_L1_out_c, pickHold, &pick_buffer[12]);/**/trip.fc50_obj2_L1_out_c=fc50_obj2_L1_out_c.trip_latch;	

		pick.fc50N_obj1_L2_out=off_delay(fc50N_obj1_L2_out.pick_up, pick.fc50N_obj1_L2_out, pickHold, &pick_buffer[13]);/**/trip.fc50N_obj1_L2_out=fc50N_obj1_L2_out.trip_latch;
			
  	break;
		
		case 2:
			
		pick.fc50_obj2_L2_out_a=off_delay(fc50_obj2_L2_out_a.pick_up, pick.fc50_obj2_L2_out_a, pickHold, &pick_buffer[14]);/**/trip.fc50_obj2_L2_out_a=fc50_obj2_L2_out_a.trip_latch;	
		pick.fc50_obj2_L2_out_b=off_delay(fc50_obj2_L2_out_b.pick_up, pick.fc50_obj2_L2_out_b, pickHold, &pick_buffer[15]);/**/trip.fc50_obj2_L2_out_b=fc50_obj2_L2_out_b.trip_latch;		
		pick.fc50_obj2_L2_out_c=off_delay(fc50_obj2_L2_out_c.pick_up, pick.fc50_obj2_L2_out_c, pickHold, &pick_buffer[16]);/**/trip.fc50_obj2_L2_out_c=fc50_obj2_L2_out_c.trip_latch;	
			
		pick.fc50_obj2_L3_out_a=off_delay(fc50_obj2_L3_out_a.pick_up, pick.fc50_obj2_L3_out_a, pickHold, &pick_buffer[17]);/**/trip.fc50_obj2_L3_out_a=fc50_obj2_L3_out_a.trip_latch;	
		pick.fc50_obj2_L3_out_b=off_delay(fc50_obj2_L3_out_b.pick_up, pick.fc50_obj2_L3_out_b, pickHold, &pick_buffer[18]);/**/trip.fc50_obj2_L3_out_b=fc50_obj2_L3_out_b.trip_latch;		
		pick.fc50_obj2_L3_out_c=off_delay(fc50_obj2_L3_out_c.pick_up, pick.fc50_obj2_L3_out_c, pickHold, &pick_buffer[19]);/**/trip.fc50_obj2_L3_out_c=fc50_obj2_L3_out_c.trip_latch;	
		
		pick.fc50N_obj1_L3_out=off_delay(fc50N_obj1_L3_out.pick_up, pick.fc50N_obj1_L3_out, pickHold, &pick_buffer[20]);/**/trip.fc50N_obj1_L3_out=fc50N_obj1_L3_out.trip_latch;	
			
		break;
		
		case 3:
			
		pick.fc51_obj1_out_a=off_delay(fc51_obj1_out_a.pick_up, pick.fc51_obj1_out_a,pickHold,&pick_buffer[21]);/**/trip.fc51_obj1_out_a=fc51_obj1_out_a.trip;
		pick.fc51_obj1_out_b=off_delay(fc51_obj1_out_b.pick_up, pick.fc51_obj1_out_b,pickHold,&pick_buffer[22]);/**/trip.fc51_obj1_out_b=fc51_obj1_out_b.trip;	
		pick.fc51_obj1_out_c=off_delay(fc51_obj1_out_c.pick_up, pick.fc51_obj1_out_c,pickHold,&pick_buffer[23]);/**/trip.fc51_obj1_out_c=fc51_obj1_out_c.trip;
		
		pick.fc51_obj2_out_a=off_delay(fc51_obj2_out_a.pick_up, pick.fc51_obj2_out_a,pickHold,&pick_buffer[24]);/**/trip.fc51_obj2_out_a=fc51_obj2_out_a.trip;
		pick.fc51_obj2_out_b=off_delay(fc51_obj2_out_b.pick_up, pick.fc51_obj2_out_b,pickHold,&pick_buffer[25]);/**/trip.fc51_obj2_out_b=fc51_obj2_out_b.trip;	
		pick.fc51_obj2_out_c=off_delay(fc51_obj2_out_c.pick_up, pick.fc51_obj2_out_c,pickHold,&pick_buffer[26]);/**/trip.fc51_obj2_out_c=fc51_obj2_out_c.trip;
			
		pick.fc51N_obj1_out=off_delay(fc51N_obj1_out.pick_up, pick.fc51N_obj1_out,pickHold,&pick_buffer[27]);/**/trip.fc51N_obj1_out=fc51N_obj1_out.trip;
			
		
		break;
		
		
		case 4:
			
		pick.fc27_obj1_L1_out=off_delay(fc27_obj1_L1_out.pick_up, pick.fc27_obj1_L1_out,pickHold,&pick_buffer[28]);/**/trip.fc27_obj1_L1_out=fc27_obj1_L1_out.trip;
		pick.fc27_obj1_L2_out=off_delay(fc27_obj1_L2_out.pick_up, pick.fc27_obj1_L2_out,pickHold,&pick_buffer[29]);/**/trip.fc27_obj1_L2_out=fc27_obj1_L2_out.trip;
		
		pick.fc59_obj1_L1_out_a=off_delay(fc59_obj1_L1_out_a.pick_up, pick.fc59_obj1_L1_out_a,pickHold,&pick_buffer[30]);/**/trip.fc59_obj1_L1_out_a=fc59_obj1_L1_out_a.trip;
		pick.fc59_obj1_L1_out_b=off_delay(fc59_obj1_L1_out_b.pick_up, pick.fc59_obj1_L1_out_b,pickHold,&pick_buffer[31]);/**/trip.fc59_obj1_L1_out_b=fc59_obj1_L1_out_b.trip;
		pick.fc59_obj1_L1_out_c=off_delay(fc59_obj1_L1_out_c.pick_up, pick.fc59_obj1_L1_out_c,pickHold,&pick_buffer[32]);/**/trip.fc59_obj1_L1_out_c=fc59_obj1_L1_out_c.trip;
		
		pick.fc59_obj1_L2_out_a=off_delay(fc59_obj1_L2_out_a.pick_up, pick.fc59_obj1_L2_out_a,pickHold,&pick_buffer[33]);/**/trip.fc59_obj1_L2_out_a=fc59_obj1_L2_out_a.trip;
		pick.fc59_obj1_L2_out_b=off_delay(fc59_obj1_L2_out_b.pick_up, pick.fc59_obj1_L2_out_b,pickHold,&pick_buffer[34]);/**/trip.fc59_obj1_L2_out_b=fc59_obj1_L2_out_b.trip;
		pick.fc59_obj1_L2_out_c=off_delay(fc59_obj1_L2_out_c.pick_up, pick.fc59_obj1_L2_out_c,pickHold,&pick_buffer[35]);/**/trip.fc59_obj1_L2_out_c=fc59_obj1_L2_out_c.trip;

			
		break;
		
		
		case 5:
			
		pick.fc46d_obj1_L1_out=off_delay(fc46d_obj1_L1_out.pick_up, pick.fc46d_obj1_L1_out,pickHold,&pick_buffer[36]);/**/trip.fc46d_obj1_L1_out=fc46d_obj1_L1_out.trip_latch;
		pick.fc46i_obj1_L1_out=off_delay(fc46i_obj1_L1_out.pick_up, pick.fc46i_obj1_L1_out,pickHold,&pick_buffer[37]);/**/trip.fc46i_obj1_L1_out=fc46i_obj1_L1_out.trip;
			
		pick.fc49_obj1_L1_out_a=off_delay(fc49_obj1_L1_out_a.alarm, pick.fc49_obj1_L1_out_a,pickHold,&pick_buffer[38]);/**/trip.fc49_obj1_L1_out_a=fc49_obj1_L1_out_a.trip;
		pick.fc49_obj1_L1_out_b=off_delay(fc49_obj1_L1_out_b.alarm, pick.fc49_obj1_L1_out_b,pickHold,&pick_buffer[39]);/**/trip.fc49_obj1_L1_out_b=fc49_obj1_L1_out_b.trip;
		pick.fc49_obj1_L1_out_c=off_delay(fc49_obj1_L1_out_c.alarm, pick.fc49_obj1_L1_out_c,pickHold,&pick_buffer[40]);/**/trip.fc49_obj1_L1_out_c=fc49_obj1_L1_out_c.trip;
		
		pick.fc49_obj1_L2_out_a=off_delay(fc49_obj1_L2_out_a.alarm, pick.fc49_obj1_L2_out_a,pickHold,&pick_buffer[41]);/**/trip.fc49_obj1_L2_out_a=fc49_obj1_L2_out_a.trip;
		pick.fc49_obj1_L2_out_b=off_delay(fc49_obj1_L2_out_b.alarm, pick.fc49_obj1_L2_out_b,pickHold,&pick_buffer[42]);/**/trip.fc49_obj1_L2_out_b=fc49_obj1_L2_out_b.trip;
		pick.fc49_obj1_L2_out_c=off_delay(fc49_obj1_L2_out_c.alarm, pick.fc49_obj1_L2_out_c,pickHold,&pick_buffer[43]);/**/trip.fc49_obj1_L2_out_c=fc49_obj1_L2_out_c.trip;			
		
		break;
		
		
		case 6:
			
		pick.fc49_obj2_L1_out_a=off_delay(fc49_obj2_L1_out_a.alarm, pick.fc49_obj2_L1_out_a,pickHold,&pick_buffer[44]);/**/trip.fc49_obj2_L1_out_a=fc49_obj2_L1_out_a.trip;
		pick.fc49_obj2_L1_out_b=off_delay(fc49_obj2_L1_out_b.alarm, pick.fc49_obj2_L1_out_b,pickHold,&pick_buffer[45]);/**/trip.fc49_obj2_L1_out_b=fc49_obj2_L1_out_b.trip;
		pick.fc49_obj2_L1_out_c=off_delay(fc49_obj2_L1_out_c.alarm, pick.fc49_obj2_L1_out_c,pickHold,&pick_buffer[46]);/**/trip.fc49_obj2_L1_out_c=fc49_obj2_L1_out_c.trip;
		
		pick.fc49_obj2_L2_out_a=off_delay(fc49_obj2_L2_out_a.alarm, pick.fc49_obj2_L2_out_a,pickHold,&pick_buffer[47]);/**/trip.fc49_obj2_L2_out_a=fc49_obj2_L2_out_a.trip;
		pick.fc49_obj2_L2_out_b=off_delay(fc49_obj2_L2_out_b.alarm, pick.fc49_obj2_L2_out_b,pickHold,&pick_buffer[48]);/**/trip.fc49_obj2_L2_out_b=fc49_obj2_L2_out_b.trip;
		pick.fc49_obj2_L2_out_c=off_delay(fc49_obj2_L2_out_c.alarm, pick.fc49_obj2_L2_out_c,pickHold,&pick_buffer[49]);/**/trip.fc49_obj2_L2_out_c=fc49_obj2_L2_out_c.trip;
		
		
		pick.fcBF_out=off_delay(fcBF_out.pick_up,pick.fcBF_out,pickHold,&pick_buffer[50]);/**/trip.fcBF_out=fcBF_out.trip;
		
			
		break;
		
		case 7:
			
		pick.fc37_obj1_L1_out_a=off_delay(fc37_obj1_L1_out_a.pick_up,pick.fc37_obj1_L1_out_a,pickHold,&pick_buffer[51]);/**/trip.fc37_obj1_L1_out_a=fc37_obj1_L1_out_a.trip;
		pick.fc37_obj1_L1_out_b=off_delay(fc37_obj1_L1_out_b.pick_up,pick.fc37_obj1_L1_out_b,pickHold,&pick_buffer[52]);/**/trip.fc37_obj1_L1_out_b=fc37_obj1_L1_out_b.trip;
		pick.fc37_obj1_L1_out_c=off_delay(fc37_obj1_L1_out_c.pick_up,pick.fc37_obj1_L1_out_c,pickHold,&pick_buffer[53]);/**/trip.fc37_obj1_L1_out_c=fc37_obj1_L1_out_c.trip;
		
		pick.fc37_obj2_L1_out_a=off_delay(fc37_obj2_L1_out_a.pick_up,pick.fc37_obj2_L1_out_a,pickHold,&pick_buffer[54]);/**/trip.fc37_obj2_L1_out_a=fc37_obj2_L1_out_a.trip;
		pick.fc37_obj2_L1_out_b=off_delay(fc37_obj2_L1_out_b.pick_up,pick.fc37_obj2_L1_out_b,pickHold,&pick_buffer[55]);/**/trip.fc37_obj2_L1_out_b=fc37_obj2_L1_out_b.trip;
		pick.fc37_obj2_L1_out_c=off_delay(fc37_obj2_L1_out_c.pick_up,pick.fc37_obj2_L1_out_c,pickHold,&pick_buffer[56]);/**/trip.fc37_obj2_L1_out_c=fc37_obj2_L1_out_c.trip;
		
		
		break;
		
		
		case 8:
			
		pick.fcUNBd_obj1_L1_out_a=off_delay(fcUNBd_obj1_L1_out_a.pick_up,pick.fcUNBd_obj1_L1_out_a,pickHold,&pick_buffer[57]);/**/trip.fcUNBd_obj1_L1_out_a=fcUNBd_obj1_L1_out_a.trip;
		pick.fcUNBd_obj1_L1_out_b=off_delay(fcUNBd_obj1_L1_out_b.pick_up,pick.fcUNBd_obj1_L1_out_b,pickHold,&pick_buffer[58]);/**/trip.fcUNBd_obj1_L1_out_b=fcUNBd_obj1_L1_out_b.trip;
		
		pick.fcUNBi_obj1_L1_out_a=off_delay(fcUNBi_obj1_L1_out_a.pick_up,pick.fcUNBi_obj1_L1_out_a,pickHold,&pick_buffer[59]);/**/trip.fcUNBi_obj1_L1_out_a=fcUNBi_obj1_L1_out_a.trip;
		pick.fcUNBi_obj1_L1_out_b=off_delay(fcUNBi_obj1_L1_out_b.pick_up,pick.fcUNBi_obj1_L1_out_b,pickHold,&pick_buffer[60]);/**/trip.fcUNBi_obj1_L1_out_b=fcUNBi_obj1_L1_out_b.trip;
	
		
		break;
		
		
		case 9:
			
		pick.fcPVPd_obj1_L1_out_a=off_delay(fcPVPd_obj1_L1_out_a.pick_up,pick.fcPVPd_obj1_L1_out_a,pickHold,&pick_buffer[61]);/**/trip.fcPVPd_obj1_L1_out_a=fcPVPd_obj1_L1_out_a.trip;
		pick.fcPVPd_obj1_L1_out_b=off_delay(fcPVPd_obj1_L1_out_b.pick_up,pick.fcPVPd_obj1_L1_out_b,pickHold,&pick_buffer[62]);/**/trip.fcPVPd_obj1_L1_out_b=fcPVPd_obj1_L1_out_b.trip;
		pick.fcPVPd_obj1_L1_out_c=off_delay(fcPVPd_obj1_L1_out_c.pick_up,pick.fcPVPd_obj1_L1_out_c,pickHold,&pick_buffer[63]);/**/trip.fcPVPd_obj1_L1_out_c=fcPVPd_obj1_L1_out_c.trip;
		
		pick.fcPVPi_obj1_L1_out_a=off_delay(fcPVPi_obj1_L1_out_a.pick_up,pick.fcPVPi_obj1_L1_out_a,pickHold,&pick_buffer[64]);/**/trip.fcPVPi_obj1_L1_out_a=fcPVPi_obj1_L1_out_a.trip;
		pick.fcPVPi_obj1_L1_out_b=off_delay(fcPVPi_obj1_L1_out_b.pick_up,pick.fcPVPi_obj1_L1_out_b,pickHold,&pick_buffer[65]);/**/trip.fcPVPi_obj1_L1_out_b=fcPVPi_obj1_L1_out_b.trip;
		pick.fcPVPi_obj1_L1_out_c=off_delay(fcPVPi_obj1_L1_out_c.pick_up,pick.fcPVPi_obj1_L1_out_c,pickHold,&pick_buffer[66]);/**/trip.fcPVPi_obj1_L1_out_c=fcPVPi_obj1_L1_out_c.trip;
		
	
		break;
		
		
  }
	
	

	if(++pick_up_counter==10){pick_up_counter=0;}






}
