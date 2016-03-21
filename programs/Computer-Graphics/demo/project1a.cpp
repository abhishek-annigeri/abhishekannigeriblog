#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<iostream>
using namespace std;

int x[10],y[10];
int p[30],q[30];
int i;
void myinit()
{	
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
	gluOrtho2D(-500.0,500.0,-500.0,500.0);
	glFlush();
}


void road()
{
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex2i(-500,-200);
glVertex2i(500,-200);
glEnd();
glFlush();
}

void plotpoints(int xc,int yc,int x,int y)
{
	glPointSize(2.0);
	glBegin(GL_POINTS);
	glVertex2i(x+xc,y+yc);
	glVertex2i(-x+xc,y+yc);
	glVertex2i(-x+xc,-y+yc);
	glVertex2i(x+xc,-y+yc);
	glVertex2i(y+xc,x+yc);
	glVertex2i(y+xc,-x+yc);
	glVertex2i(-y+xc,-x+yc);
	glVertex2i(-y+xc,x+yc);	
	glEnd();
}

void bres(int xc, int yc, int r)
{
	int d0,d1;
	int x,y;
	x=0;y=r;
	d0=2*(1-r);
	while(y>x)
	{
	plotpoints(xc,yc,x,y);
	if(d0<0)
	{
		d1=2*d0+2*y-1;
		if(d1<=0)
		{
			x++;
			d0+=2*x+1;
		}
		else
		{
			x++;y--;d0+=2*x-2*y+2;
		}
	}
	else
		if(d0>0)
		{
			d1=2*x-2*d0+1;
			if(d1<0)
			{
				y--;
				d0+=-2*y+1;
			}
			else
			{
				x++;
				y--;
				d0+=2*x-2*y+2;
			}
		}
		else
		{
			x++;
			y--;
			d0+=2*x-2*y+2;
		}
	}	
}

void cycle()
{
glColor3f(1.0,0.0,0.0);  
glLineWidth(2);
glBegin(GL_LINE_LOOP);
for(int i=0;i<=4;i++)
{
glVertex2i(x[i],y[i]);
}
glEnd();

glColor3f(1.0,0.0,0.0);  
bres(x[0],y[0],15);
bres(x[2],y[2],15);	

glBegin(GL_LINES);
glVertex2i(x[1],y[1]);
glVertex2i(x[4],y[4]);

glVertex2i(x[1],y[1]);
glVertex2i(x[3],y[3]);

glVertex2i(x[3],y[3]);
glVertex2i(x[5],y[5]);

glVertex2i(x[3],y[3]);
glVertex2i(x[6],y[6]);


glVertex2i(x[4],y[4]);
glVertex2i(x[7],y[7]);

glEnd();

bres(x[7],y[7],5);

}


void car()
{
glClear(GL_COLOR_BUFFER_BIT);
road();
p[0]=270;
p[1]=290;
p[2]=300;
p[3]=310;
p[4]=390;
p[5]=400;
p[6]=410;
p[7]=430;

p[8]=430;
p[9]=400;
p[10]=380;
p[11]=320;
p[12]=300;
p[13]=270;

for(i=0;i<=7;i++)
{
q[i]=-180;
}
q[8]=-140;
q[9]=-130;
q[10]=-90;
q[11]=-90;
q[12]=-130;
q[13]=-140;

glColor3f(1.0,0.0,0.0);
glLineWidth(4);
glBegin(GL_LINE_LOOP);
for(i=0;i<=13;i++)
{
glVertex2i(p[i],q[i]);
}
glEnd();



glColor3f(0.0,0.0,0.0);
for(i=0;i<=10;i++)
{
bres(p[2],q[2],15-i);
bres(p[5],q[5],15-i);
}
glFlush();

p[14]=305;
p[15]=320;
p[16]=320;

q[14]=-130;
q[15]=-130;
q[16]=-97;

p[20]=323;
p[21]=345;
p[22]=345;
p[23]=323;

q[20]=-130;
q[21]=-130;
q[22]=-97;
q[23]=-97;


glLineWidth(2);
glBegin(GL_POLYGON);
for(i=20;i<=23;i++)
{
glVertex2i(p[i],q[i]);
}
glEnd();


glLineWidth(2);
glBegin(GL_POLYGON);
for(i=14;i<=16;i++)
{
glVertex2i(p[i],q[i]);
}
glEnd();

glFlush();

p[24]=375;
p[25]=350;
p[26]=350;
p[27]=375;

q[24]=-130;
q[25]=-130;
q[26]=-97;
q[27]=-97;


p[17]=395;
p[18]=380;
p[19]=380;

q[17]=-130;
q[18]=-130;
q[19]=-97;

glLineWidth(2);
glBegin(GL_POLYGON);
for(i=17;i<=19;i++)
{
glVertex2i(p[i],q[i]);
}
glEnd();


glLineWidth(2);
glBegin(GL_POLYGON);
for(i=24;i<=27;i++)
{
glVertex2i(p[i],q[i]);
}
glEnd();


glFlush();

}


void delay()
{
for(double j=0;j<=10000000;j++)
{

}
}


void move()
{

for(int j=0;j<=70;j++)
{
delay();
glClear(GL_COLOR_BUFFER_BIT);
road();
for(int i=0;i<=7;i++)
{
x[i]=x[i]+10;
}
cycle();
glFlush();
delay();
}
}

void display()
{

x[0]=-450;
x[1]=-425;
x[2]=-400;
x[3]=-412;
x[4]=-437;
x[5]=-419;
x[6]=-407;
x[7]=-437;

y[0]=-180;
y[1]=-180;
y[2]=-180;
y[3]=-155;
y[4]=-155;
y[5]=-142;
y[6]=-142;
y[7]=-145;

glColor3f(0.0,0.0,0.0);
cycle();
move();
car();
glFlush();
}

int main(int argc, char** argv) { 
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1600,900);
glutInitWindowPosition(100,100);
glutCreateWindow("Project 1 : Morphing (Bicycle To Car)");
glutDisplayFunc(display);
myinit();
glutMainLoop();
return 0;
}
