#include<stdio.h>
#include<stdlib.h>
void main()
{
FILE *fp1,*fp2;
char ch,fname1[20],fname2[20];
printf("\nEnter source file name\n");
gets(fname1);
printf("\nEnter destiantion file name\n");
gets(fname2);
fp1=fopen(fname1,"r");
fp2=fopen(fname2,"w");
if(fp1==NULL || fp2==NULL)
{
printf("Unable to open\n");
exit(0);
}
do
{
ch=fgetc(fp1);
fputc(ch,fp2);
}
while(ch!=EOF);
fcloseall();
printf("\nFiles copied successfully\n");
}
