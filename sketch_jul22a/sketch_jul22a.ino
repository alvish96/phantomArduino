#include <DateTime.h>

#define TIME_MSG_LEN 11

#define TIME_HEADER 255

//get the time from pc:

getPCtime();

void getPCtime() {
while(Serial.available() >= TIME_MSG_LEN ){
if( Serial.read() == TIME_HEADER ) {
time_t pctime = 0;
for(int i=0; i < TIME_MSG_LEN -1; i++){
char c= Serial.read();
if( c >= '0' && c <= '9')
pctime = (10 * pctime) + (c - '0') ; // convert digits to a number
}
DateTime.sync(pctime);
}
}
}

//than in code use the commands like

Hours = (DateTime.Hour,DEC);
Minutes = DateTime.Minute;
Seconds = DateTime.Second;
