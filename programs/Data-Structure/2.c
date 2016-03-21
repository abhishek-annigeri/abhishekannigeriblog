#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1,value=0,i,item,opnd1,opnd2,stk[20];

void push(int item)
{
top++;
stk[top]=item;
}

int pop()
{
value=stk[top];
top--;
return value;
}

void main()
{
int l;
char ch,postfix[20];
printf("Enter the postfix expression\n");
scanf("%s",postfix);
l=strlen(postfix);
for(i=0;i<l;i++)
{
ch=postfix[i];
if(isalnum(ch))
{
push(ch-'0');
}
else
{
opnd2=pop();
opnd1=pop();
switch(ch)
{
case '+' : value=opnd1+opnd2;
	    break;
case '-' : value=opnd1+opnd2;
	  break;
case '*' : value=opnd1*opnd2;
	 break;
case '/' : value=opnd1/opnd2;
 	break;
default : printf("Invalid expression\n");
	  break;
}
push(value);
}
}
printf("Value=%d\n",value);
}
