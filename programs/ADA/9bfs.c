#include<stdio.h>
#include<stdlib.h>
int a[20][20];
void bfs(int v,int n){
	int visited[20],dis[20],i,j,front,rear,q[20];
	for(i=1;i<=n;i++)
	visited[i]=dis[i]=0;
	front=rear=0;
	q[rear++]=v;
	visited[v]=1;
	while(front<rear){
		i=q[front++];
		for(j=1;j<=n;j++){
			if(a[i][j] && !visited[j]){
				dis[j]=dis[i]+1;
				q[rear++]=j;
				visited[j]=1;
				printf("\nvertex %d to %d distance =%d\n",v,j,dis[j]);
			}
		}
			//else
			//if(!a[i][j] || visited[j])
			//{
			//printf("The vertex %d to %d are not reachable\n",v,j);
			//}
	}
}
void main()
{
	int n,i,j,source;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter the Adjacency matrix\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	printf("Enter the source node\n");
	scanf("%d",&source);
	bfs(source,n);
}
/*Enter the number of nodes	4

Enter the Adjacency matrix
0 1 1 0 
0 0 0 0 
0 0 0 1 
1 1 0 0 

Enter the source node	1

vertex 1 to 2 distance =1
vertex 1 to 3 distance =1
vertex 1 to 4 distance =2		*/

