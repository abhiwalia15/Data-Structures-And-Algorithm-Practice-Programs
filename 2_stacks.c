/* C program to implement 2 stacks using 1 array
written by- MrinalWalia and PriyonathMondal */

/*In this method we are efficiently utilizing the available space.
It doesn’t cause an overflow if there is space available in arr[].
The this method we are going to start two stacks from two extreme corners of arr[].
stack 1 starts from the leftmost element, the first element in stack 1
is pushed at index 0 of the arr[]. The stack 2 starts from the rightmost corner,
the first element in stack 2 is pushed at index (n-1) of arr[].
Both stacks will move in opposite direction to each other.
To check for overflow,all we need to check is for space between top elements of stack 1 and stack 2 */

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
