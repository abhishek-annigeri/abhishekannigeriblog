#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
int i,n,encode[20],decode[20],ch;
char string[20];

while(1)
{
printf("1:Enter a String\n2:Encode\n3:Decode\n4:Exit\n\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{

case 1:	printf("enter a string\n");
	scanf("%s",string);
	printf("Entered String is : %s\n",string);
	n=strlen(string);
	printf("Length of The String is : %d\n",n);
	break;	

case 2:	printf("Encoded string is :\n");
	for(i=0;i<n;i++)
	{
	encode[i]=string[i];
	encode[i]=encode[i]+10;
	printf("%c",encode[i]);
	}
	break;

case 3:	printf("\nDecoded String is :\n");
	for(i=0;i<n;i++)
	{
	decode[i]=encode[i];
	decode[i]=decode[i]-10;
	printf("%c",decode[i]);
	}
	break;

case 4: exit(0);

default : printf("invalid option\n");
	  break;	
	}

printf("\n");
}
}
