#include "boar.h"

int find_min(int * arr,int n)
{
    int m=*arr;

    for(int i=0;i<n;i++)
    {
        if(m> *arr){
            m=*arr;
        }
        arr++;
    }

    return m;
}
