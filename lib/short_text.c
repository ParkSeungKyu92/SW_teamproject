#include<stdio.h> 
#include<stdlib.h> 
#include<string.h> 
#include<curses.h> 
#include<signal.h> 
#include<string.h> 
#include "timer.h" 
 
 
 
#define ESC 0x1b 
 
 
char buf_short[500][100] = {0,}; 
 
 
void short_text() 
{ 
 	FILE *fp = fopen("Short_text.txt","r"); 
 	if(fp == NULL) 
 	{ 
 		printf("error 1 \n"); 
 		exit(0); 
 	} 
 	else 
 	{	bool isStart = false;
 		int page = 0;		 
 		int sh = 0; 
 		int line=0;
		int line2=0; 
 		char ch = 0; 
 		int i=0,j=0; 
 		int col=0,row=0; 
 		int count=0;
		int sec=0; 
 		while(!feof(fp)) // buffer set 
 		{ 
 			fgets(buf_short[row],sizeof(buf_short[row]),fp);			 
 			if(buf_short[row][strlen(buf_short[row])-1] == 13) 
 			{ 
 				buf_short[row][strlen(buf_short[row])-1] = 0; 
 			}			 
 			row++; 
 		} 
 		 
 		for(i=0;i<row;i++) 
 		{ 
 			move(line,0);
 			refresh(); 
 			printf("\r%s",buf_short[i]);
 			line+=1; 
			line2+=1; 			
			if(i%11==10) 	//11 lines are in 1 page(i=10)
 			{	 
 				//page++; 
 				//move(line*2,50); 
 				//printw("(%d/%d)",page,(row-1)/11 + 1); 
 				//refresh(); 
 				//This section print number of pages 
 				
 				line=1; 
 				move(line,0); 
 				count = 0;sh = i-10; 
 				refresh(); 
 				while(sh<=i) 
 				{
					 
 					ch = getchar(); 
					if (isStart == false)
					{
						sec = stopwatch(1);
						isStart = true;
					}					
					if(ch == ESC) 
 						return;
 					
 					if(ch == 13 || count+1 == strlen(buf_short[sh])) // enter 
 					{

						sec = stopwatch(0);
						//printf("%d %d",sh+1,row);
 						move(23,45);
						//printw("%d",sec);
						printw("*time : %2d hour %2d min %2d sec *\n", 							sec / 3600, sec / 60 % 60,sec%60);
							
						refresh();
						
 						sh++; 
 						line+=2;count=0; 
 						move(line,0); 
 						printf("\r"); 
 						refresh(); 
						isStart = false;
 					} 
 					else if(ch == 127) // back space 
 					{ 
 						printf("\b "); 
 						printf("\b"); 
 						count<=0?count:count--;
 					} 
 					else // print 
 					{	 
 						if(buf_short[sh][count]==ch) 
 						{ 
 							printf("%c",ch); 
 							count++; 
 						} 
 						else 
 						{ 
 							printf("\033[0;31m%c",ch); 
 							printf("\033[0m"); 
 							count++; 
 						} 
 					} 
 				} 
 				clear(); 

				sec = stopwatch(0);
				//printf("%d %d",sh+1,row);
				move(23,45);
				//printw("%d",sec);
				printw("*time : %2d hour %2d min %2d sec *\n", 							sec / 3600, sec / 60 % 60,sec%60);

 				line = 0;	 
 				line2 = 0;
				
 
			} 
			
			else if((i+1) == row) 	
			{//last page; becauz we don't know how many lines are in this page. 
 				//page++; 
 				//move(line*2,50); 
 				//printw("(%d/%d)",page,(row-1)/11 + 1); 
				//refresh(); 
				//This section print number of pages 
				//clear();
				line=0;
 				move(line,0);
				refresh();
				line+=1;
 				isStart = false;
 				move(line,0);
				refresh();
				//printw("2");
				count = 0;sh = i-((row-1)%11); 
 				while(sh<(row-1)) 
 				{ 
 					ch = getchar();
					if (isStart == false)
					{
						sec = stopwatch(1);
						isStart = true;
					}
 					if(ch == ESC) 
 						return; 
 					if(ch == 13 || count+2 == strlen(buf_short[sh])) // enter 
 					{	
						sec = stopwatch(0);
 						move(23,45);
						printw("*time : %2d hour %2d min %2d sec *\n", 							sec / 3600, sec / 60 % 60,sec%60);
						
						refresh();
						sh++; 
 						line+=2;count=0; 
						move(line,0); 
 						printf("\r"); 
 						refresh(); 
						isStart = false;
						
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
						/*
						printf("%c",ch); 
						refresh(); 							
						count++; */
					
						 
 						if(buf_short[sh][count]==ch) 
 						{ 
 							printf("%c",ch); 
 							count++; 
 						} 
 						else 
 						{ 
 							printf("\033[0;31m%c",ch); 
 							printf("\033[0m"); 
 							count++; 
 						}
						  
 					} 
				} 
 				clear();
				sec = stopwatch(0);
				//printf("%d %d",sh+1,row);
				move(23,45);
				//printw("%d",sec);
				printw("*time : %2d hour %2d min %2d sec *\n", 							sec / 3600, sec / 60 % 60,sec%60);

				line=0;
				line2=0; 
 			} 

 

 
 			 
 		} 
 		fclose(fp); 				 
 	} 
 
} 

