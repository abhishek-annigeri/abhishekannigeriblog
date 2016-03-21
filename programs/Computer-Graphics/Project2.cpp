
		#include<string.h>
		#include<GL/glut.h>
		#include<GL/glu.h>
		#include<GL/gl.h>
		#include<math.h>
		#include<iostream>
		using namespace std;
		
		void put_pixel(int x,int y)
			{
				glPointSize(3.0);
				glBegin(GL_POINTS);				        		
				glVertex2i(x,y);
				glEnd();
				glFlush();
			}

		void put_pixel1(float x,float y)
		{
			glPointSize(3.0);
			glBegin(GL_POINTS);				        		
			glVertex2f(x,y);
			glEnd();
			glFlush();
		}



	void dda1(int x1,int y1,int x2,int y2) {	
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
		put_pixel1(x1,y1);
		for(int i=1;i<=steps;i++)
		{
		x=x+incx;
		y=y+incy;
		put_pixel1(x,y);
		glFlush();
		}
	}

	void dda(int x1,int y1,int x2,int y2) {	
		int dx,dy,steps,incx=1,incy=1,x,y;
		dx=x2-x1;
		dy=y2-y1;
		if(abs(dx) > abs(dy))
			steps=abs(dx);
		else
			steps=abs(dy);
		incx=dx/(float)steps;
		incy=dy/(float)steps;
		x=x1;
		y=y1;
		put_pixel(x1,y1);
		for(int i=0;i<=steps;i++)
		{
		x=x+incx;
		y=y+incy;
		put_pixel(x,y);glFlush();
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

		void cal_discrete() {
			glClear(GL_COLOR_BUFFER_BIT);
			cord();
			glColor3f(1,0,0);			
			int n,i,ef=0;
			float rf[30],crf[300],f[30],l=0;
			float x[30],y[30];
			cout<<"enter the n (1-9)\n";
			cin>>n;
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
			for(i=1;i<=n;i++) {
				y[i]=crf[i]*100;
				x[i]=i*50;
				}
			dda(x[1],0,x[1],y[1]);
			glFlush();
			for(i=1;i<n;i++) {
				dda(x[i],y[i],x[i+1],y[i+1]);
				glFlush();	
				}
			for(i=1;i<n-1;i++) {
				dda(x[i+1],y[i],x[i+1],y[i+1]);
				glFlush();
				}
		cout<<"|-----------------------------------------------------------------------------|\n";
		cout<<"\n|\tx\t|f\t|"<<"Relative Frequency     |"<<"\tCummlative Frequency"<<endl;
		cout<<"------------------------------------------------------------------------------|\n";
		for(i=1;i<=n;i++) {
			cout<<"|\t"<<i<<"\t|"<<f[i]<<"\t|"<<rf[i]<<"     \t|\t"<<crf[i]<<endl;
			cout<<"|-----------------------------------------------------------------------------|\n";
			}

		glColor3f(0,0,0);	        
			char pt='.';
			char a[20]={'0','1','2','3','4','5','6','7','8','9'};
			int k=0;
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
		
				k=50;
			for (int i = 0,m=1; i<=9; i++,m++) {
				glRasterPos2i(k-5,-5);
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,a[m]);
				glFlush();
				k=k+50;
					}
	
			char t[50]="EMPERICAL DISTRIBUTION FOR DISCRETE DATA";
			for (int i = 0; i<=40; i++) {
				glRasterPos2i(70+(i*16),120);
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, t[i]);
				glFlush();
					}


			char t1[50]="Y Axis=Cummulative Relative Frequency";
			for (int i = 0; i<=40; i++) {
				glRasterPos2i(70+(i*10),-10);
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, t1[i]);
				glFlush();
					}
	
			char t2[50]="X Axis=Number Of Occurences";
			for (int i = 0; i<=40; i++) {
				glRasterPos2i(70+(i*10),-20);
				glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, t2[i]);
				glFlush();
					}
			glFlush(); 
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

//dda1(0,0,x[0],y[0]);
		for(i=0;i<n;i++) {
dda1(x[i],y[i],x[i+1],y[i+1]);
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




	void triangular() {
		glClear(GL_COLOR_BUFFER_BIT);
		cord();
		int a,b,c;
		float ex,h;
		cout<<"Enter a , b & c\n";	
		cin>>a>>b>>c;
		float x;
		if(a>b && b>c) {
			ex=a+b+c/3;
			h=(float)(2.0/(c-a));	
		}
		else {
			cout<<"Enter x from range(0 - 1)\n";
			cin>>x;
			if(b<=x && x<=c) {
				h=(2.0*(c-x)/((c-a)*(c-b)));
					}
			if(a<=x && x<=b) {
				cout<<"Enter x from range(0 - 1)\n";
				cin>>x;
				h=(2.0*(x-a)/((c-b)*(c-a)));
					}
			else {	
				cout<<"Invalid data\n";
				return;
				}
			}
		
		a=a*50-200;
		b=b*50;
		c=c*50+200;
		h=(h*-50);
		glRasterPos2i(a,-10);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'a');
		glRasterPos2i(b,-10);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'b');
	
		glRasterPos2i(c,-10);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'c');
	
		glRasterPos2i(-20,h);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,'h');
	
		glColor3f(0,0,0);	        		
		char t[50]="TRIANGULAR DISTRIBUTION";
		int l=strlen(t);
		for (int i = 0; i<=l; i++) {
			glRasterPos2i(70+(i*16),120);
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, t[i]);
			glFlush();
				}
	
		glColor3f(1,0,0);	        		
		glBegin(GL_LINES);
		glVertex2i(b,h);
		glVertex2i(b,0);
	
		glColor3f(0,1,0);	        		
		glVertex2i(b,h);
		glVertex2i(a,0);
	
		glColor3f(0,0,1);	        	
		glVertex2i(b,h);
		glVertex2i(c,0);

		glEnd();
		glFlush();	
		}
	

		void display()
		{
		glFlush();
		glColor3f(0,0,0);
		glLineWidth(3.0);
		glFlush(); 
			while(true)
			{ 
			cout<<"\n\n\n\t****Emperical Distribution & Trigular Distribution Using DDA Line Algorithm****\n";
			cout<<"\n\t\t1:Emperical Distribution For Discrete Data\n";
			cout<<"\t\t2:Emperical Distribution For Continuous Data\n";
			cout<<"\t\t3:Triangular Distribution\n";
			cout<<"\t\t4:Exit\n";
			cout<<"\n\t\tEnter Your Choice:\n";
			int ch;
			cin>>ch;
				switch(ch)
				{
					case 1: cal_discrete();break;
					case 2: cal_cont();break;
					case 3: triangular();break;
					case 4: exit(0);
					default : cout<<"Invalid Choice\n";
				}
			}
	}

void myinit()
		{	
			glClearColor(1,1,1,1);
			glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(0,0,0);	        
			gluOrtho2D(-50.0,1000.0,-50.0,130.0);
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
