#include<stdio.h>
#include<conio.h>

void main()
{
    int n, a[10][10], i, j, src;

    printf("Enter the no. of nodes\n");
    scanf("%d",&n);

    printf("Enter the adj. matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);

    printf("Enter the source node\n");
    scanf("%d",&src);

    dij(n, a, src);

}/*end main*/

dij(int n, int a[10][10], int src)
{
    int d[10], s[10], i, j, u, v, min;

    for(i=1;i<=n;i++)
    {
        d[i]=a[src][i];
        s[i]=0;
    }/*end for*/

    s[src]=1;

    for(i=1;i<=n;i++)
    {
        min =999;
        for(j=1;j<=n;j++)
            if(s[j]==0) if(d[j]<min)
        {

            min=d[j];
            u=j;
        }/*end for*/

        s[u]=1;
        for(v=1;v<=n;v++)
            if(s[v]==0 && d[v]>d[u]+a[u][v])
                d[v]=d[u]+a[u][v];
    }

    printf("the distance from src is\n");
    for(i=1;i<=n;i++)
        printf("%d to %d is %d\n", src, i, d[i]);
    }/* end function*/



