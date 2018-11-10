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

void deleteKey()
{
    NODE cur,next,prev;
    int key,flag=0;
    printf("Enter the key\n");
    scanf("%d",&key);
    if(first==NULL)
    {
        printf("List empty\n");
        return;
    }
    if(first->rlink==NULL)
    {
        if(first->info==key)
        {
            printf("%d is deleted",first->info);
            free(first);
            first=NULL;
            return;
        }
    }
    if(key==first->info)
    {
        printf("%d is deleted",first->info);
        cur=first;
        first=first->rlink;
        first->llink=NULL;
        free(cur);
        cur=NULL;
        return;
    }
    if(key==last->info)
    {
        printf("%d is deleted",last->info);
        cur=last;
        last=last->llink;
        last->rlink=NULL;
        free(cur);
        cur=NULL;
        return;
    }
    else{
        cur=first->rlink;
        while(cur!=NULL)
        {
            if(cur->info==key)
            {
                prev=cur->llink;
                next=cur->rlink;
                printf("%d is deleted",cur->info);
                free(cur);
                cur=NULL;
                prev->rlink=next;
                next->llink=prev;
                return;
                flag=1;
            }
            cur=cur->rlink;
        }
        if(flag==0)
            printf("KEY NOT FOUND");
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

    printf("1.insertfront\t2.insertkey\t3.deletekey\t4.display\t5.exit\n");
    for(;;)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insertfront();
                break;
            case 2: insertkey();
                break;
            case 3:deleteKey();
                break;
            case 4:display();
                break;
            case 5:exit(0);
                break;

        }/*end switch*/
    }/*end for*/
    getch();
}/*end main*/

