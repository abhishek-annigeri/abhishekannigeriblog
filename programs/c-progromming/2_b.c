#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
int ch;
float a,b,c,d,r1,r2;
printf("Enter the values of a,b & c\n");
scanf("%f%f%f",&a,&b,&c);
if(a==0 || b==0 || c==0)
printf("Invalid inputs\n");
else
{
d=b*b-4*a*c;
if(d>0)
ch=1;
else if(d<0)
ch=2;
else if(d==0)
ch=3;
}

switch(ch)
{
case 1: printf("Roots are real and distinct\n");
	r1=(-b+sqrt(d)/(2*a));
	r2=(-b-sqrt(d)/(2*a));
	printf("Roots of an equation are: %f and %f\n",r1,r2);
	break;

case 2: printf("Roots are complex and imaginary\n");
	d=sqrt(abs(d));
	r1=-b/(2*a);
	r2=d/(2*a);
	printf("Roots of an equation are: %fi + %f and %fi - %f\n",r1,r2,r1,r2);
	break;

case 3: printf("Roots are equal\n");
	r1=-b/(2*a);
	r2=r1;
	printf("Roots of an equation are: %f and %f\n",r1,r2);
	break;
}
}
