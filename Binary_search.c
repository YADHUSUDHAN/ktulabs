//Program of search in an array
#include <stdio.h>
int main()
{
	int ar[20],n,i,item,beg=0,end,mid;
	printf("Enter the limit of array : ");
	scanf("%d",&n);
	printf("Enter elements to array(in Ascendig or descending order)  \n");
	for(i=0;i<n;i++)		
	{
		scanf("%d",&ar[i]);
	}
	end = n-1;
	mid = (n-1)/2;
	printf("Enter the element to be searched : ");
	scanf("%d",&item);
	while(beg<= end && ar[mid] != item)
	{
		mid = (beg+end)/2;
		if(item>ar[mid])
		{
			beg=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}
	if(ar[mid]==item)
	{
		printf("Item is found at location : %d",mid+1);
	}
	else
	{
		printf("Item is not found in array.");
	}
	return 0;
}
