
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdarg.h>
#include "charpointarr.h"
#include "genarr.h"


#define CYZI_REDIS_SERVER_ABSTRACT_PATH "/home/yunchu/redis-cyzi/src/redis-server"

int main(){



char *stacktrace[CHAR_ARR_MAX_LENGTH];
generCharArr(stacktrace);




const char *commands[CHAR_ARR_MAX_LENGTH];
char * currentFunName;
char * resolvedAddr;
int commandLen=0;

for(int i=stack_num-1,commandIndex=0;i>=0;i--,commandIndex++){

    currentFunName=stacktrace[i];
    resolvedAddr=resolveAddr(currentFunName);
    char commandBuf[256]={0};
    commandLen+=sprintf(commandBuf,"addr2line -a %s -e %s -f -C;",resolvedAddr,CYZI_REDIS_SERVER_ABSTRACT_PATH);
    printf(" resolved command is %s\n",commandBuf);

  //  char * tempCommands=commandBuf;
//    commands++=tempCommands;
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





  char * resolveAddr(const char * originalStr){
	char result[64];

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
	char * actualAddr=result;
	return actualAddr;
}

