#include<stdio.h>
#include<stdlib.h>
#include<termio.h>
#include"getch_.h"
#define ESC 0x1b
int menu()
{
	char longtxt[2][20] = {"-> 1. long text \n", "   1. long text\n"};
	char shorttxt[2][20] = {"-> 2. short text \n", "   2. short text\n"};
	int lt=0,st=1;
	unsigned char n;
	printf("%s%s",longtxt[lt],shorttxt[st]);
	while(1)
	{	
		
		n = getch_();
 		
		if(n == 13 || n == 10)
		{
			return lt<st ? 1 : 2;
		}
		else if(n == 'w')
		{
			system("clear");
			lt=++lt%2;
			st=++st%2;
			printf("%s%s",longtxt[lt],shorttxt[st]);
		}
		else if(n == 's')
		{
			system("clear");
			lt=++lt%2;
			st=++st%2;
			printf("%s%s",longtxt[lt],shorttxt[st]);
		}
		else if(n == ESC)
		{
			return -1;
		}	
			
	}
	
}
