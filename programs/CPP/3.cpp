#include<stdlib.h>
#include<iostream>
using namespace std;
class vector
{
public : int a[20],n;
         void read();
        int operator *(vector);
};

void vector :: read()
{
cout<<"Enter the limit"<<endl;
cin>>n;
cout<<"Enter the vector elements"<<endl;
for(int i=0;i<n;i++)
cin>>a[i];
}

int vector :: operator *(vector v)
{
int sum=0,i,mul=1;
if(n==v.n)
{
cout<<"Resultant vector is :"<<endl;
for(int i=0;i<n;i++)
{
mul=a[i]*v.a[i];
sum=sum+mul;
cout<<mul<<endl;
}
return sum;
}
else
{
cout<<"Vector mul;tiplication is not possible";
return 0;
}
}

int main()
{
vector v1,v2;
int s;
cout<<"Enter 1st vector"<<endl;
v1.read();
cout<<"Enter 2nd vector"<<endl;
v2.read();
s=v1*v2;
cout<<"Result="<<s<<endl;
return 0;
}

