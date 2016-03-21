#include<stdio.h>
#include<stdlib.h>
void dfs(int n,int a[20][20],int u,int s[]){
	int v;
	s[u]=1;
	for(v=0;v<n;v++){
		if(a[u][v]==1 && s[v]==0){
			dfs(n,a,v,s);
		}
	}
}
void main(){
	int i,j,n,s[20],a[20][20],connected,flag,source;
	printf("Enter the number of nodes:\n");
	scanf("%d",&n);
	printf("Enter the matrix\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf("Enter the sourcce node\n");
	scanf("%d",&source);
	connected=0;
	for(j=0;j<n;j++){
		for(i=0;i<n;i++){
			s[i]=0;
		}
		dfs(n,a,j,s);
		flag=0;
		for(i=0;i<n;i++){
			if(s[i]==0)
				flag=1;
		}
		if(flag==0)
		connected=1;
	}
	if(connected==1)
		printf("graph is connected\n");
	else
		printf("graph is not connected\n");
}
/*Enter the number of nodes:	5

Enter the matrix
0 1 1 0 0
0 0 0 0 1 
0 1 0 1 0
0 0 0 0 1   
0 0 0 0 0

Enter the sourcce node	1
graph is connected		

Enter the number of nodes:	5

Enter the matrix
0 1 1 0 0 0
0 0 1 0  
0 0 0 0 0 
0 0 1 0 0 
0 1 0 0 0 

Enter the sourcce node	3
graph is not connected		*/

