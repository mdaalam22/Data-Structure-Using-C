/* Implementation of contiguous list */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define maxSize 5
void insert();
void deletelist();
void display();
int ub=-1,pos,list[maxSize],data,t;
int main()
{
	int ch;
	printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	printf("\nEnter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			insert();
			break;
		case 2:
		    deletelist();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
		    printf("\nInvalid option!!");			
	}
	main();
	getch();
}
void insert()
{
	if(ub==maxSize-1)
	{
		printf("\nList is full\n");
		main();
	}
	else
	 {
	 	printf("\nEnter position to insert data: ");
	 	scanf("%d",&pos);
	 	if(pos>ub+1)
	 	 {
	 	   printf("\nPosition out of range");	
		  }
		  else
		    {
		    	printf("Enter any data:");
		    	scanf("%d",&data);
		    	t=ub;
		    	while(t>=ub)
		    	{
		    		list[t+1]=list[t];
		    		t--;
				}
				list[pos]=data;
			}
			ub++;
	 }
}
void deletelist()
{
	if(ub==-1)
	{
		printf("\nList is empty");
		main();
	}
	else
	 {
	 	printf("Enter position to delete element:");
	 	scanf("%d",&pos);
	 	if(pos>=0 && pos<=ub)
	 	{
	 		t=pos;
	 		printf("\nDeleted item is %d",list[pos]);
	 		while(t<=ub)
	 		{
	 			list[t]=list[t+1];
	 			t++;
			 }
		 }
		 else
		   {
		   	printf("Position out of range");
		   }
	 	  ub--;
	 }
}
void display()
{
	int i;
	if(ub==-1)
	{
		printf("\nList is empty");
		main();
	}
	else
	 {
	 	for(i=0;i<=ub;i++)
	 	{
	 		printf("%d\t",list[i]);
		 }
	 }
	
}
