#include<stdio.h>
#include<GL/glut.h>
#include<process.h>
#include<string.h>

void apple();
void basket();
void display();
void board();
void myinit();
void key(unsigned char k,int x,int y);

int a1=300,a2=400,a3=470,a4=550,a5=1000,a6=1200,a7=1480,a8=1700,a9=1900,a10=2380,a11=2500,a12=2700,a13=2900;
int a14=3150,a15=3350,a16=3500,a17=3700,a18=3900,a19=4000,a20=4100,a21=4200,a22=4400,a23=4450,a24=4500,a25=4530;
int ap1=0,ap2=0,ap3=0,ap4=0,ap5=0,ap6=0,ap7=0,ap8=0,ap9=0,ap10=0,ap11=0,ap12=0,ap25=0;
int ap13=0,ap14=0,ap15=0,ap16=0,ap17=0,ap18=0,ap19=0,ap20=0,ap21=0,ap22=0,ap23=0,ap24=0;
int sc=0,fail=0,page=0,mo=0,m=-1;





void text(char *str,int x,int y)
{
	int len=strlen(str);
	glRasterPos2i(x,y);
	
	for(int i=0;i<len;i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
	}	
}

void titletext(char *str,int x,int y)
{
	int len=strlen(str);
	glRasterPos2i(x,y);
	
	for(int i=0;i<len;i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
	}	
}

void gameover(void)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	titletext("GAME OVER",200,300);
	glFlush();
	//glutPostRedisplay();
}

void quit(void)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1, 0, 0);
	titletext("q - to Quit",10,380);
	glFlush();
	//glutPostRedisplay();
}


void winner(void)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 1.0, 0.0);
	titletext("CONGRADULATIONS YOU WON!!!!!!",200,200);
	glFlush();
	//glutPostRedisplay();
}

void ins(void)
{glPushMatrix(); 
	
		glClear(GL_COLOR_BUFFER_BIT);
			
	   glColor3f(1,0,0);
	   text("--> Catch Apples,falling from top in to the Basket",180,300);
	   text("--> Use MOUSE to move the BASKET left and right",180,250);
	   text("--> Press ENTER to start",180,200);
	   text("--> Press q to Quit",180,150);
	glFlush();
	glPopMatrix();
}

void frontdisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.294, 0.000, 0.510);
	titletext("JAWAHARLAL NEHRU NATIONAL COLLEGE OF ENGINEERING, SHIVAMOGGA",160,900);

	glColor3f(0.545, 0.271, 0.075);
	text("DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",290,850);

	glColor3f(0.663, 0.663, 0.663);
	text("A MINI PROJECT ON",385,775);

	glColor3f(0.000, 0.502, 0.502);
	titletext("A GAME TO CATCH APPLES IN BASKET",300,700); 

	glColor3f(0.294, 0.000, 0.510);
	text("SUBMITTED BY:",400,600);
	
	glColor3f(0.502, 0.000, 0.000);
	text("SANATH M R",150,550);

	glColor3f(0.502, 0.000, 0.000);
	text("4JN14CS088",150,500);

	glColor3f(0.502, 0.000, 0.000);
	text("GANESH PRASAD",700,550);

	glColor3f(0.502, 0.000, 0.000);
	text("4JN14CS127",700,500);

	glColor3f(0.000, 0.545, 0.545);
	text("UNDER THE GUIDANCE OF:",370,425);
	
	glColor3f(0.502, 0.502, 0.000);
	text("Dr.Manjula G.R ",125,350);
	text("Assoc.Professor,",125,300);
	text("Dept. of CSE,JNNCE",125,250);

	text("Mrs. Ayesha Siddiqa",725,350);
	text("Lecturer,",725,300);
	text("Dept. of CSE,JNNCE",725,250);
	
	text("Mrs. Sushma R.B ",400,350);
	text("Assistant Professor,",400,300);
	text("Dept. of CSE,JNNCE",400,250);
	
	glColor3f(0.184, 0.310, 0.310);
	text("Press 'SPACE' to Next",390,100);	
	glFlush();
	
}

