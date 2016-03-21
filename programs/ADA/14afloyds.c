#include<stdio.h>
#define max 0
#define true 1
#define alp 999
int min(int a, int b){
   return(a<b)?a:b;
}
void main(){
	int n,i,j,k, a[10][10], c[10][10];
	printf("\nEnter limit:");
	scanf("%d", &n);
	printf("\nEnter adj  matrix:");
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		  scanf("%d", &c[i][j]);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++) 
	       		a[i][j]=c[i][j];
	for(k=0;k <n; k++){
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				a[i][j]=min(a[i][j], a[i][k]+a[k][j]);
			}
		}
	}
	printf("\nshortest path\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}  
/*Enter limit:4

Enter adj  matrix:
0 999 3 999
2 0 999 999
999 6 0 1
1 999 999 0

shortest path
  0  9  3  4
  2  0  5  6
  2  6  0  1
  1 10  4  0		*/
