#include "nfbm.h"
#include "protection_functions.h"
#include "measurement_functions.h"


struct thermal_parameters fc49_obj1_therm;
struct thermal_parameters fc49_obj2_therm;

struct fc49_inputParameters fc49_obj1_L1_in;
struct fc49_inputParameters fc49_obj1_L2_in;

struct fc49_inputParameters fc49_obj2_L1_in;
struct fc49_inputParameters fc49_obj2_L2_in;


struct fc49_outputParameters fc49_obj1_L1_out_a={0};
struct fc49_outputParameters fc49_obj1_L1_out_b={0};
struct fc49_outputParameters fc49_obj1_L1_out_c={0};

struct fc49_outputParameters fc49_obj1_L2_out_a={0};
struct fc49_outputParameters fc49_obj1_L2_out_b={0};
struct fc49_outputParameters fc49_obj1_L2_out_c={0};

struct fc49_outputParameters fc49_obj2_L1_out_a={0};
struct fc49_outputParameters fc49_obj2_L1_out_b={0};
struct fc49_outputParameters fc49_obj2_L1_out_c={0};

struct fc49_outputParameters fc49_obj2_L2_out_a={0};
struct fc49_outputParameters fc49_obj2_L2_out_b={0};
struct fc49_outputParameters fc49_obj2_L2_out_c={0};


void fc49_init(){






}



void fc49_all(){
	
	static float therm_a_obj1=0;
	static float therm_b_obj1=0;
	static float therm_c_obj1=0;
	
	static float therm_a_obj2=0;
	static float therm_b_obj2=0;
	static float therm_c_obj2=0;
	
	
	therm_a_obj1=thermal_status(tRMS.Ia,fc49_obj1_therm,therm_a_obj1);
	therm_b_obj1=thermal_status(tRMS.Ib,fc49_obj1_therm,therm_a_obj1);
	therm_c_obj1=thermal_status(tRMS.Ic,fc49_obj1_therm,therm_a_obj1);
	
	therm_a_obj2=thermal_status(tRMS.IRESa,fc49_obj2_therm,therm_a_obj2);
	therm_b_obj2=thermal_status(tRMS.IRESb,fc49_obj2_therm,therm_a_obj2);
	therm_c_obj2=thermal_status(tRMS.IRESc,fc49_obj2_therm,therm_a_obj2);
	
	
	//obj1
	
	fc49(therm_a_obj1,fc49_obj1_L1_in,&fc49_obj1_L1_out_a,EN.bits.fc49_obj1_L1);
	fc49(therm_b_obj1,fc49_obj1_L1_in,&fc49_obj1_L1_out_a,EN.bits.fc49_obj1_L1);
	fc49(therm_c_obj1,fc49_obj1_L1_in,&fc49_obj1_L1_out_a,EN.bits.fc49_obj1_L1);
	
	fc49(therm_a_obj1,fc49_obj1_L2_in,&fc49_obj1_L2_out_a,EN.bits.fc49_obj1_L2);
	fc49(therm_b_obj1,fc49_obj1_L2_in,&fc49_obj1_L2_out_a,EN.bits.fc49_obj1_L2);
	fc49(therm_c_obj1,fc49_obj1_L2_in,&fc49_obj1_L2_out_a,EN.bits.fc49_obj1_L2);
	
	
	//obj2
	
	fc49(therm_a_obj2,fc49_obj2_L1_in,&fc49_obj2_L1_out_a,EN.bits.fc49_obj2_L1);
	fc49(therm_b_obj2,fc49_obj2_L1_in,&fc49_obj2_L1_out_a,EN.bits.fc49_obj2_L1);
	fc49(therm_c_obj2,fc49_obj2_L1_in,&fc49_obj2_L1_out_a,EN.bits.fc49_obj2_L1);
	
	fc49(therm_a_obj2,fc49_obj2_L2_in,&fc49_obj2_L2_out_a,EN.bits.fc49_obj2_L2);
	fc49(therm_b_obj2,fc49_obj2_L2_in,&fc49_obj2_L2_out_a,EN.bits.fc49_obj2_L2);
	fc49(therm_c_obj2,fc49_obj2_L2_in,&fc49_obj2_L2_out_a,EN.bits.fc49_obj2_L2);






}


