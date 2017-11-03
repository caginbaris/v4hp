
#ifndef MLIB_DEFINITIONS_H
#define MLIB_DEFINITIONS_H



struct phase_cs_in{

		float Vc;
		float Vs;
		float Ic;
		float Is;
};

struct phase_cs_out{

		float rms_V;
		float rms_V2;
		float rms_I;
		float rms_I2;
		float P;
		float Q;
		float X;
		float R;	
		float phase_V;
		float phase_I;
		float phase_disp;

};

struct sym_out{

	
	float V1;
	float V2;
	float V0;

	float I1;
	float I2;
	float I0;

};


struct spectra {

	float qBuffer[100];
	float foutReal[13];
	float foutImag[13];
	float foutMag[13];

};



struct pvp_data{

	float a;
	float b;
	float c;

};



struct thermal_parameters{

	float rms;
	float Inom; // 0.1 to 4*Inom- def 1.1 k-factor*Inom_obj
	float tau;
	float ts;
	unsigned int freeze;

};







#endif
