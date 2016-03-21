#include<stdlib.h>
#include<iostream>
using namespace std;

class List
{
public : int data;
	 List *head,*ptr;

List()
{
head=NULL;
}
~List()
{
cout<<"Object Destroyed"<<endl;
delete(head);
}

void insert_front()
{
cout<<"Enter Element to be inserted"<<endl;
int ele;
cin>>ele;
List *newnode=new List;
newnode->data=ele;
newnode->ptr=head;
head=newnode;
}

void delete_front()
{
List *temp;
if(head==NULL)
cout<<"List is empty"<<endl;
else
{
temp=head;
cout<<"Delete element from the list is = "<<temp->data<<endl;
head=head->ptr;
delete(temp);
}
}

void display()
{
List *temp;
if(head==NULL)
cout<<"List is empty"<<endl;
else
{
cout<<"Element in the list are : "<<endl;
temp=head;
while(temp!=NULL)
{
cout<<temp->data<<endl;
temp=temp->ptr;
}
}
}
};

int main()
{
List l;
while(1)
{
cout<<"1:Insert\n2:Delete\n3:Display\n4:Exit\n"<<endl;
cout<<"Enter your choice"<<endl;
int ch; 
cin>>ch;
switch(ch)
{
case 1: l.insert_front();
	break;
case 2: l.delete_front();
	break;
case 3: l.display();
	break;
case 4: exit(0);
default : cout<<"Invalid choice"<<endl;
	break;

}
}
return 0;
}
