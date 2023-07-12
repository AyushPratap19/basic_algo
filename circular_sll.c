#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node * NODE;
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
void insert_front(NODE head,int item)
{
    NODE temp;
    temp=getNode();
    temp->info=item;
    temp->link=head->link;
    head->link=temp;
}
void insert_rear(NODE head,int item)
{
    NODE temp,cur=head;
    temp=getNode();
    temp->info=item;
    while(cur->link!=head)
    {
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=head;
}

void delete_front(NODE head)
{
    NODE first,next;
   if(head->link==head)
   {
    printf("no elements to delete\n");
    return;
   }
  
        first=head->link;
        next=first->link;
        printf("deleted element is %d\n",first->info);
        free(first);
        head->link=next;

}
void delete_rear(NODE head)
{
    NODE prev=NULL,cur=head;
   if(head->link==head)
   {
    printf("no elements to delete\n");
    return;
   }
  while(cur->link!=head){
    prev=cur;
    cur=cur->link;
  }
       
        printf("deleted element is %d\n",cur->info);
        free(cur);
        prev->link=head;

}


void display(NODE head)
{
    if(head->link==head)
    {
        printf("Nothing to display\n");
        return;
    }
    NODE curr=head->link;
    printf("Elements in circular sll :\n");
    while(curr!=head)
    {
        printf("%d\t",curr->info);
        curr=curr->link;
    }
    printf("\n");
}

int main() {
    int ch,item;
    NODE head=NULL;
    head=getNode();
    head->link=head;
    while(1)
    {
        printf("Enter 1:insert_f 2:insert_r 3:display  4:exit 5:delete_f 6: delete_r\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter item to insert\n");
            scanf("%d",&item);
            insert_front(head,item);
            break;

            case 2:
            printf("Enter item to insert\n");
            scanf("%d",&item);
            insert_rear(head,item);
            break;

            case 3:
            display(head);
            break;
             
             case 5:
             delete_front(head);
             break;

               case 6 :
             delete_rear(head);
             break;
         
            default:
            exit(0);
        }
    }
    return 0;
}