
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdarg.h>

//void initData();
char *resolveAddr();
char * buildCommand(int commandLen,int commandCount,char *[] commands);


#define CYZI_REDIS_SERVER_ABSTRACT_PATH "/home/yunchu/redis-cyzi/src/redis-server"

int main(){



char *stacktrace[8]={                   "src/redis-server(print_stacktrace+0x25) [0x4c0c45]",
                                       "src/redis-server(cyziServerLogRaw+0xf9) [0x4c0f79]",
                                       "src/redis-server(cyziServerLog+0xbe) [0x4c106e]",
                                       "src/redis-server(aeCreateFileEvent+0x2d) [0x436ccd]",
                                       "src/redis-server(initServer+0x540) [0x433880]",
                                       "src/redis-server(main+0x40a) [0x42bf7a]",
                                       "/lib64/libc.so.6(__libc_start_main+0xf5) [0x7f3dc0129555]",
                                       "src/redis-server() [0x42c319]"};
//initData(&stacktrace);
int stack_num = 8;


char * commands[stack_num];
char * currentFunName;
char * resolvedAddr;
int commandLen=0;
for(int i=stack_num-1,commandIndex=0;i>=0;i--,commandIndex++){

    currentFunName=stacktrace[i];
    resolvedAddr=resolveAddr(currentFunName);
    char commandBuf[256]={0};
    commandLen+=sprintf(commandBuf,"addr2line -a %s -e %s -f -C;\0",resolvedAddr,CYZI_REDIS_SERVER_ABSTRACT_PATH);

    char *command=commandBuf;
    commands[commandIndex]=command;
}

    char * command=buildCommand(commandLen,stack_num,commands);

    printf("command is:%s\n",command);

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
//		printf("%s", data);
//	}
//	pclose(fp);

return 0;
}


char * buildCommand(int commandLen,int commandCount,char *[] commands){

    char  allCommands[commandLen+1];

    int allCommandsIndex=0;
    for(int i=0;i<commandCount;i++){

        while(*commandCount[i]!='\0'){
            allCommands[allCommandsIndex++]=*commandCount[i]++;
        }

    }
    allCommands[commandLen+1]='\0';
    char * command=allCommands;
    return command;

}





  char * resolveAddr(char * originalStr){
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

