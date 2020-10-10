




#include <time.h>
#include <sys/time.h>
#include <stdarg.h>
#include <sys/types.h>
#include <syslog.h>

#define CYZI_LOG_MAX_LEN    1024 /* Default maximum length of syslog messages.*/
#define CYZI_LL_RAW (1<<10) /* Modifier to log without timestamp */
#define CYZI_LOG_PATH "CyziLog.log"

void cyziServerLog(int loglevel,char * message,...);


void cyziServerLogRaw(int level, const char *msg);


















