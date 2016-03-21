#include<stdio.h>
int main()
{
int i,temp,rem,n,r,sum;
printf("Enter limit ranging from 100 to 999\n");
scanf("%d",&n);
for(i=100;i<=n;i++)
{
temp=i;
sum=0;
while(temp>0)
{
rem=temp%10;
sum=sum+(rem*rem*rem);
temp=temp/10;
}
if(i==sum)
printf("%d is an Armstrong number\n",i);
}
return 0;
}
