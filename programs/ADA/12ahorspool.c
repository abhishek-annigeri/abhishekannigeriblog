#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
	int table[126];
	char t[100],p[30];
	int n,i,k,j,m,flag=0;
	printf("\nEnter the String:");
	gets(t);
	n=strlen(t);
	printf("\nLength of String =%d",n);
	printf("\nEnter pattern:");
	gets(p);
	m=strlen(p);
	printf("\nLength of Pattern =%d",m);
	for(i=0;i<126;i++)
		table[i]=m;
	for(j=0;j<=m-2;j++)
		table[p[j]]=m-1-j;
	i=m-1;
	while(i<=n-1){
		k=0;
		while(k<=m-1&&p[m-1-k]==t[i-k])
			k++;
		if(k==m){
			printf("\nposition of pattern %d\n",i-m+2);
			flag=1;
			break;
		}
		else
			i=i+table[t[i]];
	}
	if(!flag)
		printf("\nPattern  not found\n");
}

