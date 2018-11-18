#include<stdio.h>
#include<conio.h>
#define SIZE 100

int a[SIZE] ,n;

//function to perform BST operation using an array
void BST(int ele)
{
	if(a[0]==NULL)
	{
		a[0] = ele;
		return;
	}//end if
	
	n=0;
	while(a[n]!=NULL)
	{
		if(ele < a[n])
			n = 2*n+1;
		else
			n = 2*n+2;
	}//end while
	
	a[n]=ele;
}// end function

void display()
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		if(a[i] == NULL)
			continue;
		printf("a[%d] = %d \n",i,a[i]);
	}//end for
	
}//end function

void main()
{
	int ch,i,j,ele;
	printf("1.BST\t2.display\t3.exit\n");
	for(;;)
	{
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:for(i=0;i<SIZE;i++)
						a[i]=NULL;
					printf("Enter no. of elements\n");
					scanf("%d",&j);
					printf("Enter the elements of the array >--->>>\n");
					for(i=0;i<j;i++)
					{
						scanf("%d",&ele);
						BST(ele);
					}//end for
					break;
					
			case 2:display();
					break;
			
			case 3:exit(0);
					break;
		}//end switch
	}//end for
	
}//end main
