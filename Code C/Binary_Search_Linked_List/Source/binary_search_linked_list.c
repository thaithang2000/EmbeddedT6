/*
* File: binary_search_linked_list.c
* Author: Thai Thang
* Date: 10/07/2023
* Description: This is a file include some operation for binary search in linked list
*/

#include "C:\Users\thang\Desktop\embedded\Binary_Search_Linked_List\Header\binary_search_linked_list.h"


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
* Function: add_sort_node
* Description: add a new node at the last position in the linked list and sort the list from small value to big value
* Input:
*   array - pointer to pointer has datatype is node -  address of pointer array which point to first node of linkedlist
*   value - an integer value - value of the member
* Output:
*   new list is sorted from small to big
*/
void add_sort_node(node **array,int value){
    node *temp, *p;
    temp = Createnode(value);
    p = *array;
    if(*array == NULL || (*array)->value > value) // if the first node is null or value of first node > new node 
    {                                             // theb switch postion of two node                  
        temp->next = *array;                       
        *array = temp;
        return;
    }

    while (p->next != NULL && p->next->value < value) // search if next node is the last node or value of next node < new node 
    {                                                 // then switch position of two node
        p = p->next;
    }
    temp->next = p->next;   
    p->next =temp;
}



/*
* Function: tree_diagram
* Description: find all the middle position's value in linkedlist
* Input:
*   array - pointer has datatype is node 
*   start - position to start finding
*   end - position to end finding
* Output:
*   The list with all middle position's value
*/
centernode *tree_diagram(node *array, int start, int end){
    if (array == NULL || start > end)  //if there is not any node in linked list or start position > end position
    {
        return NULL;
    }
    int mid = (start + end)/2;
    node *temp = array;
    for (int i = start; i < mid; i++) // break if run to the last node in linked list 
    {
        if (temp->next == NULL)
        {
            break;
        }
        temp = temp->next;
    }
    centernode *root = (centernode*)malloc(sizeof(centernode)); // create a list to store all middle position's value
    root->value = temp->value;
    root->left = tree_diagram(array,start,mid-1); // find a middle position's value from the left of the list
    root->right = tree_diagram(temp->next,mid+1,end); // find a middle position's value from the right of the list
    return root;
}


/*
* Function: center
* Description: find the lenght of the list and all the middle position's value
* Input:
*   array -pointer has datatype is node 
* Output:
*   Function: tree_diagram(array,0,size-1);
*   All the middle position's value
*/
centernode *center(node *array){
    int size = 0;
    node *temp = array;
    while (temp != NULL) // find the size of linked list
    {
        size++;
        temp = temp->next;
    }
    return tree_diagram(array,0,size-1);
}




/*
* Function: binary_search
* Description: Find if the linked list have the value
* Input:
*   root - pointer has datatype is centernode - which is stored all the middle position's value
*   value - an interger value to find 
* Output:
*   Null if not have the value
*   root if have the value
*/
centernode *binary_search(centernode* root, int value){
    static int loop;
    loop++;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->value == value)
    {
        printf("tong so lan lap: %d\n",loop);
        return root;
    }
    
    if (value > root->value)
    {
        return binary_search(root->right, value);
    } else{
        return binary_search(root->left,value);
    }
    
    
}

/*
* Function: print_list
* Description: print all the value in linked list
* Input:
*   array - pointer has datatype is node
* Output:
*   print all the value in array 
*/
void print_list(node *array){
    while (array != NULL)
    {
        printf("%d  ",array->value);
        array = array->next;
    }
    
}

