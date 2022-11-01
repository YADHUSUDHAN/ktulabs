#include <stdio.h>
#include <stdlib.h>
struct node *head1 = NULL ;
struct node *head2 = NULL ;
struct node *head3 = NULL ;
struct node *new_node;
struct node
{
    int co;
    int exp;
    struct node *next;
};
void insertion(int n,struct node **head)
{
    int i;
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
			printf("\n");
			if(*head == NULL)
			{
				printf("Enter the coeficient of term %d : ",(i+1));
				scanf("%d",&new_node->co);
				printf("Enter the exponent of term %d : ",(i+1));
				scanf("%d",&new_node->exp);
				*head = new_node;
				new_node->next = NULL;
			}
			else
			{	
				struct node *temp;
				printf("Enter the coeficient of term %d : ",(i+1));
				scanf("%d",&new_node->co);
				printf("Enter the exponent of term %d : ",(i+1));
				scanf("%d",&new_node->exp);
				temp = *head;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = new_node;
				new_node->next = NULL;
			}		
		}
	}
}
void printpo(struct node *head)
{
		struct node *temp;
		temp = head;
		printf("%dX^%d  ",temp->co,temp->exp);
		temp = temp->next;
		while(temp != NULL)
		{
			printf("+ ");
			printf("%dX^%d  ",temp->co,temp->exp);
			temp = temp->next;
		}
}
void addpo(struct node *p,struct node *q)
{
		struct node *t1,*t2,*temp;
		t1 = p;
		t2 = q;
		while(t1 != NULL && t2 != NULL)
		{
			if(t1->exp == t2->exp)
			{
				new_node = (struct node*)malloc(sizeof(struct node));
				new_node->exp = t1->exp;
				new_node->co = t1->co + t2->co;
				if(head3 == NULL)
				{
					head3 = new_node;
					new_node->next = NULL;
				}
				else
				{	
					temp = head3;
					while(temp->next != NULL)
					{
						temp = temp->next;
					}
					temp->next = new_node;
					new_node->next = NULL;
				}
				t1 = t1->next;
				t2 = t2->next;
			}
			else if(t1->exp > t2->exp)
			{
				new_node = (struct node*)malloc(sizeof(struct node));
				new_node->exp = t1->exp;
				new_node->co = t1->co;
				temp = head3;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = new_node;
				new_node->next = NULL;
				t1 = t1->next;
				
			}
			else if(t1->exp < t2->exp)
			{
				new_node = (struct node*)malloc(sizeof(struct node));
				new_node->exp = t2->exp;
				new_node->co = t2->co;
				temp = head3;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = new_node;
				new_node->next = NULL;
				t2 = t2->next;
				
			}
			
		}
		while(t1 != NULL || t2 != NULL)
		{
			printf("balance\n");
			/*new_node = (struct node*)malloc(sizeof(struct node));*/
			if(t1 != NULL)
			{
				/*new_node->exp = t1->exp;
				new_node->co = t1->co;
				temp = head3;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = new_node;
				new_node->next = NULL;*/
				t1 = t1->next;
			}
			else if(t2 != NULL)
			{
				/*new_node->exp = t2->exp;
				new_node->co = t2->co;
				temp = head3;
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = new_node;
				new_node->next = NULL;*/
				t2 = t2->next;
			}
				
		}
}

int main()
{
	int n,m;
	printf("Polynomial program \n\n");
	printf("\nEnter the number of terms of first polynomial : ");
	scanf("%d",&n);
	insertion(n,&head1);
	printf("\nEnter the number of terms of second polynomial : ");
	scanf("%d",&m);
	insertion(m,&head2);
	addpo(head1,head2);
	printf("\n");
	printf("Polyomial 1 : ");
	printpo(head1);
	printf("\n");
	printf("Polyomial 2 : ");
	printpo(head2);
	printf("\n");
	printf("Polynomial after adition\n");
	printf("Polyomial 3 : ");
	printpo(head3);
    return 0;
}


