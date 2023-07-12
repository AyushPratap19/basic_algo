#include<stdio.h>
#include<stdlib.h>
typedef
struct emp
{
    int id;
    char name[20];
    int salary;
}E;
typedef
struct node
{
    struct node*llink;
    E E1;
    struct node*rlink;
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
NODE insert_front(NODE first){
    NODE temp;
    temp=getNode();
    printf("enter the employee details\n");
    scanf("%d%s%d",&((temp->E1).id),(temp->E1).name,&((temp->E1).salary));
    if(first==NULL)
    {
        temp->rlink=temp->llink=NULL;
        return temp;
    }
    temp->rlink=first;
    first->llink=temp;
    return temp;
}

void highest_sal(NODE first)
{
    int max=0;
    NODE cur=first;
    while(cur!=NULL)
    {
        if((cur->E1).salary>max)
        max=(cur->E1).salary;
        
        cur=cur->rlink;
    }
    
    cur=first;
    while(cur!=NULL)
    {
        if((cur->E1).salary==max)
        {
            printf("Eid:%d En:%s Esal:%d \n",(cur->E1).id,(cur->E1).name,(cur->E1).salary);
        }
        cur=cur->rlink;
    }
}


void letter_A(NODE first)
{
    NODE cur=first;
    while(cur!=NULL)
    {
        if((cur->E1).name[0]=='A'){
        printf("Eid:%d En:%s Esal:%d \n",(cur->E1).id,(cur->E1).name,(cur->E1).salary);
        }
        
        cur=cur->rlink;
    } 
}

void updateName(NODE first)
{
    char updtName[20];
    int id;
    printf("Enter Id to update\n");
    scanf("%d",&id);
    printf("Enter Name to update with\n");
    scanf("%s",updtName);
    
    NODE cur=first;
    while(cur!=NULL)
    {
        if((cur->E1).id==id)
        break;
        cur=cur->rlink;
    }
    strcpy((cur->E1).name,updtName);
    
    printf("Eid:%d En:%s Esal:%d \n",(cur->E1).id,(cur->E1).name,(cur->E1).salary);
    
}

void display(NODE first)
{
    NODE cur=first;
    if(first==NULL)
    {
        printf("empty dll\n");
        return;
    }
    printf("ID   NAME   SALARY\n");
    while(cur!=NULL)
    {
        printf("%d   %s   %d\n",(cur->E1).id,(cur->E1).name,(cur->E1).salary);
        cur=cur->rlink;
    }
    printf("\n");
}

int main()
{
    NODE first=NULL;
    int ch;
      while(1)
    {
        printf("Enter 1:insert 2:emp with highest salary 3: name starting with letter 'A' 4:update based on ID 5:display  6:exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            first=insert_front(first);
            break;

            case 2:
            highest_sal(first);
            break;

            case 3:
            letter_A(first);
            break;

            case 4:
            update(first);
            break;

            case 5:
            display(first);
            break;
         
            default:
            exit(0);
        }
    }
    return 0;
}