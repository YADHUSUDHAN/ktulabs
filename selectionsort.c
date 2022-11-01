#include <stdio.h>
int ar[20],n,min,i,j;
void selection()
{
	int temp;
	printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the  elements \n");
    for(i = 0; i < n ; i++)
    {
        scanf("%d",&ar[i]);
    }
	for ( i = 0; i < n ; i++)
    {
        min = i;
        for ( j = i; j < n; j++)
        {
            if (ar[min]>ar[j])
            {
                min = j;
            }
            
        }
        temp = ar[i];
        ar[i] = ar[min];
        ar[min] = temp;
    }
    printf("Sorted elements elements\n ");
    for(i = 0; i < n ; i++)
    {
        printf("%d ",ar[i]);
    }
}
void insertion()
{
	int key;
	printf("Enter the number of elements : ");
    scanf("%d",&n);
    printf("Enter the  elements \n");
    for(i = 0; i < n ; i++)
    {
        scanf("%d",&ar[i]);
    }
	for ( i = 1; i < n ; i++)
    {
        key = ar[i];
        j = i-1;
        while (j >= 0 && ar[j] > key) 
        {
            ar[j + 1] = ar[j];
            j = j - 1;
        }
        ar[j + 1] = key;
    }
    printf("Sorted elements elements\n ");
    for(i = 0; i < n ; i++)
    {
        printf("%d ",ar[i]);
    }
}
int main()
{
	char opt;
	begin :
    printf("Selection sort - a\nIsertion sort - b\nEnter an option : ");
    scanf(" %c",&opt);
    if(opt == 'a' || opt == 'A')
    {
		selection();
	}
	else if(opt == 'b' || opt == 'B')
    {
		insertion();
	} 
	else
    {
		printf("Please enter a valid option\n");
		goto begin;
	}
    return 0;
}
