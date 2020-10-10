


#define CYZI_LOG_MAX_LEN    1024 /* Default maximum length of syslog messages.*/
#include <time.h>
#include <sys/time.h>
#include <stdarg.h>
#include <sys/types.h>

void cyziServerLog(int loglevel,char * message);

void cyziServerLogRaw(int level, const char *msg);


















