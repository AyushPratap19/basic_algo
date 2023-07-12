//sine series expansion
#include<stdio.h>
#include<math.h>
int main(){
    int i,degree;
    float x,num,deno,sum=0,term;
    printf("enter the degree to calculate sine\n");
    scanf("%d",&degree);
    x=degree*3.142/180;
    num=x;
    deno=1;
    i=2;
    do{
        term=num/deno;
        num=-num*x*x;
        deno=deno*i*(i+1);
        sum=sum+term;
        i=i+2;
    }
    while(fabs(term)>=0.000001);
    printf("sine of %d is %.3f\n",degree,sum);
    printf("predefined sine value of %d is %.3f\n",degree,sin(x));
    return 0;
}