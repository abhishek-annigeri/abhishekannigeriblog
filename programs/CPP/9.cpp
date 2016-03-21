#include<iostream>
#include<stdlib.h>
using namespace std; 
template<class T>
class queue
{
public :int front,rear,size;
        T a[20],ele;

queue()
{
size=3;
rear=-1;
front=0;
}

void insert_rear()
{
if(rear >= size-1)
cout<<"Queue is full\n";
else
{
cout<<"Enter the item to be inserted\n";
cin>>ele;
a[++rear]=ele;
}
}

void delete_front()
{
if(front > rear)
cout<<"Queue is empty\n";
else
{
cout<<"Deleted item="<<a[front]<<endl;
front++;
}
}

void display()
{
if(front > rear)
cout<<"Queue is empty\n";
else
{
for(int i=front;i<=rear;i++)
cout<<a[i]<<"\t";
}
}
};

int main()
{
queue<int> q1;
queue<double> q2;
cout<<"\n Size of the queue is 3\n";
loop : cout<<"1:Integer Queue\n2:Double Queue\n3:Exit";
int c;
cin>>c;
switch(c)
{
case 1:

while(1)
{
cout<<"\n1:Insert\n2:Delete\n3:Exit\n";
int ch1;
cin>>ch1;
switch(ch1)
{
case 1: q1.insert_rear();q1.display();break;
case 2: q1.delete_front();q1.display();break;
case 3: goto loop;
default : cout<<"Invalid choice\n";break;
}
}
break;

case 2: 
while(1)
{
cout<<"\n1:Insert\n2:Delete\n3:Exit\n";
int ch2;
cin>>ch2;
switch(ch2)
{
case 1: q2.insert_rear();q2.display();break;
case 2: q2.delete_front();q2.display();break;
case 3: goto loop;
default : cout<<"Invalid choice\n";break;
}
}
break;
default : exit(0);
}
return 0;
}
