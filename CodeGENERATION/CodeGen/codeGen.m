%Build
%CodeGen Script v0.23%
%codeGen.m
%08/10/2022
%function codeGen(build)
%
%            ***IMPORTANT - Create Model Backup before use***
%
%
%
%In order to generate C code with reusable functions, this codeGen function
%creates a referenced model from the top most subsystem then replaces that
%subsystem with the referenced model. This top most subsystem must contain
%the entirety of the model to be converted with only those In's and Out's
%expected as parameters and returns to and from the C function. Once this
%function has run, there will be a referenced model for the given model.
%
%There can not be an existing referenced model for the given model or the
%build will fail.
% 
%Generated code and model reference will be generated in the current
%working directory.  " .../MyModel_ert_rtw " 
%
%
%                            ***IMPORTANT***
%                 failure to backup your model may result
%                  in irreversible changes to your model.
%       ***Backup your Model before handing to this function.***
%                 if this function fails, you may need to
%                  restore the model before trying again.
%
%*************************************************************************%

%function codeGen('model')
function codeGen(mdl)   

    %display build directory
      %
      %for code location, the build directory prints to screen
      %
        wd = pwd();
        disp('Current Working Directory is: ');
        disp(wd);
        disp('Code directory will be built here.');
    
    %open model
      %
      %open_system() is commented to suppress the Simulink model from opening
      %load_system() loads the model into memory without opening the model
      %
        %disp('Opening model...');
        %open_system(mdl);
        disp('Loading model...');
        load_system(mdl);
      
    
    %get subsystem
        %        ***model reference naming determined here***
        %
        %in order to generate reusable functions the top-level subsystem
        %will later be passed to a model reference generation function. 
        %Simulink.SubSystem.convertToModelReference('SubSystem',mdl);
        %
        %To do this we need to know this top-level subsystem's name.
        %
        %the following identifies the subsystem's name and trims the string for
        %later use.
        %
        %identify top-level subsystem
        y = find_system(mdl,'SearchDepth',1,'BlockType','SubSystem');
        z =char(y);
        %disp(z);

        %resulting srting subSys is used for SubSystem identification and
        %model reference naming
        subSys = extractAfter(z,"/");
        %disp(subSys);
    
    %referenced model naming
        %resulting string refmdl is used for model reference naming
        refmdl = strcat(subSys,'_RefMdl');
        %disp(refmdl);
    
    
    %configure subsystem parameters
        %
        %here, the top-level subsystem parameters are configured for
        %reusable functions. Treat as Atomic must be set to on for Reusable
        %function to be availible.
        %
        disp('Configuring model for C code Generation...');
        disp('Configuring top-level subsystem...');
        set_param(z, ...
          'TreatAsAtomicUnit', 'on',...
          'RTWSystemCode', 'Reusable function', ...
          'RTWFcnNameOpts', 'Use subsystem name', ...
          'RTWFcnName', '<function name>',...
          'RTWFileNameOpts', 'Use function name',...
          'RTWFileName', '<file name>');
    
    
     %configure model
        %
        %
        %in order for code to generate as expected, the following
        %name-value pairs are passed to set_param and implimented 
        %in the top models configuration parameters.
        %
        %for code generation to succeed the top model and model reference
        %must have the same configuration parameter settings. the settings
        %for the parent model will filter down to child models including 
        %the reference model generated after this configuration.
        %
        %the order of these steps matters. configure the model for code
        %generation BEFORE converting the subsystem to a reference model.
        %
        disp('Configuring top model...');
        set_param(mdl,...
            'SolverType', 'Fixed-step',...
            'SystemTargetFile','ert.tlc',...
            'GenCodeOnly','on',...
            'BuildConfiguration', 'Faster Runs',...
            'UseFloatMulNetSlope', 'on',...
            'GainParamInheritBuiltInType', 'on',...
            'UseDivisionForNetSlopeComputation', 'on',...
            'ObjectivePriorities','Execution efficiency',...
            'DefaultParameterBehavior','Tunable',...
            'ZeroExternalMemoryAtStartup', 'off',...
            'ZeroInternalMemoryAtStartup', 'off',...
            'InstructionSetExtensions', 'None',...
            'CodeInterfacePackaging','Reusable function',...
            'GenerateAllocFcn','on',...
            'SupportNonFinite','on',...
            'SupportAbsoluteTime','on',...
            'PurelyIntegerCode','off',...
            'SupportComplex', 'on',...
            'SupportContinuousTime','off',...
            'MultiInstanceErrorCode','None',...
            'SuppressErrorStatus','off',...
            'GenerateSampleERTMain', 'off',...
            'GenerateReport', 'on');
    
    

    %save the model preferences in preperation for subsystem converstion   
        save_system(mdl);
    
    
    %Convert subsystem to model reference
        %        ***model reference naming implimented here***
        %
        %
        %before generating code, the top-level subsystem must be replaced
        %by a reference model. the following takes the subsystem and 
        %the previously generated reference model name and creates the 
        %model reference and replaces the subsystem.
        %
        %
        %                       ***Warning***
        %    be aware that the next line will modify your top model
        %    and create a reference model that links the two. (As far 
        %    as "I" can tell this is irreversible.) if the build fails
        %    after successfully generating the reference model, you will
        %    need to restore your model from a backup and remove the 
        %    generted reference model manually to attempt again.
        %               ***   BACK UP YOUR MODEL   ***
        %
        %
        %Simulink.SubSystem.convertToModelReference('SubSystem',mdl);
        disp('Converting top-level subsystem to model reference ...');
        Simulink.SubSystem.convertToModelReference(...
            y,...%subsystem
            refmdl,...%referenced model name
            'AutoFix',true,...
            'ReplaceSubsystem',true,...
            'CheckSimulationResults',true);        
    
    %Save systems before code generation.
        disp('Saving reference model...');
        save_system(refmdl);
        disp('Saving model...');
        save_system(mdl);
    
        disp('Generating code...');
    
    %Generate the code
    
        slbuild(refmdl);
    
        disp('Code generation successful...');
    %close_system(mdl);
end