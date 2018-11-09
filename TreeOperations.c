#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE ;
    NODE root=NULL;

void inorder(NODE root)
{
    if(root==NULL)
        return;

    inorder(root->llink);
    printf("%d\t",root->info);
    inorder(root->rlink);
}

void preorder(NODE root)
{
    if(root==NULL)
        return;

    printf("%d\t",root->info);
    preorder(root->llink);
    preorder(root->rlink);
}

void postorder(NODE root)
{
    if(root==NULL)
        return;

    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t",root->info);
}

void ConstructBST()
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    NODE prev,cur;
    printf("Enter the data\n");
    scanf("%d",&temp->info);
    temp->rlink=temp->llink=NULL;

    if(root==NULL)
    {
        root=temp;
        return;
    }

    prev=cur;
    cur=root;
    while(cur!=NULL)
    {
        prev=cur;
        if(temp->info<cur->info)
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    if(temp->info<prev->info)
        prev->llink=temp;
    else
        prev->rlink=temp;
}

void main()
{

    int n,ch,i;

    printf("ENTER YOUR CHOICE\n");
    printf("1.Construct binary tree\t2.Preorder\t3.inorder\t4.postorder\t5.exit\n");
    for(;;)
    {
        printf("Enter choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("Enter no. of elements\n");
                   scanf("%d",&n);
                   for(i=0;i<n;i++)
                        ConstructBST();
                   break;

            case 2:printf("preorder trversal\n");
                   preorder(root);
                   break;

            case 3:printf("Inorder traversal\n");
                   inorder(root);
                   break;

            case 4:printf("postorder traversal\n");
                   postorder(root);
                   break;

            case 5:exit(0);
                   break;

            default: printf("Invalid choice\n");

    }

}

getch();

}
