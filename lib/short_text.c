#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curses.h>
#include<signal.h>


#define ESC 0x1b

char buf[100000];

void short_text()
{
	FILE* fp = fopen("Short_text.txt","r");
	if(fp == NULL)
	{
		printf("error !\n");
		exit(0);
	}
	else
	{
		int line = 0;
		char ch = 0;
		int i = 0, len = 0;	
		move(0,0);
		refresh();
		while(fscanf(fp,"%c",&ch) != EOF)
		{	
			buf[len++] = ch;	
			
			if(ch == '\n')
			{
				line = line+2;
				move(line,0);
				refresh();
			}
			else
			{	
				addch(ch);
				refresh();
					
			}
		}
		line = 1;
		move(line,0);
		refresh();
		
		while(ch != ESC)
		{
			ch = getchar();
			if(ch == 13)
			{
				line = line+2;
				move(line,0);
				printf("\r");
				refresh();
			}
			else
			{
				printf("%c",ch);
			}		
		}	
		endwin();

	}
	return ;
}
