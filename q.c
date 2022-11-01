#include <stdio.h>
#include <stdlib.h>
struct node *front = NULL;
struct node *rear = NULL;
struct node
{
	int item;
	struct node *next;
};
void print()//function for printing list elements 
{
	if(front == NULL)//checking whether the list is empty
	{
		printf("The list is empty!!");
	}
	else
	{
		struct node *temp;
		temp = front;
		printf("Elements in the list \n");
		while(temp != NULL)//Traversing upto last element of the list
		{
			printf("%d  ",temp->item);
			temp = temp->next;
		}
	}
}
void enqueue()
{
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("Memory not available.");
	}
	else
	{
		printf("Enter the number : ");
		scanf("%d",&newnode->item);
		if(front == NULL)
		{
			front = newnode;
			rear = front;
			newnode->next = NULL;
		}
		else
		{
			rear->next = newnode;
			newnode->next = NULL;
			rear = newnode;
		}
	}
}
void dequeue()
{
	struct node *temp;
	if(front == NULL)
	{
		printf("Queue underflow.\n");
	}
	else
	{
		temp = front;
		printf("Deleted element : %d\n",front->item);
		front = front->next;
		if(front == NULL)
		{
			rear = NULL;
		}
		free(temp);
	}
}	
int main()
{
	char opt,opt2;
	printf("Queue program\n");
	begin:
	printf("Enqueue() - A\nDequeue() - B\n");
	printf("Enter an option : ");
	scanf(" %c",&opt);
	if(opt == 'a' || opt == 'A' )
	{
		enqueue();
	}
	else if(opt == 'b' || opt == 'B' )
	{
		dequeue();
	}
	else if(opt == 'c' || opt == 'C' )
	{
		print();
	}
	else
	{
		printf("Invalid input retry.\n");
		goto begin;
	}
	printf("do you want to continue (Yes - y or No- n) : ");
	scanf(" %c",&opt2);
	if(opt2 == 'y' || opt2 == 'Y')
	{
		goto begin;
	}
	else if(!(opt2 == 'n' || opt2 == 'N'))
	{
		printf("Invalid input retry.\n");
		goto begin;
	}
	return 0;
}
