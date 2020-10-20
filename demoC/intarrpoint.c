#include <stdio.h>
#include "genarr.h"
#include "intarrpoint.h"



int main(void)
{

int original[INT_ARR_MAX_LENGTH];
generIntArr(original);

printf("add arr before:\n");
printfArr(original,INT_ARR_MAX_LENGTH);

valuePlus(original,INT_ARR_MAX_LENGTH,101);

printf("add 10 after:\n");

printfArr(original,INT_ARR_MAX_LENGTH);

return 0;
}

void  valuePlus(int * original,int arraylen,int valueplus)
{
    for(int i=0;i<arraylen;i++)
    {
        *original+=valueplus;
	original++;
    }
}
void printfArr(int * original,int arraylen)
{
    for(int i=0;i<arraylen;i++)
    {
        //printf("%d ",*original++);  // *original; original++;
        //printf("%d ",original[i]);  // 直接将其当做数组来操作
        printf("%d ",*(original+i));  // 数组名,向后偏移的位置
    }
    printf("\n");

}
