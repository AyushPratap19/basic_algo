 #include<stdio.h>
#include<stdlib.h>

typedef
 struct node
 {
 int info;
 struct node *link;
 }*nd;

nd getnode()
{
nd x;
x=(nd)malloc(sizeof(struct node));
 if(x==NULL)
 {
 printf("memory not available");
 exit(0);
 }
return x;
}

void insert_f(nd head,int elem)
{
nd temp,next;
temp=getnode();
next=head->link;
temp->info=elem;
head->link=temp;
temp->link=next;

}

void insert_r(nd head,int elem)
{
nd temp,cur=head;
temp=getnode();
temp->info=elem;
temp->link=NULL;

 while(cur->link!=NULL)
 {
 cur=cur->link;
 }
cur->link=temp;

}

void delete_f(nd head)
{

 if(head->link==NULL)
 {
 printf("no elements to delete\n");
 return;
 }
nd first=head->link;
nd second=first->link;
head->link=second;

printf("deleted element is %d\n",first->info);
free(first);
}

void delete_r(nd head)
{
int elem;
nd cur=head,prev=NULL;
 if(head->link==NULL)
 {
 printf("no elements to delete\n");
 return;
 }
  while(cur->link!=NULL)
  {
   prev=cur;
   cur=cur->link;
  }
printf("deleted element is %d\n",cur->info);
free(cur);
prev->link=NULL;

}

void display(nd head)
{
nd cur=head->link;
 if(head->link==NULL)
 {
 printf("no elements to display\n");
 return;
 }
printf("elements of sll are:\n");
 while(cur!=NULL)
 {
 printf("%d ",cur->info);
 cur=cur->link;
 }
 printf("\n");
}

int main()
{
int ch,elem;
nd head;
head=getnode();
head->link=NULL;
 while(1)
 {
 printf("enter 1:insert_f 2:insert_r  3:delete_f 4:delete_r 5:display 6:exit \n");
 scanf("%d",&ch);
  switch(ch)
  {
  case 1:
  printf("enter the element\n");
  scanf("%d",&elem);
  insert_f(head,elem);
  break;
  
  case 2:
  printf("enter the element\n");
  scanf("%d",&elem);
  insert_r(head,elem);
  break;
  
  case 3:
  delete_f(head);
  break;
  
  case 4:
   delete_r(head);
  break;
  
  case 5:
  display(head);
  break;
  
  
  default: exit(0);
  
  }
 }
} 


