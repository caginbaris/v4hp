#ifndef externalData_H
#define externalData_H

#include "plib_handles.h"

extern struct plib_handles pick;
extern struct plib_handles trip;

union ToWord{
	
	struct plib_handles w_str;
	uint32_t w_arr[3];
	
};

extern struct spectra spect_Ia;
extern struct spectra spect_Ib;
extern struct spectra spect_Ic;



#endif

