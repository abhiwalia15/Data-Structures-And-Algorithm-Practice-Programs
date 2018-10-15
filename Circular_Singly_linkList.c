#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;
    NODE last = NULL;

void insertbeg()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&temp->info);
    temp->link = temp; /*temp pointer pointing to itself*/
    if(last==NULL)
    {
        /*list empty*/
        last=temp;
    }
    else{
        temp->link = last->link;
        last->link = temp;
    }
}

void insertend()
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&temp->info);
    temp->link = temp; /*temp pointer pointing to itself*/
    if(last==NULL)
    {
        /*list empty*/
        last=temp;
    }
    else{
        temp->link = last->link;
        last->link = temp;
        last = temp;
    }
}

void deletebeg()
{
    NODE temp;
    if(last==NULL)
    {
        printf("List empty\n");
        return;
    }
    if(last->link = last)
    {
        printf("%d is deleted\n",last->info);
        free(last);
        last=NULL;
        return;
    }
    temp = last->link;
    last->link = temp->link;
    printf("%d is deleted\n",temp->info);
    free(temp);
    temp=NULL;
}

void deleteend()
{
    NODE cur;
    if(last==NULL)
    {
        printf("List empty\n");
        return;
    }
    if(last->link = last)
    {
        printf("%d is deleted\n",last->info);
        free(last);
        last=NULL;
        return;
    }
    cur=last->link;
    while(cur->link!=last)
    {
        cur=cur->link;
    }
    cur->link=last->link;
    printf("%d is deleted\n",last->info);
    free(last);
    last=cur;
}

void display()
{
    NODE cur;
    if(last==NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        cur=last->link;
        printf("The list is\n");
        while(cur!=last)
        {
            printf("%d\t",cur->info);
            cur=cur->link;
        }
        printf("%d\t",cur->info);
    }
}

void main()
{
    int ch;

    printf("1.insertfront\t2.insertend\t3.deletefront\t4.deleteend\t5.display\t6.exit\n");
    for(;;)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insertbeg();
                break;
            case 2: insertend();
                break;
            case 3: deletebeg();
                break;
            case 4: deleteend();
                break;
            case 5:display();
                break;
            case 6:exit(0);
                break;

        }/*end switch*/
    }/*end for*/
}/*end main*/
