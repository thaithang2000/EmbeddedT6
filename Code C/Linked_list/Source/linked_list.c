/*
* File: linked_list.c
* Author: Thai Thang
* Date: 08/07/2023
* Description: This is a file include some basic operation of linked list
*/

#include "C:\Users\thang\Desktop\embedded\Linkedlist\Header\linked_list.h"


/*
* Function: createNode
* Description: create a node in a linked list have 2 member: value of the node and a pointer hold address of the next node
* Input:
*   value -  an integer value - value of the member 
* Output:
*   ptr - address of the node created
*/
node* Createnode(int value)
{
    node *ptr = (node*) malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}


/*
* Function: push_back
* Description: add a new node at the last position in the linked list
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
*   value - an integer value - value of the member
* Output:
*   new list with new node at the last position
*/
void push_back(node **array, int value)
{
    node *temp, *p;
    temp = Createnode(value);
    if (*array == NULL)
    {
        *array = temp;
    }else{
        p = *array;
        while (p->next != NULL)
        {
           p = p->next;
        }
        p->next = temp;
    }
    
}



/*
* Function: pop_back
* Description: delete a node at the last position in linkedlist
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
* Output:
*   new list without last node ( compare to the input list)
*/
void pop_back(node **array){
    node *temp, *p;
    int i = 0;
    int j;
    p = *array;
    temp = *array;
    while(p->next != NULL){
        p = p->next;
        i++;
    }
    free(p);
    for (j = 0; j < i-1; j++)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}


/*
* Function: insert
* Description: add a new node at position you want
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
*   value - an integer value - value of the node
*   pos - an interger value - position of the list to add new node
* Output:
*   new list with new node at the position input
*/
void insert(node **array, int pos, int value)
{
    node *temp, *p;
    temp = Createnode(value);
    p = *array;
    int i = 1;
    if (pos == 0)
    {
        temp->next = *array;
        *array = temp;
    } else{
        while(pos != i && p->next != NULL){
            p = p->next;
            i++;
        }
        temp->next = p->next;
        p->next = temp;
    }
}




/*
* Function: size
* Description: return the size of the linkedlist
* Input:
*   array - pointer has datatype is node -  address of pointer array which point to first node of linkedlist
* Output:
*   size - an integer value - size of list
*/
int size(node *array)
{
    int i = 1;
    while(array->next != NULL){
        array = array->next;
        i++;
    }
    return i;
}

/*
* Function: get
* Description: return value of the position you want
* Input:
*   array - pointer has datatype is node -  address of pointer array which point to first node of linkedlist
*   index - an integer value - position of the node you want to know it value
* Output:
*   value of the node you want to know - an integer value 
*/
int get(node *array, int index)
{
    int i = 0;
    while(index != i && array->next != NULL){
        array = array->next;
        i++;
    }
    return array->value;
}

/*
* Function: earse
* Description: delete the node at the position
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
*   pos - an integer value - position of the node you want to delete
* Output:
*   Delete the node at the position you want
*/
void earse(node **array, int pos)
{
    node *temp, *p;
    int i = 1;
    p = *array;
    if (pos == 0)
    {
        temp = *array;
        temp = temp->next;
        free(*array);
        *array = temp;
    }else{
        while(pos != i && p->next != NULL){
            p = p->next;
            i++;
        }
        temp = p->next->next;
        free(p->next);
        p->next = temp;
    }
    
}