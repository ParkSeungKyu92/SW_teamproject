#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<curses.h>
#include<signal.h>


#define ESC 0x1b


void long_text(int n)
{
	char buf[100][70] = {0,};
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
		int cnt = 0;		
		int sh = 0;
		int line=0;
		char ch = 0,as;
		int i=0,j=0;
		int col=0,row=0;
		int count=0;
		while(fscanf(fp,"%c",&ch) != EOF) // buffer set
		{
			if(row == 0 && ch == 13) // title set
			{
				buf[row][col] = 0;				
				row++;
				col = 0;
			}
			else if(col==69) // text line
			{
				
				buf[row][col] = 0; //str last NULL
				row++;
				col=0;
				if(ch == 13)
				{
					buf[row][col] = ' ';
					col++;
				}
				else
				{
					buf[row][col] = ch;
					col++;
				}

				
			}
			else 
			{	
				if(ch == 13)
				{
					buf[row][col] = ' ';
					col++;
				}
				else
				{
					buf[row][col] = ch;
					col++;
				}
				
			}
		}
		row++;
		clear();
		line = 0;

		for(i=0;i<row;i++)
		{
			move(line,0);
			refresh();
			if(i==0)
			{
				addstr(buf[i]);
				refresh();
			}
			else
			{
				addstr(buf[i]);
				refresh();
			}
			line+=2;
			
			if(i%12==11)
			{
				line=1;
				move(line,0);
				count = 0;sh = 0;
				refresh();
				while(sh<12)
				{
					ch = getch_();
					if(ch == ESC)
						return;
					if(ch == 13 || count == 69) // enter
					{
						sh++;
						line+=2;count=0;
						move(line,0);
						printf("\r");
						refresh();
					}
					else if(ch == 127) // back space
					{
						printf("\b ");
						printf("\b");
						refresh();
						count--;
					}
					else // print
					{	
						printf("%c",ch);
						refresh();
						count++;
					}
				}
				clear();
				line = 0;	

			}
			else if((i+1) == row)
			{
				line=1;
				move(line,0);
				count = 0;sh = 0;
				refresh();
				while(sh<row-(i+1))
				{
					ch = getch_();
					if(ch == ESC)
						return;
					if(ch == 13 || count == 69) // enter
					{
						sh++;
						line+=2;count=0;
						move(line,0);
						printf("\r");
						refresh();
					}
					else if(ch == 127) // back space
					{
						printf("\b ");
						printf("\b");
						refresh();
						count--;
					}
					else // print
					{	
						printf("%c",ch);
						refresh();
						count++;
					}
				}
				clear();
				line = 0;

			}


			
		}
		fclose(fp);
		endwin();
				
	}

}

