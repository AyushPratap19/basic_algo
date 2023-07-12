#include<stdio.h>
#include<math.h>

int main()
{
int dig,n,rev=0,temp;
printf("enter\n");
scanf("%d",&n);
temp=n;
while(n!=0)
 {
    dig=n%10;
    rev=dig+rev*10;
    n=n/10;
 }
   if(temp==rev)
    printf("pall\n");
   else
    printf(" not pall\n");

}