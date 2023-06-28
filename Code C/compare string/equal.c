#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

uint8_t i = 0;
bool isEqual(const char arr1[], const char arr2[]){
    while (arr1[i] == arr2[i])
    {
        if (arr1[i] == '\0')
        {
            return true;
        }
        i++;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    char arr1[] = "Hello";
    char arr2[] = "Hello";
    printf("Test: %d",isEqual(arr1, arr2));
    return 0;
}
