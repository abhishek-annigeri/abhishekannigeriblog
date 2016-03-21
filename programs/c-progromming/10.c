#include<stdio.h>
#include<stdlib.h>
void main()
{
int i,j,n,m,ch,s=0;
while(1)
{
printf("1:Read n and m\n2:Sum of n to m\n3:Sum of all even numbers\n4:Sum of All odd numbers\n");
printf("5:exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter n\n");
	scanf("%d",&n);
	printf("Enter m\n");
	scanf("%d",&m);
	if(n>m)
	printf("N is Greater then M\n");
	else
	printf("N=%d\tM=%d\n",n,m);
	break;
case 2: s=0;
	for(i=n;i<=m;i++)
	s=s+i;
	printf("Sum of numbers b/w n&m is:%d\n",s);
	break;
case 3: s=0;
	if(n%2!=0)
	n=n+1;
	for(i=n;i<m;i++)
	{
	s=s+i;
	i++;
	}
	printf("Sum of even numbers b/w n&m is:%d\n",s);
	n=n-1;
	break;
case 4:	s=0;
	if(n%2==0)
	n=n+1;
	for(i=n;i<m;i++)
	{
	s=s+i;
	i++;
	}
	printf("Sum of odd numbers b/w n&m is:%d\n",s);
	n=n-1;
	break;
default: printf("Invalid choice\n");
	 break;
case 5: exit(0);
}
}
}
