#include<stdio.h>
void main()
{
float c,f;
printf("Enter the temperature in degrees \n");
scanf("%f",&c);
f=(c*9/5)+32;
printf("Converted temperature in fahrenheit is=%f\n",f);
printf("\nEnter the temperature in fahrenhite\n");
scanf("%f",&f);
c=(f-32)*5/9;
printf("Converted temperature in celsius =%f\n",c);
}
