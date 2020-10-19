#include <stdio.h>
#include "genarr.h"
#include "intarrpoint.h"



int main(void)
{

int original[INT_ARR_MAX_LENGTH];
generIntArr(original);

printf("add arr before:\n");
printfArr(original,INT_ARR_MAX_LENGTH);

valuePlus(original,INT_ARR_MAX_LENGTH,10);

printf("add 10 after:\n");

printfArr(original,INT_ARR_MAX_LENGTH);

return 0;
}

void  valuePlus(int * original,int arraylen,int valueplus)
{
    for(int i=0;i<arraylen;i++)
    {
        original[i]+=valueplus;
    }
}
void printfArr(int * original,int arraylen)
{
    for(int i=0;i<arraylen;i++)
    {
        puts(*original++);
    }
    puts("");

}
