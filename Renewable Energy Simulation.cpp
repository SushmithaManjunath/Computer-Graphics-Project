#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
#define pi 3.142


//____________________________- declarations
int id, sub_menu, id2, id3, id4;
int sc=0;
int i,angle;	//angle is used in sun 
GLfloat theta = 0.0;

//_____________________- function prototyping

void display4();							  //displaying of fan and all
void create_menu();						  //creating menu
void spin();								   //spining of fan
void myReshape4(int w, int h);		//reshape to fit maximized window

//____________________- function definations


//_______________________________________________________________________- text screen
void output(float x,float y,char *string) //big letters
{
	int len,i;
	glRasterPos2f(x,y);
	len=(int)strlen(string);
	for(i=0;i<len;i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
	}
}


void output1(float x1,float y1,char *string1) //small letters
{
	int len,i;
	glRasterPos2f(x1,y1);
	len=(int)strlen(string1);
	for(i=0;i<len;i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,string1[i]);
	}
}

void output2(float x1,float y1,char *string1) //small letters
{
	int len,i;
	glRasterPos2f(x1,y1);
	len=(int)strlen(string1);
	for(i=0;i<len;i++)
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24,string1[i]);
	}
}
//______________________________________________________________________________- text screen end


//______________________________________________________________________________- start of main screen


static double  x=0.0; //for speed of rotation

// _______________background grass,sea,sky using polygon structures

void background()
{
//glClear(GL_COLOR_BUFFER_BIT);

	//grass
glColor3f(0,0.6,0.25);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glColor3f(0,0.6,0.25);
glVertex2f(1360,0);
glColor3f(0,0.6,0.25);
glVertex2f(1360,350);
glColor3f(0,0.6,0.25);
glVertex2f(0,350);
glColor3f(0,0.6,0.25);
glEnd();

//sea
glColor3f(0.9,0.9,1);
glBegin(GL_POLYGON);
glVertex2f(0,350);
glColor3f(0.1,0.7,1);
glVertex2f(1360,350);
glColor3f(0.3,0.6,1);
glVertex2f(1360,400);
glColor3f(0.2,0.7,1);
glVertex2f(0,400);
glColor3f(0.2,0.7,1);
glEnd();

//sea shore
glColor3f(0,0.6,0.8);
glBegin(GL_LINES);
glLineWidth(2.0);
glVertex2f(0,350);
glColor3f(0.8,0.8,0.79);
glVertex2f(1360,350);
glColor3f(0.8,0.8,0.79);
glEnd();

//sky
glColor3f(0.9,0.9,0.95);
glBegin(GL_POLYGON);
glVertex2f(0,400);
glColor3f(0.4,0.5,1);
glVertex2f(1360,400);
glColor3f(0.3,0.5,1);
glVertex2f(1360,768);
glColor3f(0.3,0.4,1);
glVertex2f(0,768);
glColor3f(0.5,0.8,1);
glEnd();

glFlush();
}

//_________________________-draw house
void draw_house() //draw house in main screen
{
//glClear(GL_COLOR_BUFFER_BIT);

background(); //to draw background plane

glColor3f(0.6,0.6,0.6);			//front portion
glBegin(GL_POLYGON);
glVertex2f(500,200);
glColor3f(0.6,0.6,0.6);
glVertex2f(800,200);
glColor3f(0.6,0.6,0.6);
glVertex2f(800,450);
glColor3f(0.6,0.6,0.6);
glVertex2f(500,450);
glColor3f(0.6,0.6,0.6);
glEnd();

glColor3f(0.65,0.65,0.65);			//side portion
glBegin(GL_POLYGON);
glVertex2f(450,260);
glColor3f(0.65,0.65,0.65);
glVertex2f(500,200);
glColor3f(0.65,0.65,0.65);
glVertex2f(500,450);
glColor3f(0.65,0.65,0.65);
glVertex2f(450,510);
glColor3f(0.65,0.65,0.65);
glEnd();

glColor3f(0.6,0.6,0.6);					  //dark grey colour(0.6,0.6,0.6) or light brown color (0.8,0.3,0.1)
glBegin(GL_TRIANGLES);			// front portion triangle
glVertex2f(490,450);
glColor3f(0.6,0.6,0.6);
glVertex2f(810,450);
glColor3f(0.6,0.6,0.6);
glVertex2f(650,550);
glColor3f(0.6,0.6,0.6);
glEnd();

glColor3f(0.7,0.5,0.35);					 //light grey colour (0.65,0.65,0.65) or dark brown (0.7,0.5,0.35);
glBegin(GL_POLYGON);			//portion behind solar panel
glVertex2f(450,510);
glColor3f(0.7,0.5,0.35);
glVertex2f(490,450);
glColor3f(0.7,0.5,0.35);
glVertex2f(650,550);
glColor3f(0.7,0.5,0.35);
glVertex2f(600,610);
glColor3f(0.7,0.5,0.35);
glEnd();

glColor3f(0.7,0.5,0.3);				 //light grey colour (0.65,0.65,0.65) or dark brown (0.7,0.5,0.35);
glBegin(GL_POLYGON);			  //right side top portion beside the portion of solar panel
glVertex2f(650,550);
glColor3f(0.7,0.5,0.3);
glVertex2f(810,450);
glColor3f(0.7,0.5,0.3);
glVertex2f(760,500);
glColor3f(0.7,0.5,0.3);
glVertex2f(600,610);
glColor3f(0.7,0.5,0.3);
glEnd();

glColor3f(0,0,1); 
glBegin(GL_POLYGON);				//solar panel
glVertex2f(460,510);
glColor3f(0,0,1);
glVertex2f(495,465);
glColor3f(0,0,1);
glVertex2f(635,550);
glColor3f(0,0,1);
glVertex2f(600,600);
glColor3f(0,0,1);
glEnd();

glColor3f(0,0.1,0.2);							//doors
glBegin(GL_POLYGON);
glVertex2f(610,200);
glColor3f(1,0.3,0.2);
glVertex2f(690,200);
glColor3f(1,0.3,0.2);
glVertex2f(690,300);
glColor3f(1,0.6,0.2);
glVertex2f(610,300);
glColor3f(1,0.6,0.5);
glEnd();

glFlush();
}
//___________________-draw sun using triangle strip
void sun()
{
	glPushMatrix();
glTranslatef(500,720,0);
glColor3f(1,1,0);
glBegin(GL_TRIANGLE_STRIP);
for(i=0;i<360;i++)
{
	angle=(3.1415/4.0)*i;
	glVertex2f(40*cos(angle)+0.5,40*sin(angle)+0.5);
	glVertex2f(30*cos(angle)+0.5,30*sin(angle)+0.5);
	glVertex2f(0.5,0.5);
}
glEnd();
glPopMatrix();
glFlush();
}

