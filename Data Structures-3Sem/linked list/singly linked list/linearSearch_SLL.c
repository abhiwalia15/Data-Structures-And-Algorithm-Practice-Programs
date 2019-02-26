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
    while(cur->link==NULL)
        cur=cur->link;
    cur->link = temp;
}/*end function*/

void search()
{
    NODE cur;
    int key,loc,flag=0;
    printf("Enter the key\n");
    scanf("%d",&key);

    if(first==NULL)
    {
        printf("Enter list empty\n");
        return;
    }/*end if*/

    cur=first;
    loc=1;
    while(cur!=NULL)
    {
        if(key==cur->info)
        {
            printf("%d key found at location %d\n",key,loc);
            flag=1;
        }/*end if*/
        cur=cur->link;
        loc++;
    }/*end while*/
    if(flag!=1){
        printf("key not found\n");
        return;
    }
}/*end main*/

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
    printf("1.insertfront\t2.insertend\t3.find key\t4.display\t5.exit\n");
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
            case 3:search();
                break;
            case 4:display();
                break;
            case 5: exit(0);
                break;
        }
    }
}
