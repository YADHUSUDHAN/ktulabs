//program for implementing stack 
#include <stdio.h>
char stack[10];//array for using as stack
int top = -1;//for acessing elements in stack
void pop()//function for pop operation
{
	if(top == -1)
	{
		printf("Stack underflow.\n");
	}
	else
	{
		printf("Deleted item : %c.\n",stack[top]);
		top--;
	}
}
void push()//function for push operation
{
	if(top == 10)
	{
		printf("Stack overflow.\n");
	}
	else
	{	
		char x;
		top++;
		printf("Enter the item : ");
		scanf(" %c",&x);
		printf("Inserted item : %c.\n",x);
		stack[top] = x;
	}
}
void stackview()
{
	if(top == -1)
	{
		printf("Stack is empty.\n");
	}
	else
	{
		printf("Items in stack : ");
		for(int i = 0;i<=top;i++)
		{
			printf("%c\t",stack[i]);
		}
		printf("\n");
	}
}		
int main()
{
	int opt;
	char opt2;
	printf("STACK PROGRAM\n");
	begin :
	printf("\n1 - VIEW STACK ITEMS.\n");
	printf("2 - PUSH() OPERATION.\n");
	printf("3 - POP() OPERATION.\n");
	printf("\nENTER AN OPTION : ");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1 : stackview();
				 break;
		case 2 : push();
				 break;
		case 3 : pop();
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
