///Header///
//
//ert_main_test.c
//
//this main program file is used to demonstrate the calling of a Simulink generated C function
//when executed the program will call the eph2satpos_Function and pass it the generated structure
//with test ephemerise data. the function is also passed the output which when complete will print 
//to the display the ephemeris data.
//
//To compile from the command line, the gcc command is:
//gcc ert_main_test2.c eph2satpos_mdl.c eph2satpos_Function.c rt_nonfinite.c rt_powd_snf.c rtGetInf.c rtGetNaN.c rt_atan2d_snf.c -o eph
//
//To run the program, the command is:
//eph
//
//
//
//
//

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "eph2satpos_mdl.h"            /* Model header file */

static RT_MODEL_eph2satpos_mdl_T eph2satpos_mdl_M_;
static RT_MODEL_eph2satpos_mdl_T *const eph2satpos_mdl_MPtr = &eph2satpos_mdl_M_;/* Real-time model */

/* '<Root>/In1' */
static mybus rtu_In1;

/* '<Root>/SV_ecef' */
static real_T rty_SV_ecef[3];
void eph2satpos_Function(const mybus *rtu_In1, real_T rty_SV_ecef[3]);

//main
int main (){
	
	// load mybus object with test ephemeris data
  rtu_In1.toc_		= 525600.0000134110;
  rtu_In1.af0		= 0.0004690550267700000;
  rtu_In1.af1		= -0.00000000001000444171950000;
  rtu_In1.af2  		= 0;
  rtu_In1.Crs		= -137.7812500000000;
  rtu_In1.deltan	= 0.000000004009809881820000;
  rtu_In1.Mo		= 0.425959991538000;
  rtu_In1.Cuc		= -0.000007105991244320000;
  rtu_In1.e			= 0.011218535946700;
  rtu_In1.Cus		= 0.000004127621650700000;
  rtu_In1.a			= 26560375.51302242;
  rtu_In1.toe		= 525600;
  rtu_In1.Cic		= -0.00000008381903171540000;
  rtu_In1.omega0	= -1.036670036230000;
  rtu_In1.Cis		= 0.0000001229345798490000;
  rtu_In1.io		= 0.986415988482000;
  rtu_In1.Crc		= 312.2812500000000;
  rtu_In1.w			= 0.884008384555000;
  rtu_In1.omegaD	= -0.000000008161768541850000;
  rtu_In1.didt		= -0.0000000003832302487920000;
  rtu_In1.tGd		= 0.000000005122274160390000;

//call eph2satpos_Function
//eph2satpos_Function(&rtu_In1, rty_SV_ecef);
  eph2satpos_Function(&rtu_In1, rty_SV_ecef);
	  //FOR TEST OUTPUT
  //Printf for ecef output
  char arr[3];
       arr[0] = 'x';
       arr[1] = 'y';
       arr[2] = 'z';
	printf("ecef:\n");   
	for(int i = 0; i <= 2; i++){
		printf("%c = %f\n", arr[i], rty_SV_ecef[i]);
	}

	
	
	return 0;
	//end program
}