//program for implementing linear queue 
#include <stdio.h>
char queue[10];//array for using as queue
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
		printf("Deleted item : %c.\n",queue[front]);
		front++;
		if(front == 10 )//if front become greater than rear ,it means last element is deleted.so set queue to empty condition.
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
        char x;
		front = 0;
        rear = 0;
        printf("Enter the item : ");
		scanf(" %c",&x);
		printf("Inserted item : %c.\n",x);
		queue[rear] = x;

	}
	else
	{	
		char x;
		rear++;
		printf("Enter the item : ");
		scanf(" %c",&x);
		printf("Inserted item : %c.\n",x);
		queue[rear] = x;//insertion takes place through rear end of queue
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
		printf("Items in queue : ");
		for(int i = front;i<=rear;i++)//list elements from front end to rear end
		{
			printf("%c\t",queue[i]);
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
