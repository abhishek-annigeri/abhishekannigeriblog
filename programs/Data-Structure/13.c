#include<stdio.h>
#include<stdlib.h>
void heapify(int[],int);
void heapsort(int[],int);
void adjust(int[],int);
void heapsort(int a[],int n)
{
	int i,temp;
	heapify(a,n);
	for(i=n;i>=1;i--)
	{
		temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		adjust(a,i);
	}
}
void heapify(int a[],int n)
{
	int i,j,k,item;
	for(k=2;k<=n;k++)
	{
		item=a[k];
		i=k;
		j=i/2;
		while(j!=0&&item>a[j])
		{
			a[i]=a[j];
			i=j;
			j=i/2;
		}
		a[i]=item;
	}
}

void adjust(int a[],int n)
{
	int i,j,item;
	j=1;
	i=2*j;
	item=a[j];
	      while(i<n)
	     {
		if((i+1<n)&&(a[i+1]>a[i]))
			i++;
		if(item<a[i])
		{
			a[j]=a[i];
			j=i;
			i=2*j;
		}
		else
			break;
	}
	a[j]=item;
 }
 void main()
 {
	int a[10],i,n;
	printf("Enter the limit\n");
	scanf("%d",&n);
	printf("\n Enter element of the array:\n");
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	printf("Elements are:\n");
	for(i=1;i<=n;i++)
	printf("%d\t",a[i]);
	heapsort(a,n);
	printf("\nAfter Sorting :\n");
	for(i=1;i<=n;i++)
	printf("%d\t",a[i]);
}
