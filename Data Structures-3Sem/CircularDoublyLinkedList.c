#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *llink;
    struct node *rlink;
    };

typedef struct node *NODE;
    NODE last=NULL;

void insert()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    NODE next;

    printf("Enter the data\n");
    scanf("%d",&temp->info);

    temp->llink = temp;
    temp->rlink = temp;

    if(last==NULL) {
        last=temp;
        return;
    }
    next=last->rlink;
    temp->rlink=next;
    next->llink=temp;
    last->rlink=temp;
    temp->llink=last;
    return;
}

void display()
{
    NODE cur;
    if(last==NULL)
    {
        printf("LIST EMPTY\n");
        return;
    }
    cur=last->rlink;
    printf("The lsit is \n");
    while(cur!=last)
    {
        printf("%d\t",cur->info);
        cur=cur->rlink;
    }
   printf("%d\t",cur->info);
}

void main()
{
    int ch;
    printf("1.insert\t2.display\t3.exit\n");
    for(;;)
    {
        printf("Enter your choice \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:insert();
                break;
            case 2:display();
                break;
            case 3:exit(0);
                break;
        }
    }
    getch();
}

