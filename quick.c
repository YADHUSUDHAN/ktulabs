#include <stdio.h>
#include <stdlib.h>
int partition(int *a,int l,int r)
{
	int temp,pvt = a[l],i=l,j=r;
	while(i<j)
	{
		while(a[i] <= pvt)
		{
			i++;
		}
		while(a[j] > pvt)
		{
			j--;
		}
		if(i<j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[j];
	a[j] = a[l];
	a[l] = temp;
	return j;
}
void quicksort(int *a,int l,int r)
{
	int j;
	if(l<r)
	{
		j = partition(a,l,r);
		quicksort(a,l,j);
		quicksort(a,j+1,r);
	}
}
int main()
{
	int n,i,*ar;
	printf("Enter the number of elements : ");
	scanf("%d",&n);
	ar = (int*)malloc(n*sizeof(int));
	printf("Enter the elements \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ar[i]);
	}
	quicksort(ar,0,n-1);
	printf("Sorted elements \n");
	for(i=0;i<n;i++)
	{
		printf("%d ",ar[i]);
	}
	return 0;
}
