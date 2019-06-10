#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Edge
{
    int cost, begv, endv;
}; typedef struct Edge E;

void main()
{
    int i, j, a[10][10], n;

    printf("Enter the no. of nodes\n");
    scanf("%d",&n);

    printf("Enter the adj. matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);

            kruskal(a,n);


}/*end main*/

getparent(int parent [], int v)
        {
            while(parent[v] != -1)
                v = parent[v];
            return v;
        }

kruskal(int a[10][10], int n)
{
    E Ed[100], temp;
    int i, j, count=1, pendv,pbegv,parent,sum=0,noe=0;

    /*dont accept 0 and 999's*/
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]!=0 && a[i][j]!=999)
    {

        Ed[count].begv = i;
        Ed[count].endv = j;
        Ed[count].cost = a[i][j];
        count++;
    }/* end for*/

    count = count-1;

    /* arrange in ascending order now*/
    for(i=1;i<=count-1;i++)
        for(j=1;j<=count-i;j++)
        if(Ed[j+1].cost < Ed[j].cost)
    {
        temp.begv = Ed[j+1].begv;
        temp.endv = Ed[j+1].endv;
        temp.cost = Ed[j+1].cost;
    }/*end for*/


    for(i=1;i<=n;i++)

    for(i=1;i<=count;i++)
    {

        pbegv = getparent(parent,Ed[i].begv);
        pendv = getparent(parent,Ed[i].endv);
        if(pbegv!=pendv)
        {
            sum=sum+Ed[i].cost;
            noe = noe+1;
            parent[Ed[i].endv] = Ed[i].begv;
            if(noe==n-1)
            {
                printf("MST COST IS %d",sum);
                break;
                }

            }
    }



