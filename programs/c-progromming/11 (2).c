#include<stdio.h>
void add(int,float,int,float);
void sub(int,float,int,float);
void main()
{
struct complex
{
int r;
float i;
};
struct complex c1,c2;

printf("Enter 1st complex number\n");
printf("Enter real part\n");
scanf("%d",&c1.r);
printf("Enter imaginary part\n");
scanf("%f",&c1.i);

printf("\nEnter 2nd complex number\n");
printf("Enter real part\n");
scanf("%d",&c2.r);
printf("Enter imaginary part\n");
scanf("%f",&c2.i);

add(c1.r,c1.i,c2.r,c2.i);
sub(c1.r,c1.i,c2.r,c2.i);
}

void add(int a1,float a2,int b1,float b2)
{
int s1;
float s2;
s1=a1+b1;
s2=a2+b2;
printf("Sum of 2 complex are :%d+%fi\n",s1,s2);
}

void sub(int a1,float a2,int b1,float b2)
{
int s1;
float s2;
s1=a1-b1;
s2=a2-b2;
printf("Sub of 2 complex are :%d+%fi\n",s1,s2);
}
