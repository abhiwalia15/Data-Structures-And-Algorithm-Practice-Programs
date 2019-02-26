#include<stdio.h>
#include<conio.h>
void bfs(int n, int a[10][10], int src, int s[10])
{
	int i, f=0,r=-1,q[10],v;
	printf("%d",src);
	s[src] = '/';
	q[++r] = src;
	while(f<=r)
	{
		v=q[f++];
		for(i=1;i<=n;i++)
		{
			if(s[i]==0 && a[v][i]==1)
			{
				q[++r]=i;
				printf("%d",i);
				s[i] = 1;
			}
		}
	}
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
	bfs(n,a,src,s);
	

}
