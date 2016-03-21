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
	top:
	printf("\n Enter the size of the array:");
	scanf("%d",&n);
	if(n>0)
	{
	printf("\n Enter element of the array:\n");
	for(i=1;i<=n;i++)
	       scanf("%d",&a[i]);
	printf("\n\t The element of the array before sorting:");
	printf("\n\t________________________________________\n\n");
	for(i=1;i<=n;i++)
		printf("\t%d",a[i]);
	heapsort(a,n);
	printf("\n\n\t The element of the array after sorting:");
	printf("\n\t________________________________________\n\n");
	for(i=1;i<=n;i++)
		printf("\t%d",a[i]);
	}
	else
	{
		printf("\n Enter the any +ve number:");
		goto top;
	}
 }

