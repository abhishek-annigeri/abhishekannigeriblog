#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j,key,temp,high,low,a[1000],n;
struct timer{
    int limit;
    int time;
}mytimer[10];
int quicksort(int a[],int low,int high){
          int j;
          if(low<high){
                  j=partition(a,low,high);
                  quicksort(a,low,j-1);
                  quicksort(a,j+1,high);
          }
}
int partition(int a[],int low,int high){
          key=a[low];
          i=low+1;
          j=high;
          while(1){
                 while(i<high && key>=a[i])
                           i++;
                          while(key<a[j])
                                   j--;
                                  if(i<j){
                                          temp=a[i];
                                          a[i]=a[j];
                                          a[j]=temp;
                                  }
                                  else{
                                          temp=a[low];
                                          a[low]=a[j];
                                          a[j]=temp;
                                         return j;
                                 }
         }
}
void main(){
	int k=0,q,ch;
	struct timeval st,en;
	printf("\nNo. times : ");
	scanf("%d",&ch);
	for(q=0;q<ch;q++){
		printf("\nEnter the value of n:");
		scanf("%d",&n);
		for(i=0;i<n;i++)
			a[i]=rand()%1000;
		printf("\nThe Array is\n");
		for(i=0;i<n;i++)
			printf("%d\t",a[i]);
		gettimeofday(&st,0);
		printf("\n\nSorted Array is\n");
		quicksort(a,0,n-1);
		gettimeofday(&en,0);
		for(i=0;i<n;i++)
			printf("%d\t",a[i]);
		printf("\nTime taken %d microseconds\n",mytimer[q].time=(en.tv_usec-st.tv_usec));
		mytimer[q].limit=n;
	}
	printf("\nInputs\tTimetaken\n");
	for(q=0;q<ch;q++)
	printf("\n%d\t%d\n",mytimer[q].limit, mytimer[q].time);
}

