




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

#define ADDR2LINE_COMMAND_TEMPLATE "addr2line %s -e %s -f -C -p;" // 函数地址，可执行文件路径

#define ATOS_COMMAND_TEMPLATE "atos -p %d -o %s -fullPath  %s;" // 进程pid， 可行文件路径 ，函数地址


void cyziServerLog(int loglevel,char * message,...);



















