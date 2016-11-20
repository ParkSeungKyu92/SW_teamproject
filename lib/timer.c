#include <stdio.h>
#include <time.h>
void secToHHMMSS(int secs, char* s, size_t size);
int stopwatch(int onOff);
char timerBuffer[9];

int stopwatch(int onOff) {
  static int oldTime; 

  if (onOff == 1) {
    oldTime = (int) time(NULL);
    return 0;
  }

  if (onOff == 0) { 
    /*secToHHMMSS(
                (int) time(NULL) - oldTime,
                timerBuffer,
                sizeof(timerBuffer)
                );*/
   return ((int) time(NULL) - oldTime);
  }

}


void secToHHMMSS(int secs, char* s, size_t size) { 
  int hour, min, sec;

  sec  = secs % 60;
  min  = secs / 60 % 60;
  hour = secs / 3600;

  printf("%02d:%02d:%02d", hour, min, sec);
 
} 
