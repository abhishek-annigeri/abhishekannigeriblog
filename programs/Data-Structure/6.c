#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node *next;
};

struct node *start=NULL;

void create()
{
 struct node *temp,*newn;
 int ele;
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
 temp=newn;
 }
 else
 {
 temp->next=newn;
 temp=newn;
 }
 printf("Enter Zero to terminate\n");
 scanf("%d",&ele);
 }
 while(ele!=0);
 temp->next=start;
 }


 void display()
 {
 struct node *temp=start->next;
 if(start==NULL)
 {
 printf("List is empty\n");
 }
 else
 {
 printf("Linked List:\n");
 printf("%d-->%d-->%d\n",start,start->info,start->next);
 while(temp!=start)
 {
 printf("%d-->%d-->%d\n",temp,temp->info,temp->next);
 temp=temp->next;
 }
 }
 printf("\n");
 }


void delete_beginning()
{
struct node *temp=start->next,*del;
int ele;
if(start==NULL)
printf("Linked list is empty\n");
else if(start->next==start)
start=NULL;
else
{
del=start;
while(temp->next!=start)
temp=temp->next;
start=start->next;
temp->next=start;
del->next=NULL;
free(del);
}
}

void delete_end()
{
struct node *temp1=start,*temp2=start->next;
int ele;
if(start==NULL)
printf("List is empty\n");
else if(start->next==start)
start=NULL;
else
{
while(temp2->next!=start)
{
temp1=temp1->next;
temp2=temp2->next;
}
temp1->next=temp2->next;
temp2->next=NULL;
free(temp2);
}
}

void delete_element()
{
struct node *temp1=start,*temp2=start->next;
int key,f=0;
printf("Enter the key element\n");
scanf("%d",&key);
if(start==NULL)
printf("Linked list is empty\n");
else
{
if(start->info==key)
{
while(temp2->next!=start)
temp2=temp2->next;
start=start->next;
temp2->next=start;
free(temp1);
}
else if((start->next==start)&&(start->info==key))
start=NULL;
else
{
while(temp2!=start)
{
if(temp2->info==key)
{
f=1;
break;
}
temp1=temp1->next;
temp2=temp2->next;
}
if(f==1)
{
temp1->next=temp2->next;
temp2->next=NULL;
free(temp2);
}
else
{
printf("Element not found\n");
}
}
}
}

void delete_alternate()
{
struct node *temp1=start,*temp2=start->next,*del;
int i,count=1;
if(start==NULL)
printf("Linked List is empty");
else
{
if(start->next==start)
printf("Only one element in List\n");
if(((start->next)->next)==start)
start->next=start;
else
{
while(temp2!=start)
{
count++;
temp2=temp2->next;
}
temp2=start->next;
for(i=1;i<=count-1;i++)
{
if((i%2)!=0)
{
del=temp2;
temp1->next=temp2->next;
temp1=temp1->next;
temp2=temp1->next;
free(del);
i++;
}
else
{
temp2=temp2->next;
temp1=temp1->next;
}
}
}
}
}

void main()
{
int ch;
while(1)
{
printf("1:Delete from beginning\n2:Delete from the end\n3:Delete a given element\n4:Delete alternate element\n5:Display\n\n6:Create\n7:Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: delete_beginning();break;
case 2: delete_end(); break;
case 3: delete_element(); break;
case 4: delete_alternate(); break;
case 5: display();break;
case 6: create();break;
case 7: exit(0);
default : printf("Invalid choice\n");break;
}
}
}
