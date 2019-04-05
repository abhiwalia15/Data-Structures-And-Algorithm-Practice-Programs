#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
    int i,j,a[10][10],sum, n;

    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the cost adj. matrix\n");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i][j]);

    sum = tsp(n,a,1);
    printf("%d is the tsp tour cost",sum);
}/*end main*/

tsp(int n, int a[10][10], int source)
{
    int i,j,sum,s[10],min,u,temp;
    for(i=1;i<=n;i++)
    {
        s[i]=0;
        temp=source;
        s[source]=1;
        sum=0;
        for(i=1;i<=n-1;i++)
        {
            min=999;
            for(j=1;j<=n;j++)
                if(s[j]==0 && a[source][j]<min)
            {
                min = a[source][j];
                u=j;
            }
            sum=sum+a[source][u];
            s[u]=1;
            source=u;
        }
        sum = sum+a[u][temp];
        return sum;
    }
}
