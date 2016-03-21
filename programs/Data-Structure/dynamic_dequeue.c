#include<stdio.h>
#include<stdlib.h>

void insert_rear();
void delete_rear();
void delete_front();
void insert_front();
void display();
void input_restricted();
void output_restricted();
int ch,ele;

struct node
{
int data;
struct node *next;
};

struct node *start=NULL;

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
struct node *newn,*temp=start;
printf("Enter the element to be inserted\n");
scanf("%d",&ele);
newn=(struct node*)malloc(sizeof(struct node));
newn->data=ele;
newn->next=NULL;
if(start==NULL)
{
start=newn;
}
else
{
while(temp->next!=NULL)
temp=temp->next;
temp->next=newn;
}
}

void insert_front()
{
struct node *newn;
printf("Enter the element to be inserted\n");
scanf("%d",&ele);
newn=(struct node*)malloc(sizeof(struct node));
newn->data=ele;
newn->next=NULL;
if(start==NULL)
{
start=newn;
}
else
{
newn->next=start;
start=newn;
}
}

void delete_rear()
{
struct node *temp=start;
if(start==NULL)
printf("List Is Empty\n");
else if((start->next)==NULL)
start=NULL;
else
{
while((temp->next)->next!=NULL)
temp=temp->next;
temp->next=NULL;
}
}

void delete_front()
{
if(start==NULL)
printf("List Is Empty\n");
else if((start->next)==NULL)
start=NULL;
else
{
start=start->next;
}
}


void display()
{
struct node *temp=start;
if(start==NULL)
printf("List is empty\n");
else
{
while(temp!=NULL)
{
printf("%4d-->%d-->%4d\n",temp,temp->data,temp->next);
temp=temp->next;
}
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
