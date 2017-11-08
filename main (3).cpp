#include <stdlib.h>	// Note: declare stdlib.h BEFORE glut.h
#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14f
GLfloat pos=0,y=0,birdxoffset=0,birdyoffset=0;
GLfloat balloffset = 0, balldirection= 1,birdxdirec=1,birdydirec=1;
GLfloat spin_speed = 0,cloudxoffset=0,clouddirec=1;
GLint day=1;

int main_window;
void bitmap_output(float x, float y, float z, char *string, void *font)
{
	char *c;
	glLoadIdentity();
	//glColor3f(1.0f, 0.0f, 0.0f);
	glRasterPos2f(x, y);
	//len = (int)strlen(string);
	glDisable(GL_TEXTURE_2D);
	for(c=string; *c != '\0'; c++)
    {
     glutBitmapCharacter(font, *c);
    }
	glEnable(GL_TEXTURE_2D);
}
void init()
{
    glClearColor(0.847,0.627,0.867, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1350.0,0.0,700.0);
    glutPostRedisplay();
}

void dayumbrellachair()
{
    glPushMatrix();
    GLfloat x,y;
    glColor3d(1.0,0.0,0.0);
    glBegin(GL_POLYGON);//chair1st
    glVertex2f(70,50);
    glVertex2f(55,145);
    glVertex2f(135,145);
    glVertex2f(150,50);
    glEnd();
    glBegin(GL_POLYGON);//chairrefdown
    glColor3d(0.863,0.078,0.235);
    glVertex2f(150,50);
    glVertex2f(160,55);
    glVertex2f(145,150);
    glVertex2f(135,145);
    glEnd();
    glBegin(GL_POLYGON);//chairreftop
    glColor3d(0.863,0.078,0.235);
    glVertex2f(55,145);
    glVertex2f(65,150);
    glVertex2f(145,150);
    glVertex2f(135,145);
    glEnd();
    glBegin(GL_POLYGON);//chairlegleft
    glColor3d(0.863,0.078,0.235);
    glVertex2f(72,54);
    glVertex2f(45,40);
    glVertex2f(40,44);
    glVertex2f(70,59);
    glEnd();
    glBegin(GL_POLYGON);//chairleftlegdown
    glColor3d(0.863,0.078,0.235);
    glVertex2f(40,44);
    glVertex2f(40,30);
    glVertex2f(45,30);
    glVertex2f(45,40);
    glEnd();
    glBegin(GL_POLYGON);//chairrightleg
    glColor3d(0.863,0.078,0.235);
    glVertex2f(150,54);
    glVertex2f(130,35);
    glVertex2f(123,38);
    glVertex2f(150,64);
    glEnd();
    glBegin(GL_POLYGON);//chairrightlegdown
    glColor3d(0.863,0.078,0.235);
    glVertex2f(123,38);
    glVertex2f(123,25);
    glVertex2f(130,25);
    glVertex2f(130,35);
    glEnd();
    glBegin(GL_POLYGON);//chairlegfront
    glColor3d(0.863,0.078,0.235);
    glVertex2f(149,54);
    glVertex2f(280,83);
    glVertex2f(147,61);
    glVertex2f(280,87);
    glEnd();
    glBegin(GL_POLYGON);//chairfront
    glColor3d(1.000,0.0,0.0);
    glVertex2f(157,85);
    glVertex2f(280,87);
    glVertex2f(159,61);
    glEnd();
    glBegin(GL_POLYGON);//umb1ststand
    glColor3d(0.957,0.643,0.376);
    glVertex2f(180,25);
    glVertex2f(180,300);
    glVertex2f(185,300);
    glVertex2f(185,25);
    glEnd();
    glBegin(GL_POLYGON);//umbtop
    glColor3d(0.980,0.922,0.843);
    glVertex2f(90,300);
    glVertex2f(240,300);
    glVertex2f(195,360);
    glEnd();
    glBegin(GL_POLYGON);//umbtop
    glColor3d(0.980,0.922,0.843);
    glVertex2f(195,360);
    glVertex2f(240,300);
    glVertex2f(290,320);
    glEnd();
    glBegin(GL_POLYGON);//chair2nd
    glColor3d(1.000,0.0,0.000);
    glVertex2f(230,50);
    glVertex2f(220,145);
    glVertex2f(310,150);
    glVertex2f(320,55);
    glEnd();
    glBegin(GL_POLYGON);//chairref
    glColor3d(0.863,0.078,0.235);
    glVertex2f(220,145);
    glVertex2f(234,153);
    glVertex2f(324,158);
    glVertex2f(310,150);
    glEnd();
    glBegin(GL_POLYGON);//chairref2nd
    glColor3d(0.863,0.078,0.235);
    glVertex2f(310,150);
    glVertex2f(320,158);
    glVertex2f(330,60);
    glVertex2f(320,55);
    glVertex2f(310,165);
    glEnd();
    glBegin(GL_POLYGON);//chairlegleft2nd
    glColor3d(0.863,0.078,0.235);
    glVertex2f(230,54);
    glVertex2f(229,68);
    glVertex2f(208,42);
    glVertex2f(219,44);
    glEnd();
    glBegin(GL_POLYGON);//chairfront
    glColor3d(1.00,0.0,0.0);
    glVertex2f(330,80);
    glVertex2f(380,80);
    glVertex2f(330,65);
    glEnd();
    glBegin(GL_POLYGON);//chairleftlegdown2nd
    glColor3d(0.863,0.078,0.235);
    glVertex2f(219,44);
    glVertex2f(208,42);
    glVertex2f(208,30);
    glVertex2f(219,30);
    glEnd();
    glBegin(GL_POLYGON);//chairrightleg2nd
    glColor3d(0.863,0.078,0.235);
    glVertex2f(320,55);
    glVertex2f(320,65);
    glVertex2f(300,45);
    glVertex2f(308,40);
    glEnd();
    glBegin(GL_POLYGON);//chairreghtlegdown2nd
    glColor3d(0.863,0.078,0.235);
    glVertex2f(308,40);
    glVertex2f(300,45);
    glVertex2f(300,28);
    glVertex2f(308,28);
    glEnd();
    glBegin(GL_POLYGON);//chailegfront2nd
    glColor3d(0.863,0.078,0.235);
    glVertex2f(330,60);
    glVertex2f(320,65);
    glVertex2f(382,80);
    glVertex2f(384,77);
    glEnd();
    glBegin(GL_POLYGON);//umb2ndstand
    glColor3d(0.957,0.643,0.376);
    glVertex2f(382,34);
    glVertex2f(382,310);
    glVertex2f(388,310);
    glVertex2f(388,34);
    glEnd();
    glBegin(GL_POLYGON);//umb2ndtop
    glColor3d(0.980,0.922,0.843);
    glVertex2f(259,310);
    glVertex2f(450,310);
    glVertex2f(400,360);
    glVertex2f(250,310);
    glEnd();
    glBegin(GL_POLYGON);//umb2ndtop2
    glColor3d(0.980,0.922,0.843);
    glVertex2f(450,310);
    glVertex2f(510,330);
    glVertex2f(400,360);
    glEnd();
    glPopMatrix();
}

