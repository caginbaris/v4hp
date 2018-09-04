#include "mlib_definitions.h"
#include "plib_definitions.h"
#include "cs_handles.h"
#include "nfbm.h"
#include "powerSysData.h"
#include "alarms.h"

union alarm_indications alarm={0};

void alarms(void){
	
	static uint8_t ENalarm=0;
	static long ENalarm_counter=0;

	
	static long alarm_counters[4]={0};
	
	//sequence alarms
	
	if(Sys.phaseRotation){
		
	alarm.bit.voltage_phase_seq=on_off_delay(	mag_sym.V1>mag_sym.V2,
																						alarm.bit.voltage_phase_seq,
																						fs,
																						&alarm_counters[0]);
	
	alarm.bit.current_phase_seq=on_off_delay(	mag_sym.I1>mag_sym.I2,
																						alarm.bit.current_phase_seq,
																						fs,
																						&alarm_counters[1]);
	
	}else{
		
		
	alarm.bit.voltage_phase_seq=on_off_delay(	mag_sym.V2>mag_sym.V1,
																						alarm.bit.voltage_phase_seq,
																						fs,
																						&alarm_counters[0]);
	
	alarm.bit.current_phase_seq=on_off_delay(	mag_sym.I2>mag_sym.I1,
																						alarm.bit.current_phase_seq,
																						fs,
																						&alarm_counters[1]);
	
	}
	
	//unbalance alarms
	
	alarm.bit.unbalance_a=on_off_delay(				fRMS.IUNBa>fcUNBd_obj1_L1_in.alarm_level,
																						alarm.bit.unbalance_a,
																						fs,
																						&alarm_counters[2]);	
	
	alarm.bit.unbalance_b=on_off_delay(				fRMS.IUNBb>fcUNBd_obj1_L1_in.alarm_level,
																						alarm.bit.unbalance_b,
																						fs,
																						&alarm_counters[3]);
	
	ENalarm=on_off_delay((maxSelector_3p(fRMS.Ia,fRMS.Ib,fRMS.Ic)<Sys.I_Nom_obj1*0.5f),ENalarm,fs,&ENalarm_counter);
	
	if(ENalarm){
	
	alarm.bit.current_phase_seq=0;
	alarm.bit.voltage_phase_seq=0;
	alarm.bit.unbalance_a=0;
	alarm.bit.unbalance_b=0;		
		
	}
	
	
																					
}



