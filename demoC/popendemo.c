

#include<stdio.h>



int main(){

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

return 0;
}