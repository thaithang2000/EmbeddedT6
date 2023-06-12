#include <stdio.h>
#include "test.c"
#define MAX 10

void display(){
    printf("Hello world\n");
}
int main(int argc, char const *argv[])
{
    // This is function
    display();
    printf("MAX: %d\n",MAX);
    test();
    return 0;
}