#include<stdio.h>
void main()
{
int slno;
float bs,gs,hra,ta,it,net_sal;
char name[20];
printf("Enter the basic salary of employee\n");
scanf("%f",&bs);
printf("Enter the slno \n");
scanf("%d",&slno);
printf("Enter the name of employee\n");
scanf("%s",name);
hra=0.1*bs;
ta=0.05*bs;
it=0.025*bs;
gs=(bs+hra+ta+it);
net_sal=gs-it;
printf("Gross salary of employee =%f\n",gs);
printf("slno\t name\t    hra\t            ta\t            it\t            bs\t           gs\t        nt_sal\n");
printf("---------------------------------------------------------------------------------------------------\n");
printf("%d\t %s\t %7.2f\t %7.2f\t  %7.2f\t %7.2f\t %7.2f\t %7.2f\n",slno,name,hra,ta,it,bs,gs,net_sal);
}

