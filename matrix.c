#include<stdio.h>
#include<math.h>
int main(){
     int i,j,m,n,p,q,k;
     int a[5][5],b[5][5],c[5][5];
printf("size of matrix A\n");
scanf("%d%d",&m,&n);
printf("size of matrix B\n");
scanf("%d%d",&p,&q);
if(n==p){
printf("enter elements of matrix A\n");
for(i=0;i<m;i++){
    for(j=0;j<n;j++){
        scanf("%d",&a[i][j]);
    }
}
printf("enter elements of matrix B\n");
for(i=0;i<p;i++){
    for(j=0;j<q;j++){
        scanf("%d",&b[i][j]);
    }
}
for(i=0;i<m;i++){
     for(j=0;j<q;j++){
        c[i][j]=0;
        for(k=0;k<n;k++){
            c[i][j]+=a[i][k]*b[k][j];
        }
}
}
for(i=0;i<m;i++){
     for(j=0;j<q;j++){
        printf("%d\t",c[i][j]);
     }
     printf("\n");
}
}
else 
printf("multiplication is not possible\n");
return 0;
}