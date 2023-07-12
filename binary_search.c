#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,low,mid,high,key,n,a[100];
    printf("size of array\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("enter key element\n");
    scanf("%d",&key);
    low=0;
    high=n-1;
    while(low<=high){
        mid=(low+high)/2;
        if (a[mid]==key){
            printf("element %d is found at %d\n ",key,mid+1);
            exit(0);
        }
        else if(key<a[mid])
        high=mid-1;
        else
        low=mid+1;
    }
    printf("unsuccessful search\n");
    return 0;

}