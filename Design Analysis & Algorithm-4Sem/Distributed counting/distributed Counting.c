#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
    int a[10], n, i;

    printf("Enter the number of elements\n");
    scanf("%d",&n);

    printf("Enter the elements of array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    dist(a[i], n);
}/*end main*/

dist(int a[10], int n)
{
    int i, j, d[10], s[10], u, l;

    for(j=0;j<(u-l);j++)
        d[j]=0;
    for(i=0;i<n-1;i++)
        d[a[i]-l] = d[a[i]-l] + 1;
    for(j=1;j<(u-l);j++)
        d[j] = d[j-1]+d[j];

    for(i=n-1;i>1;i--)
    {
        j = a[i]-l;
        s[d[j]-1] = a[i];
        d[j] = d[j]-1;
    }
    return s;
}
