/*
 * Function: random_number
 * Description: This function: create a random number between minN and maxN
 * Input:
 *   minN   - an integer value
 *   maxN     - an integer value
 * Output: return a number
 */
#include "Header/find.h"

uint16_t random_number(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}
/*
 * Function: createArray
 * Description: This function: creat an array with the length we want and add random value (from 1 to 1000) for array
 * Input:
 *   length    - an interger value
 */
uint16_t *createArray(uint16_t length){
    uint16_t *ptr = (uint16_t*)malloc(sizeof(uint16_t)*length);
    srand((int)time(0));
    for (uint16_t i = 0; i < length; i++)
    {
        ptr[i] = random_number(1, 1000);
    }
    return ptr; 
}

/*
 * Function: sort
 * Description: This function: sort the array from small to big
 * Input:
 *   arr[]    -  an interger array
 *   length    - an interger value
 */
void sort(uint16_t arr[], uint64_t length){
    uint16_t temp;
    for (uint16_t i = 0; i < length - 1; i++)
    {
        for (uint16_t j = i + 1; j < length ; j++)
        {
            if (arr[i] > arr[j])
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        }
    }
    
}

/*
 * Function: find
 * Description: This function: find the value x if the array has
 * Input:
 *   arr[]   - an interger array
 *   x       - an integer value has to find in array
 *   min     - position start to find
 *   max     - position stop finding
 * Output: return postition if can find, 0 if can not find
 */
uint16_t find(uint16_t arr[], uint16_t x, uint16_t min, uint16_t max){
    uint16_t mid;
    while (max >= min)
    {
        mid = min + (max - min)/2;
        if (x == arr[mid])
        {
            return mid;
        } else if (x > arr[mid])
        {
            min = mid + 1;
        } else{
            max = mid - 1;
        }
    }
    return 0;
}