/* C program to implement 2 stacks using 1 array
written by- MrinalWalia and PriyonathMondal */

#include<stdio.h>
#include<stdlib.h>

/*main function*/
void main()
{
    /*declare variables*/
    int n,top1,top2,choice=1,a,i,arr[100];
    /*enter the size of the array*/
    printf("Enter size of array you want to use\n");
    scanf("%d",&n);

    top1=-1;
    top2=n;
    /*infinite loop*/
    for(;;)
    {
        printf("Enter your choice?\n\n");
        printf("1.Push element in stack 1\n");
        printf("2.Push element in stack 2\n");
        printf("3.Pop element from stack 1\n");
        printf("4.Pop element from stack 2\n");
        printf("5.Display stack 1\n");
        printf("6.Display stack 2\n");
        printf("0.EXIT\n");
        scanf("%d",&choice);

        switch(choice)
        {

            /*case to push element to stack 1.*/
            case 1:
            {
                /*enter element to push to stack 1*/
                printf("Enter the element\n");
                scanf("%d",&a);
                if(top1!=(top2-1))
                    arr[++top1]=a;
                else
                    printf("Overflow\n");
                break;
            }

            /*case to push element to stack 2.*/
            case 2:
            {
                /*enter element to push to stack 2*/
                printf("Enter the element\n");
                scanf("%d",&a);
                if(top2!=(top1+1))
                    arr[--top2]=a;
                else
                    printf("Overflow\n");
                break;
            }

            /*case to pop element from stack 1.*/
            case 3:
            {
                if(top1==-1)
                    printf("Stack 1 is empty\n");
                else
                {
                    a=arr[top1--];
                    printf("%d is popped from stack 1\n",a);
                }
                break;
            }

            /*case to pop element from stack 2.*/
            case 4:
            {
                if(top2==n)
                    printf("Stack 2 is empty\n");
                else
                {
                    a=arr[top2++];
                    printf("%d is deleted from stack 2\n",a);
                }
                break;
            }

            /*case to display the elements of stack 1.*/
            case 5:
            {
                if(top1==-1)
                    printf("Stack 1 is empty\n");
                else
                {
                    printf("Elements of Stack 1 are -->>\n");
                    for(i=0;i<=top1;i++)
                        printf("%d\t",arr[i]);
                    printf("\n");
                }
                break;
            }

            /*case to display the elements of stack 2*/
            case 6:
            {
                if(top2==n)
                    printf("Stack2 is empty\n");
                else
                {
                    printf("Elements of Stack 2 are -->>\n");
                    for(i=(n-1);i>=top2;i--)
                        printf("%d\t",arr[i]);
                    printf("\n");
                }
                break;
            }
            /*case to terminate the program*/
            case 0: exit(0);
                break;

        }/*end switch*/
    }/*end for*/
}/*end main*/
