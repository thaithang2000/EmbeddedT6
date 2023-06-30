/*
* File: main.c
* Author: Thai Thang
* Date: 30/06/2023
* Description: this file: find the position of x if the array has
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include"header/find.h"
int main(int argc, char const *argv[])
{
   uint16_t *array = createArray(1000);
   uint16_t result;
   sort(array,1000);

   for (uint16_t i = 0; i < 1000; i++)
   {
    printf("[%d] %d\n ",i, array[i]);
   }

   result = find(array, 10, 0, 999);
   if (result != 0)
   {
    printf("\n Position of x : %d \n", result);
   } else {
    printf("Do not have value x");
   }
   
    return 0;
}
