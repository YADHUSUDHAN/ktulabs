#include <stdio.h>
#include <stdlib.h>
struct node *top = NULL;
struct node
{
	int item;
	struct node *next;
};
void push()
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
		newnode->next = top;
		top = newnode;
	}
}
void pop()
{
	struct node *temp;
	if(top == NULL)
	{
		printf("Stack underflow.\n");
	}
	else
	{
		if(top->next == NULL)
		{
			temp = top;
			printf("Deleted element : %d\n",top->item);
			top = NULL;
			free(temp);
		}
		else
		{
			temp = top;
			printf("Deleted element : %d\n",top->item);
			top = top->next;
			free(temp);
		}
	}
}	
int main()
{
	char opt,opt2;
	printf("Stack program\n");
	begin:
	printf("Push() - A\nPop() - B\n");
	printf("Enter an option : ");
	scanf(" %c",&opt);
	if(opt == 'a' || opt == 'A' )
	{
		push();
	}
	else if(opt == 'b' || opt == 'B' )
	{
		pop();
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
