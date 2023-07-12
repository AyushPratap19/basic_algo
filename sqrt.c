#include<stdio.h>
int main(){
    float n,root,temp=0;
    printf("enter the no.\n");
    scanf("%f",&n);
    if(n<0){
        printf("enter positive value\n");
    }
    else
    {
        root=n/2;
        while(root!=temp){
            temp=root;
            root=(root+n/root)/2;
        }
    }
    printf("sqrt of %f is %f\n",n,root);
}