#include<stdio.h>
#include<stdio.h>


void merge(int a[100], int low,int mid, int high)
{
	int i=low, j=mid+1, b[100], k=low;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		b[k++]=a[i++];
		
		else
		b[k++]=a[j++];
	}
	
	while(i<=mid)
	b[k++]=a[i++];
	
	while(j<=high)
	b[k++]=a[j++];
	
	for(i=low;i<=high;i++)
	a[i]=b[j];
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
















