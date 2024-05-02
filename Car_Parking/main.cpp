//Student Name: Sayeda Sanzida Ferdous Ruhi
//Student ID: CSE 072 08182

#include<windows.h>
#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>
#include <stdlib.h>
#include<stdio.h>

void init()//initializing window-axises and window-color
{
    glClearColor(0.411,0.411,0.411,0);//105,105,105
    glOrtho(-30,+30,-30,+30,-1,+1);
}

float ax=0, ay=0, Angle=0.00;

void sky()
{
    glBegin(GL_QUADS);
        glColor3f(0.87, 1, 1);//224,255,255
        glVertex2d(30,20);
        glVertex2d(30,30);
        glVertex2d(-30,30);
        glVertex2d(-30,20);
    glEnd();
}

void wall()
{
    glBegin(GL_QUADS);
        glColor3f(0.803, 0.521, 0.247);//205,133,63
        glVertex2d(30,15);
        glVertex2d(30,20);
        glVertex2d(-30,20);
        glVertex2d(-30,15);
    glEnd();
}

void field1()
{
    glBegin(GL_QUADS);
        glColor3f(0.196, 0.803, 0.196);//50, 205, 50
        glVertex2d(10,15);
        glVertex2d(10,0);
        glVertex2d(30,0);
        glVertex2d(30,15);
    glEnd();
}

void field2()
{
    glBegin(GL_QUADS);
        glColor3f(0.196, 0.803, 0.196);//50, 205, 50
        glVertex2d(-30,15);
        glVertex2d(-30,0);
        glVertex2d(-10,0);
        glVertex2d(-10,15);
    glEnd();
}

void field3()
{
    glBegin(GL_QUADS);
        glColor3f(0.196, 0.803, 0.196);//50, 205, 50
        glVertex2d(10,-20);
        glVertex2d(10,-30);
        glVertex2d(30,-30);
        glVertex2d(30,-20);
    glEnd();
}

void field4()
{
    glBegin(GL_QUADS);
        glColor3f(0.196, 0.803, 0.196);//50, 205, 50
        glVertex2d(-30,-20);
        glVertex2d(-30,-30);
        glVertex2d(-10,-30);
        glVertex2d(-10,-20);
    glEnd();
}

void line1()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        glVertex2d(0.15,15);
        glVertex2d(0.15,-30);
    glEnd();
}

void line2()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        glVertex2d(-0.15,15);
        glVertex2d(-0.15,-30);
    glEnd();
}

void mark1()
{
    glBegin(GL_QUADS);
        glColor3f(1, 1, 1);
        glVertex2d(-9.5,-9.75);
        glVertex2d(-9.5,-11.15);
        glVertex2d(-4.5,-11.15);
        glVertex2d(-4.5,-9.75);
    glEnd();
}

void mark2()
{
    glBegin(GL_QUADS);
        glColor3f(1, 1, 1);
        glVertex2d(-19.5,-9.75);
        glVertex2d(-19.5,-11.15);
        glVertex2d(-14.5,-11.15);
        glVertex2d(-14.5,-9.75);
    glEnd();
}

void mark3()
{
    glBegin(GL_QUADS);
        glColor3f(1, 1, 1);
        glVertex2d(4.5,-9.75);
        glVertex2d(4.5,-11.15);
        glVertex2d(9.5,-11.15);
        glVertex2d(9.5,-9.75);
    glEnd();
}

void mark4()
{
    glBegin(GL_QUADS);
        glColor3f(1, 1, 1);
        glVertex2d(14.5,-9.75);
        glVertex2d(14.5,-11.15);
        glVertex2d(19.5,-11.15);
        glVertex2d(19.5,-9.75);
    glEnd();
}

void Car_Body()//polygon
{
    glColor3f(0, 0, 1);
    glBegin(GL_POLYGON);
        //we need to draw from concave position as there is a concave angle
        glVertex2d(3.25,-3);
        glVertex2d(5,-3);
        glVertex2d(5,-5);
        glVertex2d(0,-5);
        glVertex2d(0,-3);
        glVertex2d(1.75,-3);
        glVertex2d(1.75,-2);
        glVertex2d(3.25,-2);
    glEnd();
}

void Tyre(float r)//circle
{
    int i=0;
    float angle=0.0;
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
        for(i=0; i<=500; i++)
        {
            angle=(360*i)/500;
            glVertex2d(r*cos(angle), r*sin(angle));
        }
    glEnd();
}

void tyre_line1()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        glVertex2d(0,0);
        glVertex2d(0,0.5);
    glEnd();
}

void tyre_line2()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        glVertex2d(0,0);
        glVertex2d(0.5,0);
    glEnd();
}

void tyre_line3()
{
    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
        glVertex2d(0,0);
        glVertex2d(-0.5,0);
    glEnd();
}

void tree1()
{
    glPushMatrix();
        glColor3f(0.54, 0.27, 0.07);//139, 69, 19
        glBegin(GL_QUADS);
            glVertex2d(-27,14);
            glVertex2d(-25,14);
            glVertex2d(-25,16);
            glVertex2d(-27,16);
        glEnd();
        glColor3f(0, 1, 0);
        glBegin(GL_TRIANGLES);
            glVertex2d(-23,16);
            glVertex2d(-29,16);
            glVertex2d(-26,19);
        glEnd();
    glPopMatrix();
}

