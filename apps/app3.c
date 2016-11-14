#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <curses.h>

#define ESC 0x1b

char c;
char buffer[80];
	
void changeRed(char c)
{
	start_color();
	init_pair(1,COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	addch(c);
	attroff(COLOR_PAIR(1));
	refresh();
	return ;
}

int main ()
{

	int i=0;
	int j;
	while(c != ESC)
	{
		c=getchar();
		if(c == '\r' || i>10)
		{
			for(j=0; j<10;j++)			
			{	
				changeRed(buffer[j]);
			}			
			break;		
		}
		else
		{
			buffer[i] = c;
			i++;
		}
	}
	printf("%s\n",buffer);
	return 0;
}
