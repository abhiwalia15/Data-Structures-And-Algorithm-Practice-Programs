#include<stdio.h>
#include<conio.h>

void main()
{
int n, a[100], i, d, r=0, s[100];
printf("Enter no. of elements\n");
scanf("%d",&n);

printf("Enter the elements of array\n");
for(i=0;i<n;i++)
    scanf("%d",&a[i]);

printf("Enter the sum\n");
scanf("%d",&d);

for(i=0;i<n;i++)
{
    r = r+a[i];
    s[i]=0;
}

sos(a,0,0,r,s,d);
}

sos(int a[], int k, int sum, int r, int s[], int d)
{
    int i;
    s[k]=1;
    if(sum+a[k]==d)
    {
        for(i=0;i<=k;i++)
            if(s[i])
            printf("%d\t",a[i]);
            printf("\n")
    }
    else
    {
        if(sum+a[k]+a[k+1] <= d)
            sos(a, k+1, sum+a[k], r-a[k], s, d);

        if(sum+r-a[k]>=d && sum+a[k+1]<=d)
        {
            s[k]=0;
            sos(a, k+1, sum, r+a[k],s,d);
        }
    }
}
