#include<stdio.h>
#include<stdlib.h>
typedef
struct node
{
    struct node *llink;
    int info;
     struct node *rlink;
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
NODE insert_front(NODE first,int elem){
    NODE temp;
    temp=getNode();
    temp->info=elem;
    if(first==NULL)
    {
        temp->rlink=NULL;
        temp->llink=NULL;
        return temp;
    }
    temp->rlink=first;
    first->llink=temp;
    return temp;
}
NODE insert_rear(NODE first,int elem)
{
NODE temp,cur;
temp=getNode();
temp->info=elem;
if(first==NULL)
    {
        temp->rlink=temp->llink=NULL;
        return temp;
    }
    cur=first;
    while(cur->rlink!=NULL){
        cur=cur->rlink;
    }
    temp->llink=cur;
    cur->rlink=temp;
    return first;
}

NODE delete_front(NODE first)
{
NODE next;
//case1:no nodes
if(first==NULL){
    printf("No elements in dll\n");
    return first;
}
//case2:only one node
if(first->rlink==NULL){
    printf("Deleted element is %d\n",first->info);
    free(first);
    return NULL;
}
//case3:multiple nodes
next=first->rlink;
next->llink=NULL;
printf("deleted element is %d\n",first->info);
free(first);
return next;
}

NODE delete_rear(NODE first)
{
    NODE prev,cur;
    if(first==NULL)
    {
    printf("No elements in dll\n");
    return first;
    }
    if(first->rlink==NULL)
    {
    printf("Deleted element is %d\n",first->info);
    free(first);
    return NULL;
    }
    cur=first;
    prev=NULL;
    while(cur->rlink!=NULL)
    {
       prev=cur;
       cur=cur->rlink;
    }
    printf("deleted element is %d\n",cur->info);
    free(cur);
    prev->rlink=NULL;
    return first;
}
int length_dll(NODE first)
{
    NODE cur=first;
    int count=0;
    while(cur!=NULL)
    {
        cur=cur->rlink;
        count++;
    }
    return count;
}

NODE combine_dll(NODE fdll,NODE sdll)
{
    NODE res;
    while(fdll!=NULL)
    {
        int item=fdll->info;
        res=insert_rear(res,item);
        fdll=fdll->rlink;
    }
     while(sdll!=NULL)
    {
        int item=sdll->info;
        res=insert_rear(res,item);
        sdll=sdll->rlink;
    }
    return res;
}

void display(NODE first)
{
    NODE cur=first;
    if(first==NULL)
    {
        printf("empty dll\n");
        return;
    }
    printf("elements of dll are:\n");
    while(cur!=NULL)
    {
        printf("%d ",cur->info);
        cur=cur->rlink;
    }
    printf("\n");
}
int main()
{
    NODE first=NULL;
    int ch,elem;
      while(1)
    {
        printf("Enter 1:insert_f 2:insert_r 3:display  4:exit 5:delete_f 6: delete_r 7:count 8:combine two dll\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter item to insert\n");
            scanf("%d",&elem);
            first=insert_front(first,elem);
            break;

            case 2:
            printf("Enter item to insert\n");
            scanf("%d",&elem);
            first=insert_rear(first,elem);
            break;

            case 3:
            display(first);
            break;
             
             case 5:
             first=delete_front(first);
             break;

               case 6 :
             first=delete_rear(first);
             break;
             case 7:
             printf("no. of nodes are %d\n",length_dll(first));
         
            default:
            exit(0);
        }
    }
    return 0;
}