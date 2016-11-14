#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <curses.h>

#define ESC 0x1b

char c;
char buffer[10];
	
void changeRed(char c)
{
	//attroffset(A_BOLD);
	attrset(COLOR_PAIR(1));
	addch(c);
	refresh();
	return ;
}

int main ()
{

	int i=0;
	int j;

	start_color();
	init_pair(1,COLOR_RED, COLOR_BLACK);

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
	//printf("%s[1;31m",buffer);
	return 0;
}
