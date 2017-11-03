#include "nfbm.h"
#include "protection_functions.h"

// input parameters------------------------------

struct fc50_inputParameters fc50_obj1_L1_in;
struct fc50_inputParameters fc50_obj1_L2_in;
struct fc50_inputParameters fc50_obj1_L3_in;

struct fc50_inputParameters fc50_obj2_L1_in;
struct fc50_inputParameters fc50_obj2_L2_in;
struct fc50_inputParameters fc50_obj2_L3_in;

// output parameters------------------------------

// L1 obj1

struct fc50_outputParameters fc50_obj1_L1_out_a;
struct fc50_outputParameters fc50_obj1_L1_out_b;
struct fc50_outputParameters fc50_obj1_L1_out_c;

// L2 obj1

struct fc50_outputParameters fc50_obj1_L2_out_a;
struct fc50_outputParameters fc50_obj1_L2_out_b;
struct fc50_outputParameters fc50_obj1_L2_out_c;

// L3 obj1 

struct fc50_outputParameters fc50_obj1_L3_out_a;
struct fc50_outputParameters fc50_obj1_L3_out_b;
struct fc50_outputParameters fc50_obj1_L3_out_c;

// L1 obj2

struct fc50_outputParameters fc50_obj1_L1_out_a;
struct fc50_outputParameters fc50_obj1_L1_out_b;
struct fc50_outputParameters fc50_obj1_L1_out_c;

// L2 obj2

struct fc50_outputParameters fc50_obj1_L2_out_a;
struct fc50_outputParameters fc50_obj1_L2_out_b;
struct fc50_outputParameters fc50_obj1_L2_out_c;

// L3 obj2

struct fc50_outputParameters fc50_obj1_L3_out_a;
struct fc50_outputParameters fc50_obj1_L3_out_b;
struct fc50_outputParameters fc50_obj1_L3_out_c;







void fc50_init(){





}

void fc50_all(){
	
	if(selectRMS.bits.fc50_obj1_L1){
		
		fc50_obj1_L1_in.rms=tRMS.Ia;
	
	}
	
	
	
	
	
	fc50(fc50_obj1_L1_in,&fc50_obj1_L1_out_a,EN.bits.fc50_obj1_L1);
	fc50(fc50_obj1_L1_in,&fc50_obj1_L1_out_b,EN.bits.fc50_obj1_L1);
	fc50(fc50_obj1_L1_in,&fc50_obj1_L1_out_c,EN.bits.fc50_obj1_L1);





}