void eveumbrellachair()
{
    glPushMatrix();
    glColor3d(0.545,0.0,0.0);
    glBegin(GL_POLYGON);//chair1st
    glVertex2f(70,50);
    glVertex2f(55,145);
    glVertex2f(135,145);
    glVertex2f(150,50);
    glEnd();
    glBegin(GL_POLYGON);//chairrefdown
    glColor3d(0.698,0.133,0.133);
    glVertex2f(150,50);
    glVertex2f(160,55);
    glVertex2f(145,150);
    glVertex2f(135,145);
    glEnd();
    glBegin(GL_POLYGON);//chairreftop
    glColor3d(0.698,0.133,0.133);
    glVertex2f(55,145);
    glVertex2f(65,150);
    glVertex2f(145,150);
    glVertex2f(135,145);
    glEnd();
    glBegin(GL_POLYGON);//chairlegleft
    glColor3d(0.698,0.133,0.133);
    glVertex2f(72,54);
    glVertex2f(45,40);
    glVertex2f(40,44);
    glVertex2f(70,59);
    glEnd();
    glBegin(GL_POLYGON);//chairleftlegdown
    glColor3d(0.698,0.133,0.133);
    glVertex2f(40,44);
    glVertex2f(40,30);
    glVertex2f(45,30);
    glVertex2f(45,40);
    glEnd();
    glBegin(GL_POLYGON);//chairrightleg
    glColor3d(0.698,0.133,0.133);
    glVertex2f(150,54);
    glVertex2f(130,35);
    glVertex2f(123,38);
    glVertex2f(150,64);
    glEnd();
    glBegin(GL_POLYGON);//chairrightlegdown
    glColor3d(0.698,0.133,0.133);
    glVertex2f(123,38);
    glVertex2f(123,25);
    glVertex2f(130,25);
    glVertex2f(130,35);
    glEnd();
    glBegin(GL_POLYGON);//chairlegfront
    glColor3d(0.698,0.133,0.133);
    glVertex2f(149,54);
    glVertex2f(280,83);
    glVertex2f(147,61);
    glVertex2f(280,87);
    glEnd();
    glBegin(GL_POLYGON);//chairfront
    glColor3d(1.000,0.0,0.0);
    glVertex2f(157,85);
    glVertex2f(280,87);
    glVertex2f(159,61);
    glEnd();
    glBegin(GL_POLYGON);//umb1ststand
    glColor3d(0.502,0.0,0.0);
    glVertex2f(180,25);
    glVertex2f(180,300);
    glVertex2f(185,300);
    glVertex2f(185,25);
    glEnd();
    glBegin(GL_POLYGON);//umbtop
    glColor3d(0.647,0.165,0.165);
    glVertex2f(90,300);
    glVertex2f(240,300);
    glVertex2f(195,360);
    glEnd();
    glBegin(GL_POLYGON);//umbtop
    glColor3d(0.647,0.165,0.165);
    glVertex2f(195,360);
    glVertex2f(240,300);
    glVertex2f(290,320);
    glEnd();
    glBegin(GL_POLYGON);//chair2nd
    glColor3d(0.545,0.0,0.000);
    glVertex2f(230,50);
    glVertex2f(220,145);
    glVertex2f(310,150);
    glVertex2f(320,55);
    glEnd();
    glBegin(GL_POLYGON);//chairref
    glColor3d(0.698,0.133,0.133);
    glVertex2f(220,145);
    glVertex2f(234,153);
    glVertex2f(324,158);
    glVertex2f(310,150);
    glEnd();
    glBegin(GL_POLYGON);//chairref2nd
    glColor3d(0.698,0.133,0.133);
    glVertex2f(310,150);
    glVertex2f(320,158);
    glVertex2f(330,60);
    glVertex2f(320,55);
    glVertex2f(310,165);
    glEnd();
    glBegin(GL_POLYGON);//chairlegleft2nd
    glColor3d(0.698,0.133,0.133);
    glVertex2f(230,54);
    glVertex2f(229,68);
    glVertex2f(208,42);
    glVertex2f(219,44);
    glEnd();
    glBegin(GL_POLYGON);//chairfront
    glColor3d(1.00,0.0,0.0);
    glVertex2f(330,80);
    glVertex2f(380,80);
    glVertex2f(330,65);
    glEnd();
    glBegin(GL_POLYGON);//chairleftlegdown2nd
    glColor3d(0.698,0.133,0.133);
    glVertex2f(219,44);
    glVertex2f(208,42);
    glVertex2f(208,30);
    glVertex2f(219,30);
    glEnd();
    glBegin(GL_POLYGON);//chairrightleg2nd
    glColor3d(0.698,0.133,0.133);
    glVertex2f(320,55);
    glVertex2f(320,65);
    glVertex2f(300,45);
    glVertex2f(308,40);
    glEnd();
    glBegin(GL_POLYGON);//chairreghtlegdown2nd
    glColor3d(0.698,0.133,0.133);
    glVertex2f(308,40);
    glVertex2f(300,45);
    glVertex2f(300,28);
    glVertex2f(308,28);
    glEnd();
    glBegin(GL_POLYGON);//chailegfront2nd
    glColor3d(0.698,0.133,0.133);
    glVertex2f(330,60);
    glVertex2f(320,65);
    glVertex2f(382,80);
    glVertex2f(384,77);
    glEnd();
    glBegin(GL_POLYGON);//umb2ndstand
    glColor3d(0.502,0.0,0.0);
    glVertex2f(382,34);
    glVertex2f(382,310);
    glVertex2f(388,310);
    glVertex2f(388,34);
    glEnd();
    glBegin(GL_POLYGON);//umb2ndtop
    glColor3d(0.647,0.165,0.165);
    glVertex2f(259,310);
    glVertex2f(450,310);
    glVertex2f(400,360);
    glVertex2f(250,310);
    glEnd();
    glBegin(GL_POLYGON);//umb2ndtop2
    glColor3d(0.647,0.165,0.165);
    glVertex2f(450,310);
    glVertex2f(510,330);
    glVertex2f(400,360);
    glEnd();
}

