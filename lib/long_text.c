#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curses.h>
#include<signal.h>


#define ESC 0x1b

char buf[100000];

void long_text(int n)
{
	char name[6][50] = {"Gulliver's Travels.txt", "Narcissus.txt","Rapunzel.txt"
	,"The Elves and the Shoemaker.txt", "The Selfish Giant.txt", "The Wind and the Sun.txt"};
	FILE *fp = fopen(name[n],"r");
	if(fp == NULL)
	{
		printf("error 1 \n");
		exit(0);

	}
	else
	{	
		int line=0;
		char ch = 0;
		int i=0,len=0;
		int count=0;
		move(0,0);
		refresh();
		while(fscanf(fp,"%c",&ch) != EOF) // move
		{
			buf[len++] = ch;
			if(ch == '\n')
			{
				line+=2;
				move(line,0);
				refresh();

			}
			else
				addch(ch);refresh();
			
		}
		line = 1;
		move(line,0);
		refresh();
		while(ch != ESC) // output
		{	
			
			ch = getch_();
			if(ch == 13) // enter
			{
				line+=2;
				move(line,0);
				printf("\r");
				refresh();
			}
			else if(ch == 127) // back space
			{
				printf("\b ");
				printf("\b");
			}
			else // print
			{	
				
				printf("%c",ch);
			}
		
			
		}
		endwin();
				
	}

}

