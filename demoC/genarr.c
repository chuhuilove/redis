#include "genarr.h"


 void generIntArr(int * result){

     for(int i=0;i<INT_ARR_MAX_LENGTH;i++){
         *result=i+101;
         result++;
     }

}


void generTwoIntAtt(int (*ptr)[INR_ARR_COLS_LENGTH] ){
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

void generCharArr_1(char (*result)[10]){
//  result指向一个内含10个char类型值的数组
//
//char stacktrace[][CHAR_ARR_MAX_LENGTH]={"src/redis-server(print_stacktrace+0x25) [0x4c0c45]",
//                                       "src/redis-server(cyziServerLogRaw+0xf9) [0x4c0f79]",
//                                       "src/redis-server(cyziServerLog+0xbe) [0x4c106e]",
//                                       "src/redis-server(createClient+0x80) [0x441970]",
//                                       "src/redis-server(scriptingInit+0x4df) [0x48654f]",
//                                       "src/redis-server(initServer+0x624) [0x433964]",
//                                       "src/redis-server(main+0x40a) [0x42bf7a]",
//                                       "/lib64/libc.so.6(__libc_start_main+0xf5) [0x7fd165407555]",
//                                       "src/redis-server() [0x42c319]",
//				       "src/chuhui-server() [0x98cccde3f]"
//                                       };


}
void generCharArr_2(char *result[10]){
//  result是一个内含10指针元素的的数组,每个元素都指向char的指针;

result[0]="src/redis-server(print_stacktrace+0x25) [0x4c0c45]";
result[1]=                                                   "src/redis-server(cyziServerLogRaw+0xf9) [0x4c0f79]";
result[2]=                                                   "src/redis-server(cyziServerLog+0xbe) [0x4c106e]";
result[3]=                                                  "src/redis-server(createClient+0x80) [0x441970]";
result[4]=                                                   "src/redis-server(scriptingInit+0x4df) [0x48654f]";
result[5]=                                                   "src/redis-server(initServer+0x624) [0x433964]";
result[6]=                                                   "src/redis-server(main+0x40a) [0x42bf7a]";
result[7]=                                                   "/lib64/libc.so.6(__libc_start_main+0xf5) [0x7fd165407555]";
result[8]=                                                   "src/redis-server() [0x42c319]";
result[9]=            				       "src/chuhui-server() [0x98cccde3f]";

}