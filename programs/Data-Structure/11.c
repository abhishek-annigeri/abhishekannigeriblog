#include<stdio.h>
#include<stdlib.h>

int partition(int a[],int low,int high)
{
int k,i,j,temp;
k=a[low];
i=low+1;
j=high;
while(1)
{
while(i<=high && k>=a[i])
i++;
while(k<a[j])
j--;
if(i<j)
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
else
{
temp=a[low];
a[low]=a[j];
a[j]=temp;
return j;
}
}
}


void quick_sort(int a[],int low,int high)
{
int j;
if(low<high)
{
j=partition(a,low,high);
quick_sort(a,low,j-1);
quick_sort(a,j+1,high);
}
}

void main()
{
int i,n,a[20];
printf("Enter the limit\n");
scanf("%d",&n);
printf("Enter the elements\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
quick_sort(a,0,n-1);
printf("The sorted elements :\n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
}
