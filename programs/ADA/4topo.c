#include<stdio.h>
#include<stdlib.h>
int k,n,a[100][100],i,j,t[100], top,sum, u,v,indgree[100];
void topo(){
	int s[100];
	top=-1; k=0;
	find_indgree();
	for(i=0;i<n;i++){
		if(indgree[i]==0)
			s[++top]=i;
	}
	while(top!=-1){
		u=s[top--];
		t[k++]=u;
		for(v=0;v<n;v++){
			if(a[u][v]==1){
				indgree[v]--;
				if(indgree[v]==0)
					s[++top]=v;
			}
		}
	}
	printf("\nThe topological order is\n");
	for(i=0;i<n;i++){
		printf("%d\t",t[i]);
	}
}
void find_indgree(){
	for(j=0;j<n;j++){
		sum=0;
		for(i=0;i<n;i++){
			sum=sum+a[i][j];
		}
		indgree[j]=sum;
	}
	printf("indgree of elements are\n");
	for(i=0;i<n;i++)
	printf("%d\t",indgree[i]);
	printf("\n");
}
void main(){
	printf("Enter the order for the matrix\n");
	scanf("%d",&n);
	printf("\nEnter the Adjacency matrix value \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	printf("\n\nMatrix is \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		printf("%5d",a[i][j]);
		}
		printf("\n");
	}
	topo();
}

/*Enter the order for the matrix	6

Enter the Adjacency matrix value 
0 1 1 0 0 0 
0 0 0 0 0 0 
0 1 0 1 0 0
0 0 0 0 1 0
0 0 0 0 0 0 
1 0 0 0 0 0 

Matrix is 
    0    1    1    0    0    0
    0    0    0    0    0    0
    0    1    0    1    0    0
    0    0    0    0    1    0
    0    0    0    0    0    0
    1    0    0    0    0    0
indgree of elements are
1	2	1	1	1	0	

The topological order is
5	0	2	3	4	1		*/

