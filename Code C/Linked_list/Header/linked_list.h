#ifndef LINKED_LIST
#define LINKED_LIST

/*
* File: linked_list.h
* Author: Thai Thang
* Date: 08/07/2023
* Description: This is a file include everything in preprocessor for linked_list.c
*/
#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int value;
    struct node *next;
}node ;

node *createNode(int value);
void push_back(node** array, int value);
void pop_back(node **array);
void insert(node **array, int pos, int value);
int size(node *array);
int get(node *array, int index);
void earse(node **array, int pos);


#endif