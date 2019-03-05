#include<stdio.h>
#include<conio.h>

void main()
{
	int i,j,n,a[10][10];

	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	
	printf("Enter the cost adj. matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	floyds(a,n);
	
	printf("Shortest Path matrix:\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
			printf("\n");
		}
}

floyds(int a[10][10], int n)
{
	int i,j,k;

	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(a[i][j] > a[i][k]+a[k][j])
					a[i][j] = a[i][k]+a[k][j];
	}
}




