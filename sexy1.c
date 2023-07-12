#include <stdio.h>
int main() 
{
char ch;
char s[100], str[100];

scanf("%c",&ch);
// %s ke baad space daalna mandatory hai
scanf("%s ",s);
gets(str);

printf("%c \n",ch);
printf("%s \n",s);
printf("%s \n",str);

return 0;
   
}
