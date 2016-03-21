#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node *next; 
};

struct node *start=NULL;

void insert_beginning()
{
struct node *newn,*temp;
int ele;
printf("Enter the element to be inserted\n");
scanf("%d",&ele);
newn=(struct node*)malloc(sizeof(struct node));
newn->info=ele;
newn->next=NULL;
if(start==NULL)
{
start=newn;
temp=newn;
}
else
{
newn->next=start;
start=newn;
}
}

void insert_end()
{
struct node *newn,*temp=start;
int ele;
printf("Enter the element to be inserted\n");
scanf("%d",&ele);
newn=(struct node*)malloc(sizeof(struct node));
newn->info=ele;
newn->next=NULL;
if(start==NULL)
{
start=newn;
}
else
{
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newn;
newn->next=NULL;
}
}


void insert_position()
{
struct node *newn,*temp;
int ele,pos,i;
printf("Enter the position to be inserted\n");
scanf("%d",&pos);
if(pos<0)
{
printf("Invalid position\n");
}
printf("Enter the element to be inserted\n");
scanf("%d",&ele);
if(pos==1)
{
insert_beginning();
}
else
{
temp=start;
for(i=1;i<pos-1;i++)
{
temp=temp->next;
}
newn=(struct node*)malloc(sizeof(struct node));
newn->info=ele;
newn->next=temp->next;
temp->next=newn;
}
}



void insert_before_ele()
{
struct node *newn,*temp1=start,*temp2=start->next;
int ele,key,f=0;
printf("Enter the key element to be searched\n");
scanf("%d",&key);
printf("Enter the element to be inserted\n");
scanf("%d",&ele);
newn=(struct node*)malloc(sizeof(struct node));
newn->info=ele;

if(start->info==key)
{
newn->next=start;
start=newn;
}
else
{
while(temp2!=NULL)
{
if(temp2->info==key)
{
f=1;
break;
}
else
{
temp1=temp1->next;
temp2=temp2->next;
}
}
if(f==0)
printf("Element not found\n");
else
{
newn->next=temp2;
temp1->next=newn;
}
}
}

/*void create()
{
struct node *temp,*newn;int ele;
printf("Link List creation\n");
printf("Enter the element\n");
scanf("%d",&ele);
do
{
newn=(struct node*)malloc(sizeof(struct node));
newn->info=ele;
newn->next=NULL;
if(start==NULL)
{
start=newn;
}
else
{
temp->next=newn;
start=newn;
}
printf("Enter Zero to terminate\n");
scanf("%d",&ele);
}
while(ele!=0);
}
*/

void display()
{
struct node *temp;
if(start==NULL)
{
printf("List is empty\n");
}
else
{
printf("Linked List:\n");
temp=start;
while(temp!=NULL)
{
printf("%d\n",temp->info);
temp=temp->next;
}
}
printf("\n");
}

void main()
{
int ch;
//create();
while(1)
{
printf("\n1:Insert at beginning\n2:Insert at End\n3:Insert before a given element\n4:Insert at position\n5:Display\n6:Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch); 
switch(ch)
{
case 1: insert_beginning();
	break;
case 2: insert_end();
	break;
case 3: insert_before_ele();break;
case 4: insert_position();break;
case 5: display();break;
case 6: exit(0);
default : printf("Invalid choice\n");
	  break;
}
}
}
