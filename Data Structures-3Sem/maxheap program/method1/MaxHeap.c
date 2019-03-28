
#include<stdio.h>
#include<conio.h>
#include<process.h>

int a[100],n,i,root,n,temp,ch;

void createheap(int i)
{
	if(i==0)
	{
		root = i;
		return;
	}//end if
	
	else
	{
		n=i;
		while(n!=0)
		{
			root = (n-1)/2;
			if(a[root]<=a[n])
			{
				temp = a[root];
				a[root] = a[n];
				a[n] = temp;
			}//end if
			n=root;
		}//end while
	}//end else
}//end function

void display()
{
	printf("max heap\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}//end function

void main()
{
	printf("1.CreateMaxHeap\t2.display\t3.exit\n");
	for(;;)
	{
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter no. of nodes\n");
					scanf("%d",&n);
					printf("Enter the elements -->>\n");
					for(i=0;i<n;i++)
					{
						scanf("%d",&a[i]);
						createheap(i);
					}//end for
					break;
					
			case 2:display();
					break;
			
			case 3:exit(0);
					break;
		}//end switch
	}//end for
	
}//end main
