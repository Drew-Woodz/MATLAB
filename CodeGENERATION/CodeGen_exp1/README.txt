README

.../CodeGen_exp1


demonstration build


contents

.../Codegen_exp1
/proof                  
   ...                     -  previously generated C code for testingModel
codeGen.m		-  the codeGen function
testingModel.sxl	-  the dummy model
README.txt		-  you are here



this project is to demonstrate the CodeGen function. included is a dummy model testingModel.slx.
this is intended to be the simplest implementation of the codeGen function possible. 

to run, copy the codeGen.m and testingModel.slx to a new folder. set your MATLAB path to that folder
then ensure it is your current working directory.

from the MATLAB command line, enter: codeGen('testingMosdel') and press enter.

the function will take the model and produce a reference model file as well as directories for code 
generation, then populate those directories with C code and the dependencies required for a reusable function


andrew lockwood
andrew.lockwood@ngc.com
08/11/22