//____________________-draw fan with 4 blades and stand using inbuilt functions

void fan()
{

	glTranslatef(1000,650,0);
	glRotatef(180,0.0f,0.0f,1.0f);

	//fan stand
	glColor3f(0.6,0.3,0.2);
	glPushMatrix();
	glTranslatef(0,200,0);
	glScaled(0.3,5,0.3);
	glutSolidCube(80);
	glPopMatrix();
	
	//fan blade 1
	glColor3f(0.65,0.65,0.65);
    glPushMatrix();
	glRotatef(x+=5,0.0f,0.0f,1.0f);
	glScaled(1.4,0.2,0.1);								// zoom in or out
	glRotatef(x+=5,0.0f,0.0f,1.0f);
	glutSolidSphere(80,200,60);
	glPopMatrix();

	//fan blade 2
	glColor3f(0.65,0.65,0.65);
	glPushMatrix();
	glRotatef(x+=5,0.0f,0.0f,1.0f);					//rotate with a (x=+5)speed of 5 in each rotation in z plane before scaling
	glScaled(0.2,1.4,0.1);						    	//scaled to make it small
	glRotatef(x+=5,0.0f,0.0f,1.0f);				   //rotate with a (x=+5)speed of 5 in each rotation in z plane after scaling
	glutSolidSphere(80,200,300);
	glPopMatrix();

	glFlush();

}

 //______________________-movement of rays

int m1[3]={740,720,760},a[8]={480,520,500,540,470,460,550,560}; //for ray starting points m1-->y a--> x

void raysofsun(void)		
{
	m1[0]-=5;
	if(m1[0]<500) m1[0]=740;

		m1[1]-=5;
	if(m1[1]<200) m1[1]=720;

	
	m1[2]-=5;
	if(m1[2]<200) m1[2]=760;

	a[0]-=10;
	if(a[0]<220) a[0]=480;

	a[1]+=10;
	if(a[1]>760) a[1]=520;

	a[2]+=10;
	if(a[2]>760) a[2]=500;

	a[3]-=10;
	if(a[3]<220) a[3]=540;

		a[4]-=10;
	if(a[4]<210) a[4]=470;

		a[5]-=10;
	if(a[5]<210) a[5]=460;

		a[6]+=10;
	if(a[6]>760) a[6]=550;

		a[7]+=10;
	if(a[7]>760) a[7]=560;

}

