#include<stdio.h>
int main()
{
    int n,s,i,j,cf=1;
    printf("enter the number of rows in pascal triangle\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(s=1;s<=n-i;s++)
        {
            printf(" ");
        }
        for(j=0;j<=i;j++)
        {
            if(i==0||j==0)
            {
                cf=1;
            }
            else
            {
                cf=cf*(i-j+1)/j;
            }
            printf("%4d",cf);
        }
        printf("\n");
    }
}