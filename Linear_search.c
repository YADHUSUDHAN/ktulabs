//program for searching element in an array
#include <stdio.h>
int main()
{
  int ar[20],n,item,i;
  printf("Enter the limit of array : ");
  scanf("%d",&n);
  printf("Enter the elements of array :\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&ar[i]);
  }
  printf("Enter the item to search : ");
  scanf("%d",&item);
  for(i=0;i<n;i++)
  {
    if(ar[i]==item)
    {
      printf("Item is found at location : %d. ",i+1);
      break;
    }
  }
  if(i==n)
  {
  	printf("Item is not found in the array. ");
 }
  return 0;
}
