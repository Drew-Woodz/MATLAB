function Y = gcdFunc(a,b)
% Y = gcdFunc(a,b)
%
% gcdFunc is a function version of the script GCD. It is used to 
% calculate the greatest common divisor of any two given inputs
%

% Function headers should include brief descriptions of the function's
% use. This is what will appear when you enter help gcdFunc into the 
% command line.

% MATLAB Function: abs(X)
% Y = abs(X) returns the absolute value of each element in array X.
% 
a = abs(a);
b = abs(b);

% MATLAB Function: floor(X)
% Y = floor(X) rounds each element of X to the nearest integer less 
% than or equal to that element.
r = a - b*floor(a/b);

% Repeats the operation until updates of a equal updates of b
% while looks for a bool T | F (1 | 0) and ends when the bool is 
% false(0), when r does not equal 0 the result is true(1) and the 
% while loop continues.
while r ~= 0
    a = b;
    b = r;
    r = a - b*floor(a/b);
end

Y = b;

end

