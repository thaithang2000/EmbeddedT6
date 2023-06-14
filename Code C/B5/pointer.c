#include<stdio.h>
void tong(int a, int b){
    printf("Tong %d+%d: %d\n",a,b,a+b);
}

void hieu(int a, int b){
    printf("Hieu %d-%d: %d\n",a,b,a-b);
}

void tich(int a, int b){
    printf("Tich %d*%d: %d\n",a,b,a*b);
}

double thuong(int a, int b){
   return (double)a/b;
}
void toanhoc(void (*ptr)(int, int), int a, int b){
    printf("Chuong trinh toan \n");
    ptr(a,b);
}
int main()
{
    double d = 10.3;
    char string[] = "Hello";
    void *ptr = &tong;
    void *array[] = {&toanhoc, &d, string};
    printf("Gia tri d %f\n",*(double*)(array[1]));
    printf("Gia tri cua string:\n");
    for(int i=0; i<5;i++)
    {
        printf("%c",*(char*)(array[2]+i));
    }
    return 0;
}