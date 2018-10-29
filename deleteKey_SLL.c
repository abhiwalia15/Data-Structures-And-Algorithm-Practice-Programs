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
    while(cur->link!=NULL){
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

void deleteKey()
{
    int key,flag=0;
    NODE prev,cur,temp;
    printf("Enter the key element\n");
    scanf("%d",&key);

    if(first==NULL)
        printf("List empty\n");

    else if(first->info==key)
    {
        temp=first;
        first=first->link;
        printf("%d is deleted",temp->info);
        free(temp);
        temp=NULL;
        return;
    }

    else{
        cur=first->link;
        prev=first;
        while(cur!=NULL)
        {
            if(cur->info==key)
            {
                printf("%d is deleted",cur->info);
                prev->link=cur->link;
                free(cur);
                cur=NULL;
                flag=1;
                break;
            }
            prev=cur;
            cur=cur->link;
        }
        if(flag==0)
            printf("Key not found");
    }
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

    printf("\n1.insertfront\t2.insertend\t3.delete key\t4.display\t5.exit\n");
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
            case 3:deleteKey();
                break;
            case 4:display();
                break;
            case 5:exit(0);
                break;

        }/*end switch*/
    }/*end for*/
}/*end main*/