void people()
{
    glPushMatrix();
    float x,y;
    glColor3f(0.0f, 0.0f, 0.0f);	// change color to black
	glBegin(GL_POLYGON);   // hair
	glPointSize(3.0);
    for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=600+17*cos(i);
            y=250+17*sin(i);
            glVertex2f(x,y);}
	glEnd();
    glColor3f(0.75f, 0.35f, 0.009f);	// change color skin
	glBegin(GL_POLYGON);		// face
    for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=600+15*cos(i);
            y=250+15*sin(i);
            glVertex2f(x,y);}
	glEnd();
	glBegin(GL_POLYGON);   //neck
	  glVertex2i(592,236);
	  glVertex2i(608,236);
	  glVertex2i(608,232);
	  glVertex2i(592,232);
    glEnd();
    glBegin(GL_POLYGON);   //left hand
	  glVertex2i(576,217);
	  glVertex2i(582,217);
	  glVertex2i(582,198);
	  glVertex2i(579,196);
	  glVertex2i(576,198);
    glEnd();
    glBegin(GL_POLYGON);   //right hand
	  glVertex2i(618,217);
	  glVertex2i(624,217);
	  glVertex2i(624,198);
	  glVertex2i(620,196);
	  glVertex2i(618,198);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);//left eye
	glBegin(GL_POLYGON);
	  glVertex2i(592,254);
	  glVertex2i(596,254);
	  glVertex2i(596,252);
	  glVertex2i(592,252);
    glEnd();
    glBegin(GL_POLYGON);//right eye
	  glVertex2i(604,254);
	  glVertex2i(608,254);
	  glVertex2i(608,252);
	  glVertex2i(604,252);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);//mouth
    glBegin(GL_POLYGON);
      glVertex2i(600,240);
	  glVertex2i(596,242);
      glVertex2i(604,242);
    glEnd();

    glColor3f(1.0f, 0.8f, 0.0f);//shirt yellow
    glBegin(GL_POLYGON);
        glVertex2i(582,217);
        glVertex2i(572,217);
        glVertex2i(582,232);
        glVertex2i(618,232);
        glVertex2i(628,217);
        glVertex2i(618,217);
        glVertex2i(618,200);
        glVertex2i(582,200);
    glEnd();
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);//pant
        glVertex2i(582,200);
        glVertex2i(618,200);
        glVertex2i(618,174);
        glVertex2i(604,174);
        glVertex2i(600,180);
        glVertex2i(596,174);
        glVertex2i(582,174);
    glEnd();
    glColor3f(0.75f, 0.35f, 0.009f);
    glBegin(GL_POLYGON);   //left leg
	  glVertex2i(586,174);
	  glVertex2i(594,174);
	  glVertex2i(594,164);
	  glVertex2i(598,160);
	  glVertex2i(594,158);
	  glVertex2i(590,160);
	  glVertex2i(586,164);
    glEnd();
    glBegin(GL_POLYGON);   // right legs
	  glVertex2i(606,174);
	  glVertex2i(614,174);
	  glVertex2i(614,164);
	  glVertex2i(618,160);
	  glVertex2i(614,158);
	  glVertex2i(610,160);
	  glVertex2i(606,164);
    glEnd();

    glTranslatef(620 + balloffset, (164 - balloffset*0.5), 0); // move rotation center to 620,164
	glRotatef(spin_speed, 0, 0, 1);	// rotate around vector <0,0,1> (z-axis)
	glTranslatef(-620, -164, 0); // move back.
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);		// red ball
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=620+12*cos(i);
            y=164+12*sin(i);
            glVertex2f(x,y);}
	glEnd();
	glTranslatef(620, 164, 0); // move rotation center to 620,164
	glRotatef(-spin_speed, 0, 0, 1);	// rotate around vector <0,0,1> (z-axis)
	glTranslatef(-(620 + balloffset), -(164 - balloffset*0.5), 0); // move back.

    glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);		// girl hair
      for(float i=0.0f; i<=(PI); i+=0.01f)
           {
            x=800+15*cos(i);
            y=150+15*sin(i);
            glVertex2f(x,y);}
            glVertex2i(815,150);
            glVertex2i(815,138);
            glVertex2i(785,138);
            glVertex2i(785,150);
	glEnd();
    glColor3f(1.0f, 0.0f, 0.5f);//girl pink frock
    glBegin(GL_POLYGON);
        glVertex2i(780,128);
        glVertex2i(772,128);
        glVertex2i(780,138);
        glVertex2i(820,138);
        glVertex2i(828,128);
        glVertex2i(820,128);
        glVertex2i(820,110);
        glVertex2i(780,110);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2i(820,110);
        glVertex2i(830,90);
        glVertex2i(770,90);
        glVertex2i(780,110);
    glEnd();
    glColor3f(0.75f, 0.35f, 0.009f);
    glBegin(GL_POLYGON);   //girl left leg
	  glVertex2i(790,90);
	  glVertex2i(796,90);
	  glVertex2i(796,70);
	  glVertex2i(793,66);
	  glVertex2i(790,70);
    glEnd();
    glBegin(GL_POLYGON);   //girl right leg
	  glVertex2i(804,90);
	  glVertex2i(810,90);
	  glVertex2i(810,70);
	  glVertex2i(807,66);
	  glVertex2i(804,70);
    glEnd();
   glBegin(GL_POLYGON);   //left hand
	  glVertex2i(776,128);
	  glVertex2i(780,128);
	  glVertex2i(780,108);
	  glVertex2i(778,106);
	  glVertex2i(776,108);
    glEnd();
     glBegin(GL_POLYGON);   //left leg
	  glVertex2i(820,128);
	  glVertex2i(824,128);
	  glVertex2i(824,108);
	  glVertex2i(822,106);
	  glVertex2i(820,108);
    glEnd();

     // man()
    glColor3f(0.0,0.0,0.0);  //hair
	glBegin(GL_POLYGON);
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=450+15*cos(i);
            y=150+15*sin(i);
            glVertex2f(x,y);}
	glEnd();
	//neck
	glBegin(GL_POLYGON);
	glColor3f(0.75f, 0.35f, 0.009f);
    glVertex2f(445,135);
	glVertex2f(456,135);
	glVertex2f(456,128);
	glVertex2f(445,128);
	glEnd();
	//body
	glBegin(GL_POLYGON);
	glVertex2f(430,128);
	glVertex2f(471,128);
	glVertex2f(471,75);
	glVertex2f(430,75);
	glEnd();
	//hands
	glBegin(GL_POLYGON);//right
	glVertex2f(471,128);
	glVertex2f(478,128);
	glVertex2f(478,65);
	glVertex2f(474.5,63);
	glVertex2f(471,65);
	glEnd();
	glBegin(GL_POLYGON);//left
	glVertex2f(430,128);
	glVertex2f(423,128);
	glVertex2f(423,65);
	glVertex2f(426.5,63);
	glVertex2f(430,65);
	glEnd();
	glBegin(GL_POLYGON);//pant
	glColor3f(0.804,0.361,0.361);
	glVertex2f(430,75);
	glVertex2f(471,75);
	glVertex2f(471,35);
	glVertex2f(460,35);
	glVertex2f(455.5,65);
	glVertex2f(440,35);
	glVertex2f(430,35);
	glEnd();
	glBegin(GL_POLYGON);//left leg
	glColor3f(0.75f, 0.35f, 0.009f);
	glVertex2f(431,35);
	glVertex2f(431,20);
	glVertex2f(435,17);
	glVertex2f(439,20);
	glVertex2f(439,35);
	glEnd();
	glBegin(GL_POLYGON);//right leg
	glColor3f(0.75f, 0.35f, 0.009f);
	glVertex2f(470,35);
	glVertex2f(470,20);
	glVertex2f(465.5,17);
	glVertex2f(462,20);
	glVertex2f(462,35);
	glEnd();

    //man with woman
    glColor3f(0.0f, 0.0f, 0.0f);	// change color to black
	glBegin(GL_POLYGON);   // hair
    for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=1105+20*cos(i);
            y=160+20*sin(i);
            glVertex2f(x,y);}
	glEnd();
    glColor3f(1.0,0.714,0.757);
	glBegin(GL_POLYGON);
	glVertex2f(1130.0,135.0);//shirt
    glVertex2f(1150.0,120.0);
    glVertex2f(1130.0,120.0);
    glVertex2f(1130.0,90.0);
    glVertex2f(1080.0,90.0);
    glVertex2f(1080.0,120.0);
	glVertex2f(1060.0,120.0);
	glVertex2f(1080.0,135.0);
	glEnd();

    glColor3f(0.855,0.439,0.839);//pant
    glBegin(GL_POLYGON);
	glVertex2f(1080.0,90.0);
    glVertex2f(1080.0,55.0);
    glVertex2f(1100.0,55.0);
    glVertex2f(1110.0,80.0);
    glVertex2f(1110.0,55.0);
    glVertex2f(1130.0,55.0);
	glVertex2f(1130.0,90.0);
	glEnd();

    glColor3f(1.0,0.855,0.725);//left leg
    glBegin(GL_POLYGON);
	glVertex2f(1092.0,55.0);
    glVertex2f(1086.0,55.0);
    glVertex2f(1086.0,35.0);
    glVertex2f(1092.0,35.0);
	glEnd();

    glColor3f(1.0,0.855,0.725);// right leg
    glBegin(GL_POLYGON);
	glVertex2f(1121.0,55.0);
    glVertex2f(1115.0,55.0);
    glVertex2f(1115.0,35.0);
    glVertex2f(1121.0,35.0);
    glEnd();

    glColor3f(1.0,0.855,0.725);// neck
    glBegin(GL_POLYGON);
	glVertex2f(1096.0,143.0);
    glVertex2f(1096.0,135.0);
    glVertex2f(1114.0,135.0);
    glVertex2f(1114.0,143.0);
    glEnd();

    glColor3f(1.0,0.855,0.725);//left hand
    glBegin(GL_POLYGON);
	glVertex2f(1072.0,120.0);
    glVertex2f(1080.0,120.0);
    glVertex2f(1080.0,85.0);//1100
    glVertex2f(1072.0,85.0);//1092
    glEnd();

    glColor3f(1.0,0.855,0.725);//right hand
    glBegin(GL_POLYGON);
	glVertex2f(1130.0,120.0);
    glVertex2f(1138.0,120.0);
    glVertex2f(1158.0,85.0);
    glVertex2f(1150.0,85.0);
    glEnd();

    //women with man
    glColor3f(1.0,0.498,0.314);
	glBegin(GL_POLYGON);
	glVertex2f(1230.0,135.0);//shirt
    glVertex2f(1250.0,120.0);
    glVertex2f(1230.0,120.0);
    glVertex2f(1230.0,90.0);
    glVertex2f(1180.0,90.0);
    glVertex2f(1180.0,120.0);
	glVertex2f(1160.0,120.0);
	glVertex2f(1180.0,135.0);
	glEnd();

    glColor3f(0.6,0.196,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(1180.0,90.0);//skirt
    glVertex2f(1230.0,90.0);
    glVertex2f(1240.0,34.0);
    glVertex2f(1170.0,34.0);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);	// change color to black
	glBegin(GL_POLYGON);   // hair
      for(float i=0.0f; i<=PI; i+=0.01f)
           {
            x=1205+20*cos(i);
            y=160+20*sin(i);
            glVertex2f(x,y);
            glVertex2i(1225,160);
            glVertex2i(1225,110);
            glVertex2i(1185,110);
            glVertex2i(1185,160);
            }
	glEnd();

	glColor3f(1.0,0.855,0.725);//right hand
    glBegin(GL_POLYGON);
	glVertex2f(1230.0,120.0);
    glVertex2f(1238.0,120.0);
    glVertex2f(1238.0,85.0);
    glVertex2f(1230.0,85.0);
    glEnd();

    glColor3f(1.0,0.855,0.725);//left hand
    glBegin(GL_POLYGON);
	glVertex2f(1172.0,120.0);
    glVertex2f(1180.0,120.0);
    glVertex2f(1160.0,85.0);
    glVertex2f(1152.0,85.0);
    glEnd();
    glPopMatrix();
}

