
#include "demoA.h"
#include "demoB.h"
#include <stdio.h>

extern int demoAValue;

void printDemoAForB(){
extern int demoAValue;
printf("the demoA is:%d,in demoB",demoAValue);

}
