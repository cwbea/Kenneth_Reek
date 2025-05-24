#include <stdio.h>


int main(void)
{
	int n, i;

	printf("Prime Numbers between (1 - 100): \n");

	for (i = 1; i <= 100; i++) {
		n = i;
		if (n % 2 != 0) {
			printf(" %d ", n);
		}
		if (n % 2 == 0) {
			continue;
			n++;
		}
	}

	return 0;
}


