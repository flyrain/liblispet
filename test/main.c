#include <stdio.h>
#include "../lispet.h"
void hello(){
    printf("hello, world");
}

int out_add(int x, int y){
    return x + y;
}

int x(int addr){
    int value = 123;
    return value;
}

void main(int argc, char ** argv){
    lispet(1);
}
