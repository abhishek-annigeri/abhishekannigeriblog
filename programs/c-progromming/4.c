#include<stdio.h>
#include<stdlib.h>
void main()
{
int n,i,ch,val,pos;
int a[10];
printf("Enter the no of elements in an array\n");
scanf("%d",&n);
//printf("Enter the elements\n");
for(i=0;i<n;i++)
a[i]=0;
//scanf("%d",&a[i]);
while(1)
{
printf("\nEnter your choice\n");
printf("1:Insertion\n2:Deletion\n3:Exit\n4:DIsplay\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter the location where you wish to insert an element\n");
	scanf("%d",&pos);
	if(pos>n || pos<=0)
		{
	
	printf("Insertion is not possible\n");
	break;
		}	
	
	printf("Enter the value to be inserted\n");
	scanf("%d",&val);
	pos--;
	for(i=n;i>=pos;i--)
		a[i+1]=a[i];
		a[pos]=val;	
	n++;
	//printf("\nAfter insertion new array :\n");
	//for(i=0;i<n;i++)
	//printf("%d\n",a[i]);
	break;

case 2: printf("Enter ther location where u wish to delete the element\n");
	scanf("%d",&pos);
	if(pos>n)
{
	printf("Deletion is not possible\n");
	break;
}	
	for(i=pos-1;i<=n;i++)
		a[i]=a[i+1];
	n--;
printf("\nelement deleted successfully\n");
	//for(i=0;i<n;i++)
	//printf("%d\n",a[i]);
	break;

case 3: exit(0);
case 4: printf("\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
	break;	
default: printf("Invalid choice\n");
	 break;	

}
}
printf("\n");
}
