#include<stdio.h>
#include<stdlib.h>
#define size 5
int ch,ele,j=0;
void insert_rear();
void delete_rear();
void delete_front();
void insert_front();
void display();
struct queue
{
int rear,front;
int queue[size];
}q;

void input_restricted()
{
while(1)
{
printf("\n1:Insert Rear\n2:Delete Rear\n3:Delete Front\n4:Back\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: insert_rear();display();
	break;
case 2: delete_rear();display();
	break;
case 3: delete_front();display();
	break;
default : printf("Invalid choice\n");break;
case 4 : return;
}
}
}

void output_restricted()
{
while(1)
{
printf("\n1:Insert Rear\n2:Insert Front\n3:Delete Front\n4:Back\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: insert_rear();display();
	break;
case 2: insert_front();display();
	break;
case 3: delete_front();display();
	break;
case 4: return;
default : printf("Invalid choice\n");break;
}
}
}

void insert_rear()
{
if(q.rear==size)
printf("Queue is full\n");
else
{
printf("Enter the element\n");
scanf("%d",&ele);
q.rear++;
q.queue[q.rear]=ele;
}
}

void insert_front()
{
if(q.front==size)
printf("Queue is full\n");
else
{
printf("Enter the element\n");
scanf("%d",&ele);
q.queue[q.front]=ele;
q.front--;
}
}

void display()
{
int i;
printf("Dequeue\n");
for(i=q.front+1;i<=q.rear;i++)
printf("%d\t",q.queue[i]);
}

void delete_rear()
{
if(q.rear==0)
printf("Dequeue is empty\n");
else
{
q.rear--;
}
}


void delete_front()
{
if(q.front==size)
printf("Dequeue is empty\n");
else
{
q.front++;
}
}

void main()
{
while(1)
{
printf("\n1:Input Restricted Dequeue\n");
printf("2:Output Restricted Dequeue\n");
printf("3:Exit\n");
printf("\nEnter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: input_restricted();
	break;
case 2: output_restricted();
	break;
case 3: exit(0);
default : printf("invalid choice\n");
	  break;

}
}
}
