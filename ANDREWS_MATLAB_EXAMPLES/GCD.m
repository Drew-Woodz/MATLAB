
% This script is used to calculate the greatest common divisor of any two
% given inputs. Calling this script will prompt the user for two numerical
% inputs.

%Here we prompt the user for inputs
aa = input('Input the first number: ');
bb = input('Input the second number: ');

% Y = abs(X) returns the absolute value of each element in array X.
% abs(-5) = 5
aa = abs(aa);
bb = abs(bb);

% MATLAB Function: floor(X)
% Y = floor(X) rounds each element of X to the nearest integer less than or equal to that element.
r = aa - bb*floor(aa/bb);


% while looks for a bool T | F (1 | 0) and ends when the bool is false(0), when r does not equal 0
% the result is true(1) and the while loop continues.
while r ~= 0
    aa = bb;
    bb = r;
    r = aa - bb*floor(aa/bb);
end

disp(bb);% display the result