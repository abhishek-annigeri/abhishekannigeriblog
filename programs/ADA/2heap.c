#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct timer{
    int limit;
    int time;
}mytimer[10];
void heapsort(int a[],int len){
	int i,temp;
	for(i=len/2;i>=0;--i)
		heapbubble(i,a,len);
	for(i=len-1;i>0;i--){
		temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		heapbubble(0,a,i);
	}
}
void heapbubble(int pos,int a[],int len){
	int temp=0,left=0,right=0,z=0,max=0;
	z=pos;
	for(;;){
		left=2*z+1;
		right=left+1;
		if(left>=len)
			return;
		else if(right>=len)
			max=left;
		else if(a[left]>a[right])
			max=left;
		else
			max=right;
		if(a[z]>a[max])
			return;
		temp=a[z];
		a[z]=a[max];
		a[max]=temp;
		z=max;
	}
}
void main(){
          int k=0,q,ch,i,n,low,high,a[1000];
          struct timeval st,en;
          printf("\nNo. times : ");
          scanf("%d",&ch);
          for(q=0;q<ch;q++){
		  printf("\nEnter the value of n: ");
		  scanf("%d",&n);
		  for(i=0;i<n;i++)
		  	a[i]=rand()%1000;
		  printf("\nThe Array is\n");
		  for(i=0;i<n;i++)
		  	printf("%d\t",a[i]);
		  gettimeofday(&st,0);
		  printf("\nSorted Array is\n");
		  heapsort(a,n);
		  gettimeofday(&en,0);
		  for(i=0;i<n;i++)
		  	printf("%d\t",a[i]);
		  printf("\nTime taken %d microseconds\n",mytimer[q].time=(en.tv_usec-st.tv_usec));
		  mytimer[q].limit=n;
          }
          printf("\nInputs\tTimetaken");
          for(q=0;q<ch;q++)
          	printf("\n%d\t%d\n",mytimer[q].limit, mytimer[q].time);
}

