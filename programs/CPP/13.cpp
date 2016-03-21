#include<iostream>
#include<cstdlib>
using namespace std;
int size;
class stack1
{
public : int a[20],n,top;
stack1()
{
cout<<"Enter stack size\n";
cin>>size;
top=0;
}

void push()
{
int ele;
cout<<"Enter the element\n";
cin>>ele;
a[top]=ele;
top++;
}

void pop()
{
top--;
cout<<"Deleted element is:"<<a[top]<<endl;
}

void display()
{
cout<<"Stack is :\n";
for(int i=top-1;i>=0;i--)
cout<<a[i]<<"\t";
}
};

class stack2: public stack1
{
public : 

void push()
{
if(top==size)
cout<<"Stack Overflow\n";
else
stack1::push();
}

void pop()
{
if(top==0)
cout<<"Stack Underflow\n";
else
stack1::pop();
}

void display()
{
if(top==0)
cout<<"Stack Empty\n";
else
stack1::display();
}
};

int main()
{
stack2 stk;
while(1)
{
cout<<"\n1:PUSH\n2:POP\n3:Display\n4:Exit\n";
cout<<"ENter your choice\n";
int ch;
cin>>ch;
switch(ch)
{
case 1: stk.push();
	break;
case 2: stk.pop();
	break;
case 3: stk.display();
	break;
case 4: exit(0);
default : cout<<"\nInvalid Choice\n";
	break;
}
}
return 0;
}
