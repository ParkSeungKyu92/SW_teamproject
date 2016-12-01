#include<stdio.h>
#include"getch_.h"
#include"var.h"
int menu_long()
{
	int i=0;
	char n;
	char cnt = 0;
	system("clear");
	
	printf("\n\t\t\t**************************************\n\t\t\t*           LONG TEXT MENU           *\n");
	for(i=0;i<6;i++)
	{
		if(cnt==i)
		{
			printf("\t\t\t* %s %d. %s",arrow,i+1,long_menu[i]);
		}
		else
		{
			printf("\t\t\t*    %d. %s",i+1,long_menu[i]);
		}
	}
	printf("\t\t\t**************************************\n");
	while(1)
	{
		n = getch_();
		if(n == 27) // ESC 
		{
			return -1;
		}
		if(n== 10 || n == 13) // enter
		{
			return cnt;
		}
		if(n == 'w') // up
		{
			system("clear");
			if(cnt==0)
				cnt=5;
			else
				cnt=--cnt%6;
			
			printf("\n\t\t\t**************************************\n\t\t\t*           LONG TEXT MENU           *\n");
			for(i=0;i<6;i++)
			{
				if(cnt==i)
				{
					printf("\t\t\t* %s %d. %s",arrow,i+1,long_menu[i]);
				}
				else
				{
					printf("\t\t\t*    %d. %s",i+1,long_menu[i]);
				}
			}
			printf("\t\t\t**************************************\n");
			
			
		}
		if(n == 's') // down
		{
			system("clear");
			cnt=++cnt%6;
			printf("\n\t\t\t**************************************\n\t\t\t*           LONG TEXT MENU           *\n");
			for(i=0;i<6;i++)
			{
				if(cnt==i)
				{
					printf("\t\t\t* %s %d. %s",arrow,i+1,long_menu[i]);
				}
				else
				{
					printf("\t\t\t*    %d. %s",i+1,long_menu[i]);
				}
			}
			printf("\t\t\t**************************************\n");
		}
	}

}
