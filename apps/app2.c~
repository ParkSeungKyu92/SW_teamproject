#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <curses.h>
#define ESC 0x1b //ESC

void sampletext();

int main()
{
	char c;
	char buffer[80];
	char compare1[80];
	int i=0;
	int j;
	int line =1;

	initscr();
	clear();
	refresh();

	for(j=0;j<80;j++)
	{
		buffer[j] = '\0';	//init array
	}

	sampletext();

	move(1,0);

	refresh();

	while(c != ESC)
	{
		c = getchar();
		start_color();
		init_pair(1,COLOR_RED,COLOR_BLACK);
		
		if(c == '\r' || i>=80)
		{
			line = line +2;
			move(line,0);
			printf("\r");
			refresh();
			i=0;
			/*			
			for(j=0;j<80;j++)
			{
				if(buffer[j] != c)
				{	
					move(line-1,i);
					attron(COLOR_PAIR(1));
					addch(compare1[i]);
					attroff(COLOR_PAIR(1));
					move(line,i+1);
					refresh();				
				}
				else
				{
					move(line -1, i);
					addch(compare1[i]);
					move(line, i+1);
					refresh();
				}			
			}
			*/
		}
		else
		{
			putchar(c);
			buffer[i]=c;
			i++;
		}


	}

	endwin();

}

void sampletext()
{
	int line=0;
	addstr("This is Sample Text");
	line = line+2;
	move(line,0);
	addstr("you can type English");
	line = line+2;
	move(line,0);
	addstr("God Seungwan System Programming");

}

