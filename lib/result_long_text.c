#include<stdio.h>

extern int acc;
extern int err;
extern int typing;
int result_long_text(int secs)
{
	printf("\n\n\n\t *long text result*\n");
	printf("\r\t*time : %2d hour %2d min %2d sec *\n", secs / 3600, secs / 60 % 60,secs%60);
	printf("\r\t*TASU : %d*\n",60*(acc/secs));
	printf("\r\t*accuracy : %d*\n", 100*(typing/(typing-err)));
	acc=err=typing=0;
	return 0;
}
