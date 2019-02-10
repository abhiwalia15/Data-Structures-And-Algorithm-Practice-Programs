#include<stdio.h>
#include<conio.h>

struct Fraction
{
    int n;
    int d;

}f_1,f_2,f_3;

void main()
{
    /*struct FRACTION f1;
    struct FRACTION f2;
    struct FRACTION f3;*/
    printf("Enter any fracction\n");
    scanf("%d%d",&f_1.n,&f_1.d);
    printf("Enter any fracction\n");
    scanf("%d%d",&f_2.n,&f_2.d);

    f_3.d=f_1.d*f_2.d;
    f_3.n=f_1.n*f_2.n;

    printf("Fracction is %d and %d\n",f_3.n,f_3.d);
    getch();
}
