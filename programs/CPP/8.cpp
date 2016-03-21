#include<iostream>
#include<math.h>
using namespace std;

class octal
{
public : int h;
friend ostream& operator <<(ostream&,octal);

octal(int x)
{
int p=0,b=0,r=1;
int t=x;
while(t>0)
{
b=t%8;
p=p+(b*r);
r=r*10;
t=t/8;
}
h=p;
cout<<h<<endl;
}

int operator +(int k)
{
int b,p=0,r=1,i=0;
int t=h;
while(t>0)
{
b=t%10;
p=p+(pow(8,i)*b);
i++;
t=t/10;
}
p=p+k;
return p;
}
};

ostream& operator <<(ostream& o,octal oc)
{
o<<oc.h;
}

int main()
{
cout<<"Enter the integer\n";
int x;
cin>>x;
octal o=x;
cout<<"Enter an integer to add\n";
int k;
cin>>k;
int y=o+k;
cout<<"Result="<<y;
cout<<"\nAddition ="<<o<<endl;;
return 0;
}
