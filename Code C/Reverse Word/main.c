#include <stdio.h>
#include "library/header.h"

int main(int argc, char const *argv[])
{  
    int i = 0;
    char arr[] = "Hello Everyone, How are you ?";
    printf("String: %s\n", arr);
    ReveresWord(arr);
    printf("Reverse string: %s", arr);
    return 0;
}