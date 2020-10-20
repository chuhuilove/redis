#include "genarr.h"


 void generIntArr(int * result){

     for(int i=0;i<INT_ARR_MAX_LENGTH;i++){
         *result=i+101;
         result++;
     }

}

void generCharArr(char *result []){

result={                  "src/redis-server(print_stacktrace+0x25) [0x4c0c45]",
                                       "src/redis-server(cyziServerLogRaw+0xf9) [0x4c0f79]",
                                       "src/redis-server(cyziServerLog+0xbe) [0x4c106e]",
                                       "src/redis-server(createClient+0x80) [0x441970]",
                                       "src/redis-server(scriptingInit+0x4df) [0x48654f]",
                                       "src/redis-server(initServer+0x624) [0x433964]",
                                       "src/redis-server(main+0x40a) [0x42bf7a]",
                                       "/lib64/libc.so.6(__libc_start_main+0xf5) [0x7fd165407555]",
                                       "src/redis-server() [0x42c319]",
				       "src/chuhui-server() [0x98cccde3f]"
                                       };
}
