#include<stdio.h>

int main()
{
	char ch = 'B';
	printf("\033[0;31m %c\n",ch);
	printf("\033[0m\n");
	return 0;
}
