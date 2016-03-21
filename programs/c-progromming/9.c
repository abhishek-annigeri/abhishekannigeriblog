#include<stdio.h>
#include<stdlib.h>
void  main()
{
int n,c1,ch,j,i;
while(1)
{
printf("enter n\n");
scanf("%d",&n);
printf("1:fibonacci\n2:Factorial\n3:Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:		for(i=0;i<n;i++)
		{
		printf("Fibonacci series:%d\n",fib(i));
		}
		break;
case 2:		printf("factorial =\n");
		fact(n);
		break;
case 3:		exit(0);
default: printf("invalid choice\n");
		break;
}
}
}

int fib(int n)
{
if(n==0)
return 0;
else if(n==1)
return 1;
else
return fib(n-1)+fib(n-2);
}

int fact(int n)
{
int s=1,i;
for(i=1;i<=n;i++)
s=s*i;
printf("%d\n",s);
}

