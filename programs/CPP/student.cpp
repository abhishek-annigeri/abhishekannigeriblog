#include<iostream>
#include<cstdlib>
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
loop: cout<<"Enter sem\n";
cin>>sem;
if(sem>6)
{
cout<<"Invalid Sem\n";
goto loop;
}
cout<<"Enter fees\n";
cin>>fees;
cout<<"Enter stipend\n";
cin>>stipend;
}

void display(ugstudent ug[],int n)
{
int i,j,sum,f,c;
float avg;
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
}
};

class pgstudent : public student
{
public : int fees,stipend,sem;

void read()
{
student::read();
loop1: cout<<"Enter sem\n";
cin>>sem;
if(sem>6)
{
cout<<"Invlid sem\n";
goto loop1;
}
cout<<"Enter fees\n";
cin>>fees;
cout<<"Enter stipend\n";
cin>>stipend;
}

void display(pgstudent pg[],int n)
{
int sum,f,c,i,j;
float avg;
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
}

};

int main()
{
ugstudent ug[10],u;
pgstudent pg[10],p;
int n,i;
float avg;
while(1)
{
cout<<"1:UG Students\n2:PG Students\n3:Display\n4:Exit\n";
int ch;
cin>>ch;
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
	break;

case 2: cout<<"Enter the details of PG Students\n";
	cout<<"ENter the limit\n";
	cin>>n;
	for(i=1;i<=n;i++)
	{
	cout<<"Enter the details of Student "<<i<<endl;
	pg[i].read();
	}
	break;
case 3 : cout<<"Ug Students average age\n";
	u.display(ug,n);
	cout<<"\nPg Students average age\n";	 
	p.display(pg,n);
	break;
case 4: exit(0);
default : cout<<"Invalid choice\n";
	 break;
}
}
return 0;
}
