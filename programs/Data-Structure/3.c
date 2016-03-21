#include<stdio.h>
#include<stdlib.h>
#define size 5
int j,front=0,rear=-1,count=0,cqueue[size],i,n;

void insert_rear(int item)
{
if(count==size)
printf("Queue is overflow\n");
else
{
rear=(rear+1)%size;
cqueue[rear]=item;
count++;
}
}

void delete_front()
{
if(count==0)
printf("Queue is underflow\n");
else
{
printf("Deleted item = %d\n",cqueue[front]);
front=(front+1)%size;
count--;
}
}

void display()
{
if(count==0)
printf("Queue is empty\n");
else
{
j=front;
for(i=1;i<=count;i++)
{
printf("Count is %d----> %d\n",i,cqueue[j]);
j=(j+1)%size;
}
}
}

void main()
{
int ch,item;
while(1)
{
printf("1:Insert Rear\n2:Delete Front\n3:Display\n4:Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter the item to be inserted\n");
	scanf("%d",&item);
	insert_rear(item);
	break;
case 2: delete_front();
	break;
case 3: display();break;
case 4: exit(0);
default : printf("Invalid choice\n");
	  break;
}
}
}
