README

.../CodeGen_exp2


demonstration build


contents

.../Codegen_exp2
/proof                  
   ...                     -  previously generated C code for eph_model
codeGen.m		-  the codeGen function
eph_model.slx		-  the ephemeris2satpos model
model_variables.m	-  required constants, load into MATLAB workspace
mybus.mat		-  required bus 



this project is to demonstrate the CodeGen function. included is the ephemeris2satpos model
this is intended to be a more complex implementation of the codeGen function.. 

to run, copy the codeGen.m, eph_model.slx, model_variables.m, and mybus.mat files to a new 
folder. set your MATLAB path to that folder then ensure it is your current working directory.
load model_variables.m and mybus.mat into the MATLAB workspace.

from the MATLAB command line, enter: codeGen('eph_model') and press enter.

the function will take the model and produce a reference model file as well as directories for
code generation then populate those directories with C code and the dependencies required for
a reusable function.



andrew lockwood
andrew.lockwood@ngc.com
08/11/22