#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <curses.h>


int main()
{
	changeRed('a');
	return 0;
}


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
