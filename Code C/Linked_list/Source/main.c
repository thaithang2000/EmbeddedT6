/*
* File: main.c
* Author: Thai Thang
* Date: 08/07/2023
* Description: This is a main file using to test some basic operation of linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include "C:\Users\thang\Desktop\embedded\Linkedlist\Header\linked_list.h"


int main()
{
    int i, length;
    node *array = NULL;
    push_back(&array,7);
    push_back(&array,4);
    push_back(&array,11);
    push_back(&array,1);
    push_back(&array,8);
    length = size(array);
    printf("size: %d\n",length);
    printf("Value of node:\n");
    for ( i = 0; i < length; i++)
    {
        printf("%d ",get(array,i));
    }
    printf("\n");
    earse(&array,2);
    length = size(array);
    printf("size: %d\n",length);
    printf("Value of node:\n");
    for ( i = 0; i < length; i++)
    {
        printf("%d ",get(array,i));
    }
    printf("\n");
    printf("Value of node 2: %d\n",get(array,2));
    insert(&array,2,100);
    length = size(array);
    printf("size: %d\n",length);
    printf("Value of node:\n");
    for ( i = 0; i < length; i++)
    {
        printf("%d ",get(array,i));
    }
    printf("\n");
    printf("Value of node 2:: %d\n",get(array,2));
    pop_back(&array);
    length = size(array);
    printf("size: %d\n",length);
    printf("Value of node:\n");
    for ( i = 0; i < length; i++)
    {
        printf("%d ",get(array,i));
    }
    printf("\n");
    return 0;
}