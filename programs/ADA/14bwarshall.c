#include<stdio.h>
#include<stdlib.h>
void main(){
	int flag=0,i,j,a[10][10],p[10][10],n,k; 
	printf("\Enter the size of a matrix:");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix:");
	for(i=0;i<=n-1;i++){
		for(j=0;j<=n-1;j++){
			scanf("%d",&a[i][j]);
			p[i][j]=a[i][j];
		}
	}
	for(k=0;k<=n-1;k++){
		for(i=0;i<=n-1;i++){
			for(j=0;j<=n-1;j++){
				if( (p[i][k]==1 && p[k][j])==1){
					p[i][j]=1;
					flag=1;
				}
			}
		}
	}
	if(flag==1){	
		for(i=0;i<=n-1;i++){
			for(j=0;j<=n-1;j++){
				printf("%d\t",p[i][j]);
			}
			printf("\n");
		}
	}
	else{
		printf("\nTransitive closure relationship doesnot exist\n");
	}
}
/*Enter the size of a matrix:	4

Enter the adjacency matrix:
0 1 0 0 
0 0 0 1
0 0 0 0 
1 0 1 0

1	1	1	1	
1	1	1	1	
0	0	0	0	
1	1	1	1	*/
