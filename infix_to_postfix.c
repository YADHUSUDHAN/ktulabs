//program for converting infix to postfix
#include <stdio.h>
#include <string.h>//for using string function
char exprsn[50];//array for storing expression
char stack[50];//array for using as stack
char result[50];//array for storing postfix expression
int resindx = 0;//for acessing elements in postfix expression
int top = -1;//for acessing elements in stack
int pop()//function for pop operation
{
	int ret  = stack[top];
	top--;
	return ret;
}
void push(char x)//function for push operation
{
	top++;
	stack[top] = x;
}
int preced(char c)//function for checking precedence of operators 
{
	int p;	
	switch(c)
	{
		case '+' :  p = 1;break;
		case '-' :  p = 1;break;
		case '*' :  p = 2;break;
		case '/' :  p = 2;break;
		case '^' :  p = 3;break;
	}
	return p;
}
int validate(char *adrs)//function for validating expression
{
	int val;
	for(int i = 0;*(adrs+i) != '\0';i++)
	{
		if(*(adrs+i) == '('|| *(adrs+i) == ')' || *(adrs+i) == '+'|| *(adrs+i) == '-'|| *(adrs+i) == '*'|| *(adrs+i) == '/'|| *(adrs+i) == '^'|| (*(adrs+i) >= 'a' && *(adrs+i) <= 'z') || (*(adrs+i) >= 'A' && *(adrs+i) <= 'Z') || (*(adrs+i) >= '0' && *(adrs+i) <= '9'))
		{
			val = 1;
		}
		else
		{
			val = 0;
			break;
		}
	}
	return val;
}
void itop(char *adrs)//function for converting infix to postfix
{
	int i;
	for(i = 0;*(adrs+i) != '\0';i++)
	{
		if(*(adrs+i) == '(')//checking whether character is left paranthesis
		{
			push(*(adrs+i));
		}
		else if((*(adrs+i) >= 'a' && *(adrs+i) <= 'z') || (*(adrs+i) >= 'A' && *(adrs+i) <= 'Z') || (*(adrs+i) >= '0' && *(adrs+i) <= '9'))//checking whether character is an operand
		{
			result[resindx] = *(adrs+i);
			resindx++;
		}
		else if(*(adrs+i) == ')')//if right paranthesis is encountered
				{
					while(stack[top] != '(' && top!= -1)//cotinuos poping from stack and store to result until ')' is encoutered/stack become empty
					{
						result[resindx] = pop();
						resindx++;
					}
					
					top--;
					continue;				
				}
		else//if character is an operator
		{
			if(((preced(*(adrs+i)) > preced(stack[top])) ||  stack[top] == '(' || top == -1  ))//checking precedence of ecountered operator and last operator in stack
			{
				push(*(adrs+i));
			}
			else
			{
				do
				{
				result[resindx] = pop();//if the operator in stack has higher/equal precedence
				resindx++;
				}
				while(stack[top] != '(');
				push(*(adrs+i));
			}
		}
	}
	*(adrs+(i-1)) = '\0';//removing the extra added ')' from expression
}
int main()
{
	begin :
	printf("Enter the expression in infix form : ");
	scanf("%s",exprsn);
	if(validate(exprsn) == 0)//expression validation
	{
		printf("Invalid expression !!\nplease retry\n");
		goto begin;
	}
	push('(');//inserting to begining of stack
	char ch[2] = {')','\0'};//for adding to the end of expression
	strncat(exprsn,ch,2); //strig function to add to the end of string
	itop(exprsn);
	printf("\nExpression in infix form : %s \n",exprsn);
	printf("Expression in postfix form : %s \n",result);
	return 0;
}
