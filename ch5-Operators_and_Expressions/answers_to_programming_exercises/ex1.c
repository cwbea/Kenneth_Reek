#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1024

int main(void)
{
	char ch[MAX];
	
	
	printf("Enter string: ");
	fgets(ch,1024,stdin);
	ch[strcspn(ch, "\n")];
	
	for (int i = 0; i < MAX; i++) {
	ch[i] = tolower(ch[i]);
	}
	
	printf("\n%s", ch);

	return 0;
}

