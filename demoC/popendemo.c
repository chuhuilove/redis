
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <regex.h>
#include <stdarg.h>

//void initData();
char *resolveAddr(const char * original);
char * buildCommand(int commandLen,int commandCount,const char ** commands);


#define CYZI_REDIS_SERVER_ABSTRACT_PATH "/home/yunchu/redis-cyzi/src/redis-server"

int main(){



char ** stacktrace={                  "src/redis-server(print_stacktrace+0x25) [0x4c0c45]",
                                       "src/redis-server(cyziServerLogRaw+0xf9) [0x4c0f79]",
                                       "src/redis-server(cyziServerLog+0xbe) [0x4c106e]",
                                       "src/redis-server(createClient+0x80) [0x441970]",
                                       "src/redis-server(scriptingInit+0x4df) [0x48654f]",
                                       "src/redis-server(initServer+0x624) [0x433964]",
                                       "src/redis-server(main+0x40a) [0x42bf7a]",
                                       "/lib64/libc.so.6(__libc_start_main+0xf5) [0x7fd165407555]",
                                       "src/redis-server() [0x42c319]"
                                       };
//initData(&stacktrace);
const int stack_num = 8;


const char **commands;
char * currentFunName;
char * resolvedAddr;
int commandLen=0;
char * tempCommands=NULL;
for(int i=stack_num-1,commandIndex=0;i>=0;i--,commandIndex++){

    currentFunName=stacktrace[i];
    resolvedAddr=resolveAddr(currentFunName);
    char commandBuf[256]={0};
    commandLen+=sprintf(commandBuf,"addr2line -a %s -e %s -f -C;",resolvedAddr,CYZI_REDIS_SERVER_ABSTRACT_PATH);
    printf(" resolved command is %s\n",commandBuf);
    tempCommands=commandBuf;
    commands[commandIndex]=tempCommands;
}

    char * command=buildCommand(commandLen,stack_num,commands);

    printf("command is:%s\n",command);
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


char * buildCommand(int commandLen,int commandCount,const char **commands){

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

