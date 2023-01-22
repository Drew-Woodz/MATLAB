function createWellDB(fname)
% function createWellDB(fname)
% create a sqlite database with table wellLog in fname (default uiputfile)

% 2 Dec 22 Phys 497
if nargin < 1
    [name, path] = uiputfile('',"enter wellLog databse name");
    fname = [path name];
end
conn = sqlite(fname,"create");
sqlcmd = sprintf('CREATE TABLE wellLog(well TEXT, dateTime DATETIME,\n');
sqlcmd = sprintf('%s wellFt NUMERIC, tankIn NUMERIC,\n',sqlcmd);
sqlcmd = sprintf('%s current NUMERIC, event NUMERIC,\n', sqlcmd);
sqlcmd = sprintf('%s CONSTRAINT key PRIMARY KEY(well, dateTime));', sqlcmd);
execute(conn, sqlcmd)
end