#include "genarr.h"


 void generIntArr(int * result){

     for(int i=0;i<INT_ARR_MAX_LENGTH;i++){
         *result=i+101;
         result++;
     }

}


void generTwoIntAtt(int (*ptr)[] ){
//int zippo[4][2];
// 怎么解释这个二维数组
// zippo的首元素是一个内含两个int值的数组

//#define INR_ARR_COLS_LENGTH 4
//#define INR_ARR_ROWS_LENGTH 5


for(int i=0;i<INR_ARR_ROWS_LENGTH;i++){
    for(int j=0;j<INR_ARR_COLS_LENGTH;j++){
        *(*(ptr+i)+j)=i+j+107;
    }
}


//int (*pz)[2]; // pz指向一个内含两个int类型值的数组

//int *pax[2]; // pax是一个内含两个指针元素的的数组,每个元素都指向int的指针;





}

void generCharArr(char *result []){

}
