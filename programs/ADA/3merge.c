#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
void partition(int a[],int low,int high);
void mergesort(int a[],int low,int mid,int high);
struct timer{
	int limit;
	int time;
}mytimer[10];
void partition(int a[],int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		partition(a,low,mid);
		partition(a,mid+1,high);
		mergesort(a,low,mid,high);
	}
}
void mergesort(int a[],int low,int mid,int high){
	int i,k,l,m,temp[1000];
	l=low;
	i=low;
	m=mid+1;
	while(l<=mid && m<=high){
		if(a[l]<=a[m]){
			temp[i]=a[l];
			l++;
		}
		else{
			temp[i]=a[m];
			m++;
		}
	i++;
	}
	if(l>mid){
		for(k=m;k<=high;k++){
			temp[i]=a[k];
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++){
			temp[i]=a[l];
			i++;
		}
	}
	for(k=low;k<=high;k++)
		a[k]=temp[k];
}
void main(){
	int ar[1000],n,i;
	int k=0,q,ch;
	printf("\nNo. times : ");
	scanf("%d",&ch);
	for(q=0;q<ch;q++){
		struct timeval st,en;
		printf("\nEnter the value of n:");
		scanf("%d",&n);
		for(i=0;i<n;i++)
			 ar[i]=rand()%1000;
		printf("\nThe Array is\n");
		for(i=0;i<n;i++)
			printf("%d\t",ar[i]);
		gettimeofday(&st,0);
		partition(ar,0,n-1);
		gettimeofday(&en,0);
		printf("\nThe sorted array\n");
		for(i=0;i<n;i++)
			printf("%d\t",ar[i]);
		printf("\nTime taken %d microseconds\n",mytimer[q].time=(en.tv_usec-st.tv_usec));
		mytimer[q].limit=n;
	}
	printf("\nInputs\tTimetaken\t");
	for(q=0;q<ch;q++)
	printf("\n%d\t%d\n",mytimer[q].limit, mytimer[q].time);
}