void update()
{
	int time = glutGet(GLUT_ELAPSED_TIME);  // update display every 1/10th of a second!
	if(time % 5 == 0) {
		if(balloffset < 0) balldirection=1;
		if(balloffset + 620 > 790) balldirection=-1;
		balloffset+= balldirection;
        spin_speed += 5;

    if(birdxoffset > 275){
            birdxdirec = -1;
        }
    if(birdxoffset < -700){
        birdxdirec = 1;
        }
    birdxoffset+=birdxdirec;

    if(birdyoffset<0)  birdydirec=1;
    if(birdyoffset>40) birdydirec=-1;
     birdyoffset+=birdydirec;

    if(cloudxoffset<-20) clouddirec=1;
	if(cloudxoffset>810) clouddirec=-1;
	cloudxoffset+=clouddirec;
	}
   glutPostRedisplay();

}

void birds(GLfloat u,GLfloat v)
{
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3.0);
    //bird 1
    glBegin(GL_LINES);
    glVertex2f(275-u,647-v);
    glVertex2f(268-u,650-v);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(268-u,650-v);
    glVertex2f(260-u,630-v);
    glEnd();
    glBegin(GL_LINES);
	glVertex2f(260-u,630-v);
    glVertex2f(258-u,650-v);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(258-u,650-v);
    glVertex2f(251-u,640-v);
    glEnd();
    //bird 2
    glBegin(GL_LINES);
    glVertex2f(195-u,595+v);
    glVertex2f(188-u,590+v);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(188-u,590+v);
    glVertex2f(180-u,570+v);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(180-u,570+v);
    glVertex2f(178-u,590+v);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(178-u,590+v);
    glVertex2f(171-u,580+v);
    glEnd();

}

