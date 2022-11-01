#include<stdio.h>
int front=-1,rear=-1,item,queue[100],limit;
void enqueue()
{
    if(front==limit-1)
    {
        printf("\nqueue is overflow");
    }
    else{
        rear=0;
        printf("\nenter the element to be inserted: ");
        scanf("%d",&item);
        front++;
        queue[front]=item;

    }
}
void dequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("\nqueue is empty");
    }
    else if(rear>front){
        printf("\nqueue is empty");
    }
    else{
        item=queue[rear];
        printf("\nelement deleted from the queue is %d",item);
        rear++;
    }
}
int main()
{
    int ch,cont; 
    printf("\nenter the size of the queue: ");
    scanf("%d",&limit);
 do{
        printf("\n1.enqueue()\n2.dequeue");
        printf("\nenter your choice: ");
        scanf("%d",&ch);
    
        switch(ch)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            default: printf("\nyou have entered a wrong choice");
                     break;
        }
        printf("\ndo you want to continue(yes=1/no=0)");
        scanf("%d",&cont);
    }while(cont==1);
    return 0;
}