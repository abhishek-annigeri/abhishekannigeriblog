#include<iostream>
#include<stdlib.h>
using namespace std;
int i,j;
class matrix
{
    public:
	          int m,n,a[10][10];
	friend ostream& operator<<(ostream&,matrix);

void operator++()
{
  cout<<"enter the size\n";
  cin>>m>>n;
}

void insert()
{
   cout<<"enter matrix element\n";
   for(i=0;i<m;i++)
     {
      for(j=0;j<n;j++)
       {
         cin>>a[i][j];
       }
     }
}

int operator==(matrix m1)
{
	if((m==m1.m)&&(n==m1.n))
        	return 1;
	else
		return 0;
}


matrix operator+(matrix m2)
{
	matrix m3;
	for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	{
	m3.a[i][j]=a[i][j]+m2.a[i][j];
	}
	}
	m3.m=m;
	m3.n=n;
	return(m3);
}

matrix operator-(matrix m2)
{
	int i,j;
	matrix m4;
	for(i=0;i<m;i++)
	{
	for(j=0;j<n;j++)
	{
	m4.a[i][j]=a[i][j]-m2.a[i][j];
	}
	}
	m4.m=m;
	m4.n=n;
	return(m4);
}
};

ostream& operator<<(ostream& fout,matrix mm)
{
for(i=0;i<mm.m;i++)
{
for(j=0;j<mm.n;j++)
{
fout<<"\t"<<mm.a[i][j];
}
fout<<"\n";
}
}


int main()
{
	matrix m1,m2,m3,m4;
                ++m1;
        	++m2;
        	if(m1.m==m2.m || m1.n==m2.n)
	         {
                    m1.insert();
                    m2.insert();
		    cout<<"1st Matrix =\n";
		    cout<<m1;
		    cout<<"2nd matrix =\n";
		    cout<<m2;
       		    m3=m1+m2;
   		    cout<<"addition\n";
		    cout<<m3;
        	    cout<<"subtraction\n";
         	    m4=m1-m2;
          	    cout<<m4;
       		 }
       		else
           	cout<<" Invalid size";
}
