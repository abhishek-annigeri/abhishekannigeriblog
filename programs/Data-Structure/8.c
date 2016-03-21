#include<stdio.h>
#include<stdlib.h>
#define size 5
void push(int);
void pop();
void sdisplay();
void qinsert(int);
void qdelete();
void qdisplay();
void stack();
void queue();

struct node
{
int info;
struct node *next,*prev;
};

struct node *top=NULL,*front=NULL,*rear=NULL;

void main()
{
int ch;
while(1)
{
printf("\n1:Stack\n2:Queue\n3::Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: stack();break;
case 2: queue();break;
case 3: exit(0);
default :  printf("Invalid choice\n");break;
}
}
}

void stack()
{
int ch,ele;
while(1)
{
printf("\n1:Push\n2:Pop\n3:Display\n4:Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:	printf("\nEnter the element to be inserted\n");
	scanf("%d",&ele);
	push(ele);
	break;
case 2: pop();break;
case 3: sdisplay();break;
case 4: return;
default :  printf("Invalid choice\n");break;
}
}
}

void queue()
{
int ch,ele;
while(1)
{
printf("\n1:Insert\n2:Delete\n3:Display\n4:Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:	printf("Enter the element to be inserted\n");
	scanf("%d",&ele);
	qinsert(ele);
	break;
case 2: qdelete();break;
case 3: qdisplay();break;
case 4: return;
default :  printf("Invalid choice\n");break;
}
}
}


void push(int ele)
{
struct node *newn;
newn=(struct node*)malloc(sizeof(struct node));
newn->next=NULL;
newn->prev=NULL;
newn->info=ele;
if(top==NULL)
top=newn;
else
{
newn->next=top;
newn->prev=NULL;
top=newn;
}
}

void pop()
{
struct node *temp=top;
if(top==NULL)
printf("Stack Underflow\n");
else
{
top=top->next;
top->prev=NULL;
printf("Deleted element is %d",temp->info);
temp->next=NULL;
temp->prev=NULL;
free(temp);
}
}


void sdisplay()
{
struct node *temp=top;
if(top==NULL)
printf("Stack is empty\n");
else
{
printf("Stack elements are:\n");
while(temp!=NULL)
{
printf("%d\t",temp->info);
temp=temp->next;
}
}
}

void qinsert(int ele)
{
struct node *newn;
newn=(struct node*)malloc(sizeof(struct node));
newn->next=NULL;
newn->prev=NULL;
newn->info=ele;
if(rear==NULL)
{
front=newn;
rear=newn;
}
else
{
rear->next=newn;
rear=newn;
}
}

void qdelete()
{
struct node *temp=front;
printf("Deleted element=%d",temp->info);
front=front->next;
front->prev=NULL;
temp->next=NULL;
temp->prev=NULL;
free(temp);
}

void qdisplay()
{
struct node *temp=front;
printf("Queue is \n");
while(temp!=NULL)
{
printf("%d\t",temp->info);
temp=temp->next;
}
}
