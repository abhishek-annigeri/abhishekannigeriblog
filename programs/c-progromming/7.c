#include<stdio.h>
void main()
{
int a[20][20],max,min,i,j,col,k,n;
printf("enter size of matrix");
scanf("%d",&n);
printf("enter the  matrix  elements\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);

printf("entered matrix is:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}

for(i=0;i<n;i++)
{

min=a[i][0];
for(j=0;j<n;j++)
{
if(a[i][j]<=min)
{
min=a[i][j];
col=j;
}
}

max=a[0][col];
for(k=0;k<n;k++)
{
if(a[k][col]>=max)
{
max=a[k][col];
}
}
if(max==min)
printf("Saddle point is at (%d,%d) = %d \n",i,j,max);
//printf("\n %d\n",max);
//printf("\n %d\n",min);
}
printf("\n");
}
