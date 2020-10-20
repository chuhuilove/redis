
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

for(int i=CHAR_ARR_MAX_LENGTH-1,commandIndex=0;i>=0;i--,commandIndex++){

    char *currentFunName=stacktrace[i];
    char * resoledHexAddr=resolveAddr(currentFunName);

    char commandBuf[256];
    commandLen+=sprintf(commandBuf,"addr2line -a %s -e %s -f -C;",resoledHexAddr,CYZI_REDIS_SERVER_ABSTRACT_PATH);
    printf(" resolved command is %s,commandBuf address:%p,resoledHexAddr address:%p\n",commandBuf,commandBuf,resoledHexAddr);

//    char * tempCommands=commandBuf;
//    commands[commandIndex]=tempCommands;
//    commands++;
}

   // char * command=buildCommand(commandLen,stack_num,commands);

    //printf("command is:%s\n",command);
//
//    FILE *fp = NULL;
//	char data[200] = {'0'};
//	fp = popen(command, "r");
//	if (fp == NULL)
//	{
//		printf("popen error!\n");
//		return 1;
//	}
//	while (fgets(data, sizeof(data), fp) != NULL)
//	{
//		printf("executed result is: %s\n", data);
//	}
//	pclose(fp);

return 0;
}


char * buildCommand(int commandLen,int commandCount,const char *commands[]){

    char  allCommands[4096];

    int allCommandsIndex=0;


    for(int i=0;i<commandCount;i++){

        printf(" start resolve commands[%d],command is %s\n",i,*commands++);

    }


    return "12222";
//
//    for(int i=0;i<commandCount;i++){
//        printf(" start resolve commands[%d],command is %s\n",i,commands[i]);
//
//        while(*commands[i]!='\0'){
//            allCommands[allCommandsIndex++]=*commands[i]++;
//        }
//    }
//    allCommands[commandLen+1]='\0';
//    char * command=allCommands;
//    return command;

}





  int  resolveAddr(const char * originalStr){
    static char result[64];
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

