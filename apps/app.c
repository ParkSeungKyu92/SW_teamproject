#include<stdio.h>
#include"getch.h"
#include"menu.h"

int main()
{
	system("clear");
	int n = menu();
	printf("%d",n);
	return 0;
}
