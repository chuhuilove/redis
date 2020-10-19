#include <stdio.h>
#include "tool.h"
#include "boar.h"
#define ARR_MAX_LENGTH 10
int main (void )
{
    int arr[ARR_MAX_LENGTH]={1000,2,3,2,23,5,67,85,21,34};
    int max=find_max(arr,ARR_MAX_LENGTH);
    int min=find_min(arr,ARR_MAX_LENGTH);
    printf("max value is %d\n",max);
    printf("min value is %d\n",min);
    return 0;
}
