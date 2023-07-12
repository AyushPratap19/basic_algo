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

NODE insert_bst(NODE root,int info)
{
 NODE temp,cur=root,prev;
 temp=getNode();
 temp->rlink=temp->llink=NULL;
 temp->info=info;
 if(root==NULL)
 return temp;
 while(cur!=NULL)
 {
    prev=cur;
    if(cur->info>info)
    cur=cur->llink;
    else
    cur=cur->rlink;
 }
 if(prev->info<info)
 prev->rlink=temp;
 else
 prev->llink=temp;
 return root;
}
void preorder(NODE root)
{
    if(root==NULL)
    return;
    printf("%d",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}
void postorder(NODE root)
{
    if(root==NULL)
    return;
    
    preorder(root->llink);
    preorder(root->rlink);
    printf("%d",root->info);
}
void inorder(NODE root)
{
    if(root==NULL)
    return;
    
    preorder(root->llink);
    printf("%d",root->info);
    printf(" ");
    preorder(root->rlink);
    printf("\n");
}

int main()
{
    NODE root;
    root=NULL;
    int ch,elem;
     while(1)
    {
        printf("Enter 1:insert_bst 2:postorder 3:preorder  4:inorder 5:exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter item to insert\n");
            scanf("%d",&elem);
            root=insert_bst(root,elem);
            break;
            case 2:postorder(root);
            break;
            case 3:preorder(root);
            break;
            case 4:inorder(root);
            break;
            default:
            exit(0);
        }
    }
}