#include <stdio.h>
#include "inttwoarrpoint.h"


int main(void)
{

//
//#define INR_ARR_COLS_LENGTH 4
//#define INR_ARR_ROWS_LENGTH 5

int intarr[INR_ARR_ROWS_LENGTH] [INR_ARR_COLS_LENGTH]={0};
generTwoIntAtt(intarr);

printf("add before:\n");
printfArr(intarr);
plusvalue(intarr,101);
printf("add after:\n");
printfArr(intarr);
return 0;
}

void printfArr(int (*ptr)[INR_ARR_COLS_LENGTH]){
// 表示指向一个内含INR_ARR_COLS_LENGTH个int类型值的数组

    for(int i=0;i<INR_ARR_ROWS_LENGTH;i++){

        for(int j=0;j<INR_ARR_COLS_LENGTH;j++){
            printf("ptr[%d][%d]=%d \n",i,j,*(*(ptr+i)+j));
        }
    }
    printf("\n");
}

void plusvalue(int (*ptr)[INR_ARR_COLS_LENGTH],int plusValue){
// 表示一个内含INR_ARR_COLS_LENGTH个指针元素的的数组,每个元素都指向int的指针;

    for(int i=0;i<INR_ARR_ROWS_LENGTH;i++){

        for(int j=0;j<INR_ARR_COLS_LENGTH;j++){
                ptr[i][j]+=plusValue;
        }
    }
}

