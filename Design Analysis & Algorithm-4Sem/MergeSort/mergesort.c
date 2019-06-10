#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>

void merge(int a[100], int low,int mid, int high)
{
	int i=low, j=mid+1, b[100], k=low;
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
		b[k++]=a[i++];

		else
		b[k++]=a[j++];
	}

	while(i<=mid)
	b[k++]=a[i++];

	while(j<=high)
	b[k++]=a[j++];

	for(i=low;1<=high;i++)
	a[i]=b[i];
}


void mergesort(int a[100], int low, int high)
{
    int mid;

    if(low<high)
    {
    	mid=(high+low)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}


void main()
{
    int a[100],i,n;

    printf("Enter the number of elements\n");
    scanf("%d",&n);

    printf("Enter the elements of the array\n");
    for(i=1;i<;i++)
        scanf("%d\t",&a[i]);

    mergesort(a,0,n-1);

    printf("Elements after sorting are\n");
    for(i=1;i<=n;i++)
        printf("%d\t",a[i]);

}


















