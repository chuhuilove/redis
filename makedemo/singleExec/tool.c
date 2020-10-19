#include "tool.h"
#include<stdio.h>

int find_max(int * arr,int n)
{

	int m=arr[0];
    printf("the arr[0] = %d\n",m);
	for(int i=0;i<n;i++)
	{
        if(m < *(arr))
		{
            m= * arr;
		}
        arr++;
	}
	return m;
}
