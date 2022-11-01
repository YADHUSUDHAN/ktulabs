#include <stdio.h>
int g[50][50],stack[50],queue[50],visited[50],visited2[50];
int top = -1,n,front=-1,rear=-1;
int dequeue()
{
	int  item;
	item = queue[front];
	front++;
	if(front > rear )
	{
		front = -1;
		rear  = -1;	
	}
	return item;
}
void enqueue(int item)
{
	if(front == -1 && rear == -1)
	{
		front = 0;
        rear = 0;
		queue[rear] = item;

	}
	else
	{	
		rear++;
		queue[rear] = item;
	}
}

void dfs( )
{
	do
	{	
		int v=stack[top--];
		printf("%d ",v );
		for(int i =0;i<n;i++)
		{
			if(g[v][i] == 1 && visited[i] != 1)
			{				
				visited[i] = 1;
				stack[++top] = i;
			}
		}
		
	}while(top != -1);
	
}
void bfs( )
{
	do
	{	
		int v=dequeue();
		printf("%d ",v);
		for(int i =0;i<n;i++)
		{
			if(g[v][i] == 1 && visited2[i] != 1)
			{				
				visited2[i] = 1;
				enqueue(i);
			}
		}
		
	}while(front != -1);
	
}			
int main()
{
	int v;
	printf("Enter the number of elements in Graph : ");
	scanf("%d",&n);
	printf("Enter the graph data in metrix form \n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	printf("Enter the vertex to start traversal : ");
	scanf("%d",&v);
	printf("DFS Traversal : ");
	stack[++top]=v;
	visited[v] = 1;
	dfs( );
	printf("\nBFS Traversal : ");
	enqueue(v);
	visited2[v] = 1;
	bfs( );
	return 0;
}
	
	
