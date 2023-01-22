function importWellDirToDB(db)
% function importWellDirToDB(db)
% import all the wellLog.txt files in a directory to the database
% database is the full path of a database, a persistent variable
% (default = uigetfile)

% 22 oct 22 BR

persistent dbase
if nargin == 1, dbase = db; end
if nargin < 1 && isempty(dbase)
    [fi, pa] = uigetfile('*.db',"select sqlite database ...");
    dbase = [pa fi];
end
[~, pa] = uigetfile('*.txt',"select a file in in the directory");
more off;
conn = sqlite(dbase,"connect"); 
curDir = pwd;
cd(pa);
files = dir('*.txt');
tablename = "wellLog";
fprintf('importing %d files from: %s\n',length(files),pa);
moreState = get(0,'more');
for f = 1:length(files)  
    try
        wellLog = importwelllog(files(f).name);
        wellLog.well = repmat(string(wellLog.well), length(wellLog.event), 1);
        data = struct2table(wellLog);
        sqlwrite(conn, tablename, data);
        fprintf('imported %d %s\n',f, files(f).name);
    catch
        fprintf('failed to import: %s\n', files(f).name);
    end
end
close(conn);
set(0,'more',moreState);
cd(curDir);