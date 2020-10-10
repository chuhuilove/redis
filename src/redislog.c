
#include "redislog.h"
#include "util.h"
#include "localtime.h"
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>




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


    const int syslogLevelMap[] = { LOG_DEBUG, LOG_INFO, LOG_NOTICE, LOG_WARNING };
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
        int role_char;
        pid_t pid = getpid();

        gettimeofday(&tv,NULL);
        struct tm tm;
        nolocks_localtime(&tm,tv.tv_sec,cyziTimezone,cyzi_daylight_active);
        off = strftime(buf,sizeof(buf),"%d %b %Y %H:%M:%S.",&tm);
        snprintf(buf+off,sizeof(buf)-off,"%03d",(int)tv.tv_usec/1000);
        if (cyzi_sentinel_mode) {
            role_char = 'X'; /* Sentinel. */
        } else if (pid != cyzi_pid) {
            role_char = 'C'; /* RDB / AOF writing child. */
        } else {
            role_char = (cyzi_masterhost ? 'S':'M'); /* Slave or Master. */
        }
        fprintf(fp,"%d:%c %s %c %s\n",
            (int)getpid(),role_char, buf,c[level],msg);
    }
    fflush(fp);

    if (!log_to_stdout) fclose(fp);
    //if (cyzi_syslog_enabled) syslog(syslogLevelMap[level], "%s", msg);
}






