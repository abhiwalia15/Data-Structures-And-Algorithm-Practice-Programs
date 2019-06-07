#include<stdio.h>
#include<conio.h>

void nQueen(int);
int place(int [],int);




int place(int x[10], int k)
{
    int i;
    for(i=1;i<=k-1;i++)
    {
        if(x[i]==x[k])
            return 0;
        if(abs(i-k)==abs(x[i]-x[k]))
            return 0;
    }/*end for*/
    return 1;
}/*end place function*/

void nQueen(int n)
{
    int i, k=1, x[10];
    x[k]=0;
    while(k!=0)
    {
        x[k]+=1;
        while(x[k]<=n && place(x,k)==0)
            x[k]=x[k]+1;
        if(x[k]<=n)
            {
            if(k==n)
            {
                printf("The solution is\n");
                for(i=1;i<=n;i++)
                printf("%d\t",x[i]);
            }/*end if*/
            else
            {
                k++;
                x[k]=0;
            }/*end else*/

        }/*end if*/
            k--;
    }
}/*end function*/

void main()
{
    int n;

    printf("Enter the number of queens\n");
    scanf("%d",&n);
    nQueen(n);
}/*end main*/

