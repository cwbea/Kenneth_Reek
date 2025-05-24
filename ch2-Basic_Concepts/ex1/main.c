#include <stdio.h>
#include "increment.h"
#include "negate.h"

int main(void)
{
	int a = 10;
	int b = 0;
	int c = -10;
	int incrementResult;
	int negateResult;

	incrementResult = increment(a);
        printf("\nResult = %d", incrementResult);

	incrementResult = increment(b);
	printf("\nResult = %d", incrementResult);

	incrementResult = increment(c);
	printf("\nResult = %d", incrementResult);

	negateResult = negate(a);
	printf("\n\nResult = %d", negateResult);

	negateResult = negate(b);
	printf("\nResult = %d", negateResult);

	negateResult = negate(c);
	printf("\nResult = %d", negateResult);

	return 0;
}



	
