#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
FILE *fp;
int line_number=1,find_result=0;
char temp[512],str[10];
printf("Enter a String\n");
scanf("%s",str);
fp=fopen("13b.txt","r");
while(fgets(temp,512,fp)!=NULL)
{
if(strstr(temp,str)!=NULL)
{
printf("A match found at line : %d\n",line_number);
printf("\n%s\n",temp);
find_result++;
}
line_number++;
}
if(find_result==0)
printf("\n Sorry couldn't find a match\n ");
if(fp)
fclose(fp);
return (0);
}
