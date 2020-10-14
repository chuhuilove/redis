

#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <regex.h>

char ** initData();
char *resolveAddr();


#define CYZI_REDIS_SERVER_ABSTRACT_PATH "/home/yunchu/redis-cyzi/src/redis-server"

int main(){



char ** stacktrace= initData();
int stack_num = 8;


char * commands[stack_num];
int commandIndex=0;
char * currentAddr;
for(int i=stack_num-1;i>=0;i--){


    char * resolvedAddr=resolveAddr(stacktrace[i]);

    char command[128];
    int commandLength=sprintf(command,"addr2line -a %s -e %s -f -C;\0",stacktrace[i],CYZI_REDIS_SERVER_ABSTRACT_PATH);
    command[commandLength]='\0';
    commands[commandIndex]=command;

    printf(" %s resolved addr is: %s,command is:%s\n",stacktrace[i],resolvedAddr,commands[commandIndex]);
    commandIndex++;
}














/*
    FILE *fp = NULL;
	char data[200] = {'0'};
	fp = popen("addr2line -a 0x42bf7a -e /home/yunchu/redis-cyzi/src/redis-server -f -C", "r");
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
*/
return 0;
}


char ** initData(){

    char * data[]={"src/redis-server(print_stacktrace+0x25) [0x4c0c45]",
                                       "src/redis-server(cyziServerLogRaw+0xf9) [0x4c0f79]",
                                       "src/redis-server(cyziServerLog+0xbe) [0x4c106e]",
                                       "src/redis-server(aeCreateFileEvent+0x2d) [0x436ccd]",
                                       "src/redis-server(initServer+0x540) [0x433880]",
                                       "src/redis-server(main+0x40a) [0x42bf7a]",
                                       "/lib64/libc.so.6(__libc_start_main+0xf5) [0x7f3dc0129555]",
                                       "src/redis-server() [0x42c319]"};

    char ** result=data;
    return result;

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





