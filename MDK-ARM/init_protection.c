#include "nfbm.h"


union pFunctionEnable EN;
union rms_selection selectRMS;

struct curve_selection selectCURVE;
enum  curve_entry curve;

float curve_data[11][3]={
	
	{ 0.14f, 0.02f , 0.0f}, 					// IEC Inverse
	{13.5f,  1.0f  , 0.0f},						// IEC Very Inverse
	{80.0f,  2.0f  , 0.0f},						// IEC Extremely Inverse
	{120.0f, 1.0f  , 0.0f},						// IEC Long IInverse
	
	{ 8.9341f, 2.02938f , 0.17966f}, 	// ANSI Inverse
	{ 0.2663f, 1.2969f 	, 0.03393f}, 	// ANSI Short Inverse
	{ 5.6143f, 1.0f 		, 2.18592f}, 	// ANSI Long Inverse
	{ 0.0103f, 0.02f 		, 0.0228f}, 	// ANSI Moderately Inverse
	{ 3.922f,  2.0f 		, 0.0982f}, 	// ANSI Very Inverse
	{ 5.64f,   2.0f 		, 0.02434f}, 	// ANSI Extremely Inverse
	{ 0.4797f, 1.5625f 	, 0.21359f}, 	// ANSI Definite Inverse



};




