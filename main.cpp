#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>
#define PI 3.1416
#include<iostream>
using namespace std;

float p=-80.0,p1=-80;
int c;
static float	tx	=  0.0;
static float	ty	=  0.0;

void init()
{
    glClearColor(0.74902, 0.847059, 0.847059,0.0);  //sets the color value to clear buffer
    glOrtho(-10.0, 10.0, -10.0, 15.0, -10.0, 10.0); //left,right,bottom,top, near, far
}
void circle(float radius_x, float radius_y)
{
	int i = 0;
	float angle = 0.0;

	glBegin(GL_POLYGON);

		for(i = 0; i < 100; i++)
		{
			angle = 2 * PI * i / 100;
			glVertex3f (cos(angle) * radius_x, sin(angle) * radius_y, 0);
		}

	glEnd();
}
void draw()
{
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0,10.0,0);
    circle(1.5,2.5);
}

void plane()
{
    glClearColor(0.74902, 0.847059, 0.847059,0.0);  //sets the color value to clear buffer

    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	draw();
    glTranslatef(0.0,-10.0,0.0);

    glBegin(GL_QUADS);
        glColor3f(0.560784, 0.560784, 0.737255); // It can be any type Gl_POINT,_LINE
        glVertex2d(-1.0, +7.0);
        glColor3f(0.560784, 0.560784, 1.737255);
        glVertex2d(-8.0, +4.0);
        glColor3f(0.560784, 0.560784, 0.737255);
        glVertex2d(-8.0, +3.0);
        glColor3f(0.560784, 0.560784, 0.737255);
        glVertex2d(-0.85, +3.0);
    glEnd();
    glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glVertex2d(1.0, +7.0);
        glColor3f(0.560784, 0.560784, 1.737255);
        glVertex2d(8.0, +4.0);
        glVertex2d(8.0, +3.0);
        glVertex2d(0.85, +3.0);
    glEnd();
    glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glVertex2d(3.0, -6.0);
        glVertex2d(0.4, -5.0);
        glVertex2d(0.4, -6.5);
        glVertex2d(3.0, -6.5);
    glEnd();
    glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glVertex2d(-3.0, -6.0);
        glVertex2d(-0.4, -5.0);
        glVertex2d(-0.4, -6.5);
        glVertex2d(-3.0, -6.5);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glVertex2d(1.5, +10.0);
        glVertex2d(-1.5, +10.0);
        glVertex2d(-0.5, -7.0);
        glVertex2d(0.5, -7.0);
    glEnd();

    glLineWidth(3.0);

    glColor3f(0.560784, 0.560784, 1.0); //RGB Color
   glBegin(GL_LINES); // It can be any type Gl_POINT,_LINE
        glVertex2d(0.0, -3.0);
        glVertex2d(-0.5, -7.0);
    glEnd();
    glColor3f(0.560784, 0.560784, 0.737255); //RGB Color
   glBegin(GL_LINES); // It can be any type Gl_POINT,_LINE
        glVertex2d(0.0, -3.0);
        glVertex2d(0.5, -7.0);
    glEnd();
    glBegin(GL_LINES); // It can be any type Gl_POINT,_LINE
        glVertex2d(0.5, -7.0);
        glVertex2d(-0.5, -7.0);
    glEnd();

    glLineWidth(10.0);
	glColor3f(0.560784, 0.560784, 0.737255);
   // glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2d(0.0, 11.0);
        glVertex2d(-1.0, 10.0);
    glEnd();
    glLineWidth(10.0);
    glBegin(GL_LINES);
        glVertex2d(0.0, 11.0);
        glVertex2d(1.0, 10.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glColor3f(0.1, 0.2, 0.8);// It can be any type Gl_POINT,_LINE
        glVertex2d(-3.0, 4.0);
        glVertex2d(-6.0, 4.0);
        glVertex2d(-6.0, 3.0);
        glVertex2d(-3.0, 3.0);
    glEnd();
        glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glColor3f(0.1, 0.2, 0.8);// It can be any type Gl_POINT,_LINE
        glVertex2d(3.0, 4.0);
        glVertex2d(6.0, 4.0);
        glVertex2d(6.0, 3.0);
        glVertex2d(3.0, 3.0);
    glEnd();

	glPopMatrix();

    glFlush(); //force execution of Gl commands
}
void car()
{
    glClearColor(0.90,0.91, 0.98,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();//static part static thakbe
    glColor3f(0.0, 1.0, 0.0);
	glLineWidth(3.0);
	glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
	glColor3f(0.32, 0.49, 1.46);
        glVertex2d(8.0, 6.0);
        glColor3f(0.32, 0.49, 0.46);
        glVertex2d(-8.0, 6.0);
        glColor3f(0.32, 0.49, 0.46);
        glVertex2d(-8.0, 0.0);
        glColor3f(0.32, 0.49, 1.46);
        glVertex2d(8.0, 0.0);
    glEnd();

    glColor3f(0.90,0.91, 0.98);
    glBegin(GL_TRIANGLES); // It can be any type Gl_POINT,_LINE
        glVertex2d(8.0, 6.0);
        glVertex2d(6.0, 6.0);
        glVertex2d(8.0, 5.0);
    glEnd();

    glColor3f(0.55 ,0.47 ,0.14);
    glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glColor3f(0.55 ,0.47 ,0.14);
        glVertex2d(-1.0, 4.0);
        glColor3f(0.55 ,0.47 ,0.14);
        glVertex2d(-6.0, 4.0);
        glColor3f(0.55 ,0.47 ,1.14);
        glVertex2d(-6.0, 1.0);
        glVertex2d(-1.0, 1.0);
    glEnd();
    glColor3f(0.55 ,0.47 ,0.14);
    glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glColor3f(0.55 ,0.47 ,0.14);
        glVertex2d(1.0, 4.0);
        glColor3f(0.55 ,0.47 ,0.14);
        glVertex2d(6.0, 4.0);
        glColor3f(0.55 ,0.47 ,1.14);
        glVertex2d(6.0, 1.0);
        glVertex2d(1.0, 1.0);
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
    glColor3f(1.55 ,0.47 ,0.14);
        glVertex2d(4.0, 10.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2d(-4.0, 10.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2d(-6.0, 6.0);
        glColor3f(1.55 ,0.47 ,0.14);
        glVertex2d(6.0, 6.0);
    glEnd();
    glColor3f(0.90,0.91,0.98);
    glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glVertex2d(-1.0, 9.5);
        glVertex2d(-3.5, 9.5);
        glVertex2d(-4.5, 6.5);
        glVertex2d(-1.0, 6.5);
    glEnd();
    glColor3f(0.90,0.91,0.98);
    glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glVertex2d(1.0, 9.5);
        glVertex2d(3.5, 9.5);
        glVertex2d(4.5, 6.5);
        glVertex2d(1.0, 6.5);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES); // It can be any type Gl_POINT,_LINE
        glVertex2d(0.0, 10.0);
        glVertex2d(0.0, 0.0);
    glEnd();
    glLineWidth(15);
    glColor3f(0.184314,0.184314,0.309804);
    glBegin(GL_LINES); // It can be any type Gl_POINT,_LINE
        glVertex2d(-8.0, 0.5);
        glVertex2d(-9.0, 0.5);
    glEnd();

        glColor3f(0.184314,0.184314,0.309804);
        glPushMatrix();
        glTranslatef(3.8,-0.1,0);
        circle(1.5,1.5);
        glPopMatrix();

	    glPushMatrix();
        glTranslatef(-3.8,-0.1,0);
        circle(1.5,1.5);
        glPopMatrix();

        glColor3f(1.0, 1.0, 1.0);
        glPushMatrix();
        glTranslatef(3.8,-0.1,0);
        circle(0.8,0.8);
        glPopMatrix();

	    glPushMatrix();
        glTranslatef(-3.8,-0.1,0);
        circle(0.8,0.8);
        glPopMatrix();
    glPopMatrix();
	glFlush();
}
void cycle()
{
    glClearColor(0.90,0.91, 0.98,0);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

	glPushMatrix();//static part static thakbe
//outside circle
	glColor3f(0.184314,0.184314,0.309804);
	 glPushMatrix();
        glTranslatef(6.0,-2.0,0);
        circle(3.0,3.0);
        glPopMatrix();

	    glPushMatrix();
        glTranslatef(-6.0,-2.0,0);

        circle(3.0,3.0);
        glPopMatrix();
    glPopMatrix();
//white circle
    glPushMatrix();
    glColor3f(0.90,0.91, 0.98);
	    glPushMatrix();
        glTranslatef(6.0,-2.0,0);
        circle(2.5,2.5);
        glPopMatrix();

	    glPushMatrix();
        glTranslatef(-6.0,-2.0,0);
        circle(2.5,2.5);
        glPopMatrix();
    glPopMatrix();
//Inner small circle
    glPushMatrix();
    glColor3f(0.184314,0.184314,0.309804);
	 glPushMatrix();
        glTranslatef(6.0,-2.0,0);
        circle(1.0,1.0);
        glPopMatrix();

	    glPushMatrix();
        glTranslatef(-6.0,-2.0,0);

        circle(1.0,1.0);
        glPopMatrix();
    glPopMatrix();
//Paddle circle
        glPushMatrix();
        glTranslatef(-1.0,-2.0,0);
        circle(1.0,1.0);
        glPopMatrix();

    glPushMatrix();
//paddle vertical
        glColor3f(0.0, 1.0, 0.0);
        glLineWidth(10.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(-1.0, -2.0);
        glColor3f(0.65,0.50 ,0.39);
        glVertex2d(-0.5, -4.0);
    glEnd();
//paddle horizontal
    glColor3f(0.0,1 ,0);
    glLineWidth(10.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(-1.2, -4.0);
        glColor3f(0.65,0.50 ,0.39);
        glVertex2d(-0.09, -4.2);
    glEnd();
//left baka
    glColor3f(0.184314,0.184314,0.309804);
    glLineWidth(12.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(-6.0, -2.0);
        glVertex2d(-2.5, 1.8);
    glEnd();
//seat er shather line
    glColor3f(0.184314,0.184314,0.309804);
    glLineWidth(12.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(-1.0, -2.0);
        glVertex2d(-4.0, 5.2);
    glEnd();
//seat
    glColor3f(1.0, 1.0, 0.0);
    glLineWidth(20.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(-2.5, 5.2);
        glColor3f(0.65,0.50 ,0.39);
        glVertex2d(-5.0, 5.2);
    glEnd();
//middle horizontal
    glColor3f(0.184314,0.184314,0.309804);
    glLineWidth(12.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(-3.2, 3.2);
        glVertex2d(1.7, 3.2);
    glEnd();
//right line paddle er shathe
    glColor3f(0.184314,0.184314,0.309804);
    glLineWidth(12.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(-1.0, -2.0);
        glVertex2d(2.5, 4.7);
    glEnd();
//handle er shather line
    glColor3f(0.184314,0.184314,0.309804);
    glLineWidth(12.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(6.0, -2.0);
        glVertex2d(2.1, 5.5);
    glEnd();
//left horizontal
    glColor3f(0.184314,0.184314,0.309804);
    glLineWidth(12.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
	glColor3f(0.184314,0.184314,0.309804);
        glVertex2d(-1.5, -2.0);
        glVertex2d(-6, -2.0);
    glEnd();
//handle niche
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(12.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(3.0, 5.9);
        glColor3f(0.65,0.50 ,0.39);
        glVertex2d(1.1, 5.5);
    glEnd();
//handle upore
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(12.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(3.0, 5.9);
        glColor3f(0.65,0.50 ,0.39);
        glVertex2d(1.1, 6.9);
    glEnd();

//chain
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(-5.5, -2.8);
        glVertex2d(-5.0, -4.3);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(-6.8, -2.6);
        glVertex2d(-8.0, -3.5);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(-6.5, -1.2);
        glVertex2d(-8.0, -0.5);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(5.5, -2.8);
        glVertex2d(5.0, -4.3);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(6.8, -2.6);
        glVertex2d(8.0, -3.5);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(6.5, -1.2);
        glVertex2d(8.0, -0.5);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
	glBegin(GL_LINE_LOOP); // It can be any type Gl_POINT,_LINE
        glVertex2d(5.0, -2.0);
        glVertex2d(3.5, -2.0);
    glEnd();

	glPopMatrix();

	glFlush();
}
void plane1()
{
    glPushMatrix();
    glTranslatef(0.0,0.0,0.0);
    glPopMatrix();
    ty=0.0;
    tx=0.0;
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(tx,ty,0.0);
    while(ty <=.01)
                {
                    plane();
                    glTranslatef(0.0,ty,0);
                    ty+=.000001;
                }
    glPopMatrix();
    glFlush();
}
void car1()
{

    glPushMatrix();
    glTranslatef(0,0,0);
    glPopMatrix();
    tx=0.0;
    ty=0.0;
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(tx,ty,0);
    while(tx <=.01)
                {
                    car();
                    glTranslatef(tx,0,0);
                    tx+=.000001;
                }
    glPopMatrix();
    glFlush();
}
void cycle1()
{
    glPushMatrix();
    glPushMatrix();
    glTranslatef(0,0,0);
    glPopMatrix();
    tx=0.0;
    ty=0.0;
    //glColor3f(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(tx,ty,0);
    while(tx <=.01)
                {
                    cycle();
                    glTranslatef(tx,0,0);
                    tx+=.000001;
                }
    glPopMatrix();
    glPopMatrix();
	glFlush();
}
void background()
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();//static part static thakbe

    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_QUADS); // It can be any type Gl_POINT,_LINE
        glVertex2d(10.0, 15.0);
        glVertex2d(-10.0, 15.0);
        glVertex2d(-10.0, 2.0);
        glVertex2d(10.0, 2.0);
    glEnd();
    glPopMatrix();
    glFlush();

}
void spe_key(unsigned char key, int x, int y)
{

	switch (key) {

		case 'a':
		    PlaySound("Aeroplane.wav", NULL, SND_FILENAME| SND_ASYNC);
		   // PlaySound("Airplane_fly.wav", NULL, SND_FILENAME| SND_ASYNC);
                plane();
                c=1;
				break;
        case 'A':
		    PlaySound("Aeroplane.wav", NULL, SND_FILENAME| SND_ASYNC);
		   // PlaySound("Airplane_fly.wav", NULL, SND_FILENAME| SND_ASYNC);
                plane();
                c=1;
				break;
        case 'c':
            PlaySound("car.wav", NULL, SND_FILENAME| SND_ASYNC);
                background();
                c=3;
                car();
                glutDisplayFunc(car); // call display function
				break;
        case 'C':
            PlaySound("car.wav", NULL, SND_FILENAME| SND_ASYNC);
                background();
                c=3;
                car();
                glutDisplayFunc(car); // call display function
				break;
        case 'b':
            PlaySound("bicycle.wav", NULL, SND_FILENAME| SND_ASYNC);
                c=2;
                cycle();
                glutDisplayFunc(cycle); // call display function
				break;
        case 'B':
            PlaySound("bicycle.wav", NULL, SND_FILENAME| SND_ASYNC);
                c=2;
                cycle();
                glutDisplayFunc(cycle); // call display function
				break;
        default:
			break;
	}
}
void next(int key, int x, int y)
{

	switch (key) {


		case GLUT_KEY_RIGHT:
		    if(c==1)
            {
                PlaySound("Airplane_fly.wav", NULL, SND_FILENAME| SND_ASYNC);
                plane1();
            }
            else if(c==2)
            {
                PlaySound("bell_cycle.wav", NULL, SND_FILENAME| SND_ASYNC);
                cycle1();
                glutDisplayFunc(cycle1);
            }
            else if(c==3)
            {
                PlaySound("Horn Honk-SoundBible.com-1162546405.mp3", NULL, SND_FILENAME| SND_ASYNC);
                car1();
                glutDisplayFunc(car1);
            }
				break;
	  default:
			break;
	}
}

void myDisplay()
{
}
int main()
{
    cout<<"Vehicle Learning Tool\nYou need to press:\nA for Aeroplane\nB for Bicycle\nC for Car\nRight Arrow for transition";

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Size of the window
    glutInitWindowPosition(350, 70); // location of the window
    glutCreateWindow("Demo Application"); // Create window with this name
    init(); // call initialize function
    //glutSpecialFunc(spe_key);//up,down,left......
    glutDisplayFunc(myDisplay); // call display function
    glutKeyboardFunc(spe_key);
    glutSpecialFunc(next);
    glutMainLoop();
    return 0;
}

