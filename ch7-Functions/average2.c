** Compute the average of the specified number of values.

#include <stdarg.h>

float average( int n_values, ... ) // The ellipsis ... in the parameter list is part of 
				   // the C standard for variable argument functions, like printf()
				   // so it is valid.
	va_list var_arg;
	int count;
	float sum = 0;
/*
** Prepare to access the variable arguments.
*/
	va_start( var_arg, n_values );
/*
** Add the values from the variable argument list.
*/
	for( count = 0; count < n_values; count += 1 ){
		sum += va_arg( var_arg, int );
		}
/*
** Done processing variable arguments.
*/
	va_end( var_arg );

	return sum / n_values;
}
