#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *link;
    };

typedef struct node *NODE;
    NODE first=NULL;

void insert()
{
    NODE cur;
    NODE temp = (NODE)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&temp->info);
    temp->link = NULL;

    if(first==NULL)
    {
        first=temp;
        return;
    }

    cur = first;
    while(cur->link!=NULL)
        cur=cur->link;
    cur->link = temp;
}/*end function*/

void delete()
{
    NODE temp;
    if(first==NULL)
    {
        printf("Enter list empty\n");
        return;
    }/*end if*/
    else{
        temp=first;
        first = first->link;
        printf("%d is deleted from front",temp->info);
        free(temp);
        temp = NULL;
    }
}/*end function*/

void display()
{
    NODE cur;
    if(first==NULL)
    {
        printf("Enter list empty\n");
        return;
    }/*end if*/
    else{
        printf("The list is\n");
        cur=first;
        while(cur!=NULL)
        {
            printf("%d\t",cur->info);
            cur=cur->link;
        }
    }
}

void main()
{
    int ch;

    printf("1.push\t2.pop\t3.display\t4.exit\n");
    for(;;)
    {
        printf("Enter your choice\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insert();
                break;
            case 2: delete();
                break;
            case 3:display();
                break;
            case 4:exit(0);
                break;

        }/*end switch*/
    }/*end for*/
}/*end main*/

