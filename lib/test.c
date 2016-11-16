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
		char ch = 0;
		int i=0,j=0,k=0,l=0;
		int col=0,row=0;
		int count=0;
		while(fscanf(fp,"%c",&ch) != EOF) // buffer set
		{
			
			if(row == 0 && ch == '\n') // title set
			{
				buf[row][col]=0;				
				row++;
				col = 0;
			}
			else if(col==69) // text line
			{
				row++;
				buf[row][col] = NULL;
				col = 0;
			}
			else
			{
				buf[row][col] = ch;
			}
			col++;
		}

		for(i=0;i<=row/6;i++)
		{
			cnt = 0;
			clear();
			line = 0;
			move(0,0);
			refresh();
			while( (cnt <= 5) && (k+1 != row))
			{
				l = 0;
				while( (ch = buf[k][l]) != NULL)
				{
			
					if(ch == '\n')
					{
						addch(' ');
						refresh();
					}
					else
					{
						addch(ch);
						refresh();		
					}
					l++;
				}
				k++;
				cnt++;
				line+=2;
				move(line,0);
				refresh();
			}
			ch = getch_();
			/*line = 1;
			move(line,0);
			refresh();
			count = 0;
			sh = 0;
			while(sh < 6)
			{
				ch = getch_();
				if(ch == 13 || count<=70) // enter
				{
					sh++;
					count++;
					line+=2;
					move(line,0);
					printf("\r");
					refresh();
				}
				else if(ch == 127) // back space
				{
					printf("\b ");
					printf("\b");
					count--;
				}
				else // print
				{	
					count++;
					printf("%c",ch);
					
				}

			}*/
		}
		
		endwin();
				
	}

}

