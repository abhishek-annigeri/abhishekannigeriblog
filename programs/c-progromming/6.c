#include<stdio.h>
void main()
{
int k,a[10][10],b[20][20],c[10][10],i,j,r,c1,n;
printf("enter the row and column of the matrix\n");
scanf("%d%d",&r,&c1);

if(r!=c1)
{
printf("Matrix multiplication not possible\n");
//break;
}

else
{
n=r;
printf("enter 1st matrix element\n");

for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}

printf("enter 2nd matrix element\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&b[i][j]);
}
}


for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
for(k=0;k<n;k++)
{
c[i][j]=(a[i][k]*b[k][j])+c[i][j];
}
}
}


printf("Resultant matrix is :\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n");
}

}
}
