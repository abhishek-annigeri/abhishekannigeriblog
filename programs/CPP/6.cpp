#include<iostream>
#include<stdlib.h>
using namespace std;
class stack
{
	int a[10];
	int n,top;
	public: stack()
	{
		top=0;
		cout<<"enter size \n";
		cin>>n;
	}	
	stack operator+(int ele)
{
	if(top==n)
	{
		cout<<"Stack Overflow\n";
	}
	else
	{
		top++;
		a[top]=ele;
		cout<<"inserted element is : "<<a[top]<<endl;
	}
	return *this;
}
	
stack operator--()
{
	if(top==0)
	{
		cout<<"Stack Underflow\n";
	}
	else
	{
		cout<<"Deleted element : "<<a[top]<<endl;
		top--;
	}
	return *this;

}
friend ostream& operator<<(ostream&, stack);
};

int main()
{
	int ele,ch;
	stack s1;
	while(1)
	{
		cout<<"\nenter your choice \n";
		cout<<"1.Push\n2.Pop\n3.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"enter the element\n";
				cin>>ele;
				s1=s1+ele;
				cout<<s1;
				break;
			case 2: s1=--s1;
				cout<<s1;
				break;
			case 3: return 0;
				break; 
			default:cout<<"Invalid choice\n";
				break;
		}
	}
}

ostream& operator<<(ostream& fout,stack s)
{
	fout<<"Stack element are : \n";
	for(int i=s.top;i>0;i--)
	{
		fout<<s.a[i]<<endl;
	}
	return fout;
}
