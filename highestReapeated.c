#include<stdio.h>
#include<ctype.h>
int main()
{
    char str[100];
    char max;
    int i,count=0,maxy=0;
    printf("Enter the String to find the letter with maximum repeatation\n");
    gets(str);
    for(i=0;str[i]!='\0';i++){
   str[i]=tolower(str[i]);
   for(int j=0;str[j]!='\0';j++){
if(str[i]==str[j])
{
    count++;
}
   }
if(count>maxy){
    maxy=count;
    max=str[i];
}
count=0;
    }
    printf(" letter %c is repeated %d times\n",max,maxy);

}