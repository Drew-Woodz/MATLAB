README

.../CodeGen

internship project to produce a MATLAB function that generates C code automatically  with a given Simulink model.



contents
.../CodeGen
codeGen.m                                     -  the codeGen function
Generating_C_Code_for_Simulink_models.docx    -  GUI code generation instructions
README.txt                                    -  you are here

%Build
%CodeGen Script v0.23%
%codeGen.m
%08/10/2022



%**************************************************************************%
%                                                                          %
%            ***IMPORTANT - Create Model Backup before use***              %
%                                                                          %
%                                                                          %
%                                                                          %
%In order to generate C code with reusable functions, this codeGen function%
%creates a referenced model from the top most subsystem then replaces that %
%subsystem with the referenced model. This top most subsystem must contain %
%the entirety of the model to be converted with only those In's and Out's  %
%expected as parameters and returns to and from the C function. Once this  %
%function has run, there will be a referenced model for the given model.   %
%                                                                          %
%There can not be an existing referenced model for the given model or the  %
%build will fail.                                                          %
%                                                                          %
%Generated code and model reference will be generated in the current       %
%working directory.  " .../MyModel_ert_rtw "                               %
%                                                                          %
%                                                                          %
%                            ***IMPORTANT***                               %
%                 failure to backup your model may result                  %
%                  in irreversible changes to your model.                  %
%       ***Backup your Model before handing to this function.***           %
%                 if this function fails, you may need to                  %
%                  restore the model before trying again.                  %
%                                                                          %
%**************************************************************************%



andrew lockwood
andrew.lockwood@ngc.com
08/11/22