#include<stdio.h>
#include<stdlib.h>
#include<termio.h>
#include"getch_.h"
#include"var.h"
#define ESC 0x1b
int menu()
{
	int lt=0,st=1;
	unsigned char n;
	printf("\n\t\t\t*******************************\n\t\t\t*  ENGLISH PRATICE OF TYPING  *\n");
	printf("\t\t\t*******************************\n");
	printf("\t\t\t%s\t\t\t%s",longtxt[lt],shorttxt[st]);
	printf("\t\t\t*******************************\n");
	
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
			printf("\n\t\t\t*******************************\n\t\t\t*  ENGLISH PRATICE OF TYPING  *\n");
			printf("\t\t\t*******************************\n");
			printf("\t\t\t%s\t\t\t%s",longtxt[lt],shorttxt[st]);
			printf("\t\t\t*******************************\n");
		}
		else if(n == 's')
		{
			system("clear");
			lt=++lt%2;
			st=++st%2;
			printf("\n\t\t\t*******************************\n\t\t\t*  ENGLISH PRATICE OF TYPING  *\n");
			printf("\t\t\t*******************************\n");
			printf("\t\t\t%s\t\t\t%s",longtxt[lt],shorttxt[st]);
			printf("\t\t\t*******************************\n");
		}
		else if(n == ESC)
		{
			return -1;
		}	
			
	}
	
}
