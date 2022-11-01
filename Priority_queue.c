#include <stdio.h>
struct pqueue
{
	int item;
	int prty;
}pq[10],temp;
int front = -1;//for acessing front end of queue
int rear = -1;//for acessing rear end of queue
void dequeue()//function for dequeue operation
{
	if(front == -1)//checking queue is empty
	{
		printf("queue underflow.\n");
	}
	else//deletion takes place at front end,after deletion front will be the next element
	{
		printf("Deleted item : %d.\n",pq[front].item);
		if(front == rear)//if front become equals rear ,it means last element is deleted.so set queue to empty condition.
		{
			front = -1;
			rear  = -1;	
		}
		else
		{
			front++;
		}
		if(front == rear)//if front become greater than rear ,it means last element is deleted.so set queue to empty condition.
		{
			front = -1;
			rear  = -1;	
		}
	}
}
void enqueue()//function for enqueue operation
{
	if(rear == 9)//checking queue is full ,(limitation of linear que : even though if there is space in array acting as queue,we cannot insert an item to queue until  rear become -1)
	{
		printf("queue overflow.\n");
	}
    else if(front == -1 && rear == -1)//checking if queue is empty
	{
        int x,y;
		front = 0;
        rear = 0;
        printf("Enter the item : ");
		scanf(" %d",&x);
		printf("Enter the priority : ");
		scanf(" %d",&y);
		pq[rear].item = x;
		pq[rear].prty = y;

	}
	else
	{	
		int x,y;
		rear++;
		printf("Enter the item : ");
		scanf(" %d",&x);
		printf("Enter the priority : ");
		scanf(" %d",&y);
		pq[rear].item = x;
		pq[rear].prty = y;
		for(int i=rear;i>front;i--)
		{
			if(pq[i].prty<pq[i-1].prty)
			{
				temp.prty  =  pq[i].prty;
				temp.item  =  pq[i].item;
				pq[i].prty =  pq[i-1].prty;
				pq[i].item =  pq[i-1].item;
				pq[i-1].prty =  temp.prty;
				pq[i-1].item =  temp.item;
			}
		}
	}
}
void queueview()
{
	if(front == -1 && rear == -1)
	{
		printf("queue is empty.\n");
	}
	else
	{
		int i;
		printf("Items in queue    : ");
		for(i = front;i<=rear;i++)//list elements from front end to rear end
		{
			printf("%d\t",pq[i].item);
		}
		printf("\n");
		printf("Priority of items : ");
		for( i = front;i<=rear;i++)//list elements from front end to rear end
		{
			printf("%d\t",pq[i].prty);
		}
		printf("\n");
	}
}		
int main()
{
	int opt;
	char opt2;
	printf("QUEUE PROGRAM\n");
	begin :
	printf("\n1 - VIEW QUEUE ITEMS.\n");
	printf("2 - ENQUEUE() OPERATION.\n");
	printf("3 - DEQUEUE() OPERATION.\n");
	printf("\nENTER AN OPTION : ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1 : queueview();
				 break;
		case 2 : enqueue();
				 break;
		case 3 : dequeue();
				 break;
		default : printf("Invalid input.Please retry.\n\n");
				  goto begin;
				  break;
	}
	printf("Do you want to contiue (y-yes & n-no) : ");
	scanf(" %c",&opt2);
	if(opt2 == 'y' || opt2 == 'Y')
	{
		goto begin;
	}
	return 0;
}

