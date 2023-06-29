#include <stdio.h>

/*
* Function: length
* Description: This function calculates the lengh of string
* Input:
*   arr - a string
* Output:
*   returns  i: the lengh of string
*/
int length(char *arr){
    int i = 0;
    while(arr[i] != '\0')
    {
        i++;
    }
   return i;

}

/*
* Function: reversestring
* Description: This function reverse the charactor in string
* Input:
*   arr   - a string
*   start - character begin
*   end   - character end
* Output:
*   Reveres string arr
*/
void reveresstring(char *arr, int start, int end){
    while(start < end){
        char temp  = arr[start];
        arr[start] = arr[end];
        arr[end]   = temp;
        start++;
        end--;
    }
}

/*
* Function: reverseword
* Description: This function reverse the Word in string
* Input:
*   arr   - a string
* Output:
*   Reveres word arr
*/
void reveresword(char *arr)
{
    int count = length(arr);
    int start =0;

    for(int i = 0; i <= count; i++){
        if(arr[i]==' '||arr[i]=='\0'){
            reveresstring(arr, start, i-1);
            start = i + 1;
        }
    }
    reveresstring(arr, 0, count-1);
}
