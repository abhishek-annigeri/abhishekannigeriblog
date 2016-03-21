#include<stdio.h>
#define MAX 10
#define TRUE 1
#define FALSE 0
#define INFINITY 999
void shortestpath(int v,int cost[][MAX],int dist[],int n){
	int s[MAX];
	int u,i,j,w,num;
	for(i=1;i<=n;i++){
		s[i]=FALSE;
		dist[i]=cost[v][i];
	}
	s[v]=TRUE;
	dist[v]=1;
	num=2;
	while(num<=n){
		u=choose(dist,s,n);
		s[u]=TRUE;
		num++;
		for(w=1;w<=n;w++){
			if(((dist[u]+cost[u][w])<dist[w])&&!s[w])
			dist[w]=dist[u]+cost[u][w];
		}
	}
}
int choose(int dist[],int s[], int n){
	int w,j=1,min;
	min=INFINITY;
	for(w=1;w<=n;w++){
		if((dist[w]<min) && (s[w]==FALSE)){
			min=dist[w];
			j=w;
		}
	}
	return j;
}
void main(){
	int cost[MAX][MAX];
	int dist[MAX];
	int b, i,j,n,v;
	printf("\nEnter the number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the cost matrix row wise, 999 for indirect path: ");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&cost[i][j]);
	printf("\nEnter the starting node:");
	scanf("%d",&v);
	shortestpath(v,cost,dist,n);
	printf("\nShortest path from starting node %d to destination is as shown below\n",v);
	printf("Destination node\tDistance\n");
	for(j=1;j<=n;j++)
		if(j!=v)
		printf("%5d\t\t\t%5d\n",j,dist[j]);
}

/*Enter the number of vertices:	5

Enter the cost matrix row wise, 999 for indirect path: 
0 2 8 5 999
999 0 1 999 999 
999 999 0 999 3
999 999 999 0 4
999 999 999 999 0

Enter the starting node:	1

Shortest path from starting node 1 to destination is as shown below
Destination node	Distance
    2			    2
    3			    3
    4			    5
    5			    6			*/

