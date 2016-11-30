#include<stdio.h>
#include"getch_.h"
int menu_long()
{
	int i=0;
	char name[6][40] = {"Gulliver's Travels           *\n", "Narcissus                    *\n","Rapunzel                     *\n"
	,"The Elves and the Shoemaker  *\n", "The Selfish Giant            *\n", "The Wind and the Sun         *\n"};
	char ch[] = "->";
	char n;
	char cnt = 0;
	system("clear");
	
	printf("\n\t\t\t**************************************\n\t\t\t*           LONG TEXT MENU           *\n");
	for(i=0;i<6;i++)
	{
		if(cnt==i)
		{
			printf("\t\t\t* %s %d. %s",ch,i+1,name[i]);
		}
		else
		{
			printf("\t\t\t*    %d. %s",i+1,name[i]);
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
					printf("\t\t\t* %s %d. %s",ch,i+1,name[i]);
				}
				else
				{
					printf("\t\t\t*    %d. %s",i+1,name[i]);
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
					printf("\t\t\t* %s %d. %s",ch,i+1,name[i]);
				}
				else
				{
					printf("\t\t\t*    %d. %s",i+1,name[i]);
				}
			}
			printf("\t\t\t**************************************\n");
		}
	}

}
