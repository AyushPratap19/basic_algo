#include<stdio.h>
#include<stdlib.h>

typedef
struct node
{
    int info;
    struct node* link;
}*NODE;
 
NODE getnode()
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
void push(NODE top,int elem)
{
    NODE s;
    s=getnode();
    (top)++;
    s->info=elem;
    s->link=top;

}
void display(NODE top)
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d",top->info);
    }
}


int main()
{
    NODE top=-1;
    int ch,elem;
      while(1)
    {
        printf("Enter 1:push 2:pop 3: display 4:exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("enter the element to be inserted\n");
            scanf("%d",&elem);
            push(top,elem);
            break;

            case 2:
            pop(top);
            break;

            case 3:
            display(top);
            break;
         
            default:
            exit(0);
        }
    }
    return 0;
}
