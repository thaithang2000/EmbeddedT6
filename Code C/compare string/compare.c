#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef enum {
    SMALLER,
    BIGGER,
    EQUAL
} Compare;

uint8_t i = 0;
Compare isEqual(const char arr1[], const char arr2[]){
    while (arr1[i] == arr2[i])
    {
        if (arr1[i] == '\0')
        {
            return EQUAL;
        }
        i++;
    }
     if(arr1[i] > arr2[i]) 
     {
         return BIGGER;
     } else {
        return SMALLER;
     }
}

int main(int argc, char const *argv[])
{
    char arr1[] = "Hello";
    char arr2[] = "Hello";
    printf("Test %d",isEqual(arr1,arr2));
    return 0;
}
