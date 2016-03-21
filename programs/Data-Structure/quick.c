#include<stdio.h>
#include<stdlib.h>
int pivot(int m,int n)
	{
	return((m+n)/2);
	}
quicksort(int a[],int m,int n)
	{
	int i,j,k,key;
	i=m+1;
	j=n;
	if(m<n)
		{
		k=pivot(i,j);
		swap(&a[k],&a[m]);
		key=a[m];
		while(i<=j)
			{
			while(i<=n && a[i]<key)
				i++;
			while(j>=m && a[j]>key)
				j--;
			if(i<j)
				swap(&a[i],&a[j]);
			}
		swap(&a[m],&a[j]);
			quicksort(a,m,j-1);
			quicksort(a,j+1,n);
		}
	}
void swap(int *a,int *b)
	{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	}
main()
	{
	int a[50],i,r,m,n;
	m=0;
	printf("\nEnter the number of elements");
	scanf("%d",&r);
	n=r-1;
	printf("\nEnter the elements");
	for(i=0;i<r;i++)
		scanf("%d",&a[i]);
	quicksort(a,m,n);
	printf("\nThe sorted array is \n");
		for(i=0;i<r;i++)
			printf("%d\t",a[i]);
	} 


