#include<stdlib.h>
void main(){
	int i,j,k,n,c[50][50];
	printf("\n n>r (r should be less than n) \n\n");
	printf("\nEnter the values of n:");
	scanf("%d",&n);
	printf("\nEnter the value of r:");
	scanf("%d",&k);
	if(n>k){
		for(i=0;i<n;i++)
			for(j=0;j<=k;j++)
				c[i][j]=0;
		for(i=0;i<=n;i++){
			c[i][0]=1;
			c[i][i]=1;
		}
		for(i=2;i<=n;i++)
			for(j=1;j<=i-1;j++)
				c[i][j]=c[i-1][j-1]+c[i-1][j];
		printf("\ntable for valuation\n");
		for(i=0;i<=n;i++){
			for(j=0;j<=k;j++){
				if(c[i][j]!=0)
					printf("%d\t",c[i][j]);
			}
			printf("\n");
		}
		printf("\nbinomial co-efficient of (%d,%d) is :%d\n",n,k,c[n][k]);
	}
}

