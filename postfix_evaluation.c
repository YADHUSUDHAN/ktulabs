//program for postfix expression evaluation
#include <stdio.h>
#include <math.h>//for using power fuction 
char exprsn[50];//array for storing expression
float stack[50];
int top = -1;
float ans;
int pop()//function for pop operation
{
	int ret  = stack[top];
	top--;
	return ret;
}
void push(int num)//function for push operation
{
	top++;
	stack[top] = num;
}
	
float evaluate(char *x)//function for expression evaluation
{
	for(int i=0;*(x+i)!='\0';i++)
	{
		if(*(x+i)>= '0' && *(x+i)<= '9')//to check character is an operand
		{
			int num = *(x+i)-48;//to convert character type number to integer type using asci value
			push(num);
		}
		else//if character is an operator
		{
			int a = pop();//extracting last number in stack
			int b = pop();//extracting second last number in stack
			switch(*(x+i))
			{
				case '+' :  ans = a+b;break;
				case '-' :  ans = b-a;break;
				case '*' :  ans = a*b;break;
				case '/' :  ans = (float)b/(float)a;break;
				case '^' :  ans = pow(b,a);break;
			}
			push(ans);
		}
	}
	return ans;
}
int main()
{
	float answer;
	printf("Enter the expression in postfix form : ");
	scanf("%s",exprsn);
	answer = evaluate(exprsn);
	printf("%s = %f",exprsn,answer);
	stop :
	return 0;
}
