#include<stdio.h>
#include<conio.h>
#define SIZE 100

int a[SIZE] ,c;

//function to perform BST operation using an array
void BST(int ele)
{
	if(a[0]==NULL)
	{
		a[0] = ele;
		return;
	}//end if
	
	c=0;
	while(a[c]!=NULL)
	{
		if(ele < a[c])
			c = 2*c+1;
		else
			c = 2*c+2;
	}//end while
	
	a[c]=ele;
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
					printf("ENter the elements of the array---.>>\n");
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
