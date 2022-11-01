#include <stdio.h>
int main()
{
	int m,n,i,j,k,r,c,mat[50][50],count=0;
	printf("Enter the order of matrix (row,coloumn) \n");
	scanf("%d%d",&m,&n);
	int b[50][50],res[50][50];
	b[0][0] = m;
	b[0][1]= n;
	printf("Enter the elements (row wise).\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
	k=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			
			if(mat[i][j] != 0)
			{
				count++;
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=mat[i][j];
				k++;
			}
		}
	}
	b[0][2]=count;
	printf("Sparse matrix is \n");
	for(i=0;i<(count+1);i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d \t",b[i][j]);
		}
		printf("\n");
	}
	int temp;
	for(i=0;i<(count+1);i++)
	{
		temp=b[i][0];
		b[i][0]=b[i][1];
		b[i][1]=temp;
	}
	printf("Transpose Sparse matrix is \n");
	for(i=0;i<(count+1);i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d \t",b[i][j]);
		}
		printf("\n");
	}
	for(i=1;i<(count+1);i++)
	{
		r=b[i][0];
		c=b[i][1];
		res[r][c]=b[i][3];
	}
	printf("Transpose  matrix is \n");
	for(i=0;i<b[0][0];i++)
	{
		for(j=0;j<b[0][1];j++)
		{
			printf("%d \t",res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
	
		
		
