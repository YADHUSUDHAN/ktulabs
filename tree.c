#include <stdio.h>
#include <stdlib.h>
struct child *root = NULL;
struct child
{
	int data;
	struct child *lc,*rc;
};
void insertion()
{
	struct child *newchild,*parent,*ptr;
	newchild = (struct child*)malloc(sizeof(struct child));
	printf("Enter the number : ");
	scanf("%d",&newchild->data);
	newchild->lc =NULL;
        newchild->rc =NULL;
	if(root == NULL)
	{
		root = newchild;
	}
	else
	{
		ptr = root;
		while(ptr != NULL)
		{
			parent = ptr;
			if(newchild->data < ptr->data)
			{
				ptr = ptr->lc;
				if(ptr == NULL)
				{
					parent->lc = newchild;
				}
			} 
			else
			{
				ptr = ptr->rc;
				if(ptr == NULL)
				{
					parent->rc = newchild;
				}
			}
		}
	}
}
void preorder(struct child *root)
{
	struct child *ptr;
	ptr = root;
	if(ptr != NULL)
	{
		printf(" %d",ptr->data);
		preorder(ptr->lc);
		preorder(ptr->rc);
	}
}
void inorder(struct child *root)
{
	struct child *ptr;
	ptr = root;
	if(ptr != NULL)
	{
		inorder(ptr->lc);
		printf(" %d",ptr->data);
		inorder(ptr->rc);
	}
}
void postorder(struct child *root)
{
	struct child *ptr;
	ptr = root;
	if(ptr != NULL)
	{
		postorder(ptr->lc);
		postorder(ptr->rc);
		printf(" %d",ptr->data);
	}
}
int main()
{
	int i,n;
	printf("Enter the number of elements in tree : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		insertion();
	}
	printf("\nPreorder traversal\n");
	preorder(root);
	printf("\nInorder traversal\n");
	inorder(root);
	printf("\nPostorder traversal\n");
	postorder(root);
	return 0;
}

