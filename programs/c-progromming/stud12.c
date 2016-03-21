#include<stdio.h>

#include<stdlib.h>

void main()

{

struct student

{
char name[20];

int id;

char branch[20];
struct marks
{
int m1,m2,m3,sum;
float avg;
}m;
}s[20];
int c=0,best,worst,j,pos,i,n=0,ch,sum;
while(1)
{
printf("\n1:Add student details\n2:Delete Student details\n3:Display");
printf("\n4:Best Marks\n5:Works Marks\n6:Average Marks\n7:Exit\n");
printf("\nEnter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter Student Details\n");
	printf("Enter student name\n");
	scanf("%s",s[n].name);
	printf("Enter student branch\n");
	scanf("%s",s[n].branch);
	printf("Enter student Id\n");
	scanf("%d",&s[n].id);
	printf("Enter 3 marks of student\n");
	scanf("%d%d%d",&s[n].m.m1,&s[n].m.m2,&s[n].m.m3);
	s[n].m.sum=s[n].m.m1+s[n].m.m2+s[n].m.m3;
	s[n].m.avg=(s[n].m.sum)/3;
	n++;
	break;
case 2: printf("Enter the position which you want to delete\n");
	scanf("%d",&pos);
	if(pos>n)
	{
	printf("Invalid position\n");
	break;
	}
	else
	{
	for(i=pos+1;i<n;i++)
	s[i]=s[i+1];
	n--;
	}
	break;
case 3: printf("Student details are as follows\n\n");
	for(i=0;i<n;i++)
	{
	printf("Details of student%d are: \n",i+1);
	printf("Name=%s\n",s[i].name);
	printf("Branch=%s\n",s[i].branch);
	printf("Id=%d\n",s[i].id);
	printf("Marks1=%d\n",s[i].m.m1);
	printf("Marks2=%d\n",s[i].m.m2);
	printf("Marks3=%d\n",s[i].m.m3);
	}
	break;
case 4: c=0;
	best=s[0].m.sum;
	for(i=0;i<n;i++)
	{
	for(j=i+1;j<n;j++)
	{
	if(s[i].m.sum > s[j].m.sum)
	{
	c=i;	
	best=s[i].m.sum;
	}	
	else
	{
	c=j;
	best=s[j].m.sum;
	}
	}
	}
	printf("Best score is by %s is %d\n",s[c].name,best);
	break;

case 5:	c=0;
	worst=s[0].m.sum;
	for(i=0;i<n;i++)
	{
	for(j=i+1;j<n;j++)
	{
	if(s[i].m.sum < s[j].m.sum)
	{
	c=i;	
	worst=s[i].m.sum;
	}	
	else
	{
	c=j;
	worst=s[j].m.sum;
	}
	}
	}
	printf("Worst score is by %s is %d\n",s[c].name,worst);
	break;
case 6 : for(i=0;i<n;i++)
	 printf("Average marks of %s is %f\n",s[i].name,s[i].m.avg);
	break;
case 7: exit(0);
default : printf("Invalid choice\n");
		break;
}
}
}
