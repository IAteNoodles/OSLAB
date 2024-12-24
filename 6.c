#include<stdio.h>
#define queuesize 5
int item,front,rear,count,q[queuesize];
void insert_rear()
{
  if(count = = queuesize)
  {
    printf("queue overflow\n");
    return;
  }
  rear = (rear +1) % queuesize;
  q[rear] = item;
  count = count + 1;
}
 
void delete_front()
{
  int item;
  if(count = = 0)
  {
    	printf("queue is empty\n");
return;
  }
  item = q[front];
  printf("\nthe item deleted is %d",item);
  front = (front +1) % queuesize;
  count = count - 1;
}
 
 
void display()
{
  int i,f;
  if(count = = 0)
  {
    	printf("queue is empty\n");
    	return;
  }
  printf("the contents of the queue are\n");
  for(i=1,f=front;i<=count;i++)
  {
    	printf("%d\n",q[f]);
    	f = (f+1) % queuesize;
  	  }
}
void main()
{
  int choice;
front=0;
rear=-1;
count=0;
  clrscr( );
  for(;;)
  {
    	printf("\n1:insert_rear\n2:delete_front\n");
    	printf("3:display\n4:exit\n");
    	printf("enter your choice\n");
    	scanf("%d",&choice);
    	switch(choice)
    	{
      		case 1: printf("enter the item to be inserted\n");
	      		 scanf("%d",&item);
	      		 insert_rear();
	      		 break;
 
      		case 2: delete_front();
	      		 break;
 
      		case 3: display();
	      		 break;
 
      		case 4: exit(0);
    	}
  }
}