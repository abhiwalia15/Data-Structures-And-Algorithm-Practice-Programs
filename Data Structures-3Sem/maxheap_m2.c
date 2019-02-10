#include<stdio.h>
#include<conio.h>
#define SIZE 10

int a[SIZE];
int n=0;

void insert_heap(int item)
{
	int c, p;
	
	if(n==SIZE)
	{
		printf("HEAP IS FULL\n");
		return;
	}//end if
	
	c=n;
	p=(c-1)/2;
	
	while(c!=0 && item>a[p])
	{
		a[c]=a[p];
		c=p;
		p=(c-1)/2;
	}//end while
	
	a[c]=item;
	n++;
}

void display()
{
	int i;
	if(n==0)
	{
		printf("HEAP IS EMPTY\n");
		return;
	}//end if
	
	printf("HEAP LIST IS-->>\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);

}//end function

void main()
{
	int ch,item;
	
	printf("1.Heap\t2.display\t3.exit\n");
	for(;;)
	{
		printf("ENter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("ENter the item\n");
		scanf("%d",&item);
		insert_heap(item);
		break;
		
		case 2:display();
			break;
			
		case 3: exit(0);
		 	break;
			
		default: printf("Invalid case");
			break;
	}//end switch
}//end for

}//end main

