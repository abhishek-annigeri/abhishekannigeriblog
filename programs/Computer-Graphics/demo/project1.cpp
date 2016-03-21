	/*Animate a bicycle / car with given attributes – Morphing from Bicycle to car*/

		#include<string.h>
		#include<GL/glut.h>
		#include<GL/glu.h>
		#include<GL/gl.h>
		#include<iostream>
		using namespace std;
	
			int s,x[10],y[10],p[30],q[30],i,k=15,c=0;
			void transform();
			void transform1();
			void transform2();
			void transform3();
			void transform4();
			void transform5();
			void transform6();
			void transform7();
			void transform8();
			void transform9();
			void transform10();
			void transform11();
			void transform12();

	
	void myinit()	
	{	
		glClearColor(0.0,0.5,0.7,1);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
        	glMatrixMode(GL_PROJECTION);
        	glLoadIdentity();
		gluOrtho2D(0.0,1200.0,0.0,1200.0);
		glFlush();
	}	
	
	void road()
	{	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(0,300);
		glVertex2i(1200,300);
	glEnd();
	glFlush();
	glColor3f(0,0,0);	        
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
			glVertex2i(x[i],y[i]);
	glEnd();
	glColor3f(1.0,0.0,0.0);  
	bres(x[0],y[0],k);
	bres(x[2],y[2],k);	
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
	glBegin(GL_LINES);
		glVertex2i(x[2]+k,y[2]);
		glVertex2i(x[2]-k,y[2]);
		glVertex2i(x[2],y[2]+k);
		glVertex2i(x[2],y[2]-k);			
		glVertex2i(x[0]+k,y[0]);
		glVertex2i(x[0]-k,y[0]);
		glVertex2i(x[0],y[0]+k);
		glVertex2i(x[0],y[0]-k);	
	glEnd();
	
	if(c>7 && c < 12)
		k++;	
	transform();
	}
	
	
	void delay()
	{
		for(double j=0;j<=10000000;j++) { }
	}
	
	void trans1()
	{	
		glClear(GL_COLOR_BUFFER_BIT);
/*		char t[50]="MORPHING OF CYCLE TO CAR";
		int l=strlen(t);
		glColor3f(0.0,0.0,0.0);	
		for (int i = 0; i<=l; i++) {
		glRasterPos2i(70+(i*16),1000);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, t[i]);
		glFlush();
			}*/
		glFlush();
	
		glColor3f(1.0,0,0);  
		glBegin(GL_LINE_LOOP);
		for(int i=0;i<=4;i++)
		{
		glVertex2i(x[i],y[i]);
		}
		glEnd();
		glBegin(GL_LINES);
			glVertex2i(x[4],y[4]); 
			glVertex2i(x[7],y[7]);
			glVertex2i(x[3],y[3]); 
			glVertex2i(x[5],y[5]);
			glVertex2i(x[3],y[3]);
			glVertex2i(x[6],y[6]);
		glEnd();
		bres(x[7],y[7],5);
		bres(x[0],y[0],k); 
		bres(x[2],y[2],k);	
		glBegin(GL_LINES);
			glVertex2i(x[2],y[2]);
			glVertex2i(x[2]+30,y[2]);
			glVertex2i(x[2]+30,y[2]);
			glVertex2i(x[2]+30,y[3]);
			glVertex2i(x[3],y[3]);
			glVertex2i(x[2]+30,y[3]);
		glEnd();	
		road();	
		glFlush();
		}


	void trans2()
	{
		trans1();
		glColor3f(0.1,0.1,0.0);  
		glBegin(GL_LINES);
			glVertex2i(x[0],y[0]);
			glVertex2i(x[0]-30,y[0]);
			glVertex2i(x[0]-30,y[0]);
			glVertex2i(x[0]-30,y[4]);
			glVertex2i(x[0]-30,y[4]);
			glVertex2i(x[4],y[4]);
		glEnd();
		glFlush();
	}

	void trans3()
	{
		trans2();
		glColor3f(0.1,0.1,0.0);  
		glBegin(GL_LINES);
			glVertex2i(x[0],y[0]);
			glVertex2i(x[0]-30,y[0]);
			glVertex2i(x[0]-30,y[0]);
			glVertex2i(x[0]-30,y[4]);
			glVertex2i(x[0]-30,y[4]);
			glVertex2i(x[4],y[4]);
		glEnd();

		glColor3f(0.2,0.2,0.0);
		glBegin(GL_LINES);
			glVertex2i(x[2]+30,y[3]);
			glVertex2i(x[2]+10,y[3]+30);
		glEnd();
		glFlush();
	}


	void trans4()
	{
	trans3();
	road();
	glColor3f(0.3,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[2]+10,y[3]+30);
		glVertex2i(x[4]-10,y[3]+30);
	glEnd();	
	}
	
	void trans5()
	{
	trans4();
	glColor3f(0.4,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[4]-10,y[3]+30);
		glVertex2i(x[0]-30,y[4]);
	glEnd();
	}
	
	void transform()
	{
	if(c>=15 && c<20)
		trans1();
	else if(c>=20 && c<25)
		trans2();
	else if(c>=25 && c<30)
		trans3();
	else if(c>=30 && c<35)
		trans4();
	else if(c>=35 && c<40)
		trans5();
	else if(c>=40 && c<45)
		transform2();
	else if(c>=45 && c<50)
		transform3();
	else if(c>=50 && c<55)
		transform4();
	else if(c>=55 && c<60)
		transform5();
	else if(c>=60 && c<65)
		transform6();
	else if(c>=65 && c<70)
		transform7();
	else if(c>=70 && c<75)
		transform8();
	else if(c>=75 && c<80)
		transform9();
	else if(c>=80 && c<85)
		transform10();
	else if(c>=85 && c<90)
		transform11();	
	else if(c>=90)
		transform12();	
	glFlush();	
	}
	

	void transform2()
	{	
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	glColor3f(0.5,0.0,0.0);  
	glBegin(GL_LINE_LOOP);
		for(int i=0;i<=4;i++)
		{
			glVertex2i(x[i],y[i]);
		}
	glEnd();
	glColor3f(0.5,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[4],y[4]); 
		glVertex2i(x[7],y[7]);
		glVertex2i(x[3],y[3]); 
		glVertex2i(x[5],y[5]);
		glVertex2i(x[3],y[3]);
		glVertex2i(x[6],y[6]);
	glEnd();
	glColor3f(0.5,0.0,0.0);
	bres(x[7],y[7],5);
	bres(x[0],y[0],k); 
	bres(x[2],y[2],k);	
	glColor3f(0.5,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[2],y[2]);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30,y[3]);
		glVertex2i(x[3],y[3]);
		glVertex2i(x[2]+30,y[3]);
	glEnd();
	glColor3f(0.5,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[0],y[0]);
		glVertex2i(x[0]-30,y[0]);
		glVertex2i(x[0]-30,y[0]);
		glVertex2i(x[0]-30,y[4]);
	glEnd();
	glColor3f(0.5,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[2]+30,y[3]);
		glVertex2i(x[2]+10,y[3]+30);
	glEnd();
	glColor3f(0.5,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[2]+10,y[3]+30);
		glVertex2i(x[4]-10,y[3]+30);
	glEnd();
	glColor3f(0.5,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[4]-10,y[3]+30);
		glVertex2i(x[0]-30,y[4]);
	glEnd();
	}
	
	void transform3()
	{
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	glColor3f(0.6,0.0,0.0);  
	glBegin(GL_LINE_LOOP);
		for(int i=0;i<=4;i++)
		{
			glVertex2i(x[i],y[i]);
		}
	glEnd();
	glColor3f(0.6,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[4],y[4]); 
		glVertex2i(x[7],y[7]);
		glVertex2i(x[3],y[3]); 
		glVertex2i(x[5],y[5]);
		glVertex2i(x[3],y[3]);
		glVertex2i(x[6],y[6]);
	glEnd();
	glColor3f(0.6,0.0,0.0);  
	
	bres(x[0],y[0],k); 
	bres(x[2],y[2],k);	
	glColor3f(0.6,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[2],y[2]);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30,y[3]);
		glVertex2i(x[3],y[3]);
		glVertex2i(x[2]+30,y[3]);
	glEnd();
	glColor3f(0.6,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[0],y[0]);
		glVertex2i(x[0]-30,y[0]);
		glVertex2i(x[0]-30,y[0]);
		glVertex2i(x[0]-30,y[4]);
	glEnd();
	glColor3f(0.6,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[2]+30,y[3]);
		glVertex2i(x[2]+10,y[3]+30);
	glEnd();
	glColor3f(0.6,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[2]+10,y[3]+30);
		glVertex2i(x[4]-10,y[3]+30);
	glEnd();
	glColor3f(0.6,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[4]-10,y[3]+30);
		glVertex2i(x[0]-30,y[4]);
	glEnd();
	
	}
	
	void transform4()
	{
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	glColor3f(0.7,0.0,0.0);  
	glBegin(GL_LINE_LOOP);
		for(int i=0;i<=4;i++)
		{
			glVertex2i(x[i],y[i]);
		}
	glEnd();
	glColor3f(0.7,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[4],y[4]); 
		glVertex2i(x[7],y[7]);
	glEnd();
	bres(x[0],y[0],k); 
	bres(x[2],y[2],k);
	glColor3f(0.7,0.0,0.0);	
	glBegin(GL_LINES);
		glVertex2i(x[2],y[2]);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30,y[3]);
		glVertex2i(x[3],y[3]);
		glVertex2i(x[2]+30,y[3]);
	glEnd();
	glColor3f(0.7,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[0],y[0]);
		glVertex2i(x[0]-30,y[0]);
		glVertex2i(x[0]-30,y[0]);
		glVertex2i(x[0]-30,y[4]);
	glEnd();
	glColor3f(0.7,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[2]+30,y[3]);
		glVertex2i(x[2]+10,y[3]+30);
	glEnd();
	glColor3f(0.7,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[2]+10,y[3]+30);
		glVertex2i(x[4]-10,y[3]+30);
	glEnd();
	glColor3f(0.7,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[4]-10,y[3]+30);
		glVertex2i(x[0]-30,y[4]);
	glEnd();
	
	}
	
	
	void transform5()
	{
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	glColor3f(0.8,0.0,0.0);
	glLineWidth(3);
	  
	glBegin(GL_LINE_LOOP);
		for(int i=0;i<=4;i++)
		{
			glVertex2i(x[i],y[i]);
		}
	glEnd();
	glColor3f(0.8,0.0,0.0);  
	
	bres(x[0],y[0],k); 
	bres(x[2],y[2],k);	
	bres(x[0]+10,y[0],k); 
	bres(x[2]+10,y[2],k);	
	glColor3f(0.8,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[2],y[2]);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30,y[3]);
	glEnd();
	glColor3f(0.8,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[0],y[0]);
		glVertex2i(x[0]-30,y[0]);
		glVertex2i(x[0]-30,y[0]);
		glVertex2i(x[0]-30,y[4]);
	glEnd();
	glColor3f(0.8,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[2]+30,y[3]);
		glVertex2i(x[2]+10,y[3]+30);
	glEnd();
	glColor3f(0.8,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[2]+10,y[3]+30);
		glVertex2i(x[4]-10,y[3]+30);
	glEnd();
	glColor3f(0.8,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[4]-10,y[3]+30);
		glVertex2i(x[0]-30,y[4]);
	glEnd();
	
	}
	
	
	void transform6()
	{
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	glColor3f(0.9,0.0,0.0);  
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2i(x[0],y[0]);
		glVertex2i(x[2],y[2]);
	glEnd();
	glColor3f(0.9,0.0,0.0);
	bres(x[0],y[0],k); 
	bres(x[2],y[2],k);	
	bres(x[0]+10,y[0],k); 
	bres(x[2]+10,y[2],k);	
	glColor3f(0.9,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[2],y[2]);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30,y[3]);
	glEnd();
	glColor3f(0.9,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[0],y[0]);
		glVertex2i(x[0]-30,y[0]);
		glVertex2i(x[0]-30,y[0]);
		glVertex2i(x[0]-30,y[4]);
	glEnd();
	glColor3f(0.9,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[2]+30,y[3]);
		glVertex2i(x[2]+10,y[3]+30);
	glEnd();
	glColor3f(0.9,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[2]+10,y[3]+30);
		glVertex2i(x[4]-10,y[3]+30);
	glEnd();
	glColor3f(0.9,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[4]-10,y[3]+30);
		glVertex2i(x[0]-30,y[4]);
	glEnd();
	}
	
	void transform7()
	{
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	glColor3f(1.0,0.0,0.0);  
	glLineWidth(3);
	
	glBegin(GL_LINES);
		glVertex2i(x[0],y[0]);
		glVertex2i(x[2]+30,y[2]);
	glEnd();
	bres(x[0],y[0],k+5); 
	bres(x[2]+30,y[2],k+5);	
	glColor3f(1.0,0.0,0.0);  
	
	bres(x[0]+10,y[0],k+5); 
	bres(x[2]+30+10,y[2],k+5);	
	glColor3f(1.0,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30+50,y[2]);
	
		glVertex2i(x[2]+30+50,y[2]);
		glVertex2i(x[2]+30+50,y[2]+50);
	
		glVertex2i(x[2]+30+50,y[2]+50);
		glVertex2i(x[2]+40,y[2]+50);
		
		glVertex2i(x[2]+40,y[2]+50);
		glVertex2i(x[2]+10,y[2]+80);
		
		glVertex2i(x[0],y[0]);
		glVertex2i(x[0]-30-30,y[0]);
		
		glVertex2i(x[0]-30-30,y[0]);
		glVertex2i(x[0]-30-30,y[0]+50);
		
		glVertex2i(x[0]-30-30,y[0]+50);
		glVertex2i(x[0]-40,y[0]+50);
		
		glVertex2i(x[0]-40,y[0]+50);
		glVertex2i(x[0]-40+30,y[0]+80);
		
		glVertex2i(x[0]-40+30,y[0]+80);
		glVertex2i(x[2]+10,y[2]+80);
		
	glEnd();
		
	}
	
	void transform8()
	{
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	glColor3f(1.0,0.1,0.0);
	glLineWidth(3);
	  
	glBegin(GL_LINES);
		glVertex2i(x[0],y[0]);
		glVertex2i(x[2]+30,y[2]);
	glEnd();
	glColor3f(1.0,0.1,0.0);  
	
	bres(x[0],y[0],k+5); 
	bres(x[2]+30,y[2],k+5);	
	
	bres(x[0]+10,y[0],k+5); 
	bres(x[2]+30+10,y[2],k+5);	
	
	glBegin(GL_LINES);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30+50,y[2]);
	
		glVertex2i(x[2]+30+50,y[2]);
		glVertex2i(x[2]+30+50,y[2]+50);
		
		glVertex2i(x[2]+30+50,y[2]+50);
		glVertex2i(x[2]+40,y[2]+50);
		
		glVertex2i(x[2]+40,y[2]+50);
		glVertex2i(x[2]+10,y[2]+80);
		
		glVertex2i(x[0],y[0]);
		glVertex2i(x[0]-30-30,y[0]);
		
		glVertex2i(x[0]-30-30,y[0]);
		glVertex2i(x[0]-30-30,y[0]+50);
		
		glVertex2i(x[0]-30-30,y[0]+50);
		glVertex2i(x[0]-40,y[0]+50);
		
		glVertex2i(x[0]-40,y[0]+50);
		glVertex2i(x[0]-40+30,y[0]+80);
				
		glVertex2i(x[0]-40+30,y[0]+80);
		glVertex2i(x[2]+10,y[2]+80);
		
		glVertex2i(x[0]-40+15,y[0]+50);
		glVertex2i(x[0],y[0]+50);
		
		glVertex2i(x[0],y[0]+50);
		glVertex2i(x[0],y[0]+70);
			
		glVertex2i(x[0]-40+15,y[0]+50);
		glVertex2i(x[0],y[0]+70);
		
	glEnd();
	
	}
	
	
	void transform9()
	{
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	glColor3f(1.0,0.2,0.0);  
	glLineWidth(3);

	glBegin(GL_LINES);
		glVertex2i(x[0],y[0]);
		glVertex2i(x[2]+30,y[2]);
	glEnd();
	glColor3f(1.0,0.2,0.0);  
	
	bres(x[0],y[0],k+5); 
	bres(x[2]+30,y[2],k+5);	
	
	bres(x[0]+10,y[0],k+5); 
	bres(x[2]+30+10,y[2],k+5);	
	glColor3f(1.0,0.2,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30+50,y[2]);
	
		glVertex2i(x[2]+30+50,y[2]);
		glVertex2i(x[2]+30+50,y[2]+50);
		
		glVertex2i(x[2]+30+50,y[2]+50);
		glVertex2i(x[2]+40,y[2]+50);
		
		glVertex2i(x[2]+40,y[2]+50);
		glVertex2i(x[2]+10,y[2]+80);
		
		glVertex2i(x[0],y[0]);
		glVertex2i(x[0]-30-30,y[0]);
		
		glVertex2i(x[0]-30-30,y[0]);
		glVertex2i(x[0]-30-30,y[0]+50);
		
		glVertex2i(x[0]-30-30,y[0]+50);
		glVertex2i(x[0]-40,y[0]+50);
		
		glVertex2i(x[0]-40,y[0]+50);
		glVertex2i(x[0]-40+30,y[0]+80);
				
		glVertex2i(x[0]-40+30,y[0]+80);
		glVertex2i(x[2]+10,y[2]+80);
		
		glVertex2i(x[0]-40+15,y[0]+50);
		glVertex2i(x[0],y[0]+50);
	
		glVertex2i(x[0],y[0]+50);
		glVertex2i(x[0],y[0]+70);
		
		glVertex2i(x[0]-40+15,y[0]+50);
		glVertex2i(x[0],y[0]+70);
				
		glVertex2i(x[2]+40-10,y[2]+50);
		glVertex2i(x[2],y[2]+70);
	
		glVertex2i(x[2],y[2]+70);
		glVertex2i(x[2],y[2]+50);
	
		glVertex2i(x[2],y[2]+50);
		glVertex2i(x[2]+40-10,y[2]+50);
	
	glEnd();	
	}
	
	
	void transform10()
	{
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	glColor3f(1.0,0.5,0.7);
	glLineWidth(3);
	  
	glBegin(GL_LINES);
		glVertex2i(x[0],y[0]);
		glVertex2i(x[2]+30,y[2]);
	glEnd();
	for(float l=0.0;l<=2.0;l++)
	{
		glColor3f(0.0,0.0,0.0);
		bres(x[0]+l,y[0],k+5); 
		bres(x[2]+30+l,y[2],k+5);			
		bres(x[0]+10+l,y[0],k+5); 
		bres(x[2]+30+10+l,y[2],k+5);	
	}
	
	glColor3f(1.0,0.5,0.0);
	glBegin(GL_LINES);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30+50,y[2]);
	
		glVertex2i(x[2]+30+50,y[2]);
		glVertex2i(x[2]+30+50,y[2]+50);
	
		glVertex2i(x[2]+30+50,y[2]+50);
		glVertex2i(x[2]+40,y[2]+50);
	
		glVertex2i(x[2]+40,y[2]+50);
		glVertex2i(x[2]+10,y[2]+80);
	
		glVertex2i(x[0],y[0]);
		glVertex2i(x[0]-30-30,y[0]);
	
		glVertex2i(x[0]-30-30,y[0]);
		glVertex2i(x[0]-30-30,y[0]+50);
	
		glVertex2i(x[0]-30-30,y[0]+50);
		glVertex2i(x[0]-40,y[0]+50);
	
		glVertex2i(x[0]-40,y[0]+50);
		glVertex2i(x[0]-40+30,y[0]+80);
		
		glVertex2i(x[0]-40+30,y[0]+80);
		glVertex2i(x[2]+10,y[2]+80);
	
		glVertex2i(x[0]-40+15,y[0]+50);
		glVertex2i(x[0],y[0]+50);
	
		glVertex2i(x[0],y[0]+50);
		glVertex2i(x[0],y[0]+70);
	
		glVertex2i(x[0]-40+15,y[0]+50);
		glVertex2i(x[0],y[0]+70);
		
		glVertex2i(x[2]+40-10,y[2]+50);
		glVertex2i(x[2],y[2]+70);
	
		glVertex2i(x[2],y[2]+70);
		glVertex2i(x[2],y[2]+50);
	
		glVertex2i(x[2],y[2]+50);
		glVertex2i(x[2]+40-10,y[2]+50);
		
		glVertex2i(x[0]+5,y[0]+50);
		glVertex2i(x[0]+20,y[0]+50);
	
		glVertex2i(x[0]+5,y[0]+50);
		glVertex2i(x[0]+5,y[0]+70);
	
		glVertex2i(x[0]+5,y[0]+70);
		glVertex2i(x[0]+20,y[0]+70);
	
		glVertex2i(x[0]+20,y[0]+70);
		glVertex2i(x[0]+20,y[0]+50);
		
		glVertex2i(x[0]+30,y[2]+50);
		glVertex2i(x[0]+20+25,y[2]+50);
		
		glVertex2i(x[0]+30,y[2]+50);
		glVertex2i(x[0]+30,y[2]+70);
		
		glVertex2i(x[0]+30,y[2]+70);
		glVertex2i(x[0]+20+25,y[2]+70);
		
		glVertex2i(x[0]+20+25,y[2]+70);
		glVertex2i(x[0]+20+25,y[2]+50);
			
	glEnd();

	}


	void transform11()
	{
	glClear(GL_COLOR_BUFFER_BIT);
	road();
	glColor3f(1.0,0.0,0.0);  
	glLineWidth(3);
	glBegin(GL_LINES);
		glVertex2i(x[0],y[0]);
		glVertex2i(x[2]+30,y[2]);
	glEnd();
	
	for(i=30;i>0;i--)
	{
		glColor3f(0.0,0.0,0.0);
		bres(x[0]-i,y[0],k+5-i); 
		bres(x[2]+30+10-i,y[2],k+5-i);	
	}
	glFlush();
	glColor3f(1.0,0.0,0.0);  
	
	glBegin(GL_LINES);
		glVertex2i(x[2]+30,y[2]);
		glVertex2i(x[2]+30+50,y[2]);
	
		glVertex2i(x[2]+30+50,y[2]);
		glVertex2i(x[2]+30+50,y[2]+50);
	
		glVertex2i(x[2]+30+50,y[2]+50);
		glVertex2i(x[2]+40,y[2]+50);
	
		glVertex2i(x[2]+40,y[2]+50);
		glVertex2i(x[2]+10,y[2]+80);
		
		glVertex2i(x[0],y[0]);
		glVertex2i(x[0]-30-30,y[0]);
		
		glVertex2i(x[0]-30-30,y[0]);
		glVertex2i(x[0]-30-30,y[0]+50);
		
		glVertex2i(x[0]-30-30,y[0]+50);
		glVertex2i(x[0]-40,y[0]+50);
		
		glVertex2i(x[0]-40,y[0]+50);
		glVertex2i(x[0]-40+30,y[0]+80);
		
		
		glVertex2i(x[0]-40+30,y[0]+80);
		glVertex2i(x[2]+10,y[2]+80);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2i(x[0]-40+15,y[0]+50);
		glVertex2i(x[0],y[0]+50);
		glVertex2i(x[0],y[0]+70);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2i(x[2]+40-10,y[2]+50);
		glVertex2i(x[2],y[2]+70);
		glVertex2i(x[2],y[2]+50);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2i(x[0]+5,y[0]+50);
		glVertex2i(x[0]+5,y[0]+70);
		glVertex2i(x[0]+20,y[0]+70);
		glVertex2i(x[0]+20,y[0]+50);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2i(x[0]+30,y[2]+50);
		glVertex2i(x[0]+30,y[2]+70);
		glVertex2i(x[0]+20+25,y[2]+70);
		glVertex2i(x[0]+20+25,y[2]+50);
	glEnd();
	glFlush();
	}

	void transform12()
	{
		glColor3f(00.1,0.6,0);	
		glBegin(GL_POLYGON);
		glVertex2i(-1500,-1500);
		glColor3f(00.2,0.8,1);
		glVertex2i(-1500,1500);
		glColor3f(0.3,0.2,1.0);
		glVertex2i(1500,1500);
		glColor3f(1,1,1);
		glVertex2i(1500,-1500);
		glEnd();	
			road();//glFlush();
		glColor3f(1.0,0.0,0.0);  
		glLineWidth(3);
		glColor3f(0.1,0.0,0.0);  
		glBegin(GL_LINES);
			glVertex2i(x[0],y[0]);
			glVertex2i(x[2]+30,y[2]);
		glEnd();
		for(i=30;i>0;i--)
		{
			glColor3f(0.0,0.0,0.0);
			bres(x[0]-i,y[0],k+5-i); 
			bres(x[2]+30+10-i,y[2],k+5-i);	
		}
//		glFlush();
		glColor3f(1.0,0.0,0.0);  
		glBegin(GL_POLYGON);
			glColor3f(0.1,0.0,0.0);  
			glVertex2i(x[2]+30,y[2]);
			glVertex2i(x[2]+30+50,y[2]);
			glColor3f(0.2,0.0,0.2);  
			glVertex2i(x[2]+30+50,y[2]+50);
			glColor3f(0.3,0.0,0.1);  
			glVertex2i(x[2]+40,y[2]+50);
			glColor3f(0.4,0.0,0.2);  
			glVertex2i(x[2]+10,y[2]+80);
			glColor3f(0.45,0.0,0.1);  
			glVertex2i(x[0],y[0]);
			glVertex2i(x[0]-30-30,y[0]);
			glColor3f(0.5,0.0,0.2);  
			glVertex2i(x[0]-30-30,y[0]);
			glVertex2i(x[0]-30-30,y[0]+50);
			glVertex2i(x[0]-30-30,y[0]+50);
			glVertex2i(x[0]-40,y[0]+50);
			glVertex2i(x[0]-40,y[0]+50);
			glVertex2i(x[0]-40+30,y[0]+80);
			glVertex2i(x[0]-40+30,y[0]+80);
			glVertex2i(x[2]+10,y[2]+80);
		glEnd();
			glColor3f(0.0,0.0,0.0);
			glBegin(GL_POLYGON);
				glVertex2i(x[0]-40+15,y[0]+50);
				glVertex2i(x[0],y[0]+50);
				glVertex2i(x[0],y[0]+70);
			glEnd();
			glColor3f(0.0,0.0,0.0);
			glBegin(GL_POLYGON);
				glVertex2i(x[2]+40-10,y[2]+50);
				glVertex2i(x[2],y[2]+70);
				glVertex2i(x[2],y[2]+50);
			glEnd();
			glColor3f(0.0,0.0,0.0);
			glBegin(GL_POLYGON);
				glVertex2i(x[0]+5,y[0]+50);
				glVertex2i(x[0]+5,y[0]+70);
				glVertex2i(x[0]+20,y[0]+70);
				glVertex2i(x[0]+20,y[0]+50);
			glEnd();
			glColor3f(0.0,0.0,0.0);
			glBegin(GL_POLYGON);
				glVertex2i(x[0]+30,y[2]+50);
				glVertex2i(x[0]+30,y[2]+70);
				glVertex2i(x[0]+20+25,y[2]+70);
				glVertex2i(x[0]+20+25,y[2]+50);
			glEnd();
			glFlush();
			delay();delay();
		}
	


	void cal()
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
	
	for(int i=0;i<=7;i++)
	{
	x[i]=x[i]+500;
	y[i]=y[i]+500;
	}
	
	}
	
	
	
	void move()
	{
	//for(int j=0;j<=95;j++)
	int j=0;
	while(true)
	{

		if(c>100)
		{
			cycle();
		} 
			if(c>110&&c<=120)
		{
			k=15;
			c=0;
			cal();
		}
		c++;
		delay();
		glClear(GL_COLOR_BUFFER_BIT);
		road();
		glColor3f(00.1,0.6,1);	
		glBegin(GL_POLYGON);
		glVertex2i(-1500,-1500);
		glColor3f(00.2,0.8,1);
		glVertex2i(-1500,1500);
		glColor3f(0.3,0.7,1.0);
		glVertex2i(1500,1500);
		glColor3f(0.5,0.0,1);
		glVertex2i(1500,-1500);
		glEnd();	//glFlush();
		road();

		for(int i=0;i<=7;i++)
		{
			x[i]=x[i]+s;
		}
			cycle();
			glFlush();
			delay();
		}
	}
	
	void display()
	{
		cal();
		glColor3f(0.0,0.0,0.0);
		//cycle();
		road();
		//transform11();
		move();
		glFlush();
	}
	
	int main(int argc, char** argv) { 
		cout<<"Enter Speed\n";
		cin>>s;
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
