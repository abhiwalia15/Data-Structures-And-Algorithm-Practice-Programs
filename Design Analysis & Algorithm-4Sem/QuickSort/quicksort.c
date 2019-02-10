#include<stdio.h>
#include<stdio.h>

void quicksort(int a[100], int low, int high)
{
    int j;

    if(low<high)
    {
        j = partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}

int partition(int a[100], int low, int high)
{
    int key=a[low], j=high, i=low+1, temp;
    for(;;)
    {
        while(key>=a[i] && i<high)
            i++;
        while(key<=a[j])
            j--;

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }

        else
        {
            temp=a[low];
            a[low]=a[j];
            a[j]=temp;
            return j;
        }
    }

}

voim main()
{
    int a[100],i,n;

    printf("Enter the number of elements\n");
    scanf("%d",&n);

    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
        scanf("%d\n",&a[i]);

    quicksort(a,0,n-1);

    printf("Elements after sorting are\n");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);

    getch();
}
