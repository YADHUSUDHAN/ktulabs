#include <stdio.h>
#include <stdlib.h>
struct node *head = NULL ;
struct node
{
    int item;
    struct node *next;
};
void print()
{
	if(head == NULL)
	{
		printf("The list is empty!!");
		exit(0);
	}
    else
    {
		printf("Elements in the list \n");
		struct node *temp;
		temp = head;
		while(temp != NULL)
		{
			printf("%d  ",temp->item);
			temp = temp->next;
		}
	}
}
void insertion()
{
	char opt,opt2;
    int i,n;
    struct node *new_node;
    printf("\nInsertion \n");
    printf("********* \n");
    ret1 :
    printf("Insertion at begining - A\nInsertion at end - B\nInsertion at specific position - C\nInsertion at specific data - D\n");
    printf("\nEnter an option : ");
    scanf(" %c",&opt);
    if (opt == 'a' || opt == 'A')
    {
		printf("\nEnter the number of elements to insert : ");
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			new_node = (struct node*)malloc(sizeof(struct node));
			if(new_node == NULL)
			{
				printf("Memmory overflow!!");
				exit(0);
			}
			else
			{
				if(head == NULL)
				{
					printf("Enter the number to insert into list : ");
					scanf("%d",&new_node->item);
					head = new_node;
					new_node->next = NULL;
				}
				else
				{
					printf("Enter the number to insert into list : ");
					scanf("%d",&new_node->item);
					new_node->next = head;
					head  = new_node; 
				}
			}
		}
		printf("\nAfter insertion\n");
		print();
	}
	else if(opt == 'b' || opt == 'B')
	{
		printf("\nEnter the number of elements to insert : ");
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			new_node = (struct node*)malloc(sizeof(struct node));
			if(new_node == NULL)
			{
				printf("Memmory overflow!!");
				exit(0);
			}
			else
			{
				if(head == NULL)
				{
					printf("Enter the number to insert into list : ");
					scanf("%d",&new_node->item);
					head = new_node;
					new_node->next = NULL;
				}
				else
				{
				
					struct node *temp;
					printf("Enter the number to insert into list : ");
					scanf("%d",&new_node->item);
					temp = head;
					while(temp->next != NULL)
					{
						temp = temp->next;
					}
					temp->next = new_node;
					new_node->next = NULL;
				}
				
			}
		}
		printf("\nAfter insertion\n");
		print();
	}
	else if(opt == 'c' || opt == 'C')
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		if(new_node == NULL)
		{
			printf("Memmory overflow!!");
			exit(0);
		}
		int count = 0,pos;
		struct node *temp,*prev;
		printf("\nEnter the position : ");
		scanf("%d",&pos);
		if(pos<1)
		{
			printf("Ivalid position!");
			exit(0);
		}
		temp = head;
		while(count < (pos-1) && temp->next != NULL)
		{
			prev = temp;
			count++;
			temp = temp->next;
		}
		if(count == (pos-1))
		{
			if(pos == 1)
			{
				if(head == NULL)
				{
					printf("Enter the number to insert into list : ");
					scanf("%d",&new_node->item);
					head = new_node;
					new_node->next = NULL;
				}
				else
				{
					printf("Enter the number to insert into list : ");
					scanf("%d",&new_node->item);
					new_node->next = head;
					head = new_node;
				}
				printf("\nAfter insertion\n");
				print();
			}
			else if(temp->next == NULL)
			{
				printf("Enter the number to insert into list : ");
				scanf("%d",&new_node->item);
				new_node->next = NULL;
				prev->next = new_node;
				printf("\nAfter insertion\n");
				print();
			}
			else
			{
				printf("Enter the number to insert into list : ");
				scanf("%d",&new_node->item);
				new_node->next = temp;
				prev->next = new_node;
			}
		}
		else
		{
			printf("Position etered is greater than number of elements.\n");
		}
	}
	else if(opt == 'd' || opt == 'D')
	{
		new_node = (struct node*)malloc(sizeof(struct node));
		if(new_node == NULL)
		{
			printf("Memmory overflow!!");
			exit(0);
		}
		if(head == NULL)
		{
			printf("The list is empty!!");
			exit(0);
		}
		int itm;
		struct node *temp,*prev;
		printf("\nEnter the number : ");
		scanf("%d",&itm);
		ret2 :
		printf("For insertig after %d - A.\nFor insertig before %d - B.\nEnter an option : ",itm,itm);
		scanf(" %c",&opt2);
		if(!(opt2 == 'B' || opt2 == 'b' || opt2 == 'A' || opt2 == 'a'))
		{
			printf("Ivalid input!!\nRetry\n");
			goto ret2;
		}
		temp = head;
		while(temp->item != itm && temp->next != NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		if(temp->item == itm)
		{
			if(opt2 == 'B' || opt2 == 'b')
			{
				printf("Enter the number to insert into list : ");
				scanf("%d",&new_node->item);
				new_node->next = temp;
				prev->next = new_node;
			}
			else
			{
				printf("Enter the number to insert into list : ");
				scanf("%d",&new_node->item);
				new_node->next = temp->next;
				prev->next->next = new_node;
			}
		}
		else
		{
			printf("%d not found in the list.\n",itm);
		}
	}
	else
	{
		printf("Ivalid input!!\nRetry\n");
		goto ret1;
	}
}
void deletion()
{
    int i,n;
    printf("\nDeletion at specific position \n");
    printf("********* \n");
		printf("\nEnter the number of elements to delete : ");
		scanf("%d",&n);
		for(i = 0;i < n;i++)
		{
			if(head == NULL)
			{
					printf("The list is empty!!");
					break;
			}
			else
			{
				int count = 0,pos;
				struct node *temp,*prev;
				printf("\nEnter the position : ");
				scanf("%d",&pos);
				if(pos<1)
				{
					printf("Ivalid position!");
					break;
				}
				temp = head;
				while(count < (pos-1) && temp->next != NULL)
				{
					prev = temp;
					count++;
					temp = temp->next;
				}
				if(count == (pos-1))
				{
					if(pos == 1)
					{
						if(head->next== NULL)
						{
							printf("The item dleted : %d",head->item);
							free(head);
							head = NULL;
							printf("\nThe list had become empty!!");
							break;
						}
						else
						{
							head = temp->next;
							printf("The item dleted : %d",temp->item);
							free(temp);
						}
					}
					else if(temp->next == NULL)
					{						
						printf("The item dleted : %d",temp->item);
						prev->next = NULL;
						free(temp);
					}
					else
					{						
						printf("The item dleted : %d",temp->item);
						prev->next = temp->next;
						free(temp);
					}
				}
				else
				{
					printf("Position entered is greater than number of elements.\n");
					break;
				}
			}
			printf("\nAfter deletion\n");
			print();
		}
	
}
int main()
{
	char opt,opt2;
	printf("Linked List program\n\n");
	begin : 
    printf("Insertion  - A\nPrinting - B\n");
    printf("\nEnter an option : ");
    scanf(" %c",&opt);
    if (opt == 'a' || opt == 'A')
    {
		insertion();
	}
	else if(opt == 'b' || opt == 'B')
	{
    print();
	}
	else if(opt == 'c' || opt == 'C')
	{
		deletion();
	}
	ret3 :
	printf("\nDo you want to continue(yes - Y & no - N) : ");
	scanf(" %c",&opt2);
	if(opt2 == 'y' || opt2 == 'Y' )
	{
		goto begin;
	}
	else if(!(opt2 == 'N' || opt2 == 'n' ))
	{
		printf("Ivalid input!!\nRetry\n");
		goto ret3;
	}
    return 0;
}

