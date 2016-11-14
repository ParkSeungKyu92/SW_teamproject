#include<stdio.h>
#include"getch_.h"
int menu_long()
{
	char name[6][30] = {"Gulliver's Travels", "Narcissus","Rapunzel"
	,"The Elves and the Shoemaker", "The Selfish Giant", "The Wind and the Sun"};
	char ch[] = "->";
	char n;
	char cnt = 0;
	system("clear");
	for(int i=0;i<6;i++)
	{
		if(cnt==i)
		{
			printf("%s %d. %s\n",ch,i+1,name[i]);
		}
		else
		{
			printf("   %d. %s\n",i+1,name[i]);
		}
	}
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
			for(int i=0;i<6;i++)
			{
				if(cnt==i)
				{
					printf("%s %d. %s\n",ch,i+1,name[i]);
				}
				else
				{
					printf("   %d. %s\n",i+1,name[i]);
				}
			}
		}
		if(n == 's') // down
		{
			system("clear");
			cnt=++cnt%6;
			for(int i=0;i<6;i++)
			{
				if(cnt==i)
				{
					printf("%s %d. %s\n",ch,i+1,name[i]);
				}
				else
				{
					printf("   %d. %s\n",i+1,name[i]);
				}
			}
		}
	}

}
