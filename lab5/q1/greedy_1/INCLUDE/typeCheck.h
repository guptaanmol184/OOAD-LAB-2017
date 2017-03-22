#ifndef typeCheck_H
#define typeCheck_H

#include "./Implementation/typeCheck.cpp"

/*checks if the given floating point number is an INTEGER
by checking if fractional part = 0.00

RETURNS:	1, if is Integer
		 	0, if it is not Integer */
int isInteger(float number);

#endif