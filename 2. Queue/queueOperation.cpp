#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define maxSize 5
int queue[maxSize],data,rear=-1,front=-1;
void enqueue();
void dequeue();
void display();
main()
{
	int choice;
	start:
		printf("\n1. Enqueue Operation");
		printf("\n2. Dequeue Operation");
		printf("\n3. Display");
		printf("\n4. Exit\n");
		printf("Enter your choice=");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
		    case 2:
			    dequeue();
				break;
			case 3:
			    display();
				break;
			case 4:
			    exit(0);
				break;
				default:
				printf("\nEnter valid option!");
				break;				
		}
		goto start;
		getch();
}
void enqueue()
{
	if(rear==maxSize-1)
	{
		printf("\nQueue Overflow");
	}
	else
	{
		if(front==-1)
		{
			rear=0;
			front=0;
		}
		else
		{
			rear=rear+1;
		}
		printf("Enter data:");
		scanf("%d",&data);
		queue[rear]=data;
	}
}
void dequeue()
{
	if(front==-1)
	{
		printf("Queue Underflow");
	}
	else
	{
		data=queue[front];
		if(front==rear)
		{
			rear=-1;
			front=-1;
		}
		else
		{
			front=front+1;
		}
		printf("The dequeue element =%d",data);
	}
}
void display()
{
	int i;
	printf("The Content of Queue:");
	if(front==-1)
	{
		printf("The Queue os empty");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
}
