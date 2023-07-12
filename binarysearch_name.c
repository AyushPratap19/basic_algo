#include <stdio.h>
#include<string.h>
int main()
{
    char name[10][20],key[20];
    int n,i,low,high,mid,found=0;
    printf("Enter the number of elements:\t");
    scanf("%d",&n);
    printf("Enter the names in ascending order\n");
    for(i=0;i<n;i++)
        scanf("%s",name[i]);
    printf("Enter the name to be searched:\t");
    scanf("%s",key);
    low=0;
    high=n-1;
    while(low<=high && found==0)
    {
        mid=(low+high)/2;
        if(strcmp(name[mid],key)==0)
            found=1;
        else if(strcmp(name[mid],key)<0)
            low=mid+1;
        else
            high=mid-1;
    }
    if(found==1)
        printf("name found in position:%d",mid+1);
    else
        printf("name not found");
    return 0;
}