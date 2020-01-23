#include <stdio.h>
#include <conio.h>
#define maxSize 20
int stack[maxSize],top=-1;

void push(int val)
{
	top++;
	stack[top]=val;
}

int pop()
{
	int a;
	a=stack[top];
	top--;
	return a;
}
int is_operand(char ch)
{
	if(ch>='a'&&ch<='z'||ch>='A'&& ch<='Z')
	 return 1;
	else
	  return 0; 
}
main()
{
char postfix[maxSize],ch;
int i=0,op1,op2,result,m;
printf("Enter Postfix Expression:");
gets(postfix);
while(postfix[i]!='\0')
 {
 	ch=postfix[i];
 	if(is_operand(ch)==1)
 	 {
 		printf("Enter the value of %c:",ch);
 		scanf("%d",&m);
 		push(m);
	 }
	else
	 {
	  op2=pop();
	  op1=pop();
	  switch(ch)
	   {
	   	case '+':
	   		result=op1+op2;
	   		push(result);
	   		break;
	    case '-':
	   		result=op1-op2;
	   		push(result);
	   		break;
	    case '*':
	   		result=op1*op2;
	   		push(result);
	   		break;
	    case '/':
	   		result=op1/op2;
	   		push(result);
	   		break;		   		   		
	   }
	 }
	 i++; 
 }
 result=pop();
 printf("\nThe result is: %d",result);
 getch();
}
