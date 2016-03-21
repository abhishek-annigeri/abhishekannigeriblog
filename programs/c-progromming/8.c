#include<stdio.h>
void  main()
{
int f1=0,f2=0,a[20][20],i,j,n,r[20],c[20],d1,d2;
printf("enter n\n");
scanf("%d",&n);
printf("Enter matrix elements\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
printf("Matrix elements are:\n");

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
printf("\n");

for(i=0;i<n;i++)
{
r[i]=0;
for(j=0;j<n;j++)
{
r[i]=r[i]+a[i][j];
}
}

for(i=0;i<n;i++)
{
c[i]=0;
for(j=0;j<n;j++)
{
c[i]=c[i]+a[j][i];
}
}

d1=0;
d2=0;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i==j)
d1=d1+a[i][j];
}
}

for(i=n;i>0;i--)
{
for(j=n;j>0;j--)
{
if(i==j)
d2=d2+a[i][j];
}
}

printf("\nprimary diagonal sum= %d\n secondary diagonal sum=%d\n",d1,d2);
for(i=0;i<n;i++)
printf("sum of row %d: %d\n",i,r[i]);
printf("\n");
for(i=0;i<n;i++)
printf("sum of column %d : %d\n",j,c[i]);

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(r[i]==c[i])
f1=1;
}
}

if(d1==d2)
f2=1;

if((f1==1) && (f2==1))
{
if(r[0]==c[0] && r[0]==d1)
printf("Its a magic matrix");
else
printf("Its not a magic matrix");
}
else
printf("Its not a magic matrix\n");

printf("\n");
}
