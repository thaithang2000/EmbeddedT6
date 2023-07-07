#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}node;

node* Createnode(int value){
    node *ptr = (node*) malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}

void push_back(node **array, int value){
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

int get(node *array, int index){
    int i = 0;
    while(index != i && array->next != NULL){
        array = array->next;
        i++;
    }
    return array->value;
}

void insert(node **array, int pos, int value){
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

void earse(node **array, int pos){
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

int main(int argc, char const *argv[])
{
    node *array = NULL;
    push_back(&array,7);
    push_back(&array,4);
    push_back(&array,11);
    printf("test: %d\n",get(array,2));
    earse(&array,2);
    printf("test: %d\n",get(array,2));
    insert(&array,2,100);
    printf("test: %d\n",get(array,2));
    return 0;
}
