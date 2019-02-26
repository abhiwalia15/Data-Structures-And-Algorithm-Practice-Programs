#include<stdio.h>
#include<conio.h>
void dfs(int n, int a[10][10], int src, int s[10])
{
	int i;
	s[src]=1;
	printf("%d\t",src);
	for(i=1;i<n;i++)
	if(s[i]==0 && a[src][i]==1)
		dfs(n,a,i,s);
}

void main()
{
	int n,a[10][10],src, i, j, s[10];
	
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	
	printf("Enter adjancy matrix\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}	
	printf("Enter the source node\n");
	scanf("%d",&src); 
	for(i=1;i<=n;i++)
	s[i]=0;
	
	printf("BFS order is \n");
	dfs(n,a,src,s);
	

}
