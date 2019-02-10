#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *link;
    };

typedef struct node *NODE;
    NODE first=NULL;

void insertfront()
    {
        NODE temp = (NODE)malloc(sizeof(struct node));
        printf("Enter the data\n");
        scanf("%d",&temp->info);
        temp->link = NULL;

        if(first==NULL) {
            first=temp;
            return;
        }

        else {
            temp->link = first;
            first=temp;
        }/*end else*/
    }/*end function*/

void insertend()
{
    NODE cur;
    NODE temp = (NODE)malloc(sizeof(struct node));
    printf("Enter the data\n");
    scanf("%d",&temp->info);
    temp->link = NULL;

    if(first==NULL){
        first=temp;
        return;
    }/*end if*/

    cur = first;
    while(cur->link!=NULL)
        cur=cur->link;
    cur->link = temp;
}/*end function*/

void delete()
{
    int key,flag=0;
    NODE cur,prev;

    printf("Enter the key\n");
    scanf("%d",&key);
    if(first==NULL)
    {
        printf("List empty\n");
        return;
    }/*end if*/
    while(first->info==key)
    {

        flag=1;
        cur=first;
        first=first->link;
        printf("%d is deleted",cur->info);
        free(cur);
        cur=NULL;
    }/*end while*/
    prev=first;
    cur=first->link;
    while(cur!=NULL)
    {

        if(cur->info==key)
        {
            flag=1;
            prev->link=cur->link;
            printf("%d is deleted",cur->info);
            free(cur);
            cur=prev->link;
        }
    else{
        prev=cur;
        cur=cur->link;
    }/*end else*/
    }
    if(flag==0)
        printf("Key not found\n");
}

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

    printf("1.insertfront\t2.insertend\t3.delete\t4.display\t5.exit\n");
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
            case 3:delete();
                break;
            case 4:display();
                break;
            case 5:exit(0);
                break;

        }/*end switch*/
    }/*end for*/
    getch();
}/*end main*/
