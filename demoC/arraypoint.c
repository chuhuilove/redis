

#include <stdio.h>



void  valuePlus(int * original,int arraylen,int valueplus);
void printfArr(int * original,int arraylen);

int main(void)
{




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
        puts(original[i]);
    }
    puts("\n");

}
