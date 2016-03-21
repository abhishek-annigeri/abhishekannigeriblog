#include<iostream>
using namespace std;
class student
{
public : char name[20],usn[20];
	 int age;
void read()
{
cout<<"Enter name\n";
cin>>name;
cout<<"Enter usn\n";
cin>>usn;
cout<<"Enter age\n";
cin>>age;
}
};

class ugstudent : public student
{
public : int fees,stipend,sem;
	 void read()
{
student::read();
cout<<"Enter sem\n";
cin>>sem;
if(sem>6)
cout<<"Invalid Sem\n";
cout<<"Enter fees\n";
cin>>fees;
cout<<"Enter stipend\n";
cin>>stipend;
}

};

class pgstudent : public student
{
public : int fees,stipend,sem;
	 void read()
{
student::read();
cout<<"Enter sem\n";
cin>>sem;
cout<<"Enter fees\n";
cin>>fees;
cout<<"Enter stipend\n";
cin>>stipend;
}
};

int main()
{
ugstudent ug[10];
pgstudent pg[10];
int n,j,i,sum,f,c;
float avg;

cout<<"1:UG Students\n2:PG Students\n";
int ch;
switch(ch)
{

case 1: cout<<"Enter the details of UG Students\n";
cout<<"ENter the limit\n";
cin>>n;
for(i=1;i<=n;i++)
{
cout<<"Enter the details of Student "<<i<<endl;
ug[i].read();
}

for(i=1;i<=6;i++)
{
sum=0;f=0;c=0;
for(j=1;j<=n;j++)
{
if(ug[j].sem==i)
{
sum=sum+ug[j].age;
f=1;
c++;
}
}
if(f==1)
{
avg=sum/c;
cout<<"Average of sem "<<i<<" is :"<<avg<<endl;
}
}
break;

case 2: cout<<"Enter the details of PG Students\n";
cout<<"ENter the limit\n";
cin>>n;
for(i=1;i<=n;i++)
{
cout<<"Enter the details of Student "<<i<<endl;
pg[i].read();
}

for(i=1;i<=6;i++)
{
sum=0;f=0;c=0;
for(j=1;j<=n;j++)
{
if(pg[j].sem==i)
{
sum=sum+pg[j].age;
f=1;
c++;
}
}
if(f==1)
{
avg=sum/c;
cout<<"Average of sem "<<i<<" is :"<<avg<<endl;
}
}
break;
}
return 0;
}






