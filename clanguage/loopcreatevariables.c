#include <stdio.h>
#include<stdlib.h>

int main(void){


for(int i=0;i<100;i++){

    int intarr[100]={i};
    int a=i;
    int b=i+100;
    float c=1.0f;

    int * m=(int*)malloc(sizeof(int));
    *m=i;
    printf("intarr address is:%p,a address is:%p,b address is %p,c address is %p, m is %p\n",intarr,&a,&b,&c,m);
//    free(m);
    }

return 0;

}
