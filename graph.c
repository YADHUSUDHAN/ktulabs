#include <stdio.h>
int visit[10] = {0,0,0,0,0,0,0,0,0,0}
void bfs()
{
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i][j] == 1)
			{
				if(vist[j] = 0)
				{
					push(j);
					visit[j] = 1;
				}
			}
		}
		j=i+1;
		pop(j);
        }

int main()
{
	int am[10][10],n,i,j;
	printf("Enter number of vertices : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Is there edge between %d and %d (yes-1/no-0): ",i,j);
                     	scanf("%d",&ch);
			if(ch == 1)
			{
				am[i][j] = 1;
			}
			else
			{
				am[i][j] = 0;
			}
		}

        }
	return 0;
}
 
	