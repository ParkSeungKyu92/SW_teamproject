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
#include"var.h"
#include"result_long_text.h"
#define ESC 0x1b

int err;
int acc;
int typing;
char name[6][50] = {"../textfile/Gulliver's Travels.txt", "../textfile/Narcissus.txt","../textfile/Rapunzel.txt"
	,"../textfile/The Elves and the Shoemaker.txt", "../textfile/The Selfish Giant.txt", "../textfile/The Wind and the Sun.txt"};
char arrow[3] = "->";
char longtxt[2][33] = {"*  -> 1. long text            *\n", "*     1. long text            *\n"};
char shorttxt[2][33] ={"*  -> 2. short text           *\n", "*     2. short text           *\n"};
char long_menu[6][40] = {"Gulliver's Travels           *\n", "Narcissus                    *\n","Rapunzel                     *\n"
	,"The Elves and the Shoemaker  *\n", "The Selfish Giant            *\n", "The Wind and the Sun         *\n"};


int main()
{
	int comp = 0;
	int secs = 0;
	int num = 0;
	int level = 0;
	char temp;
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
				secs = stopwatch(1);
				comp = long_text(level);
				secs = stopwatch(0);
				clear();refresh();endwin();
				system("clear");
				if(comp==1){				
					result_long_text(secs);	temp = getch_();
				}
			}
		}		
		else if(num == 2) // short text
		{
			//printf("success");
			initscr();
			clear();
			refresh();
			//stopwatch(1);
			short_text();
			//stopwatch(0);
			printf("time : %s",timerBuffer);
			endwin();
		}
		system("clear");
		
	}
	return 0;
}
