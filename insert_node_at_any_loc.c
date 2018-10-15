#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *link;
    };

typedef struct node *NODE;
    NODE first=NULL;

void insert_any(int x, int n)
{
    int count;
    NODE cur;
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->info = n;
    temp->link = NULL;

    if(x==1)
    {
        temp->link = first;
        first = temp;
        return;
    }
    cur = first;
    count=1;
    while(cur!=NULL)
    {
        if(count==x-1)
        {
            temp->link = cur->link;
            cur->link = temp;
            return;
        }
    count++;
    cur=cur->link;
    }
    if(cur==NULL)
        printf("Invalid location\n");
}

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
    while(cur!=NULL){
        cur=cur->link;
    }/*end while*/
    cur->link = temp;
}/*end function*/

void deletefront()
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

void deleteend()
{
    NODE cur,prev;
    if(first==NULL)
    {
        printf("Enter list empty\n");
        return;
    }/*end if*/
    else if(first->link==NULL)
    {
        printf("%d is deleted",first->info);
        free(first);
        first=NULL;
    }
    else{
        prev = NULL;
        cur = first;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }/*end while*/
        printf("%d is deleted from end",cur->info);
        free(cur);
        cur=NULL;
        prev->link = NULL;
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
    printf("1.insertfront\t2.insertend\t3.deletefront\t4.deleteend\t5.display\t6.insert at any\t7.exit\n");
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
            case 3: deletefront();
                break;
            case 4: deleteend();
                break;
            case 5:display();
                break;
            case 6:insert_any(3,15);
                break;
            case 7:exit(0);
                break;

        }/*end switch*/
    }/*end for*/
}/*end main*/
