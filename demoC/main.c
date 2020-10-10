

#include<stdio.h>
#include "demoA.h"
#include "demoB.h"



int main(){
extern int demoAValue;
demoAValue=10;
printDemoA();
demoAValue=1000;
printDemoAForB();
return 0;

}