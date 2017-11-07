


#ifndef PLIB_DEFINITIONS_H
#define PLIB_DEFINITIONS_H



struct fc50_inputParameters {

	float rms;
	float level;
	float dropout_ratio;
	float delay;
	float dropout_time;

};

struct fc50_outputParameters {

	long trip_counter;
	long dropout_counter;

	unsigned int initial_pick_up:1;
	unsigned int pick_up:1;
	unsigned int trip:1;
	unsigned int trip_latch:1;
	
	

};


struct fc51_inputParameters {

	float rms;
	float level;
	float curve_data[3];
	float time_multiplier;


};

struct fc51_outputParameters {

	float time2trip;
	long trip_counter;
	
	unsigned int pick_up:1;
	unsigned int trip:1;


};

struct fc27_inputParameters{

	float rms;
	float level;
	float dropout_ratio;
	float delay;
	unsigned int cs; // caution: externally set by a routine

};

struct fc27_outputParameters{

	long trip_counter;
	unsigned int pick_up:1;
	unsigned int trip:1;

};

struct fc59_inputParameters{

	float rms;
	float level;
	float dropout_ratio;
	float delay;
	unsigned int cs;

};

struct fc59_outputParameters{

	long trip_counter;
	unsigned int pick_up:1;
	unsigned int trip:1;

};

struct fc46d_inputParameters{

	float rms;
	float level;
	float delay;
	float dropout_time;
	float dropout_ratio;

};


struct fc46d_outputParameters{

	
	long trip_counter;
	long dropout_counter;

	unsigned int initial_pick_up:1;
	unsigned int pick_up:1;
	unsigned int trip:1;
	unsigned int trip_latch:1;

};

struct fc46i_inputParameters {

	float rms;
	float level;
	float curve_data[3];
	float time_multiplier;

};

struct fc46i_outputParameters {

	float time2trip;
	long trip_counter;
	
	unsigned int pick_up:1;
	unsigned int trip:1;


};

struct fc49_inputParameters{

	
	float alarm_level; 
	float trip_level; 
	float dropout_ratio;

};

struct fc49_outputParameters{

	
	unsigned int alarm:1;
	unsigned int trip:1;
	

};

struct fcBF_inputParameters{

	float rmsA;
	float rmsB;
	float rmsC;

	float threshold;
	float delay;

	

	unsigned int trip_input:1;
	unsigned int CB_pos:1;
	unsigned int CB_pos_check:1;


	

};

struct fcBF_outputParameters{

	
	long trip_counter;
	long pass_flag_counter;

	unsigned int pick_up:1;
	unsigned int current_checked:1;
	unsigned int trip:1;
	unsigned int pass_flag:1;
	unsigned int pass_flag_filtered:1;
	
	



};

struct fc37_inputParameters{

	float rms;
	float level;
	float dropout_ratio;
	float delay;
	unsigned int bs; // will be assigned to CB position

};

struct fc37_outputParameters{

	long trip_counter;
	unsigned int pick_up:1;
	unsigned int trip:1;

};


struct fcUNBd_inputParameters{

	float rms;
	float level; // vectoral difference will be used
	float dropout_ratio;
	float delay;
	

};

struct fcUNBd_outputParameters{

	long trip_counter;
	unsigned int pick_up:1;
	unsigned int trip:1;

};

struct fcUNBi_inputParameters {

	float rms;
	float level;
	float curve_data[3];
	float time_multiplier;

	
};


struct fcUNBi_outputParameters{

	float time2trip;
	long trip_counter;
	
	unsigned int pick_up:1;
	unsigned int trip:1;
};


struct fcPVPd_inputParameters{

	float rms;
	float level; // vectoral difference will be used
	float dropout_ratio;
	float delay;
	

};

struct fcPVPd_outputParameters{

	long trip_counter;
	unsigned int pick_up:1;
	unsigned int trip:1;

};


struct fcPVPi_inputParameters {

	float rms;
	float level;
	float curve_data[3];
	float time_multiplier;


};


struct fcPVPi_outputParameters{

	float time2trip;
	long trip_counter;
	
	unsigned int pick_up:1;
	unsigned int trip:1;
};


#endif
