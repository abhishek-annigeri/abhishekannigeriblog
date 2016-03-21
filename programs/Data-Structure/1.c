#include<stdio.h>
#include<string.h>
#include<string.h>
char temp[2],tempstk[20][30],*opnd1,*opnd2;
int top=-1;
 void push(char temp[])
{
top++;
strcpy(tempstk[top],temp);
}

char* pop()
{
char *ele;
ele=tempstk[top];
top--;
return(ele);
}

void prepost(char prefix[],char postfix[],int l)
{
int i;
char ch;
for(i=0;i<l;i++)
{
ch=prefix[i];
temp[0]=ch;
temp[1]='\0';

switch(ch)
{
case '+' :
case '-' :
case '*' :
case '/' :
	 opnd1=pop();
	 opnd2=pop();
	strcpy(postfix,opnd1);
	strcat(postfix,opnd2);
	strcat(postfix,temp);
	push(postfix);
	break;
default : push(temp);
	  break;
}
}
}

void main()
{
int i,j,l;
char pre[20],postfix[20],prefix[20];
printf("Enter the prefix expression\n");
scanf("%s",pre);
l=strlen(pre);
for(i=0,j=l-1;i<l;i++,j--)
{
prefix[i]=pre[j];
}
prefix[i]='\0';
prepost(prefix,postfix,l);
printf("Postfix expression = %s\n",postfix);
}
