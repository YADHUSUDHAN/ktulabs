#include <stdio.h>
int main()
{
	int a[20][20],b[20][20],c[20][20],i,j,cl,r,k=1,count=0;
	printf("Enter the number of rows and columns\n");
	scanf("%d%d",&r,&cl);
	printf("Enter the matrix\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<cl;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Printing the matrix\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<cl;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<cl;j++)
		{
			if(a[i][j]!=0)
			{
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=a[i][j];
				k++;
				count++;
			}
		}
	}
	b[0][0]=r;
	b[0][1]=cl;
	b[0][2]=count;
	printf("Sparse representation\n");
	for(i=0;i<=count;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	c[0][0]=b[0][1];
	c[0][1]=b[0][0];
	c[0][2]=b[0][2];
	k=1;
	for(j=0;j<r;j++)
	{
		for(i=1;i<=count;i++)
		{	
			if(b[i][1]==j)
			{
				c[k][0]=b[i][1];
				c[k][1]=b[i][0];
				c[k][2]=b[i][2];
				k++;
			}
		}
	}
	printf("Sparse of traspose \n");
	for(i=0;i<=count;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
