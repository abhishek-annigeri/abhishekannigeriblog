#include<stdio.h>
void main()
{
int k,num,res[10],rem,i,j;
printf("Enter num\n");
scanf("%d",&num);
res[1]=0;
j=num;
i=1;
while(num!=0)
{
rem=num%16;
res[i]=rem;
num=num/16;
i++;
}
printf("%d to Hexadecimal is: ",j);
for(k=i-1;k>=1;k--)
{
switch(res[k])
{
case 10: printf("A");
	 break;
case 11: printf("B");
         break;
case 12: printf("C");
         break;
case 13: printf("D");
         break;
case 14: printf("E");
         break;
case 15: printf("F");
         break;
default: printf("%d",res[k]);
}
}
printf("\n");
}