void tree2()
{
    glPushMatrix();
        glColor3f(0.54, 0.27, 0.07);//139, 69, 19
        glBegin(GL_QUADS);
            glVertex2d(27,14);
            glVertex2d(25,14);
            glVertex2d(25,16);
            glVertex2d(27,16);
        glEnd();
        glColor3f(0, 1, 0);
        glBegin(GL_TRIANGLES);
            glVertex2d(23,16);
            glVertex2d(29,16);
            glVertex2d(26,19);
        glEnd();
    glPopMatrix();
}

void stop1()
{
    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(0, 0, 0);
            glVertex2d(-12,14);
            glVertex2d(-11,14);
            glVertex2d(-11,16);
            glVertex2d(-12,16);
        glEnd();
        glBegin(GL_QUADS);
            glColor3f(0.69, 0.13, 0.13);//178, 34, 34
            glVertex2d(-9,16);
            glVertex2d(-9,19);
            glVertex2d(-14,19);
            glVertex2d(-14,16);
        glEnd();
    glPopMatrix();
}

void stop2()
{
    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(0, 0, 0);
            glVertex2d(12,14);
            glVertex2d(11,14);
            glVertex2d(11,16);
            glVertex2d(12,16);
        glEnd();
        glBegin(GL_QUADS);
            glColor3f(0.69, 0.13, 0.13);//178, 34, 34
            glVertex2d(9,16);
            glVertex2d(9,19);
            glVertex2d(14,19);
            glVertex2d(14,16);
        glEnd();
    glPopMatrix();
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);//this function enables color
    sky();
    wall();
    field1();
    field2();
    field3();
    field4();
    line1();
    line2();
    mark1();
    mark2();
    mark3();
    mark4();
    tree1();
    tree2();
    stop1();
    stop2();
    glPushMatrix();
        glTranslated(ax, ay, 0);
        glPushMatrix();
            Car_Body();
            glTranslated(1.75, -5, 0);
            glPushMatrix();
                glRotated(Angle, 0, 0, -1);
                    Tyre(0.5);
                    tyre_line1();
                    tyre_line2();
                    tyre_line3();
            glPopMatrix();
            glTranslated(1.5, 0, 0);
            glPushMatrix();
                glRotated(Angle, 0, 0, -1);
                    Tyre(0.5);
                    tyre_line1();
                    tyre_line2();
                    tyre_line3();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glFlush();//use in 2D
}

void car_move_forward()
{
    Angle=Angle+1;
    ax=ax+0.03;//if we increase value of ax, then it will move to +x
    if(ax>=30.5)
    {
        ax=-30.5;
    }
    if(ax>=5 && ay>=0)
    {
        glutIdleFunc(0);
    }
    if(ax>=5 && ay<=-20)
    {
        glutIdleFunc(0);
    }
    glutPostRedisplay();
}

void car_move_backward()
{
    Angle=Angle-1;
    ax=ax-0.03;//if we decrease value of ax, then it will move to -x
    if(ax<=-30.5)
    {
        ax=30.5;
    }
    if(ax<=-10 && ay>=0)
    {
        glutIdleFunc(0);
    }
    if(ax<=-10 && ay<=-20)
    {
        glutIdleFunc(0);
    }
    glutPostRedisplay();
}

void car_move_up()
{
    Angle=Angle+1;
    ay=ay+0.03;
    if(ay>=15)
    {
        glutIdleFunc(0);
        ay=15;
    }
    if(ay>=0 && ax>=10)
    {
        glutIdleFunc(0);
    }
    if(ay>=0 && ax<=-10)
    {
        glutIdleFunc(0);
    }
    glutPostRedisplay();
}

void car_move_down()
{
    Angle=Angle-1;
    ay=ay-0.03;
    if(ay<=-30.5)
    {
        //ay=15;
        Angle=Angle+1;
        ay=ay+0.03;
    }
    if(ay<=-10 && ax>=10)
    {
        glutIdleFunc(0);
    }
    if(ay<=-10 && ax<=-10)
    {
        glutIdleFunc(0);
    }
    glutPostRedisplay();
}

void specialKey(int key, int x, int y)
{
    switch(key)//as we want to use keys as parameters
    {
    case GLUT_KEY_RIGHT:
        glutIdleFunc(car_move_forward);//this function will run a command till other command is given
        break;
    case GLUT_KEY_LEFT:
        glutIdleFunc(car_move_backward);
        break;
    case GLUT_KEY_UP:
        glutIdleFunc(car_move_up);
        break;
    case GLUT_KEY_DOWN:
        glutIdleFunc(car_move_down);
        break;
    case GLUT_KEY_F2:
        glutIdleFunc(0);//we use 0 here to stop the movement
        break;
    default:
        break;
    }
}

void mouse(int button, int state, int x, int y)
{
    switch(button)
    {
    case GLUT_LEFT_BUTTON:
        if(state==GLUT_DOWN)
        {
            glutIdleFunc(0);
        }
        break;

    case GLUT_RIGHT_BUTTON:
        if(state==GLUT_DOWN)
        {
            glutIdleFunc(0);
        }
        break;

    default:
        break;
    }
}

int main()
{
    int width=glutGet(GLUT_SCREEN_WIDTH);
    int height=glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowSize(width, height);//display size in height and width in pixel
    glutInitWindowPosition(0,0);//display position from x & y axis
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    //glut_rgb is color mode
    //glut_single is 2D mode
    glutCreateWindow("Car Parking Area");
    init();
    glutDisplayFunc(myDisplay);
    glutSpecialFunc(specialKey);
    glutMouseFunc(mouse);
    glutMainLoop();//use to loop the display
    return 0;
}
