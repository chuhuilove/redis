

#include<stdio.h>
#include "demoA.h"
#include "demoB.h"

extern int demoA;

int main(){

demoA=10;
printDemoA();
demoA=1000;
printDemoAForB();
return 0;

}