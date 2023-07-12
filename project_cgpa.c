#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef
struct node
{
    char subject[10];
    int marks;
    int credit;
     struct node *link;
}*NODE;

NODE getNode()
{
    NODE x=NULL;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
    {
        printf("Memory isn't allocated \n");
        exit(0);
    }
    return x;
}

void insert_r(NODE head,char a[10],int credit,int marks)
{
NODE temp,cur=head;
temp=getNode();

strcpy(temp->subject,a);
temp->credit=credit;
temp->marks=marks;
temp->link=NULL;

 while(cur->link!=NULL)
 {
 cur=cur->link;
 }
cur->link=temp;

}

void display(NODE head)
{
NODE cur=head->link;
 if(head->link==NULL)
 {
 printf("no elements to display\n");
 return;
 }
printf("Subject  \t credit  marks  remark\n\n");
 while(cur!=NULL)
 {
     if(cur->marks<40)
     {
     printf("%s    \t  %d  \t  %d  \t   F\n",cur->subject,cur->credit,cur->marks);
     }
     else
     printf("%s    \t  %d  \t  %d  \t   P\n",cur->subject,cur->credit,cur->marks);

      cur=cur->link;
 }
 printf("\n");
}


void cgpa(NODE head)
{
    NODE cur=head->link;
    int sum=0,sum1=0,sum2=0,sum3=0,sum4=0,total;

    while(cur!=NULL)
    {
      sum=sum+(cur->credit);
      cur=cur->link;
    }

    NODE cur2=head->link;
    while(cur2!=NULL)
    {
      if(cur2->marks<40)
      {
       cur2=cur2->link;
        continue;
      }

      if(cur2->credit==4)
      {
       
        
        if(cur2->marks>=100)
        {
            cur2->marks=99;
        }
      
        sum1=sum1+(((cur2->marks)/10)+1)*4;
      }

      else if(cur2->credit==3)
  
      {
         if(cur2->marks>=100)
        {
            cur2->marks=99;
        }
       
        sum2=sum2+(((cur2->marks)/10)+1)*3;
      }

      else if(cur2->credit==2)
      {
        if(cur2->marks>=100)
        {
            cur2->marks=99;
        }
        sum3=sum3+(((cur2->marks)/10)+1)*2;
      }
      
      else 
      {
        if(cur2->marks>=100)
        {
            cur2->marks=99;
        }
        sum4=sum4+(((cur2->marks)/10)+1);
      }
      
      cur2=cur2->link;

    }
   
    total=sum1+sum2+sum3+sum4;
    float cgpa=(float)total/sum;
    printf("CGPA : %f\n",cgpa);

}

int main()
{
    NODE head;
    head=getNode();
    head->link=NULL;

    
    int i,n,credit,marks;
    char a[10];
    printf("enter the no. of subjects in your semester\n");
    scanf("%d",&n);
    
    while(n--)
    {
        printf("enter your subject\n");
        scanf("%s",a);
        printf("enter the marks of the subject\n");
        scanf("%d",&marks);
        printf("enter the credits of this subject\n");
        scanf("%d",&credit);
       insert_r(head,a,credit,marks);
    }
    display(head);
    cgpa(head);
    
}