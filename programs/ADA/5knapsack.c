#include<stdio.h>
int max(int a, int b){
    return a>b?a:b;
}
void main(){
	int n,w[10],p[10],m,i,j,v[10][10];
	printf("\nEnter numb of obj:");
	scanf("%d",&n);
	printf("\nEnter Weights: ");
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	printf("\nEnter  Profits: ");
	for(i=1;i<=n;i++)
		scanf("%d",&p[i]);
	printf("\nEnter Maximum Capacity: ");
	scanf("%d",&m);
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++){
			if(i==0 || j==0)
				v[i][j]=0;
			else if(j<w[i])
				v[i][j]=v[i-1][j];
			else
				v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
		}
	}
	printf("\nThe Profit Matrix is -\n");
	for(i=0;i<=n;i++){
		for(j=0;j<=m;j++)
			printf("%d\t",v[i][j]);
		printf("\n");
	}
	printf("\n Maximum profit gained is: %d",v[n][m]);
	printf("\n Items in the knapsack:{");
	j=m;
	for(i=n;i>=1;i--)
	if(v[i][j] != v[i-1][j]){
		printf("Item-%d,",i);
		j=j-w[i];
	}
	printf("}\n");
}

/*Enter numb of obj	4
Enter Weights	2 3 1 4
Enter  Profits	40 25 15 10
Enter Maximum Capacity	4
The Profit Matrix is -
0	0	0	0	0	
0	0	40	40	40	
0	0	40	40	40	
0	15	40	55	55	
0	15	40	55	55	

 Maximum profit gained is: 55
 Items in the knapsack:{Item-3,Item-1,}			*/
