#include<stdlib.h>
#include<stdio.h>
int i,n,t,a[20],key,low,high,mid,j,f=0;

void linear()
{
printf("Using Linear Search\n\n");
printf("Enter the limit\n");
scanf("%d",&n);
printf("Enter the elements\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter the elememnt to be searched\n");
scanf("%d",&key);
for(i=0;i<n;i++)
{
if(key==a[i])
{
f=1;
printf("Element found at %d position\n",i+1);
break;
}
}
if(f==0)
printf("Element not found\n");
}

void sort()
{
printf("Using Binary Search\n\n");
printf("Enter the limit\n");
scanf("%d",&n);
printf("Enter the elements\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i] > a[j])
{
t=a[i];
a[i]=a[j];
a[j]=t;
}
}
}
printf("Sorted element are:\n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
}

void binary()
{
low=0;
high=n-1;
//printf("Using Binary Search\n\n");
printf("Enter the element to be searched\n");
scanf("%d",&key);
while(low<=high)
{
mid=(low+high)/2;
if(key==a[mid])
{
printf("Element found at %d position\n",mid+1);
f=1;
break;
}
else
{
if(key<mid)
high=mid-1;
else
low=mid+1;
}
}
if(f==0)
printf("Element not found\n");
}

void main()
{
int ch;
while(1)
{
printf("\n1:Linear Search\n2:Binary Search\n3:Exit\n");
printf("\n Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:linear();
	break;
case 2: sort();
	binary();
	break;
case 3: exit(0);
default : printf("Invalid choice\n");
	 break;
}
}
}
