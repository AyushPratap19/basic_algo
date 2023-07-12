#include<stdio.h>
#include<string.h>
int cmp(char s1[],char s2[]);
char con(char s1[],char s2[]);
int length(char s1[]);

int main(){
char s1[100],s2[100],c;
int len;
printf("enter string1\n");
gets(s1);
printf("enter string2\n");
gets(s2);
len=length(s1);
printf("length of s1=%d\n",len);
len=length(s2);
printf("length of s2=%d\n",len);
cmp(s1,s2);
c=con(s1,s2);
printf("concatenated string is : \n");
puts(s1);
return 0;
}

int cmp(char s1[],char s2[]){
    if(strlen(s1)!=strlen(s2))
    printf("strings are different\n");
    else
    for(int i=0;s1[i]!='\0';i++){
        if(s1[i]!=s2[i]){
            printf("strings are different\n");
            return 0;
        }
       else
       printf("strings are equal\n");
       return 0;

    }
}
int length(char s1[]){
    int len=0;
    while(s1[len]!='\0')
    len++;
    return (len);
}
char con(char s1[],char s2[]){
    int i,j;
    i=strlen(s1);
    for(j=0;s2[j]!='\0';i++,j++)
    s1[i]=s2[j];
    return s1;
}