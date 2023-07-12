#include<stdio.h>
int convert(int bin);
int main(){
int dec,bin;
printf("enter a binary number\n");
scanf("%d",&bin);
dec=convert(bin);
printf("decimal equivalent to %d is %d\n",bin,dec);
return 0;
}
int convert(int bin){
    if(bin==0)
    return 0;
    else
    return(bin%10+2*convert(bin/10));
}