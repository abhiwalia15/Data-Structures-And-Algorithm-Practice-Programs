#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int v[10][10];

int knapsack(int n, int m, int p[], int w[])

{
    int i,j;
	for(i=0;i<n;i++)
		{
		for(j=0;j<m;j++)
			{
				if(i==0 || j==0)
					v[i][j] = 0;


				else if(w[i]>j)
					v[i][j] = v[i-1][j];

				else
					v[i][j] = max(v[i-1][j], p[i]+v[i-1][j-w[i]]);

			}/*end for j*/

		}/*end for i*/

	return v[n][m];

}/*end function*/

void subset(int n, int m, int v[10][10], int w[10])
{
    int i,j;

    i=n;
    j=m;

    while(i!=0 && j!=0)
    {
        if(v[i][j] != v[i-1][j] )
        {
            printf("Item %d\n",i);
            j=j-w[i];
        }
        i--;
    }
}

void main()
{
    int m,n,w[10],p[10],i,j,value;

    printf("Enter the no. of items\n");
    scanf("%d",&n);

    printf("Enter the capacity\n");
    scanf("%d",&m);

    printf("Enter the weight\n");
    for(i=0;i<n;i++)
        scanf("%d",&w[i]);

    printf("Enter the profit\n");
    for(j=0;j<n;j++)
        scanf("%d",&p[j]);

    value = knapsack(n,m,p,w);
    printf("the solution of knapsack after dynamic programming\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        printf("%d",v[i][j]);
    }
    printf("\n");
    printf("The max profit obtained is %d",value);
    printf("the items of optimal subset are \n");
    subset(n,m,v,w);
}
