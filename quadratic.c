// program to calculate roots of the quadratic equation //
#include<stdio.h>
#include<math.h>
int main(){
    float a,b,c;
    float disc,deno,r1,r2;
    printf("enter the values of a,b,c\n");
    scanf("%f%f%f",&a,&b,&c);
    deno=2*a;
    disc=b*b-4*a*c;
    if(a==0&&b==0)
    {
        printf("invalid input\n");
        printf("please try with another value\n");
    }
    else if(a==0)
    {
        printf("the equation is linear\n");
        r1=-c/b;
        printf("ROOT :%f",r1);
    }
    else if(disc>0)
    {
        printf("roots are real and distinct\n");
     r1=(-b+sqrt(disc))/deno;
     r2=(-b-sqrt(disc))/deno;
     printf("ROOT1 :%f   ROOT2 :%f\n",r1,r2);
}
   else if(disc==0){
    printf("roots are real and equal\n");
    r1=-b/deno;
    r2=-b/deno;
printf("ROOT1 :%f   ROOT2=%f\n",r1,r2);
   }
else {
    printf("roots are imaginary\n");
    float real=-b/deno;
    float img=sqrt(-disc)/deno;
    printf("ROOT1 :%f+i%f  ROOT2 :%f-i%f",real,img,real,img);
}
return 0;
   }