/*C program to perform following operation using RECURSION
1.Factorial of a number
2.Fibonacci series
3.Tower of hanoe*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int fact(int);
int fib(int);
void toh(int,char,char,char);
int main()
{
	int ch,num,k,i;
	printf("\n1.Factorial\n2.Fibonacci series\n3.Tower of Hanoe\n4.Exit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nEnter any number:");
			scanf("%d",&num);
			k=fact(num);
			printf("\nThe factorial of %d!=%d",num,k);
			break;
		case 2:
			printf("\nEnter no. of term of fibonacci series:");
			scanf("%d",&num);
			for(i=1;i<=num;i++)
			{
			  printf("%d\t",fib(i));	
			}
			
			break;
		case 3:
			printf("\nEnter no. of disk:");
			scanf("%d",&num);
			toh(num,'A','C','B');
			break;
		case 4:
		    exit(0);
		default:
		  printf("\nIvalid choice!!");		
	}
	main();
	getch();
}
int fact(int a)
{
	if(a==1)
	return 1;
	else
	  return(a*fact(a-1));
}
int fib(int a)
{
	if(a==1||a==2)
	  return 1;
	else
	  return(fib(a-1)+fib(a-2));  
}
void toh(int n,char src,char dest,char temp)
{
	if(n==1)
	{
		printf("\nMove disk 1 from peg %c to peg %c ",src,dest);
		 return;
	}
	 toh(n-1,src,temp,dest);
	  printf("\nMove disk %d from peg %c to peg %c",n,src,dest);
	 toh(n-1,temp,dest,src);
}
