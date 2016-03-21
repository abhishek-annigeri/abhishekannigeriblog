#include<stdio.h>
void main()
{
int n,i,sum=0,j;
printf("Enter the value of n\n");
scanf("%d",&n);
j=n;
for(i=1;i<n;i++)
{
if(n%i==0)
sum=sum+i;
}
if(j==sum)
printf("Its perfect number\n");
else
printf("Its not perfect number\n");
}
