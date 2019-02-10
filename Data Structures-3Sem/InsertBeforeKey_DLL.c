#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *llink;
    struct node *rlink;
    };

typedef struct node *NODE;
    NODE first=NULL;
    NODE last=NULL;

void insertfront()
{
   NODE temp = (NODE)malloc(sizeof(struct node));
        printf("Enter the data\n");
        scanf("%d",&temp->info);
        temp->llink = NULL;
        temp->rlink = NULL;

        if(first==NULL) {
            first=last=temp;
            return;
        }

        else {
                temp->rlink=first;
                first->llink=temp;
                first=temp;
        }
}

void insertend()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&temp->info);
    temp->llink = NULL;
    temp->rlink = NULL;

    if(first==NULL) {
        first=last=temp;
        return;
    }

    else {
        temp->llink=last;
        last->rlink=temp;
        last=temp;
    }
}

void insertkey()
{
    NODE cur,prev;
    int key;
    printf("Enter the key \n");
    scanf("%d",&key);

    NODE temp = (NODE)malloc(sizeof(struct node));

    printf("Enter the data\n");
    scanf("%d",&temp->info);

    temp->llink = NULL;
    temp->rlink = NULL;

    if(first==NULL) {
        first=last=temp;
        return;
    }

    else if(key==first->info)
    {
        temp->rlink=first;
        first->llink=temp;
        first=temp;
        return;
    }

    else
    {
        cur=first->rlink;
        while(cur!=NULL)
        {
            if(cur->info==key)
            {
                prev=cur->llink;
                prev->rlink=temp;
                temp->llink=prev;
                temp->rlink=cur;
                cur->llink=temp;
            }
            cur=cur->rlink;
        }

    }


}

void deletebeg()
{
    NODE temp;
    if(first==NULL)
    {
        printf("List Empty\n");
        return;
    }

    else if(first->rlink==NULL)
    {
        printf("%d is deleted\n",first->info);
        free(first);
        first=NULL;
    }

    else
    {
        temp=first;
        first=first->rlink;
        first->llink=NULL;
        printf("%d is deleted\n",temp->info);
        free(temp);
        temp=NULL;
    }
}

void deleteend()
{
    NODE temp;
    if(first==NULL)
    {
        printf("List Empty\n");
        return;
    }

    else if(first->rlink==NULL)
    {
        printf("%d is deleted\n",first->info);
        free(first);
        first=NULL;
    }

    else
    {
        temp=last;
        last=last->llink;
        last->rlink=NULL;
        printf("%d is deleted\n",temp->info);
        free(temp);
        temp=NULL;
    }
}

void display()
{
    NODE cur;

    if(first==NULL)
    {
        printf("LIst EMPTY\n");
        return;
    }

    else
    {
        cur=first;
        printf("THE LIST IS\n");
        while(cur!=NULL)
        {
            printf("%d\t",cur->info);
            cur=cur->rlink;

        }
    }
}

void main()
{
    int ch;

    printf("1.insertfront\t2.insertend\t3.deletefront\t4.deleteend\t5.display\t6.insert before key\t7.exit\t\n");
    for(;;)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insertfront();
                break;
            case 2: insertend();
                break;
            case 3: deletebeg();
                break;
            case 4: deleteend();
                break;
            case 5:display();
                break;
            case 7:exit(0);
                break;
            case 6:insertkey();
                break;
        }/*end switch*/
    }/*end for*/
}/*end main*/




















