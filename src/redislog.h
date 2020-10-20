




#include <time.h>
#include <sys/time.h>
#include <stdarg.h>
#include <sys/types.h>
#include <syslog.h>

#define CYZI_LOG_MAX_LEN    1024 /* Default maximum length of syslog messages.*/
#define CYZI_LL_RAW (1<<10) /* Modifier to log without timestamp */
#define CYZI_LOG_PATH "RedisCyziLog.log"


#define CYZI_LL_DEBUG 0
#define CYZI_LL_VERBOSE 1
#define CYZI_LL_NOTICE 2
#define CYZI_LL_WARNING 3

#define CYZI_REDIS_SERVER_ABSTRACT_PATH "/home/yunchu/redis-cyzi/src/redis-server"

#define ADDR2LINE_COMMAND_TEMPLATE "addr2line -a %s -e %s -f -C -p;"


void cyziServerLog(int loglevel,char * message,...);

void cyziServerLogRaw(int level, const char *msg);

void printStacktrace();

















