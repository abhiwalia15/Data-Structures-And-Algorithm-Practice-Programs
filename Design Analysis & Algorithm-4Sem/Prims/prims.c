#include<stdio.h>
#include<conio.h>

void main()
{
    int n, a[10][10], i, j, src, sum;

    printf("Enter the no. of nodes\n");
    scanf("%d",&n);

    printf("Enter the adj. matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter the source node\n");
    scanf("%d",&src);

    sum = prims(n,a,src);

    if(sum>=999)
        printf("MST not possible\n");
    else
        printf("Cost of MST is %d",sum);
}/*end main*/

int prims(int n, int a[10][10], int src)
{
    int d[10], s[10], i, j, u, v, sum=0, min;

    for(i=1;i<=n;i++)
    {
        d[i]=a[src][i];
        s[i]=0;
    }/*end for*/

    s[src]=1;

    for(i=1;i<=n-1;i++)
    {
        min =999;
        for(j=1;j<=n;j++)
        {
            if(s[j]==0) if(d[j]<min)
        {
            u=j;
            min=d[j];
        }/*end for*/
        }

        s[u]=1;
        sum = sum+d[u];

        for(v=1;v<=n;v++)
        {
            if(s[v]==0 && d[v]>a[u][v])
                d[v]=a[u][v];
    }
    }

    return sum;
}/*end function*/



