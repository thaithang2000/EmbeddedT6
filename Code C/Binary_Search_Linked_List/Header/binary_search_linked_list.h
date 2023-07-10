#ifndef BINARY_SEARCH_LINKED_LIST
#define BINARY_SEARCH_LINKED_LIST

/*
* File: binary_search_linked_list.h
* Author: Thai Thang
* Date: 10/07/2023
* Description: This is a file include everything in preprocessor for binary search in linked_list.c
*/
#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int value;
    struct node *next;
}node ;

typedef struct centernode
{
    int value;
    struct centernode *left;
    struct centernode *right;
}centernode;

node *Createnode(int value);
void add_sort_node(node **array,int value);
centernode *tree_diagram(node *array, int start, int end);
centernode *center(node *array);
centernode *binary_search(centernode* root, int value);
void print_list(node *array);


#endif