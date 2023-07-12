#include<stdio.h>
int main(){
    int *ptr;
    int a=10;
    ptr=&a;
    printf("value of a is %d\n",a); //10
    printf("value of a is %d\n",*ptr); //10
    printf("address of a is %p\n",ptr); //address of a
     printf("address of a is %p\n",&a); //address of a
    printf("address of pointer is %p\n",&ptr); //address of ptr which is storing a
return 0;
}