void daytree()
{
    GLfloat x,y;
    glPushMatrix();
    glColor3d(0.647,0.165,0.165);
    glBegin(GL_POLYGON);
    glVertex2f(1240.0,410.0);
    glVertex2f(1270.0,410.0);
    glVertex2f(1350.0,190.0);
    glVertex2f(1350.0,100.0);
    glEnd();

    //tree leaf 1
    glColor3d(0.0,0.502,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1235.0,420.0);
    glVertex2f(1250.0,375.0);
    glVertex2f(1225.0,345.0);
    glVertex2f(1215.0,345.0);
    glVertex2f(1215.0,330.0);
    glVertex2f(1175.0,320.0);
    glVertex2f(1175.0,310.0);
    glVertex2f(1155.0,301.0);
    glVertex2f(1110.0,292.0);
    glVertex2f(1100.0,335.0);
    glVertex2f(1115.0,355.0);
    glVertex2f(1149.0,350.0);
    glVertex2f(1140.0,375.0);
    glVertex2f(1195.0,395.0);
    //glVertex2f(1235.0,420.0);
    glEnd();

    //leaf 2
    glBegin(GL_POLYGON);
    glVertex2f(1195.0,395.0);
    glVertex2f(1147.0,419.0);
    glVertex2f(1119.0,400.0);
    glVertex2f(1090.0,389.0);
    glVertex2f(1060.0,405.0);
    glVertex2f(1068.0,450.0);
    glVertex2f(1130.0,475.0);
    glVertex2f(1175.0,470.0);
    glVertex2f(1185.0,489.0);
    glVertex2f(1205.0,495.0);
    glVertex2f(1235.0,420.0);
    glEnd();

   //leave 3
    glBegin(GL_POLYGON);
    glVertex2f(1195.0,485.0);
    glVertex2f(1140.0,545.0);
    glVertex2f(1160.0,555.0);
    glVertex2f(1135.0,563.0);
    glVertex2f(1123.0,575.0);
    glVertex2f(1150.0,620.0);
    glVertex2f(1195.0,625.0);
    glVertex2f(1210.0,600.0);
    glVertex2f(1225.0,610.0);
    glVertex2f(1240.0,530.0);
    glVertex2f(1270.0,410.0);
    glVertex2f(1240.0,410.0);
   // glVertex2f(1195.0,485.0);
    glEnd();

    //leaf 4
    glBegin(GL_POLYGON);
    glVertex2f(1240.0,530.0);
    glVertex2f(1275.0,545.0);
    glVertex2f(1289.0,575.0);
    glVertex2f(1310.0,588.0);
    glVertex2f(1318.0,566.0);
    glVertex2f(1325.0,592.0);
    glVertex2f(1350.0,570.0);
    glVertex2f(1350.0,528.0);
    glVertex2f(1327.0,500.0);
    glVertex2f(1318.0,470.0);
    glVertex2f(1305.0,490.0);
    glVertex2f(1270.0,410.0);
    //glVertex2f(1240.0,530.0);
    glEnd();

    //coconuts
    glColor3d(0.196,0.804,0.196);
    glBegin(GL_POLYGON);
    for(float i=0;i<=(2*3.142f);i+=0.1f)
    {
       x = 1256+22*cos(i);
       y = 410+25*sin(i);
       glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(float i=0;i<=(2*3.142f);i+=0.1f)
    {
       x = 1300+30*cos(i);
       y = 420+34*sin(i);
       glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(float i=0;i<=(2*3.142f);i+=0.1f)
    {
       x = 1270+28*cos(i);
       y = 370+29*sin(i);
       glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
}

void evetree()
{
    GLfloat x,y;
    glPushMatrix();
    glColor3d(0.098,0.098,0.439);
    glBegin(GL_POLYGON);
    glVertex2f(1240.0,410.0);
    glVertex2f(1270.0,410.0);
    glVertex2f(1350.0,190.0);
    glVertex2f(1350.0,100.0);
    glEnd();

    //tree leaf 1
    glColor3d(0.098,0.098,0.439);;
    glBegin(GL_POLYGON);
    glVertex2f(1235.0,420.0);
    glVertex2f(1250.0,375.0);
    glVertex2f(1225.0,345.0);
    glVertex2f(1215.0,345.0);
    glVertex2f(1215.0,330.0);
    glVertex2f(1175.0,320.0);
    glVertex2f(1175.0,310.0);
    glVertex2f(1155.0,301.0);
    glVertex2f(1110.0,292.0);
    glVertex2f(1100.0,335.0);
    glVertex2f(1115.0,355.0);
    glVertex2f(1149.0,350.0);
    glVertex2f(1140.0,375.0);
    glVertex2f(1195.0,395.0);
    //glVertex2f(1235.0,420.0);
    glEnd();

    //leaf 2
    glBegin(GL_POLYGON);
    glVertex2f(1195.0,395.0);
    glVertex2f(1147.0,419.0);
    glVertex2f(1119.0,400.0);
    glVertex2f(1090.0,389.0);
    glVertex2f(1060.0,405.0);
    glVertex2f(1068.0,450.0);
    glVertex2f(1130.0,475.0);
    glVertex2f(1175.0,470.0);
    glVertex2f(1185.0,489.0);
    glVertex2f(1205.0,495.0);
    glVertex2f(1235.0,420.0);
    glEnd();

   //leave 3
    glBegin(GL_POLYGON);
    glVertex2f(1195.0,485.0);
    glVertex2f(1140.0,545.0);
    glVertex2f(1160.0,555.0);
    glVertex2f(1135.0,563.0);
    glVertex2f(1123.0,575.0);
    glVertex2f(1150.0,620.0);
    glVertex2f(1195.0,625.0);
    glVertex2f(1210.0,600.0);
    glVertex2f(1225.0,610.0);
    glVertex2f(1240.0,530.0);
    glVertex2f(1270.0,410.0);
    glVertex2f(1240.0,410.0);
   // glVertex2f(1195.0,485.0);
    glEnd();

    //leaf 4
    glBegin(GL_POLYGON);
    glVertex2f(1240.0,530.0);
    glVertex2f(1275.0,545.0);
    glVertex2f(1289.0,575.0);
    glVertex2f(1310.0,588.0);
    glVertex2f(1318.0,566.0);
    glVertex2f(1325.0,592.0);
    glVertex2f(1350.0,570.0);
    glVertex2f(1350.0,528.0);
    glVertex2f(1327.0,500.0);
    glVertex2f(1318.0,470.0);
    glVertex2f(1305.0,490.0);
    glVertex2f(1270.0,410.0);
    //glVertex2f(1240.0,530.0);
    glEnd();

    //coconuts
    glColor3d(0.282,0.239,0.545);
    glBegin(GL_POLYGON);
    for(float i=0;i<=(2*3.142f);i+=0.1f)
    {
       x = 1256+22*cos(i);
       y = 410+25*sin(i);
       glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(float i=0;i<=(2*3.142f);i+=0.1f)
    {
       x = 1300+30*cos(i);
       y = 420+34*sin(i);
       glVertex2f(x,y);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for(float i=0;i<=(2*3.142f);i+=0.1f)
    {
       x = 1270+28*cos(i);
       y = 370+29*sin(i);
       glVertex2f(x,y);
    }
    glEnd();
    glPopMatrix();
}

void ship(GLfloat x,GLfloat y)
{
     /*base*/
        glBegin(GL_POLYGON);
		glColor3d(0.545,0.271,0.075);
		glVertex2f(710+x,490+y);
		glVertex2f(710+x,483+y);
        glColor3f(.0f,0.0f,0.0f);
		glVertex2f(742+x,453+y);
        glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(889+x,455+y);
        glColor3d(0.545,0.271,0.075);
		glVertex2f(954+x,485+y);
        glColor3d(0.545,0.271,0.075);
		glVertex2f(954+x,492+y);
		glEnd();

        /*p1*/
        glColor3d(0.70,0.0,0.0);
        glBegin(GL_POLYGON);
        glVertex2f(730+x,487+y);
		glVertex2f(730+x,496+y);
		glVertex2f(878+x,500+y);
		glVertex2f(878+x,490+y);
		//glVertex2f(720+x,538+y);
		glEnd();

      /*p3*/
        glColor3d(0.30,0.30,0.30);
	    glBegin(GL_POLYGON);
        glVertex2f(750+x,494+y);
		glVertex2f(750+x,503+y);
		glVertex2f(866+x,508+y);
		glVertex2f(866+x,497+y);
		//glVertex2f(750+x,555+y);
        glEnd();

      /*p4*/
	    glColor3d(0.863,0.078,0.235); /* crimson*/
	    glBegin(GL_POLYGON);
        glVertex2f(788+x,503+y);
		glVertex2f(788+x,512+y);
		glColor3d(0.3,0.3,0.0);
		glVertex2f(808+x,512+y);
		glVertex2f(808+x,502+y);
        glEnd();

        glBegin(GL_POLYGON);//upper right
	    glColor3d(0.4,0.4,0.4);
		glVertex2f(866+x,508+y);
		glVertex2f(866+x,498+y);
		glVertex2f(908+x,498+y);
		glVertex2f(908+x,504+y);
		glEnd();

     	glBegin(GL_POLYGON);
	    glColor3f(0.50,0.0,0.0); /* dark red lower*/
		glVertex2f(878+x,500+y);
		glVertex2f(878+x,490+y);
		glVertex2f(914+x,490+y);
		glVertex2f(914+x,498+y);
		glEnd();

        glColor3d(0.863,0.078,0.235); /* crison red big*/
		glBegin(GL_POLYGON);
        glVertex2f(814+x,506+y);
		glVertex2f(814+x,518+y);
		glColor3d(0.3,0.3,0.0);
		glVertex2f(854+x,518+y);
		glVertex2f(854+x,507+y);
	    glEnd();
}

void daybg()
{
    GLfloat x,y;
    glPushMatrix();
    glColor3d(0.0,0.749,1.0);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(50.0);
    glBegin(GL_LINES);
    glEnd();

    //sky
    glBegin(GL_POLYGON);
    glColor3d(0.529,0.808,0.980);
    glVertex2i(1350,700);
    glVertex2i(1350,460);
    glVertex2i(0,460);
    glColor3f(1.0,1.0,0.0);
    glVertex2i(0,700);
    glVertex2i(60,700);
    glVertex2i(140,700);
    glEnd();

    glColor3f(0.0,0.0,1.0);//sea
    glBegin(GL_QUADS);
    glVertex2i(0,460);
    glVertex2i(1350,460);
    glColor3d(0.0,0.749,1.0);
    glVertex2i(1350,160);
    glVertex2i(0,320);
    glEnd();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);		// sun
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=100+30*cos(i);
            y=625+30*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glColor3d(0.902,0.902,0.980);
    glBegin(GL_POLYGON);		// cloud1 middle
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=500+cloudxoffset+20*cos(i);
            y=625+20*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glBegin(GL_POLYGON);		// cloud1 leftside
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=525+cloudxoffset+15*cos(i);
            y=620+15*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glBegin(GL_POLYGON);		// cloud1 rightside
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=477+cloudxoffset+10*cos(i);
            y=615+10*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glBegin(GL_POLYGON);		// cloud2
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=900-cloudxoffset+25*cos(i);
            y=625+25*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glBegin(GL_POLYGON);		// cloud2
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=925-cloudxoffset+18*cos(i);
            y=615+18*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glBegin(GL_POLYGON);		// cloud1 rightside
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=940-cloudxoffset+10*cos(i);
            y=610+10*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glBegin(GL_POLYGON);		// cloud1 rightside
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=870-cloudxoffset+18*cos(i);
            y=615+18*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glColor3d(0.961,0.871,0.702);//sand
    glBegin(GL_QUADS);
    glVertex2i(0,320);
    glVertex2i(1350,160);
    glColor3d(0.957,0.643,0.376);
    glVertex2i(1350,0);
    glVertex2i(0,0);
    glEnd();
   glPopMatrix();

}

void evebg()
{
    GLfloat x,y;
    glPushMatrix();
    glColor3d(0.0,0.749,1.0);
    glEnable(GL_LINE_SMOOTH);
    glLineWidth(50.0);
    glBegin(GL_LINES);
    glEnd();

    //sky
    glBegin(GL_POLYGON);
    glColor3d(1.0,0.843,0.0);
    glVertex2i(0,700);
    glColor3d(0.580,0.0,0.827);
    glVertex2i(1350,700);
    glColor3d(0.941,0.502,0.502);
    glVertex2i(1350,460);
    glColor3d(1.0,0.388,0.278);
    glVertex2i(800,460);
    glVertex2i(360,460);
    glVertex2i(0,460);
    glEnd();

    glColor3d(1.0,0.498,0.314);//sea
    glBegin(GL_QUADS);
    glVertex2i(0,460);
    glColor3d(1.0,0.388,0.278);
    glVertex2i(1350,460);
    glColor3d(0.098,0.098,0.439);
    glVertex2i(1350,160);
    glColor3d(0.0,0.0,0.545);
    glVertex2i(0,320);
    glEnd();

    glColor3d(1.0,0.549,0.0);
    glBegin(GL_POLYGON);		// sun boundary
      for(float i=0.0f; i<=(PI); i+=0.01f)
           {
            x=50+30*cos(i);
            y=460+30*sin(i);
            glVertex2f(x,y);}
	glEnd();
    glColor3d(1.0,0.271,0.0);
    glBegin(GL_POLYGON);		// sun
      for(float i=0.0f; i<=(PI); i+=0.01f)
           {
            x=50+25*cos(i);
            y=460+25*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glColor3d(1.0,0.498,0.314);
    glBegin(GL_POLYGON);		// cloud1 middle
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=500+cloudxoffset+20*cos(i);
            y=625+20*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glBegin(GL_POLYGON);		// cloud1 leftside
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=525+cloudxoffset+15*cos(i);
            y=620+15*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glBegin(GL_POLYGON);		// cloud1 rightside
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=477+cloudxoffset+10*cos(i);
            y=615+10*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glBegin(GL_POLYGON);		// cloud2
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=900-cloudxoffset+25*cos(i);
            y=625+25*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glBegin(GL_POLYGON);		// cloud2
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=925-cloudxoffset+18*cos(i);
            y=615+18*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glBegin(GL_POLYGON);		// cloud2
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=940-cloudxoffset+10*cos(i);
            y=610+10*sin(i);
            glVertex2f(x,y);}
	glEnd();

    glBegin(GL_POLYGON);		// cloud2
      for(float i=0.0f; i<=(2*PI); i+=0.01f)
           {
            x=870-cloudxoffset+18*cos(i);
            y=615+18*sin(i);
            glVertex2f(x,y);}
	glEnd();
    glColor3d(0.647,0.165,0.165);//sand
    glBegin(GL_QUADS);
    glVertex2i(0,320);
    glVertex2i(1350,160);
    glColor3d(0.0,0.0,0.0);
    glVertex2i(1350,0);
    glVertex2i(0,0);
    glEnd();
    glPopMatrix();
}

void drawobjects()
{
    if(day==1)
    {
    daybg();
    dayumbrellachair();
    people();
    pos+=0.1;
	ship(pos,y);
    glutPostRedisplay();
    daytree();
    }
    else
    {
    evebg();
    eveumbrellachair();
	 pos+=0.1;
	ship(pos,y);
    evetree();
    }
    birds(birdxoffset,birdyoffset);
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    exit(0);
}

void keys(unsigned char key1,int x,int y)
{
	switch(key1)
	{
	case 'd':
	case 'D':
		day=1;
		break;
	case 'e':
	case 'E':
		day=0;
		break;
	/*case 'b':
	case 'B':
		glutDisplayFunc(MainWindowDisp);		// tells glut which function to call to render a screen.
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	glutIdleFunc(update);              	//	glutIdleFunc(update);
    glEnable(GL_SMOOTH);*/

	}
}


void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //	GL_COLOR_BUFFER_BIT -- reset the frame buffer (otherwise, has colors from last draw!)
	glutKeyboardFunc(keys);
	glutMouseFunc(mouse);
	drawobjects();
    glutSwapBuffers();
}


void keyboardFunc( unsigned char key, int x, int y )
{
    switch( key )
    {
    case 'd':
    case 'D':
		day=1;
		main_window= glutCreateWindow("BEACH VIEW");
		//glutSetWindow(main_window);
		//glutDisplayFunc(render);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		gluOrtho2D(0.0,1350.0,0.0,700.0);
		glutDisplayFunc(render);
		break;

    case 'e':
    case 'E':
		day=0;
		main_window= glutCreateWindow("BEACH VIEW");
		//glutSetWindow(main_window);
		//glutDisplayFunc(render);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		gluOrtho2D(0.0,1350.0,0.0,700.0);
		glutDisplayFunc(render);
		break;

     };

}

void MainWindowDisp(void)
{
	glutPostRedisplay();
	glFlush();
	//glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //single buffering
	//glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH); //double buffering
	//	GLUT_SINGLE or GLUT_DOUBLE -- single vs. double buffering.
	//	GLUT_RGB -- specifies color mode is RGB
	//	GLUT_DEPTH -- We need a depth-buffer (can add other similar buffers)
	glutInitWindowSize(1350.0,700.0);	//width, height of the window.
	glutInitWindowPosition(0, 0);	// location on the screen the window appears
	(void)glutCreateWindow("VIEWS");	// creates the window.
	init();		// things to do once.
	glColor3d(0.545,0.0,0.545);
	bitmap_output(-0.350,0.800,0,"COLLEGE : THE OXFORD COLLEGE OF ENGINEERING", GLUT_BITMAP_HELVETICA_18);
	glColor3d(0.502,0.0,0.502);
	bitmap_output(-0.45,0.5, 0,"COMPUTER    GRAHPICS    PROJECT", GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-0.45,0.4, 0,"PROJECT TITLE:      BEACH    VIEW", GLUT_BITMAP_HELVETICA_18);

	glColor3d(0.294,0.0,0.510);
	bitmap_output(-0.20,0.2,0,"PRESS D OR d FOR DAY VIEW ",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-0.20,0.1,0,"PRESS E OR e FOR EVENING VIEW",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-0.20,0.0,0,"CLICK LEFT BUTTON TO EXIT",GLUT_BITMAP_HELVETICA_18);
	glColor3d(0.0,0.0,0.0);
    bitmap_output(-0.20,-0.5,0,"Team members: ",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-0.20,-0.6,0,"RAMYA B      1OX14CS070",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-0.20,-0.7,0,"RASHMI       10X14CS071",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-0.20,-0.8,0,"SWATHI YADAV 1OX14CS099",GLUT_BITMAP_HELVETICA_18);
	bitmap_output(-0.20,-0.9,0,"VINEETHA J   1OX14CS107",GLUT_BITMAP_HELVETICA_18);
	//bitmap_output(-0.20,-0.9,0,"PRESS B OR b TO GO BACK TO MAIN WINDOW",GLUT_BITMAP_HELVETICA_18);
	glutSwapBuffers();
	glutPostRedisplay();
	glFlush();
	glutDisplayFunc(MainWindowDisp);		// tells glut which function to call to render a screen.
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	glutIdleFunc(update);              	//	glutIdleFunc(update);
    glEnable(GL_SMOOTH);
	glutMainLoop();				// once this is called, glut takes over --
	return 0;							// returns only when the window is closed.
}

