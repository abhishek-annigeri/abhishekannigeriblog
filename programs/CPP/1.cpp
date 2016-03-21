#include<stdlib.h>
#include<iostream>
using namespace std;
class student
{
public : char usn[20],name[20];
	 int m1,m2,m3;
	 float avg;
void read()
{
cout<<"Enter the name"<<endl;
cin>>name;
cout<<"Enter the usn"<<endl;
cin>>usn;
cout<<"Enter the marks of the student"<<endl;
cin>>m1>>m2>>m3;
}

void display()
{
cout<<"Name="<<name<<endl;
cout<<"USN="<<usn<<endl;
cout<<"Marks"<<m1<<"\t"<<m2<<"\t"<<m3<<endl;
cout<<"Average="<<avg<<endl;
}

void cal()
{
if(m1<=m2 && m1<=m3)
avg=float(m2+m3)/2;
else if(m2<=m1 && m2<=m3)
avg=float(m1+m3)/2;
else
avg=float(m1+m2)/2;
}
};


int main()
{
student s[20];
int i,n;
cout<<"Enter the number of students"<<endl;
cin>>n;
cout<<"Enter the student details"<<endl;
for(i=0;i<n;i++)
s[i].read();

for(i=0;i<n;i++)
s[i].cal();
cout<<"Student details are as follows"<<endl;
for(i=0;i<n;i++)
s[i].display();
return 0;
}
