#include<iostream>
using namespace std;


class employee
{
protected: char name[20];
           int empid;
	   int sal;
public :   virtual void cal_sal()=0;
	   virtual void read()=0;
	   virtual void display()=0; 
};


class manager : public  employee
{
public : float da,hra,netsalary;
	 
manager()
{
da=0.20;
hra=0.30;
}

void read()
{
cout<<"Enter Manager employee details\n";
cout<<"Enter name\n";
cin>>name;
cout<<"Enter empid\n";
cin>>empid;
cout<<"Enter basic salary of employee\n";
cin>>sal;
}

void cal_sal()
{
netsalary=sal+(da*sal)+(hra*sal);
}

void display()
{
cout<<"Employee details\n";
cout<<name<<"\n"<<empid<<"\n"<<sal<<endl;
cout<<"\nNet salary is:"<<netsalary<<endl;
}
}; 

class salesman : public employee
{
public : float da,hra,ta,netsalary;
salesman()
{
da=0.10;
hra=0.20;
ta=0.05;
}

void read()
{
cout<<"Enter Salesman employee details\n";
cout<<"Enter name\n";
cin>>name;
cout<<"Enter empid\n";
cin>>empid;
cout<<"Enter basic salary of employee\n";
cin>>sal;
}

void cal_sal()
{
netsalary=sal+(da*sal)+(hra*sal)+(ta*sal);
}

void display()
{
cout<<"Employee details\n";
cout<<name<<"\n"<<empid<<"\n"<<sal<<endl;
cout<<"\nNet salary is:"<<netsalary<<endl;
}
}; 


int main()
{
int m1,n,i;
employee *e[22];
manager m[10];
salesman s[10];
cout<<"Enter the limit for manager\n";
cin>>n;
cout<<"Enter limit for salesman\n";
cin>>m1;
for(int i=1;i<=n;i++)
{
e[i]=&m[i];
e[i]->read();
e[i]->cal_sal();
}

for(int i=n+1,k=0;i<m1+n;k++,i++)
{
e[i]=&s[k];
e[i]->read();
e[i]->cal_sal();
}

cout<<"Details of Manager are:\n";
for(i=1;i<=n;i++)
{
cout<<"Manager "<<endl;
e[i]->display();
}

cout<<"Details of Salesman are:\n";
for(i=n+1;i<m1+n;i++)
{
cout<<"Salesman "<<endl;
e[i]->display();
}
return 0;
}
