#include<stdlib.h>
#include<iostream>
using namespace std;
int a[20];double b[20];
template<class T>
void sort(T a[],int n)
{
T t;
int i,j;
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i] > a[j])
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}

cout<<"Sorted array ="<<endl;
for(i=0;i<n;i++)
cout<<a[i]<<endl;
}

int main()
{
int i,j,n;
do
{
cout<<"1:Integer Sort"<<endl;
cout<<"2:Double Sort"<<endl;
cout<<"3:Exit"<<endl;
cout<<"Enter your choice"<<endl;
int ch;
cin>>ch;
switch(ch)
{

case 1: cout<<"Enter the limit"<<endl;
	cin>>n;
	cout<<"Enter the elements"<<endl;
	for(i=0;i<n;i++)
	cin>>a[i];
	sort(a,n);
	break;

case 2: cout<<"Enter the limit"<<endl;
        cin>>n;
         cout<<"Enter the elements"<<endl;
         for(i=0;i<n;i++)
         cin>>b[i];
         sort(b,n);
         break;

case 3:exit(0);
default : cout<<"Invalid choice"<<endl;
		break;
}
}
while(1);
return 0;
}
