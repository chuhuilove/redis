
#include "redislog.h"
#include "util.h"
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <execinfo.h>
#include <stdlib.h>


void nolocks_localtime_cyzi(struct tm *tmp, time_t t, time_t tz, int dst);
char* retrievalAddr(const char* originalStr);


void cyziServerLog(int loglevel,char * message,...){
	va_list ap;
	   char msg[CYZI_LOG_MAX_LEN];
	   va_start(ap, message);
	   vsnprintf(msg, sizeof(msg), message, ap);
	   va_end(ap);
	
	   cyziServerLogRaw(loglevel,msg);

}

/* 底层日志记录.只用来记录非常大的消息,小一些的消息使用serverLog()更好. */
void cyziServerLogRaw(int level, const char *msg) {


	extern time_t cyziTimezone; 
	extern  int cyzi_daylight_active; 
	extern  int cyzi_sentinel_mode; 
	extern char *cyzi_masterhost; 
	extern pid_t cyzi_pid; 		


    const char *c = ".-*#";
    FILE *fp;
    char buf[64];
    int rawmode = (level & CYZI_LL_RAW);
    int log_to_stdout =0;

    level &= 0xff; /* clear flags */


    fp = log_to_stdout ? stdout : fopen(CYZI_LOG_PATH,"a");
    if (!fp) return;

	

    if (rawmode) {
        fprintf(fp,"%s",msg);
    } else {
        int off;
        struct timeval tv;
        int role_char='Y';
        pid_t pid = getpid();

        gettimeofday(&tv,NULL);
        struct tm tm;
        nolocks_localtime_cyzi(&tm,tv.tv_sec,cyziTimezone,cyzi_daylight_active);
         off = strftime(buf,sizeof(buf),"%Y-%m-%d %H:%M:%S.",&tm);
        snprintf(buf+off,sizeof(buf)-off,"%03d",(int)tv.tv_usec/1000);
       
        fprintf(fp,"%d:%c %s %c %s\n",
            (int)getpid(),role_char, buf,c[level],msg);
    }
	printStacktrace(fp);
    fflush(fp);
	//文件频繁的打开与关闭,会造成Redis性能整体的下降
    if (!log_to_stdout) fclose(fp);
   
}



void printStacktrace(FILE * fp)
{
    int size = 512;
    void * array[size];
    int stack_num = backtrace(array, size);
    char ** stacktrace = backtrace_symbols(array, stack_num);




    for (int i = stack_num-1; i>=0; i--)
    {
//        fprintf(fp,"%s\n", stacktrace[i]);

         char *functionName=*(stacktrace+i);
       char * resolvedAddr=retrievalAddr(functionName);
         fprintf(fp,"funcation address is %s,sizeof(%s)=%ld\n", resolvedAddr,resolvedAddr,sizeof(resolvedAddr));
    }



    free(stacktrace);
}


 char* retrievalAddr(const char* originalStr){
static	char result [64];
	int lastChar=']';
	int isAddr=0;
	int j=0;
	for(int i=0;originalStr[i]!=lastChar;i++){
		if(isAddr){
			result[j++]=originalStr[i];
			continue;
		}
		if(originalStr[i]=='['){
			isAddr=1;			
		}	
	}
	result[j]='\0';
	return result;
}


static int is_leap_year_cyzi(time_t year) {
    if (year % 4) return 0;         /* A year not divisible by 4 is not leap. */
    else if (year % 100) return 1;  /* If div by 4 and not 100 is surely leap. */
    else if (year % 400) return 0;  /* If div by 100 *and* not by 400 is not leap. */
    else return 1;                  /* If div by 100 and 400 is leap. */
}

void nolocks_localtime_cyzi(struct tm *tmp, time_t t, time_t tz, int dst) {
    const time_t secs_min = 60;
    const time_t secs_hour = 3600;
    const time_t secs_day = 3600*24;

    t -= tz;                            /* Adjust for timezone. */
    t += 3600*dst;                      /* Adjust for daylight time. */
    time_t days = t / secs_day;         /* Days passed since epoch. */
    time_t seconds = t % secs_day;      /* Remaining seconds. */

    tmp->tm_isdst = dst;
    tmp->tm_hour = seconds / secs_hour;
    tmp->tm_min = (seconds % secs_hour) / secs_min;
    tmp->tm_sec = (seconds % secs_hour) % secs_min;

    /* 1/1/1970 was a Thursday, that is, day 4 from the POV of the tm structure
     * where sunday = 0, so to calculate the day of the week we have to add 4
     * and take the modulo by 7. */
    tmp->tm_wday = (days+4)%7;

    /* Calculate the current year. */
    tmp->tm_year = 1970;
    while(1) {
        /* Leap years have one day more. */
        time_t days_this_year = 365 + is_leap_year_cyzi(tmp->tm_year);
        if (days_this_year > days) break;
        days -= days_this_year;
        tmp->tm_year++;
    }
    tmp->tm_yday = days;  /* Number of day of the current year. */

    /* We need to calculate in which month and day of the month we are. To do
     * so we need to skip days according to how many days there are in each
     * month, and adjust for the leap year that has one more day in February. */
    int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    mdays[1] += is_leap_year_cyzi(tmp->tm_year);

    tmp->tm_mon = 0;
    while(days >= mdays[tmp->tm_mon]) {
        days -= mdays[tmp->tm_mon];
        tmp->tm_mon++;
    }

    tmp->tm_mday = days+1;  /* Add 1 since our 'days' is zero-based. */
    tmp->tm_year -= 1900;   /* Surprisingly tm_year is year-1900. */
}