void update(int value)
{
	
if(a1>-115)	a1-=3+m;
if(a2>-110)	a2-=3+m;
if(a3>-100) a3-=3+m;
if(a4>-105) a4-=3+m;
if(a5>-100)	a5-=3+m;
if(a6>-100)	a6-=3+m;
if(a7>-101)	a7-=3+m;
if(a8>-102)	a8-=3+m;
if(a9>-116)	a9-=3+m;
if(a10>-102) a10-=3+m;
if(a11>-114) a11-=3+m;
if(a12>-121) a12-=3+m;
if(a13>-102) a13-=3+m;
if(a14>-114) a14-=3+m;
if(a15>-121) a15-=3+m;
if(a16>-102) a16-=3+m;
if(a17>-114) a17-=3+m;
if(a18>-121) a18-=3+m;
if(a19>-102) a19-=3+m;
if(a20>-114) a20-=3+m;
if(a21>-121) a21-=3+m;
if(a22>-102) a22-=3+m;
if(a23>-114) a23-=3+m;
if(a24>-121) a24-=3+m;
if(a25>-121) a25-=3+m;

glutPostRedisplay();
if(page!=3&&page!=4)
glutTimerFunc(1,update,0);
}


int dispapp(int ap,int Xaxis,int Yaxis)
{

if(ap==0)
	{
       if((mo<(Xaxis+60)&&mo>(Xaxis+15)&&Yaxis<-18&&Yaxis>-35))
		{
			ap=1;
			sc+=2;
		}
	  else
		{

			if(Yaxis<-99)
		        fail++;
			if(fail>2)
				page=3;
			glPushMatrix();
			glTranslated(Xaxis,Yaxis,0.0);   
			apple();							
			glPopMatrix();
		}
	
	}
return ap;
}





void display()
{  



	if(page==1)
	{glClear(GL_COLOR_BUFFER_BIT);
		ins();
		basket();
	}
	if(page==4)
	{
		//board();
		winner();
	}
    if(page==3)
		gameover();
	if(page==0)
		frontdisplay();
	if(page==2)
	{
	  fail=0;
	  glClear(GL_COLOR_BUFFER_BIT);
	  basket();
	  quit();
	  board();
	glColor3f(1.0,0.0,0.0);
	ap1=dispapp(ap1,40,a1);
	ap2=dispapp(ap2,100,a2);
	ap3=dispapp(ap3,300,a3);
	ap4=dispapp(ap4,40,a4);
	ap5=dispapp(ap5,160,a5);
	ap6=dispapp(ap6,300,a6);
	ap7=dispapp(ap7,70,a7);
	ap8=dispapp(ap8,40,a8);
	ap9=dispapp(ap9,60,a9);
	ap10=dispapp(ap10,100,a10);
	ap11=dispapp(ap11,300,a11);
	ap12=dispapp(ap12,40,a12);
	ap13=dispapp(ap13,160,a13);
	ap14=dispapp(ap14,320,a14);
	ap15=dispapp(ap15,70,a15);
	ap16=dispapp(ap16,40,a16);
	ap17=dispapp(ap17,60,a17);
	ap18=dispapp(ap18,100,a18);
	ap19=dispapp(ap19,300,a19);
	ap20=dispapp(ap20,40,a20);
	ap21=dispapp(ap21,160,a21);
	ap22=dispapp(ap22,320,a22);
	ap23=dispapp(ap23,70,a23);
	ap24=dispapp(ap24,80,a24);
	ap25=dispapp(ap25,279,a25);

	}


		if(sc==46&&fail==2&&a25<-115)
				page=4;
		if(sc==48&&fail==1&&a25<-115)
				page=4;
		if(sc==50&&fail==0&&a25<-115)
				page=4;
	glFlush();
	glutSwapBuffers();


}





