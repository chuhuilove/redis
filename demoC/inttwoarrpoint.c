#include <stdio.h>
#include "inttwoarrpoint.h"
#include "genarr.h"

int main(void)
{

//
//#define INR_ARR_COLS_LENGTH 4
//#define INR_ARR_ROWS_LENGTH 5

int (*intarr)[INR_ARR_COLS_LENGTH];
generTwoIntAtt(intarr);

printfArr(intarr);


return 0;
}

void printfArr(int (*ptr)[]){

for(int i=0;i<INR_ARR_ROWS_LENGTH;i++){

    for(int j=0;j<INR_ARR_COLS_LENGTH;j++){
        printf("ptr[%d][%d]=%d ",i,j,*(*(ptr+i)+j));
    }
}
printf("\n");

}

