#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int pos;
int binsearch(int n,int a[],int low,int high,int key){
 	int mid=(low+high)/2;
	if(low>high)
		return 0;
	if(key==a[mid])
		return -1;
	else if(key<a[mid])
		binsearch(n,a,low,mid-1,key);
	else
		binsearch(n,a,mid+1,high,key);
}
int linear(int a[],int key,int n){
	int i=0;
		if(n<=0){
			return 0;
		}
		else  if(a[n-1]==key){
			return -1;
		}
		else{
			linear(a,key,n-1);
		}
}
void swap(int a[],int n){
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
struct timer{
	int limit;
	float time;
}mytimer[10];
void main(){
	double t;
	int n,i,a[1000],b[10],k,ch,low,high,j,run;
	struct timeval st,en;
	float t1[10];
	char s[10];	
	do{
		printf("\n1.binary search\n2.linear search\n3.exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the number times you want to run:");
				scanf("%d",&run);
				for(j=0;j<run;j++){
					printf("\nEnter the number of elements:");
					scanf("%d",&n);
					//printf("Enter the array elements\n");
					for(i=0;i<n;i++)
						a[i]=rand()%1000;
					//scanf("%d",&a[i]);
					printf("\nElements before sorting\n");
					for(i=0;i<n;i++)
						printf("%d\t",a[i]);
					gettimeofday(&st,0);
					swap(a,n);
					printf("\nElements after sorting\n");
					for(i=0;i<n;i++)  
        	                              printf("%d\t",a[i]);
					printf("\nEnter the element to be searched:");
					scanf("%d",&k);
					low=0;high=n-1;
					pos=binsearch(n,a,low,high,k);
					gettimeofday(&en,0);
					if(pos==-1){
						printf("\nSearch Successfull\n");
						s[j]='s';
					}
					else{
						printf("\nSearch Unsuccessfull\n");
						s[j]='u';
					}
					printf("\ntime taken %3.1f\n",mytimer[j].time=(en.tv_sec-st.tv_sec));
					mytimer[j].limit=n;
					b[j]=n;
					t1[j]=mytimer[j].time;
				}
				printf("\nNo of elements\tTime taken\t\tOutput\n");
				for(i=0;i<run;i++){
					printf("%d\t\t%f\t\t%c\t\t\n",b[i],t1[i],s[i]);
				}
				break;
			case 2: printf("\nEnter the number times you want to run:");
				scanf("%d",&run);
				for(j=0;j<run;j++){	
					printf("\nEnter the number of elements:");
					scanf("%d",&n);
					for(i=0;i<n;i++)
						a[i]=rand()%1000;
					printf("\nElements before sorting\n");
					for(i=0;i<n;i++)
						printf("%d\t",a[i]);
					gettimeofday(&st,0);
					swap(a,n);
					printf("\nElements after sorting\n");
					for(i=0;i<n;i++)  
        	                              printf("%d\t",a[i]);		
					gettimeofday(&st,0);
					printf("\nEnter the element to be searched:");
					scanf("%d",&k);
					pos=linear(a,k,n);
					gettimeofday(&en,0);
					if(pos==-1){
						printf("\nSearch Successfull\n");
						s[j]='s';
					}
					else{
						printf("\nSearch Unsuccessfull\n");
						s[j]='u';
					}
					printf("\ntime taken %3.1f\n",mytimer[j].time=(en.tv_sec-st.tv_sec));
					mytimer[j].limit=n;
					b[j]=n;
					t1[j]=mytimer[j].time;
				}
				printf("\nNo of elements\tTime taken\t\tOutput\n");
				for(i=0;i<run;i++){
					printf("%d\t\t%f\t\t%c\t\t\n",b[i],t1[i],s[i]);
				}
				break;
			case 3: exit(0);
			default:printf("\nwrong choice\n");
		}
	}while(ch!=3);

}

