#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
char t[200],p[200];
int m,n,flag;

printf("Enter the text\n");
gets(t);

printf("Enter the pattern\n");
gets(p);

m = strlen(p);
n = strlen(t);

flag = horspool(t,p,m,n);

if(flag == -1)
    printf("String not found\n");

else
    printf("String found and starts at %d",flag);

}/*end main*/

int horspool(char t[200], char p[200], int m, int n)
{
    int i,j;
    char table[200];

    for(i=0;i<n;i++)
        table[t[i]] = m;

    for(i=0;i<m-1;i++)
        table[p[i]] = m-1-i;

    i = m-1;

    while(i<n)
    {
        j=0;

        while(j<m && p[m-1-j]==t[i-j])
            j=j+1;
        if(j==m)
            return i-j+1;
        else
            i = i+table[t[i]];
    }/*end while*/
    return -1;


}/* end function*/
