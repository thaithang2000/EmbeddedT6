#include <stdio.h>

/*
* Function: LengString
* Description: This function calculates the lengh of string
* Input:
*   arr - a string
* Output:
*   returns  i: the lengh of string
*/
int LenghString(char *arr){
    int i = 0;
    while(arr[i] != '\0')
    {
        i++;
    }
   return i;

}

/*
* Function: ReverseString
* Description: This function reverse the charactor in string
* Input:
*   arr   - a string
*   start - character begin
*   end   - character end
* Output:
*   Reveres string arr
*/
void ReveresString(char *arr, int start, int end){
    while(start < end){
        char temp  = arr[start];
        arr[start] = arr[end];
        arr[end]   = temp;
        start++;
        end--;
    }
}

/*
* Function: ReverseWord
* Description: This function reverse the Word in string
* Input:
*   arr   - a string
* Output:
*   Reveres word arr
*/
void ReveresWord(char *arr)
{
    int lengh = LenghString(arr);
    int start =0;

    for(int i = 0; i <= lengh; i++){
        if(arr[i]==' '||arr[i]=='\0'){
            ReveresString(arr, start, i-1);
            start = i + 1;
        }
    }
    ReveresString(arr, 0, lengh-1);
}
