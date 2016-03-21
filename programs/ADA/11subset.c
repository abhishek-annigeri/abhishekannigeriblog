#include<stdio.h>
int w[50],d,n,count=0,x[50],i,flag=0;
void sumofsubset(int s,int k,int r){
	x[k]=1;
	if(s+w[k] == d){
		flag=1;
		printf("\n Subset = %d \n",++count);
		for(i=0;i<=k;i++){
			if(x[i] == 1)
				printf("%d,",w[i]);
		}
	}else{
		if(s+w[k]+w[k+1] <= d)
			sumofsubset(s+w[k],k+1,r-w[k]);
		if((s+r-w[k]>= d) && (s+w[k+1] <= d)){
			x[k]=0;
			sumofsubset(s,k+1,r-w[k]);
		}
	}
}
void main(){
	int s,r=0,k;
	printf("\nEnter the number of elements in the set:");
	scanf("%d",&n);
	printf("\n Enter the elements of the set:");
	for(i=0;i<n;i++)
		scanf("%d",&w[i]);
	printf("\nEnter the sum:");
	scanf("%d",&d);
	for(i=0;i<n;i++)
		x[i]=0;
	for(i=0;i<n;i++)
		r+=w[i];
	sumofsubset(0,0,r);
	if(flag==0)
		printf("\nSolution not possible\n");
}

