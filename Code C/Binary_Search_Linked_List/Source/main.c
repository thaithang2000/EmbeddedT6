/*
* File: main.c
* Author: Thai Thang
* Date: 10/07/2023
* Description: This is a main file using to test binary search in  linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "C:\Users\thang\Desktop\embedded\Binary_Search_Linked_List\Header\binary_search_linked_list.h"


int main()
{
    node *array = NULL;
    //tao ngau nhien 10000 node
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        int value = rand() % 10000 + 1;
        add_sort_node(&array, value);
    }
    add_sort_node(&array,11);
    print_list(array);
    centernode *ptr = center(array);
    centernode *result = binary_search(ptr,11);
    if (result == NULL)
    {
        printf("khong tim thay");
    }else{
        printf("tim thay %d\n",result->value);
    }
    
    return 0;
}