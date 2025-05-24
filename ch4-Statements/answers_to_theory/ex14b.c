#include <stdio.h>
#include <stdbool.h>

void eat_hamburger(void);
bool hunger(bool num);

int main(void)
{

	int num;
	
	while (hunger(num)) {
		eat_hamburger;
	}

	return 0;
}



void eat_hamburger(void)
{
	printf("\nEating hamburger..\n");
}

bool hunger(bool num)
{
	printf("\nAre you hungry?\n");
	printf("\nEnter 1 for true\n");
	printf("\nEnter 0 for false\n");
	printf("\nEnter choice: ");
	scanf("%d", &num);

	if (num == 1) {
		eat_hamburger();
	}
	else {
		printf("\nNo longer hungry\n");
	}

	return num;
}



