#include<iostream>
#include<stdlib.h>
using namespace std;
class complex
{
public : int real;
	 float img;

void read()
{
cout<<"Enter the real part"<<endl;
cin>>real;
cout<<"Enter imaginary part"<<endl;
cin>>img;
}

void display()
{
cout<<real<<"+i"<<img<<endl;
}

complex add(int n,complex c)
{
c.real=c.real+n;
return c;
}
	 complex add(complex s1,complex s2)
{
complex s3;
s3.real=s1.real+s2.real;
s3.img=s1.img+s2.img;
return s3;
}
};

int main()
{
complex c1,c2,c3;
while(1)
{
cout<<"1:Add Integer to complex number"<<endl;
cout<<"2:Add 2 complex numbers"<<endl;
cout<<"3:Exit"<<endl;
cout<<"Enter your choice"<<endl;
int ch;
cin>>ch;
switch(ch)
{
case 1: cout<<"Enter Complex number"<<endl;
	c1.read();
	cout<<"Enter integer number to add"<<endl;
	int n;
	cin>>n;
	c3=c3.add(n,c1);
	cout<<"Result="<<endl;
	c3.display();
	break;
case 2: cout<<"Enter 1st Complex number"<<endl;
         c1.read();
         cout<<"Enter 2nd complex  number "<<endl;
         c2.read();
         c3=c3.add(c2,c1);
         cout<<"Result="<<endl;
         c3.display();
	break;
case 3: exit(0);

default : cout<<"Invalid choice"<<endl;
	 break;
}
}
return 0;
}
