#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int createNode();
void insAtBeg();
void insAtSp();
void insAtEnd();
void delAtBeg();
void delAtEnd();
void delAtSp();
void display();
int data,pos;
struct node{
	int info;
	struct node *next;
	
};
struct node *start=NULL,*newnode,*temp,*temp1;

main()
{
	int ch;
	printf("\n1.Insert at beginning\n2.Insert at specific position\n3.Insert at end\n4.Deletion at beginning\n5.Deletion at end\n6.Deletion at specific position\n7.Display\n8.Exit\n");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			insAtBeg();
			break;
		case 2:
			insAtSp();
			break;
		case 3:
		    insAtEnd();
			break;	
		case 4:			
		  delAtBeg();
			break;
		case 5:
			delAtEnd();
			break;
		case 6:
			delAtSp();
			break;
         case 7:
         	display();
         	break;
		case 8:
		  exit(0);
		 default:
		   printf("enter valid choice!"); 	
						
				
	}
	main();

}
int createNode()
{
	newnode=(struct node*)malloc(sizeof(struct node*));
}
void insAtBeg()
{
	createNode();
	printf("\nEnter any data:");
	scanf("%d",&data);
	newnode->info=data;
	if(start==NULL){
		start=newnode;
		newnode->next=NULL;
	}
	else{
		newnode->next=start;
		start=newnode;
		
	}
}
void insAtSp(){
	createNode();
	printf("\nEnter any data:");
	scanf("%d",&data);
	newnode->info=data;
	printf("Enter position to insert:");
	scanf("%d",&pos);
	temp=start;
	int i;
		for(i=1;i<pos-1;i++){
			temp=temp->next;
		}
		 newnode->next=temp->next;
		 temp->next=newnode;
}
void insAtEnd(){
	createNode();
	printf("\nEnter any data:");
	scanf("%d",&data);
	newnode->info=data;
	newnode->next=NULL;
	if(start==NULL){
		start=newnode;
		
	}else{
		temp=start;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
	}
}
void display()
{
	if(start==NULL)
	{
		printf("\nList is empty");
	}
	else{
		temp=start;
		while(temp!=NULL){
			printf("%d\t",temp->info);
			temp=temp->next;
		}
	}
}
void delAtBeg(){
	if(start==NULL){
		printf("\nList is empty");
		
	}
	else if(start->next==NULL){
			start=NULL;
			
		}
	
	
	else{
		temp=start;
		start=start->next;
		free(temp);
	}
	
}
void delAtEnd(){
	if(start==NULL){
		printf("\nlist is empty");
	}
	else if(start->next==NULL)
	{
		printf("%d",start->info);
		start=NULL;
	}
	else{
		temp=start;
		temp1=temp->next;
		while(temp1->next!=NULL){
			temp=temp->next;
			temp1=temp1->next;
		}
		printf("%d",temp1->info);
		free(temp1);
		temp->next=NULL;
	}
		
	
}
void delAtSp(){
	int i;
 	if(start==NULL){
 		printf("\nList is empty");
 		main();
	 }
	 else{
	 	printf("\nEnter position of element to delete:");
	 	scanf("%d",&pos);
	 	temp=start;
	 	for(i=1;i<pos-1;i++){
	 		temp=temp->next;
		 }
		 temp1=temp->next;
		 temp->next=temp1->next;
		 printf("\nDeleted node is: %d",temp1->info);
		 free(temp1);
	 }	
}

