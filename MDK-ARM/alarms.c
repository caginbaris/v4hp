#include "mlib_definitions.h"
#include "plib_definitions.h"
#include "cs_handles.h"
#include "nfbm.h"
#include "powerSysData.h"
#include "alarms.h"

union alarm_indications alarm={0};

void alarms(void){

	
	static long alarm_counters[3]={0};
	
	//sequence alarms
	
	if(Sys.phaseRotation){
		
	alarm.bit.voltage_phase_seq=on_off_delay(	mag_sym.V1>mag_sym.V2,
																						alarm.bit.voltage_phase_seq,
																						fs,
																						&alarm_counters[0]);
	
	alarm.bit.current_phase_seq=on_off_delay(	mag_sym.I1>mag_sym.I2,
																						alarm.bit.voltage_phase_seq,
																						fs,
																						&alarm_counters[1]);
	
	}else{
		
		
	alarm.bit.voltage_phase_seq=on_off_delay(	mag_sym.V2>mag_sym.V1,
																						alarm.bit.voltage_phase_seq,
																						fs,
																						&alarm_counters[0]);
	
	alarm.bit.current_phase_seq=on_off_delay(	mag_sym.I2>mag_sym.I1,
																						alarm.bit.voltage_phase_seq,
																						fs,
																						&alarm_counters[1]);
	
	}
	
	//unbalance alarms
	
	alarm.bit.unbalance=on_off_delay(					fRMS.IUNBa>fcUNBd_obj1_L1_in.alarm_level,
																						alarm.bit.unbalance,
																						fs,
																						&alarm_counters[2]);	
																					
}



