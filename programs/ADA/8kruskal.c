#include<stdio.h>
int root[10], flag = 0, count=0, temp, min;
int a[20], cost[20][20], n, i, j, k, totalcost = 0, x, y;
void find_min (), check_cycle (), update ();
void find_min (){
	min = 999;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (min > cost[i][j]){
				min = cost[i][j];
				x = i;
				y = j;
			}
}
void check_cycle (){
	if ((root[x] == root[y]) && (root[x] != 0))
		flag = 0;
	else
		flag = 1;
}
void update (){
	if (root[x] == 0 && root[y] == 0)
		root[x] = root[y] = x;
	else if (root[x] == 0)
		root[x] = root[y];
	else if (root[y] == 0)
		root[y] = root[x];
	else{
		temp = root[y];
		for (i = 1; i <= n; i++)
			if (root[i] == temp)
				root[i] = root[x];
	}
}
main (){
	printf ("\nEnter the number of vertices:");
	scanf ("%d", &n);
	printf ("\nEnter the cost of the matrix:\n");
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf ("%d", &cost[i][j]);
	find_min ();
	while (min != 999 && count != n - 1){
		check_cycle ();
		if (flag){
			printf ("%d  --->  %d  =  %d\n", x, y, cost[x][y]);
			totalcost += cost[x][y];
			update ();
			count++;
		}
		cost[x][y] = cost[y][x] = 999;
		find_min ();
	}
	if (count < n - 2)
		printf ("The graph is not connected\n");
	else
		printf ("The minimum cost is: %d\n", totalcost); 
}

/*Enter the number of vertices:	5

Enter the cost of the matrix:
999 5 15 20 999 
5 999 25 999 999 
15 25 999 30 37
20 999 30 999 35
999 999 37 35 999

1  --->  2  =  5
1  --->  3  =  15
1  --->  4  =  20
4  --->  5  =  35
The minimum cost is: 75		*/