void basket()
{
	glPushMatrix();  
	

	glColor3f(0.5,0.3,0.2);        //basket bottom
	  
	  glBegin(GL_QUADS);
	  glVertex2f(mo+10,40);
	  glVertex2f(mo+45,40);
	  glVertex2f(mo+55,95);
	  glVertex2f(mo+00,95);
	  glEnd();


	  glColor3f(0.01,0.0,0.0);   //basket top
	  glBegin(GL_POLYGON);
	  glVertex2f(mo+10,85);
	  glVertex2f(mo+45,85);
	  glVertex2f(mo+55,95);
	  glVertex2f(mo+45,105);
	  glVertex2f(mo+10,105);
	  glVertex2f(mo+00,95);
      glEnd();

	    glBegin(GL_QUADS);       //green ground
	  glColor3f(0.0,1.0,0.0);
	  glVertex2f(0,0);
	  glVertex2f(499,0);
	  glVertex2f(499,30);
	  glVertex2f(0,30);
	  glEnd();

	glPopMatrix();
}



void apple()
{
	 glColor3f(1.0,0.0,0.0);
	  glBegin(GL_POLYGON); 
	  glVertex2f(60,120);
	  glVertex2f(64,117);
	  glVertex2f(68,120);
	  glVertex2f(70,126);
	  glVertex2f(70,132);
	  glVertex2f(68,138);
	  glVertex2f(66,138);
	  glVertex2f(64,134);
	  glVertex2f(62,138);
	  glVertex2f(58,132);
	  glVertex2f(58,126);
	  glEnd();
      glColor3f(0.0,0.0,0.0);
	  glBegin(GL_LINES);
	  glVertex2f(64,134);
	  glVertex2f(62,146);
	  glEnd();
}




	
void My_mouse_routine(int x, int y)
{
  if(x>900)
	mo=450;
  else
	mo = x/2;

}


void board()
{

	  glColor3f(0.0,0.0,0.0);  //score board outline
	  glBegin(GL_QUADS);
      glVertex2f(448,348);
	  glVertex2f(482,348);
	  glVertex2f(482,382);
	  glVertex2f(448,382);
      glEnd();


	  glColor3f(1.0,1.0,1.0);   //score board
	  glBegin(GL_QUADS);
      glVertex2f(450,350);
	  glVertex2f(480,350);
	  glVertex2f(480,380);
	  glVertex2f(450,380);
      glEnd();
	
	glColor3f(1.0,0.0,0.0);     
     char str[100]="0001020304050607080910111213141516171819202122232425";
	 
	glRasterPos2f(460,360);
 
	for(int i=sc;i<sc+2;i++)
	{
		
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str[i]);
	}
	glFlush();
}
	  



void myinit()
{

	glClearColor(0.0,0.529,0.808,0.922);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,500.0,0.0,400.0);

}

void frontinit()
{
	glClearColor(0.941, 0.902, 0.549,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1000,0,1000,-100,100);
	glutPostRedisplay();	
}

void key(unsigned char k,int x,int y)
{  
	
	
	if(k==' ')
	{
			page=1;
	    
			glutPostRedisplay();;
		
	    
		myinit();
	}
	if(k==13) //aschi value of enter
	{
		page=2;
		glutTimerFunc(1,update,0);
		glutIdleFunc(basket);
	    glutIdleFunc(board);
		myinit();
	}
	if(k=='.')
	{
		mo+=30;
	}
	if(k==',')
	{
		mo-=30;
	}

	if(k=='q')
	{
		exit(0);
	}

}


void main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1366.0,718.0);
	glutCreateWindow("APPLES IN BASKET");
	
	glutSetCursor(GLUT_CURSOR_NONE);
	glutPassiveMotionFunc( My_mouse_routine );
	glutKeyboardFunc(key);
	frontinit();
    glutDisplayFunc(display);
	
	glEnable(GLUT_DEPTH);
	glutMainLoop();
}
