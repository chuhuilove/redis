
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdarg.h>
#include "charpointarr.h"
#include "genarr.h"


#define CYZI_REDIS_SERVER_ABSTRACT_PATH "/home/yunchu/redis-cyzi/src/redis-server"

int main(){


//
//char stacktrace[][CHAR_ARR_MAX_LENGTH]={"src/redis-server(print_stacktrace+0x25) [0x4c0c45]",
//                                       "src/redis-server(cyziServerLogRaw+0xf9) [0x4c0f79]",
//                                       "src/redis-server(cyziServerLog+0xbe) [0x4c106e]",
//                                       "src/redis-server(createClient+0x80) [0x441970]",
//                                       "src/redis-server(scriptingInit+0x4df) [0x48654f]",
//                                       "src/redis-server(initServer+0x624) [0x433964]",
//                                       "src/redis-server(main+0x40a) [0x42bf7a]",
//                                       "/lib64/libc.so.6(__libc_start_main+0xf5) [0x7fd165407555]",
//                                       "src/redis-server() [0x42c319]",
//				       "src/chuhui-server() [0x98cccde3f]"
//                                       };


char *stacktrace[100]={0};

generCharArr_2(stacktrace);


const char *commands[CHAR_ARR_MAX_LENGTH];

int commandLen=0;
int commandIndex=0;

for(int i=CHAR_ARR_MAX_LENGTH-1;i>=0;i--,commandIndex++){

    char * resoledHexAddr=resolveAddr((char*)stacktrace[i]);
    char * commandBuf=(char*)malloc(128*sizeof (char));
    commandLen+=sprintf(commandBuf,"addr2line -a %s -e %s -f -C -p;",resoledHexAddr,CYZI_REDIS_SERVER_ABSTRACT_PATH);
   *(commands+commandIndex)=commandBuf;

    free(resoledHexAddr);
    resoledHexAddr=NULL;
}

char * fullCommand=buildCommand(commands,commandIndex-2,commandLen);

// 释放掉 commands
for(int i=commandIndex-1;i>=0;i--){
    free((void *)commands[i]);
}




    FILE *fp = NULL;
    char data[200] = {'0'};
    fp = popen(fullCommand, "r");
    if (fp == NULL)
    {
        printf("popen error!\n");
        return 1;
    }
    while (fgets(data, sizeof(data), fp) != NULL)
    {

        printf("%s", data);
    }
    pclose(fp);

return 0;
}




char * buildCommand(const char *commands[],int rows,int commandCount){

    char * result=(char*)malloc((unsigned long)commandCount*sizeof (char)+1);
    int resultIndex=0;
    for(int i=0;i<rows;i++){

     const char * singileCommand=*(commands+i);
     // sprintf 会自动填充'\0'
      while(*singileCommand!='\0'){
          result[resultIndex++]=*singileCommand++;
      }
    }
    return result;
}





char* resolveAddr(const char * originalStr){
    char * result=(char*) malloc(64*sizeof (char));

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

