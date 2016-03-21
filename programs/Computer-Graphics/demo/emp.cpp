#include<string.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
#include<iostream>
using namespace std;

	void put_pixel(float x,float y)
		{
			glPointSize(1.0);
			glBegin(GL_POINTS);				        		
			glVertex2f(x,y);
			glEnd();
			glFlush();
		}


	void myinit()
	{	
		glClearColor(1,1,1,1);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0,0,0);	        
		gluOrtho2D(-50.0,1000.0,-50.0,130.0);
		glFlush();	
	}



	void dda(int x1,int y1,int x2,int y2) {	
		int dx,dy,steps;
		float x,y;
		float incx,incy;
		dx=x2-x1;
		dy=y2-y1;
		if(fabs(dx) > fabs(dy))
			steps=fabs(dx);
		else
			steps=fabs(dy);
		incx=(float)dx/(float)steps;
		incy=(float)dy/(float)steps;
		x=x1;
		y=y1;	
		put_pixel(x1,y1);
		for(int i=1;i<=steps;i++)
		{
		x=x+incx;
		y=y+incy;
		put_pixel(x,y);
		glFlush();
		}
	}


	void cord() {
		glBegin(GL_LINES);
		glVertex2i(-1000,0);
		glVertex2i(1000,0);
		glVertex2i(0,-1000);
		glVertex2i(0,+1000);
		glEnd();
		 }


	void cal_cont() {
		glClear(GL_COLOR_BUFFER_BIT);
		cord();
		glColor3f(1,0,0);			
		int n,i,ef=0;
		float rf[30],crf[300],f[30],l=0;
		float x[30],y[30];
		float lb[30],ub[30];
		cout<<"Enter the limit (1-9)\n";
		cin>>n;
		cout<<"Enter the Internal\nIn The Format : <lower limit > 0 > <upper limit < 10 >\n";
		for(i=1;i<=n;i++)
			cin>>lb[i]>>ub[i];
		cout<<"Enter f for n\n";
		for(i=1;i<=n;i++)
			cin>>f[i];
		for(i=1;i<=n;i++)
			ef=ef+f[i];
		for(i=1;i<=n;i++) {
			rf[i]=(f[i]/ef);
			l=l+rf[i];
			crf[i]=l;
				}
		int f1=0;
		for(i=1;i<=n;i++) {
			y[i]=crf[i]*100;		
			x[i]=ub[i]*100;
				}

		cout<<"|----------------------------------------------------------------------------------------------|\n";
		cout<<"\n|\tx|lower limit   |Upper limit|\tf\t|"<<"Relative Frequency     |"<<"Cummlative Frequency"<<endl;
		cout<<"-----------------------------------------------------------------------------------------------|\n";
		for(i=1;i<=n;i++) {
		cout<<"|\t"<<i<<"|\t"<<lb[i]<<"\t|"<<ub[i]<<"\t   |\t"<<f[i]<<"\t|"<<rf[i]<<"\t\t|"<<crf[i]<<endl;
		cout<<"|----------------------------------------------------------------------------------------------|\n";
				}

		glColor3f(0,0,0);
		char t[50]="EMPERICAL DISTRIBUTION FOR CONTINUOUS DATA";
		int len=strlen(t);
		for (int i = 0; i<=len; i++) {
			glRasterPos2i(30+(i*16),110);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, t[i]);
			glFlush();	
			}
		int k;
		char pt='.';
		char a[20]={'0','1','2','3','4','5','6','7','8','9'};
		k=50-15;
		for (int i = 0,m=0; i<ub[n]; i++,m++) {
			glRasterPos2i(k+(i*6),-5);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[m]);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,pt);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[5]);
			glFlush();
			k=k+100;
				}

		k=0-15;
		for (int i = 0,m=1; i<ub[n]; i++,m++) {
			k=k+100;
			glRasterPos2i(k+(i*6),-5);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[m]);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,pt);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[0]);
			glFlush();
			}

		k=0;
		for (int i = 0,m=1; i<=9; i++,m++) {
			k=k+10;
			glRasterPos2i(-35,k);
			if(i==9)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[1]);
			else
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[0]);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,pt);
			if(i==9)
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[0]);
			else
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[m]);
			glFlush();
			}
		glFlush();
	}


	void display()
	{
		cal_cont();
		cord();	
		glFlush();
	}

		int main(int argc, char** argv) {
			glutInit(&argc,argv);
			glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
			glutInitWindowSize(1000,700);
			glutInitWindowPosition(100,100);
			glutCreateWindow("Project 2 : Emperical & Triangular Distribution");
			myinit();		
			glutDisplayFunc(display);
			glutMainLoop();
			return 0;
		}