//________________-to draw rays( rp-->ray parts)
void rp() 
{
	
	glLineWidth(5);
	glColor3f(1,1,0);

	glBegin(GL_LINES);
	glVertex3i(475,m1[0],0);
	glVertex3i(475,m1[0]-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(a[0],m1[1],0);
	glVertex3i(a[0],m1[1]-15,0);
	glEnd();


	glBegin(GL_LINES);
	glVertex3i(a[1],m1[1],0);
	glVertex3i(a[1],m1[1]-15,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(a[2],m1[0],0);
	glVertex3i(a[2],m1[0]-15,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(490,m1[0],0);
	glVertex3i(490,m1[0]-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(505,m1[0],0);
	glVertex3i(505,m1[0]-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(520,m1[0],0);
	glVertex3i(520,m1[0]-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(535,m1[0],0);
	glVertex3i(535,m1[0]-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(550,m1[0],0);
	glVertex3i(550,m1[0]-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(a[3],m1[2],0);
	glVertex3i(a[3],m1[2]-15,0);
	glEnd();

		glBegin(GL_LINES);
	glVertex3i(a[4],m1[2],0);
	glVertex3i(a[4],m1[2]-15,0);
	glEnd();

		glBegin(GL_LINES);
	glVertex3i(a[5],m1[2],0);
	glVertex3i(a[5],m1[2]-15,0);
	glEnd();

		glBegin(GL_LINES);
	glVertex3i(a[6],m1[2],0);
	glVertex3i(a[6],m1[2]-15,0);
	glEnd();

		glBegin(GL_LINES);
	glVertex3i(a[7],m1[2],0);
	glVertex3i(a[7],m1[2]-15,0);
	glEnd();

}

//_______________-drawing of bgi-->(battery generator invertor/dc) in main screen
void bgi() 
{
	glColor3f(1,1,1);
	glBegin(GL_POLYGON); //invertor / dc
	glVertex3i(550,420,0);
	glVertex3i(620,420,0);
	glVertex3i(620,460,0);
	glVertex3i(550,460,0);
	glEnd();

	glBegin(GL_POLYGON); //batteries
	glVertex3i(500,200,0);
	glVertex3i(560,200,0);
	glVertex3i(560,250,0);
	glVertex3i(500,250,0);
	glEnd();

		glBegin(GL_POLYGON); //generator
	glVertex3i(720,200,0);
	glVertex3i(770,200,0);
	glVertex3i(770,270,0);
	glVertex3i(720,270,0);
	glEnd();
	glFlush();
}

//_____________________-connecting wires
void wires() 
{
glColor3f(0.3,0.3,0.8);					//color of the wire is light purple or blue(0,0,1)

glBegin(GL_LINES);					//connecting wires between panel and invertor
glVertex3i(580,460,0);
glVertex3i(580,520,0);
glEnd();

glBegin(GL_LINES);					//connecting wires between invertor and batteries
glVertex3i(552,420,0);
glVertex3i(552,250,0);
glEnd();

glBegin(GL_LINES);					 //connecting wires between invertor and mill
glVertex3i(620,440,0);
glVertex3i(790,440,0);
glEnd();

glBegin(GL_LINES);					 //connecting wires between invertor and mill
glVertex3i(788,440,0);
glVertex3i(788,180,0);
glEnd();

glBegin(GL_LINES);					//connecting wires between invertor and mill
glVertex3i(786,178,0);
glVertex3i(1000,178,0);
glEnd();

glBegin(GL_LINES);					//connecting wires between invertor and mill
glVertex3i(997,180,0);
glVertex3i(997,250,0);
glEnd();

glBegin(GL_LINES);					//connecting wires between invertor and generator
glVertex3i(730,270,0);
glVertex3i(730,425,0);
glEnd();

glBegin(GL_LINES);					 //connecting wires between invertor and generator
glVertex3i(560,425,0);
glVertex3i(732,425,0);
glEnd();

glFlush();
}

//structures are used in construction of trees
typedef struct
{
	int x;
	int y;
}point;


typedef struct
{
	int x,y,font;
}tr;

double inc=pi/6,ang1=3*pi/2;	//tree construction
point pp,pq;

//used to draw  tree
 point getpoint(int x,int y,int a,int b,double t)
{
	point s;
	s.x=x+a*cos(t);
   s.y=y+b*sin(t);
	return s;
} 

 tr ts1[8]={{350,350,3},{200,320,2},{950,340,2},{1100,320,3},{1250,320,2}}; // postion to construct trees ... used in main screen

//to draw tree
 void tree(GLint x,GLint y,GLint font)
{
GLfloat inc,p,q,r,s,a,b,t1,t2;
inc=font*10;
p=x+inc;
r=x-inc;
q=s=y;
a=font*5;
b=font*20;
t2=3*pi/2;
t1=pi/2;
	
glColor3f(0.7,0.2,0.1);

 point p1,p2;
 double ang1=3*pi/2,ang2=3*pi/2;
while(ang2>=pi/2)								// to draw the stem of tree
 {
	 p1=getpoint(p,q,a,b,ang2);
	p2=getpoint(r,s,a,b,ang1);
	glColor3f(0.7,0.2,0.1);		
	glBegin(GL_LINES);
		glVertex2f(p1.x,p1.y);
		glVertex2f(p2.x,p2.y);
		glEnd();
		
		ang1+=0.01;
		ang2-=0.01;
 }

b=font*50;
a=font*15;
glColor3f(0,0.8,0.1122);	

point pp,pq;
glColor3f(0,0.8,0.1122);					//color and code to draw the leaves of the tree
 glBegin(GL_POLYGON);
   for(double i=0;i<pi;i+=0.3142)
   {
      pp=getpoint(x,y+font*10,a,b,i);
		  pq=getpoint(x,y+font*10,a+10,b+10,i+0.1571);
		  glVertex2f(pp.x,pp.y);
           glVertex2f(pq.x,pq.y);
   }
   pp=getpoint(x,y+font*10,a,b,i);
   glVertex2f(pp.x,pp.y);
  glEnd(); 

  glFlush();
 glutPostRedisplay();
}

 //calling tree func
 void d1()
{
	for(int i=0;i<5;i++)			//draw 5 trees
 tree(ts1[i].x,ts1[i].y,ts1[i].font);

}

void init2()							//used for main screen
{
glClearColor(0,0,0,0);
glOrtho(0,1360,0,768,-20,200);
}

void display2(void)
{
	
glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	draw_house();
	sun();
	wires();
	rp();
	bgi();
		d1();			//tree
	glPopMatrix();

	glPushMatrix();
	fan();
	glPopMatrix();

	glColor3f(0,0,1);			output(520,220,"1");	
   
	glColor3f(0,0,1);			output(740,230,"2");

	glColor3f(0,0,1);			output(590,430,"3");

	glColor3f(0,0,1);			output(100,100,"1->Battery");	

	glColor3f(0,0,1);			output(100,80,"2->Generator");	

	glColor3f(0,0,1);			output(100,60,"3->Invertor/Dc Service Enterance");

	glColor3f(0,0,1);			output(1100,100,"Right Click for Menu");

glFlush();

glutPostRedisplay();
	glFlush();

glutSwapBuffers();

	create_menu();
}
//____________________________________________________________________________________- end of main screen


//____________________________________________________________________________________- start of solar panel working screen

//_______________-drawinf of solar rays

int r=450,r1=440,x1=250,x2=240,x3=260,x4=270,x5=275,x6=280;;	//r,r1 for rays size and y axis  and   x1,x2,x3,x4 for x axis decrement
int c1=336,c2=328;																			//for flow of current in solar panel screen

void rays(void)
{
	r-=5;
	if(r<200) r=450;

	r1-=5;
	if(r1<200) r1=450;

		x1-=5;
	if(x1<80) x1=250;

		x2-=5;
	if(x2<80) x2=240;

		x3+=5;
	if(x3>550) x3=260;

		x4+=5;
	if(x4>550) x4=270;

		x5-=5;
	if(x5<80) x5=275;

		x6+=5;
	if(x6>510) x6=280;
// to draw curent in solar panel screen
		c1+=10;
	if(c1>388) c1=336;

			c2+=10;
	if(c2>384) c2=328;
	glutPostRedisplay();
	
}

void init3()							// used in solar panel screen
{
	glOrtho(0,500,0,500,-20,200);
	glClearColor(0,0.7,0.9,0);
}

//__________________-constuction of solar panels
void panel() 
{
	int i,j;
	
	//solar panels background black sheet
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex3i(100,200,0);
	glVertex3i(250,200,0);
	glVertex3i(250,300,0);
	glVertex3i(100,300,0);
	glEnd();

	for(i=100;i<=250;i+=10)
	{	
		//vertical lines
		glColor3f(0,0,1); 
		glBegin(GL_LINES);				//intialy from left line (100,200) and (100,300)
		glVertex3i(i,200,0);
		glVertex3i(i,300,0);
		glEnd();
	}

	for(j=300;j>=200;j-=10)	
	{
		//horizontal lines
		glColor3f(0,0,1);
		glBegin(GL_LINES);
		glVertex3i(100,j,0);				//intially from top line (100,300) and (250,300)
		glVertex3i(250,j,0);
		glEnd();
	}
	glFlush();

}

//___________________-draw front view of transparent house

	int f1=1,f2; 	// used for flickering effect of bulb in working of solar panel screen
void house()
{
	
	// front view of house wall
	glColor3f(0.4,0.5,0.8);					//light blue(0.4,0.5,0.8)
	glBegin(GL_POLYGON);				//or draw line loop with color(1,0,0);
	glVertex3i(370,100,0);
	glVertex3i(440,100,0);
	glVertex3i(440,220,0);
	glVertex3i(370,220,0);
	glEnd();

	//door of the house
	glColor3f(0,0.1,0.2);
	glBegin(GL_POLYGON);
	glVertex3i(390,100,0);
	glColor3f(1,0.3,0.2);
	glVertex3i(410,100,0);
	glColor3f(1,0.6,0.2);
	glVertex3i(410,150,0);
	glColor3f(1,0.6,0.2);
	glVertex3i(390,150,0);
	glColor3f(1,0.6,0.5);
	glEnd();

	//top roof(triangle)
	glColor3f(0.7,0.5,0.35);			//light brown color(0.7,0.5,0.3)
	glBegin(GL_POLYGON);
	glVertex3i(370,220,0);
	glVertex3i(440,220,0);
	glVertex3i(405,300,0);
	glEnd();

// right side of house
	glColor3f(0.4,0.4,0.6);
	glBegin(GL_POLYGON);
	glVertex3i(440,100,0);
	glVertex3i(470,120,0);
	glVertex3i(470,240,0);
	glVertex3i(440,220,0);
	glEnd();

//top right side of house(right of triangle)
	glColor3f(0.7,0.4,0.3);					//brown color(0.7,0.4,0.3)
	glBegin(GL_POLYGON);
	glVertex3i(440,220,0);
	glVertex3i(470,240,0);
	glVertex3i(435,310,0);
	glVertex3i(405,300,0);
	glEnd();

	//wire from panel to house
	glColor3f(1,0.7,0.5);
	glBegin(GL_POLYGON);
	glVertex3i(330,190,0);
	glVertex3i(380,190,0);
	glVertex3i(380,200,0);
	glVertex3i(330,200,0);
	glEnd();

	//extension to connect bulb
	glBegin(GL_POLYGON);
	glVertex3i(380,192,0);
	glVertex3i(390,192,0);
	glVertex3i(390,198,0);
	glVertex3i(380,198,0);
	glEnd();

	//dc enterance
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex3i(350,185,0);
	glVertex3i(360,185,0);
	glVertex3i(360,205,0);
	glVertex3i(350,205,0);
	glEnd();
	glColor3f(0,0,1);	output(352,190,"1");

	//bulb with flickering effect
	glPushMatrix();						
	glTranslatef(393,195,20);
	glScalef(1.3,1.8,1.5);
										//code to get flickering effect
	if(f1) {f2=1;f1=0;}
    else  {f1=1;f2=0;}
	if(f1==1) glColor3f(1,1,0);
	else glColor3f(0.7,0.7,0);

	glutWireSphere(5,15,20);			//wire sphere to draw bulb
	glPopMatrix();

	glColor3f(0,0,1);	output(400,195,"Bulb");
	glFlush();

}

//_____________________-draw solar rays
void sr()
{
		glLineWidth(5);
	glColor3f(1,1,0);

	
	glBegin(GL_LINES);
	glVertex3i(190,r1,0);
	glVertex3i(190,r1-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(200,r1,0);
	glVertex3i(200,r1-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(210,r1,0);
	glVertex3i(210,r1-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(220,r1,0);
	glVertex3i(220,r1-20,0);
	glEnd();
		

	glBegin(GL_LINES);
	glVertex3i(230,r1,0);
	glVertex3i(230,r1-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(240,r,0);
	glVertex3i(240,r-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(250,r,0);
	glVertex3i(250,r-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(260,r,0);
	glVertex3i(260,r-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(270,r1,0);
	glVertex3i(270,r1-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(280,r1,0);
	glVertex3i(280,r1-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(290,r1,0);
	glVertex3i(290,r1-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(300,r1,0);
	glVertex3i(300,r1-20,0);
	glEnd();
	
	//slant rays
	glBegin(GL_LINES);
	glVertex3i(x1,r1,0);
	glVertex3i(x1-2,r1-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(x2,r1,0);
	glVertex3i(x2-2,r1-20,0);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex3i(x3,r1,0);
	glVertex3i(x3+2,r1-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(x4,r1,0);
	glVertex3i(x4+2,r1-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(x5,r1,0);
	glVertex3i(x5+2,r1-20,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3i(x6,r1,0);
	glVertex3i(x6+2,r1-20,0);
	glEnd();

	glLineWidth(2);
}

//same function as tree but without the code for tree stem
void big_grass(GLint x,GLint y,GLint font)
{
GLfloat inc,p,q,r,s,a,b,t1,t2;
inc=font*10;
p=x+inc;
r=x-inc;
q=s=y;
a=font*5;
b=font*20;
t2=3*pi/2;
t1=pi/2;

 double ang1=3*pi/2,ang2=3*pi/2;

b=font*50;
a=font*15;
glColor3f(0,0.8,0.1122);				//color for big grass

point pp,pq;
glColor3f(0.5,0.9,0.3122);				//color for big grass

//big grass
 glBegin(GL_POLYGON);
   for(double i=0;i<pi;i+=0.3142)
   {
      pp=getpoint(x,y+font*10,a,b,i);
		  pq=getpoint(x,y+font*10,a+10,b+10,i+0.1571);
		  glVertex2f(pp.x,pp.y);
           glVertex2f(pq.x,pq.y);
   }
   pp=getpoint(x,y+font*10,a,b,i);
   glVertex2f(pp.x,pp.y);
  glEnd(); 
}

tr ts2[8]={{80,350,1.8},{150,300,2},{220,370,1},{320,350,2},{440,350,1}};  //parameters are x,y, size of tree in  solar panel screen

void d2()
{
	for(int i=0;i<7;i++)  //draw 7 trees
 tree(ts2[i].x,ts2[i].y,ts2[i].font);
}

tr ts3[8]={{40,0,1},{100,0,1},{220,0,1},{410,0,1},{460,0,1}};	//used in solar panel screen

void d3()
{
	for(int i=0;i<5;i++)		//draw 5 big grasses
 big_grass(ts3[i].x,ts3[i].y,ts3[i].font);
}

void cur()						//draw flow of current in solar panel screen
{
	glLineWidth(7.0);
	glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex3i(c1,195,0);
	glVertex3i(c1+3,195,0);
	glEnd();

		glBegin(GL_LINES);
	glColor3f(1,0,0);
	glVertex3i(c2,195,0);
	glVertex3i(c2+3,195,0);
	glEnd();
}

void display3(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(0,0,0);
	background();						//draw background same used in main screen
	glPopMatrix();

	//drawing sun and translation
	glPushMatrix();
		glTranslatef(250,450,20);
		glColor3f(1,0.8,0);
		glutSolidSphere(20,500,500);
	glPopMatrix();

	glPushMatrix();
		house();							 //draw house
		cur();								   //draw current
		glutPostRedisplay();
	glPopMatrix();

	
	//panel rotation to look like 3D
	glPushMatrix();
	glLineWidth(4.0);
	glRotatef(-20,0,0,1);
	glColor3f(0,0.4,0);
	panel();								//draw panel
	glPopMatrix();

	glPointSize(2);


	sr();				  //drawing sun rays
	d2();				//tree
	d3();				//to draw big grass
	//glFlush();
		glColor3f(0,0,1);	output(70,75,"1. DC enterance");
		glColor3f(0,0,1);	output(410,75,"* Right click for menu *");
glutPostRedisplay();
	glFlush();

glutSwapBuffers();
	create_menu();
}
//_______________________________________________________________________________- end of solar panel working screen

//_______________________________________________________________________________-start of windmill working
//vertices to draw the blades and wind arrows
GLfloat vertices[][3]={{-1.26,-0.06,-0.06},{-1.16,-0.06,-0.06},{-1.16,1.00,-0.06},{-1.20,1.00,-0.06},{-1.26,-0.06,0.06},{-1.16,-0.06,0.06},{-1.16,1.00,0.06},{-1.20,1.00,0.06}};
GLfloat vertices1[][3]={{-1.36,-0.06,-0.86},{-1.32,-0.06,-0.86},{-1.32,0.06,-0.86},{-1.36,0.06,-0.86},{-1.26,-0.06,0.06},{-1.16,-0.06,0.06},{-1.16,0.06,0.06},{-1.26,0.06,0.06}};
GLfloat vertices2[][3]={{-1.26,-0.06,-0.06},{-1.16,-0.06,-0.06},{-1.16,0.06,-0.06},{-1.26,0.06,-0.06},{-1.26,-0.06,0.86},{-1.22,-0.06,0.86},{-1.22,0.06,0.86},{-1.26,0.06,0.86}};
GLfloat vertices3[][3]={{-1.26,-0.02,-0.06},{-0.18,-0.02,-0.06},{-0.18,0.06,-0.06},{-1.26,0.06,-0.06},{-1.26,-0.02,0.06},{-0.18,-0.02,0.06},{-0.18,0.06,0.06},{-1.26,0.06,0.06}};
GLfloat vertices4[][3]={{-0.48,-0.02,-0.06},{0.24,-0.02,-0.06},{0.24,0.04,-0.04},{-0.48,0.04,-0.04},{-0.48,-0.02,0.06},{0.24,-0.02,0.06},{0.24,0.04,0.04},{-0.48,0.04,0.04}};


//color for these blades and wind arrows
GLfloat colors[][3]={{0.8,0.8,0.9},{0.0,0.0,0.0},{0.8,0.8,0.9},{1.0,1.0,1.0},{0.8,0.8,0.9},{1.0,1.0,1.0},{0.8,0.8,0.9},{1.0,1.0,1.0}};
GLfloat colors1[][3]={{0.8,0.8,0.9},{0.0,0.0,0.0},{0.8,0.8,0.9},{1.0,1.0,1.0},{0.8,0.8,0.9},{1.0,1.0,1.0},{0.8,0.8,0.9},{1.0,1.0,1.0}};
GLfloat colors2[][3]={{0.8,0.8,0.9},{0.0,0.0,0.0},{0.8,0.8,0.9},{1.0,1.0,1.0},{0.8,0.8,0.9},{1.0,1.0,1.0},{0.8,0.8,0.9},{1.0,1.0,1.0}};
GLfloat colors3[][3]={{0.8,0.8,0.9},{0.0,0.0,0.0},{0.8,0.8,0.9},{1.0,1.0,1.0},{0.8,0.8,0.9},{1.0,1.0,1.0},{0.8,0.8,0.9},{1.0,1.0,1.0}};
GLfloat colors4[][3]={{0.8,0.8,0.9},{0.0,0.0,0.0},{0.8,0.8,0.9},{1.0,1.0,1.0},{0.8,0.8,0.9},{1.0,1.0,1.0},{0.8,0.8,0.9},{1.0,1.0,1.0}};


//normal is required in 3D screen to get color distrubution correctly
GLfloat normals[][3]={{-0.5,-0.5,-0.5},{0.5,-0.5,-0.5},{0.5,0.5,-0.5},{-0.5,0.5,-0.5},{-0.5,-0.5,0.5},{0.5,-0.5,0.5},{0.5,0.5,0.5},{-0.5,0.5,0.5}};

//polygon fun is used to draw the wind turbine
void polygon(int a,int b,int c,int d)
{
// blades used colors,normals,vertices
glBegin(GL_POLYGON);

glColor3fv(colors[a]);
glNormal3fv(normals[a]);
glVertex3fv(vertices[a]);

glColor3fv(colors[b]);
glNormal3fv(normals[b]);
glVertex3fv(vertices[b]);

glColor3fv(colors[c]);
glNormal3fv(normals[c]);
glVertex3fv(vertices[c]);

glColor3fv(colors[d]);
glNormal3fv(normals[d]);
glVertex3fv(vertices[d]);

glEnd();


// blades used colors1,normals,vertices1
glBegin(GL_POLYGON);

glColor3f (1.0,0.6,1.0);

glColor3fv(colors1[a]);
glNormal3fv(normals[a]);
glVertex3fv(vertices1[a]);

glColor3fv(colors1[b]);
glNormal3fv(normals[b]);
glVertex3fv(vertices1[b]);

glColor3fv(colors1[c]);
glNormal3fv(normals[c]);
glVertex3fv(vertices1[c]);

glColor3fv(colors1[d]);
glNormal3fv(normals[d]);
glVertex3fv(vertices1[d]);

glEnd();

// blades used colors2,colors1,normals,vertices2

glBegin(GL_POLYGON);

glColor3f (1.0,0.6,1.0);

glColor3fv(colors2[a]);
glNormal3fv(normals[a]);
glVertex3fv(vertices2[a]);

glColor3fv(colors1[b]);
glNormal3fv(normals[b]);
glVertex3fv(vertices2[b]);

glColor3fv(colors2[c]);
glNormal3fv(normals[c]);
glVertex3fv(vertices2[c]);

glColor3fv(colors2[d]);
glNormal3fv(normals[d]);
glVertex3fv(vertices2[d]);

glEnd();


//extension of blades used colors3,normals,vertices3
glBegin(GL_POLYGON);

glColor3f (1.0,0.6,1.0);

glColor3fv(colors3[a]);
glNormal3fv(normals[a]);
glVertex3fv(vertices3[a]);

glColor3fv(colors3[b]);
glNormal3fv(normals[b]);
glVertex3fv(vertices3[b]);

glColor3fv(colors3[c]);
glNormal3fv(normals[c]);
glVertex3fv(vertices3[c]);

glColor3fv(colors3[d]);
glNormal3fv(normals[d]);
glVertex3fv(vertices3[d]);

glEnd();


// extension of fan used colors4,normals,vertices4
glBegin(GL_POLYGON);

glColor3f (1.0,0.6,1.0);

glColor3fv(colors4[a]);
glNormal3fv(normals[a]);
glVertex3fv(vertices4[a]);

glColor3fv(colors4[b]);
glNormal3fv(normals[b]);
glVertex3fv(vertices4[b]);

glColor3fv(colors4[c]);
glNormal3fv(normals[c]);
glVertex3fv(vertices4[c]);

glColor3fv(colors4[d]);
glNormal3fv(normals[d]);
glVertex3fv(vertices4[d]);

glEnd();

}

//_____________________- displayinf of fan and its extensions

void colorcube(void)
{
polygon(0,3,2,1);
polygon(2,3,7,6);
polygon(0,4,7,3);
polygon(1,2,6,5);
polygon(4,5,6,7);
polygon(0,1,5,4);
}

//______________- draw current flow

float p1=0,q2=0,q3=0;  //p used instead of x, and q used instead of  y

void current()
{
//horizontal flow of current

glBegin(GL_POLYGON);
glColor3f(1,0,0);
glVertex2f(-0.05+p1,-1.630);
glVertex2f(-0.10+p1,-1.630);
glVertex2f(-0.10+p1,-1.670);
glVertex2f(-0.05+p1,-1.670);
glVertex2f(-0.05+p1,-1.700);
glVertex2f(-0.01+p1,-1.654);
glVertex2f(-0.05+p1,-1.600);
glEnd();

//down flow of current
glBegin(GL_POLYGON);
glColor3f(1,0,0);
glVertex2f(-0.11,-0.40+q2);
glVertex2f(-0.14,-0.40+q2);
glVertex2f(-0.09,-0.46+q2);
glVertex2f(-0.05,-0.40+q2);
glVertex2f(-0.07,-0.40+q2);
glVertex2f(-0.07,-0.35+q2);
glVertex2f(-0.11,-0.35+q2);
glEnd();

//upflow of current

glBegin(GL_POLYGON);
glColor3f(1,0,0);
glVertex2f(1.77,-1.5+q3);
glVertex2f(1.77,-1.5+q3);
glVertex2f(1.77,-1.56+q3);
glVertex2f(1.72,-1.56+q3);
glVertex2f(1.72,-1.56+q3);
glVertex2f(1.72,-1.56+q3);
glVertex2f(1.72,-1.50+q3);

glEnd();
glFlush();
}

//____________________- to draw wind 
void draw_arrow()
{
//glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
glColor3f(1,1,1);
glVertex2f(-2.90+p1,0.750);
glVertex2f(-3.0+p1,0.750);
glVertex2f(-3.0+p1,0.700);
glVertex2f(-2.90+p1,0.700);
glVertex2f(-2.90+p1,0.650);
glVertex2f(-2.84+p1,0.720);
glVertex2f(-2.90+p1,0.8);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1,1,1);
glVertex2f(-2.90+p1,0.400);
glVertex2f(-3.0+p1,0.400);
glVertex2f(-3.0+p1,0.350);
glVertex2f(-2.90+p1,0.350);
glVertex2f(-2.90+p1,0.300);
glVertex2f(-2.84+p1,0.370);
glVertex2f(-2.90+p1,0.450);
glEnd();
	 

glBegin(GL_POLYGON);
glColor3f(1,1,1);
glVertex2f(-2.90+p1,0.100);
glVertex2f(-3.0+p1,0.100);
glVertex2f(-3.0+p1,0.050);
glVertex2f(-2.90+p1,0.050);
glVertex2f(-2.90+p1,0.000);
glVertex2f(-2.84+p1,0.070);
glVertex2f(-2.90+p1,0.150);
glEnd();
	 


glBegin(GL_POLYGON);
glColor3f(1,1,1);
glVertex2f(-2.90+p1,-0.200);
glVertex2f(-3.0+p1,-0.200);
glVertex2f(-3.0+p1,-0.250);
glVertex2f(-2.90+p1,-0.250);
glVertex2f(-2.90+p1,-0.300);
glVertex2f(-2.84+p1,-0.230);
glVertex2f(-2.90+p1,-0.150);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1,1,1);
glVertex2f(-2.90+p1,-0.500);
glVertex2f(-3.0+p1,-0.500);
glVertex2f(-3.0+p1,-0.550);
glVertex2f(-2.90+p1,-0.550);
glVertex2f(-2.90+p1,-0.600);
glVertex2f(-2.84+p1,-0.530);
glVertex2f(-2.90+p1,-0.450);
glEnd();
glFlush();

}




//__________________-to draw house front view
void house1()
{
	glPushMatrix();
	glLineWidth(10);
	glColor3f(0.7,0.3,0.1);
	glBegin(GL_LINE_LOOP);	//front portion
	glVertex3f(1,-1,0);
	glVertex3f(2,-1,0);
	glVertex3f(2,0,0);
	glVertex3f(1,0,0);
	glEnd();

	glColor3f(0.7,0.3,0.1);
	glBegin(GL_LINE_LOOP);	//top portion
	glVertex3f(1.0,0,0);
	glVertex3f(2.0,0,0);
	glVertex3f(1.5,0.8,0);
	glEnd();

	glColor3f(0.7,0.3,0.1);
	glBegin(GL_LINE_LOOP);	//right side portion
	glVertex3f(2,-1,0);
	glVertex3f(3.1,-1,0);
	glVertex3f(3.1,0,0);
	glVertex3f(2,0,0);
	glEnd();

	glColor3f(0.7,0.3,0.1);
	glBegin(GL_LINE_LOOP); //right side top portion
	glVertex3f(2.0,0,0);
	glVertex3f(3.1,0,0);
	glVertex3f(2.7,0.8,0);
	glVertex3f(1.5,0.8,0);
	glEnd();

	glColor3f(0.7,0.3,0.1);
	glBegin(GL_LINE_LOOP);	//door of the house
	glVertex3f(1.3,-1,0);
	glVertex3f(1.6,-1,0);
	glVertex3f(1.6,-0.6,0);
	glVertex3f(1.3,-0.6,0);
	glEnd();

	glFlush();
	glutPostRedisplay();
	glPopMatrix();
	glLineWidth(1.0);
}

//____________________- to draw outerparts like stand ,wires of current flow

void draw_outerparts()
{
	//intermediate processings
glBegin(GL_POLYGON);
glColor3f(0.6,0.6,0.6);
glVertex3f(0.8,-1.9,-1.7);
glVertex3f(0.8,-1.30,-1.7);
glVertex3f(1.3,-1.30,-1.7);
glVertex3f(1.3,-1.9,-1.7);
glEnd();

	glColor3f(1,1,0);	output1(0.85,-1.6,"Intermediates");
	glColor3f(1,0,0);	output1(1.55,-1.45,"DC enterance");

//dc service enterance
glBegin(GL_POLYGON);
glColor3f(1,1,1);
glVertex3f(1.50,-1.35,-1.7);
glVertex3f(1.50,-1.5,-1.7);
glVertex3f(2.0,-1.5,-1.7);
glVertex3f(2.0,-1.35,-1.7);
glEnd();

	//down stream wire from fan
glBegin(GL_POLYGON);
glColor3f(0.8,0.8,0.9);
glVertex3f(-0.18,-0.0,-1.0);
glVertex3f(-0.18,-1.7,-1.0);
glVertex3f(-0.01,-1.7,-1.0);
glVertex3f(-0.01,-0.0,-1.0);
glEnd();

//lower portion of horizontal wire
glBegin(GL_POLYGON);
glColor3f(0.8,1,0);
glVertex3f(-0.20,-1.70,-1.7);
glVertex3f(-0.20,-1.750,-1.7);
glVertex3f(1.70,-1.75,-1.7);
glVertex3f(1.70,-1.70,-1.7);
glEnd();

// cross joining of wires by insulation
glBegin(GL_POLYGON);
glColor3f(1,0,0);
glVertex3f(1.70,-1.70,-1.7);
glVertex3f(1.70,-1.75,-1.7);
glVertex3f(1.8,-1.69,-1.7);
glVertex3f(1.8,-1.64,-1.7);
glEnd();

//upper portion of horizontal wires
glBegin(GL_POLYGON);
glColor3f(0.8,0.8,0.9);
glVertex3f(-0.20,-1.61,-1.7);
glVertex3f(-0.20,-1.70,-1.7);
glVertex3f(1.70,-1.70,-1.7);
glVertex3f(1.62,-1.61,-1.7);
glEnd();

//joining wires
glBegin(GL_POLYGON);
glColor3f(0.8,0.8,0.9);
glVertex3f(1.72,-1.56,-1.7);
glVertex3f(1.62,-1.61,-1.7);
glVertex3f(1.70,-1.70,-1.7);
glVertex3f(1.8,-1.64,-1.7);
glEnd();

//upper wire to connect to house
glBegin(GL_POLYGON);
glColor3f(0.8,0.8,0.9);
glVertex3f(1.80,-0.85,-1.7);
glVertex3f(1.80,-1.70,-1.7);
glVertex3f(1.70,-1.75,-1.7);
glVertex3f(1.70,-0.85,-1.7);
glEnd();

glFlush();
}

int f3=1,f4;	// used for flickering effect of bulb in working of wind mill screen
void bulb()
{
		glPushMatrix();
		if(f3) {f4=1;f3=0;}
		else  {f3=1;f4=0;}
		if(f3==1)glColor3f(1,0.5,0);
		else glColor3f(1,1,0);
		glTranslatef(1.75,-0.77,0.05);
		glScalef(0.015,0.015,0.015);
		glutWireSphere(6,20,20);
		glFlush();
		glutPostRedisplay();
		glPopMatrix();
	}


void init4()											//used for working of wind mill screen
{
	glClearColor(0,0,0,1);
	gluOrtho2D(0.0,1360.0,0.0,768.0);
}

void myReshape4(int w,int h)				//used reshape function for working of wind mill screen
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else
		glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.5, 0.0, -5.0);  //viewing transform 
     //glScalef(1.5, 1.5, 1.5);
}

void spin()							//used to spin the windmill fan
{
	theta +=1.5;					//rotate with a speed of 1.5
	if(theta > 360)theta -=360;
	glutPostRedisplay();
}


void display4(void)
{

glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
glLoadIdentity();

	if(p1<1.6 )
p1=p1+0.08;
else
p1=0;


if(q3<0.7)
q3+=0.07;
else
q3=0;


if(q2>-0.93)
q2-=0.06;
else
q2=0;

glPushMatrix();
house1();			
draw_outerparts();
draw_arrow();
current();
glPopMatrix();

glPushMatrix();
glRotatef(theta,1.0,0.0,0.0);
	colorcube();
glPopMatrix();

glPushMatrix();
glColor3f(1,1,1);	output(1.75,-0.68,"Bulb");
bulb();
glutPostRedisplay();
glPopMatrix();

glFlush();
	glutSwapBuffers();
	glPopMatrix();
	create_menu();

}
//_______________________________________________________________________________-end of windmill working

//_______________________________________________________________________________-start of exit screen
void disp()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glColor3f(0,0.5,0);		glVertex3f(0,0,0);
	glColor3f(1,0.5,0);		glVertex3f(1360,0,0);
	glColor3f(0,0.5,0);		glVertex3f(1360,768,0);
	glColor3f(1,0.5,0);		glVertex3f(0,768,0);
	glEnd();

	glColor3f(1,1,0);
	output2(150,650,"* *G O    G R E E N * *");
	output2(300,500,"* * S A V E    T R E E S   ,    S A V E     P A P E R  * *");
	output2(450,350,"* * U S E    R E N E W A B L E    E N E R G Y * *");
	output2(600,200,"* * A V O I D    G L O B A L     W A R M I N G * *");
	glFlush();

//delay code
int i, j=3500*200;
 while(j!=0)
{j--;
 i=2000;
 while(i!=0)
 {i--;}
}
exit (0);			//after displayin quotes i.e abot 10 sec then exit for project
}
//______________________________________________________________________________-end of exit screen

//_______________________________________________________________________________-start of menu creation for display
void detail_menu (int id)
{  
	switch (id)
	{		
	case 1: 

//__________________________- main screem

glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(1360,768);
glutInitWindowPosition(0,0);
id=glutCreateWindow("MAIN SCREEN");
init2();
glutDisplayFunc(display2);
glutIdleFunc(raysofsun);
create_menu();
glutMainLoop();

			break;

    case 2:
//____________________________-solar panel screen
		
	glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize (1360, 768);
	glutInitWindowPosition (0, 0);
	id=glutCreateWindow ("SOLAR PANEL");
	glutDisplayFunc(display3);
	glutIdleFunc(rays);
	init3();
	create_menu();
	glutMainLoop ();
		   break;

	case 3:
//___________________________- working of windmill

			glClearColor(0,0,0,1);
			gluOrtho2D(0.0,1360.0,0.0,768.0);

	glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize (1360, 768);
	glutInitWindowPosition (0, 0);
	id=glutCreateWindow ("WORKING OF WINDMILL");
		 glutReshapeFunc(myReshape4);
	glutDisplayFunc (display4);
	glutIdleFunc(spin);
		init4();
		create_menu();
	glEnable(GL_DEPTH_TEST);
	glutMainLoop ();
          
	break;

		default : ;
	}
}

void main_menu (int id)
{
	switch (id)
	{
	case 4: detail_menu (id);

	case 5: 
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (1360, 768);
	glutInitWindowPosition (0, 0);
	id=glutCreateWindow ("Quotes screen");
		glutDisplayFunc (disp);
		init2();
	glutMainLoop ();
	
	}
}

void create_menu()
{
	sub_menu = glutCreateMenu (detail_menu);
	glutAddMenuEntry ("MAIN SCREEN",1);
	glutAddMenuEntry ("SOLAR PANEL WORKING",2); 
	glutAddMenuEntry (" WORKING OF WIND MILL",3); 
    glutCreateMenu (main_menu);
	glutAddSubMenu (" VIEW",sub_menu);
	glutAddMenuEntry ("EXIT",5);
	glutAttachMenu (GLUT_RIGHT_BUTTON); 
}
//________________________________________________________________________- end of menu creation

void init()					//used for front screen
{
	glClearColor(0,0,0,1);
	gluOrtho2D(1360,0,768,0);
}

int l=850;			//intial position of loading

//_____________-loading func to load the screen
void loading()
{
	glClearColor(0,0,0,1);
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2i(0,0);
	glVertex2i(1360,0);
	glColor3f(1,1,1);
	glVertex2i(1360,768);
	glVertex2i(0,768);
	glEnd();

	glLineWidth(4);

	//screen co-ordinates in reverse directions

	glBegin(GL_LINE_LOOP);	//loading bar
	glColor3f(1,0.9,0);
	glVertex2i(850,400);
	glVertex2i(450,400);
	glVertex2i(450,430); 
	glVertex2i(850,430);
	glEnd();

	glColor3f(0.5,1,0.8);		output(750,320,"LOADING .....");
	glColor3f(0.5,1,0.8);		output(550,460,"Please wait....");
	glPointSize(15);
	glColor3f(0,1,0); 
	glBegin(GL_POINTS); 
	glVertex2f(l,415);
	glEnd();

	if(l==455)	detail_menu(1);				//main screen is displayed by passing parameter as id=1
glutPostRedisplay();
	glFlush();
}

void load()
{
	 l-=1;								//load with a speed of 1.0
	 	glutPostRedisplay();
}

//displaying of the loading screen
void disp1()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,1,0);
loading();
glEnd();
glFlush();
glutSwapBuffers();
}

//keyboard function in front screen
void keyboard(unsigned char key,int x,int y)
{
	if(key==13)						//if Enter is pressed goto loading screen
	{
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(1355,700);
glutInitWindowPosition(0,0);
glutCreateWindow("Loading");
init();
glutDisplayFunc(disp1);
glutIdleFunc(load);
glutMainLoop();

sc=2;				//screen=2 
glutPostRedisplay();
	}
	if(key=='q'||key=='Q')				//if q or Q is pressed quit by displaying quoted screen then exit
	{
		glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (1360, 768);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("Quotes screen");
		glutDisplayFunc (disp);
		init2();						//init2 is used which is used for main screen
	glutMainLoop ();
	}
}


void display1(void) //diplaying of text
{
	int x=0;
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glColor3f(0.9,0.9,0.9);				glVertex3i(0,0,0);
	glColor3f(0.8,0.5,0);			    glVertex3i(1360,0,0);
	glColor3f(0.9,0.9,0.9);			    glVertex3i(1360,768,0);
	glColor3f(0,0.5,0);			    glVertex3i(0,768,0);
	glEnd();

	//screen co-ordinates in reverse directions
	//display in large fonts
	glColor3f(0,0.3,1);	output(1050,50,"* * * J A W A H A R L A L    N E H R U    N A T I O N A L    C O L L E G E    O F    E N G I N N E R I N G * * *");

	glColor3f(0,0.3,1);	output(750,100,"* * S H I M O G A * *");

	glColor3f(1,1,1);	output(850,150,"* $ M i n i    P r o j e c t    u s i n g    O p e n G L # *");

	glColor3f(0,0,1);	output2(1150,200,"* * G R A P H I C A L   R E P R E S E N T A T I O N   O F   R E N E W A B L E   E N E R G Y * *");
	
	glColor3f(1,1,1);	output(750,240,"Submitted by");

	glColor3f(0,0,0);	output(650,290,"Skandamurthy shastry B.S.");

	glColor3f(0,0,0);	output(850,290,"4JN09CS097");

	glColor3f(0,0,0);	output(650,320,"Shashank R");

	glColor3f(0,0,0);	output(850,320,"4JN09CS090");

	glColor3f(0,0.5,1);	output(760,390,"Under the Guidence of");

	glColor3f(0,0,0);	output(1050,450,"Mr. Ravindra S");

	glColor3f(0,0,0);	output(350,450,"Ms. Sneha C Patil");

	//display in small fonts

	glColor3f(0,0.3,1);	output1(1050,470,"B.E,M.Tech,Asst.Professor");

	glColor3f(0,0.3,1);	output1(350,470,"B.E,M.Tech,Lecturer");

	glColor3f(0,0,1);	output1(1050,490,"Dept of CS&E,Shimoga");

	glColor3f(0,0,1);	output1(350,490,"Dept of CS&E,Shimoga");

	//display in large fonts
	glColor3f(0.7,0,0.2);	output(350,650,"Press Enter to continue");

	glColor3f(1,0,0);	output(1110,670,"Press Q to Quit");
	
	if(sc==2)
	{
		detail_menu(1);
	}
	glutSwapBuffers();
	glFlush();
	
}

void main( int argc, char ** argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize (1360, 768);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("FRONT SCREEN");
	glutDisplayFunc (display1);			//display the front screen
	glutKeyboardFunc(keyboard);
	init();										
	glutMainLoop ();
}
