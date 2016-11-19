#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curses.h>
#include<signal.h>

//
#include"timer.h"
#include"getch_.h"
#include"menu.h"
#include"menu_long.h"
#include"long_text.h"
#include"short_text.h"

#define ESC 0x1b

char name[6][30] = {"Gulliver's Travels", "Narcissus","Rapunzel"
			,"The Elves and the Shoemaker", "The Selfish Giant", "The Wind and the Sun"};
char ch[] = "->";

int main()
{
	int num = 0;
	int level = 0;
	while(1)
	{
		system("clear");
		num = menu();
		if(num == -1)
		{
			system("clear");
			break;
		}
		else if(num == 1) //long text
		{
			level = menu_long();
			if(level == -1)
			{
				
				continue;
			}
			else // start
			{
				initscr();
				clear();
				refresh();
				stopwatch(1);
				long_text(level);
				stopwatch(0);
				printf("time : %s",timerBuffer);
				endwin();
			}
		}		
		else if(num == 2) // short text
		{
			//printf("success");
			initscr();
			clear();
			refresh();
			short_text();
			endwin();
		}
		system("clear");
		
	}
	return 0;
}
