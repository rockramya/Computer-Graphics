#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<windows.h>
#include<sal.h>



double PI = 3.142;
int i = 0, j = 0, fg = 0;
float drawangle, x1 = 1, x2 = 1;
bool pause, pause1, pause2, pause3, pause4, pause5, pause6;
float x4 = 0, y4 = 0;
float x3 = 0, y3 = 0;

int start = 0;
int t = 1;
float xs = 90;
float ys = -42;

char* ptr1, * ptr2, * ptr3, * ptr4, * ptr5, * ptr6, * ptr7, * ptr8, * ptr9, * db1;
const float DEG2RAD = 3.14159 / 180;
int flag = 0, count = 0, count1 = 0, dt = 0, dd = 0, dx = 0, da = 0, db = 0, dat1 = 0, dat2 = 0;

int len1, len2, len3, len4, len5, len6, len7;

int dbFlag =0,dbFlag1=0,dbFlag2=0,dbFlag3=0;
float dbConx = -2, dbCony = -19, dbConx1 = -2, dbCony1 = -19, dbReq = -2, dbRes = -19;
float angle, p1 = -48.0, p2 = 20.0, p3 = 10.0, p4 = -15.0, p5 = -14.0, p6 = 50.0, p7 = -60.0, p8 = -25.0, p9 = -15.0, p10 = -20.0, p11 = 7.0, p12 = 72.0,
p13 = 50.0, p14 = 27.0, p15 = 48.0, p16 = -30.0, p17 = 10.0, p18 = -19.0;
float pos1 = -40.0, pos2 = 50.0;


void one();
void download();
void response();
void downloading();
void upload();


void* currentfont;

//font for text
void setFont(void* font)
{
    currentfont = font;
}

//function to write text
void drawstring(float x, float y, float z, const char* string)
{
    char* c;
    int len = (int)strlen(string);
    int i;
    glRasterPos3f(x, y, z);
    for (i = 0; i < len; i++)
    {
        glColor3f(0.0, 0.0, 0.0);
        glutBitmapCharacter(currentfont, string[i]);
    }

}


//functions for objection creation

void drawLogo()                     // S Logo
{
    glColor3f(0, 0.1, 0.7);//middle
    glBegin(GL_POLYGON);
    glVertex2f(-20, 2);
    glVertex2f(10, 2);
    glVertex2f(20, 7);
    glVertex2f(-10, 7);
    glEnd();

    glColor3f(0.7, 0.1, 0);//left
    glBegin(GL_POLYGON);
    glVertex2f(-20, 3);
    glVertex2f(-10, 8);
    glVertex2f(-10, 25);
    glVertex2f(-20, 30);
    glEnd();

    glColor3f(0, 0.1, 0.7);//top
    glBegin(GL_POLYGON);
    glVertex2f(-10, 26);
    glVertex2f(10, 26);
    glVertex2f(20, 31);
    glVertex2f(-20, 31);
    glEnd();

    glColor3f(0.7, 0.1, 0);//right
    glBegin(GL_POLYGON);
    glVertex2f(10, 1);
    glVertex2f(20, 6);
    glVertex2f(20, -21);
    glVertex2f(10, -16);
    glEnd();

    glColor3f(0, 0.1, 0.7);//bottom
    glBegin(GL_POLYGON);
    glVertex2f(-10, -17);
    glVertex2f(10, -17);
    glVertex2f(20, -22);
    glVertex2f(-20, -22);
    glEnd();
}

void drawTable()
{
    glColor3f(0.8, 0.4, 0);//frontside
    glBegin(GL_POLYGON);
    glVertex2f(-50, -27);
    glVertex2f(50, -27);
    glVertex2f(50, -37);
    glVertex2f(-50, -37);
    glEnd();

    glColor3f(0.8, 0.4, 0);//leg1eft
    glBegin(GL_POLYGON);
    glVertex2f(-50, -32);
    glVertex2f(-45, -32);
    glVertex2f(-45, -77);
    glVertex2f(-50, -77);
    glEnd();

    glColor3f(0.8, 0.4, 0);//legright
    glBegin(GL_POLYGON);
    glVertex2f(50, -32);
    glVertex2f(45, -32);
    glVertex2f(45, -77);
    glVertex2f(50, -77);
    glEnd();

    glColor3f(0.5, 0.1, 0);//leg rightinside
    glBegin(GL_POLYGON);
    glVertex2f(40, -37);
    glVertex2f(37, -37);
    glVertex2f(37, -55);
    glVertex2f(40, -55);
    glEnd();

    glColor3f(0.5, 0.1, 0);//leg leftinside
    glBegin(GL_POLYGON);
    glVertex2f(-40, -37);
    glVertex2f(-37, -37);
    glVertex2f(-37, -55);
    glVertex2f(-40, -55);
    glEnd();

    glColor3f(0.5, 0.1, 0);//surface
    glBegin(GL_POLYGON);
    glVertex2f(-40, -12);
    glVertex2f(40, -12);
    glVertex2f(50, -27);
    glVertex2f(-50, -27);
    glEnd();

    glColor3f(0.5, 0.1, 0);  //frontleftleg3d
    glBegin(GL_POLYGON);
    glVertex2f(-45, -37);
    glVertex2f(-43, -37);
    glVertex2f(-43, -72);
    glVertex2f(-45, -77);
    glEnd();

    glColor3f(0.5, 0.1, 0);   //frontrightleg3d
    glBegin(GL_POLYGON);
    glVertex2f(45, -37);
    glVertex2f(43, -37);
    glVertex2f(43, -72);
    glVertex2f(45, -77);
    glEnd();
}

void drawLaptop()
{
    glColor3f(0.5, 0.5, 0.5);//bottompart
    glBegin(GL_POLYGON);
    glVertex2f(-10, -12);
    glVertex2f(10, -12);
    glVertex2f(15, -22);
    glVertex2f(-15, -22);
    glEnd();

    glColor3f(0, 0, 0.5);//bottompart
    glBegin(GL_POLYGON);
    glVertex2f(-9.5, -13);
    glVertex2f(9.5, -13);
    glVertex2f(13, -20);
    glVertex2f(-13, -20);
    glEnd();

    glColor3f(0, 0, 0);//screen
    glBegin(GL_POLYGON);
    glVertex2f(-10, 13);
    glVertex2f(10, 13);
    glVertex2f(10, -12);
    glVertex2f(-10, -12);
    glEnd();

    glColor3f(1, 0, 1);//ALIENWARE
    glBegin(GL_LINES);
    glVertex2f(-6, -11);
    glVertex2f(6, -11);
    glEnd();

    glColor3f(0.4, 0, 1);//innerscreen
    glBegin(GL_POLYGON);
    glVertex2f(-9, 11);
    glVertex2f(9, 11);
    glColor3f(1, 1, 1);
    glVertex2f(9, -10);
    glVertex2f(-9, -10);
    glEnd();

    glColor3f(0, 0, 0);//bottom3d
    glBegin(GL_POLYGON);
    glVertex2f(-15, -22);
    glVertex2f(15, -22);
    glVertex2f(14, -23);
    glVertex2f(-14, -23);
    glEnd();
}
void drawWindow()
{
    glColor3f(0.3, 0, 0);//window
    glBegin(GL_POLYGON);
    glVertex2f(-35, 80);
    glVertex2f(35, 80);
    glVertex2f(35, 18);
    glVertex2f(-35, 18);
    glEnd();

    glColor3f(1, 1, 0.6);//innerwindow
    glBegin(GL_POLYGON);
    glVertex2f(-34, 78);

    glVertex2f(34, 78);
    glColor3f(0.1, 0.9, 1);
    glVertex2f(34, 20);
    glVertex2f(-34, 20);
    glEnd();
}

void drawWall()
{
    glColor3f(1, 0.6, 0.2);//wall
    glBegin(GL_POLYGON);
    glVertex2f(-90, 100);
    glVertex2f(90, 100);
    glVertex2f(90, -24);
    glVertex2f(-90, -24);
    glEnd();

    glColor3f(1, 0.9, 0.2);//leftwall
    glBegin(GL_POLYGON);
    glVertex2f(-100, 100);
    glVertex2f(-90, 100);
    glVertex2f(-90, -24);
    glVertex2f(-140, -100);
    glEnd();

    glColor3f(1, 0.9, 0.2);//rightwall
    glBegin(GL_POLYGON);
    glVertex2f(100, 100);
    glVertex2f(90, 100);
    glVertex2f(90, -24);
    glVertex2f(140, -100);
    glEnd();
}

void drawFloor()
{
    glColor3f(0.6, 0.2, 0.1);//floor
    glBegin(GL_POLYGON);
    glVertex2f(-90, -24);
    glVertex2f(90, -24);
    glVertex2f(140, -100);
    glVertex2f(-140, -100);
    glEnd();
}



void draw(float radius)            //used to create a circle shape like figure.
{
    float delta_theta = 0.001;
    glBegin(GL_POLYGON); // OR GL_LINE_LOOP


    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    for (drawangle = 0; drawangle < 2 * 3.1415; drawangle += delta_theta)
        glVertex3f(radius * cos(drawangle), radius * sin(drawangle), 0);

    glEnd();

}




void client()     //this function is to design the system(monitor and CPU)
{

    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex2i(30, 60);
    glVertex2i(80, 60);
    glVertex2i(80, 115);
    glVertex2i(30, 115);
    glEnd();

    glColor3f(0.4, 0, 1);  // Inner Screen
    glBegin(GL_POLYGON);
    glVertex2f(32.0, 64.0);
    glVertex2f(78.0, 64.0);
    glColor3f(1, 1, 1);
    glVertex2f(78.0, 112.0);
    glVertex2f(32.0, 112.0);
    glEnd();

    glColor3f(0.22, 0.22, 0.22); //base support
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(30.0, 44.0);
    glVertex2f(80.1, 44.0);
    glVertex2f(80.1, 60.0);
    glVertex2f(30.0, 60.0);
    glEnd();


    glColor3f(0.5, 0.5, 0.5);   // handle for holding base support
    glBegin(GL_POLYGON);
    glVertex2f(51.0, 34.0);
    glVertex2f(51.0, 44.0);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(59.0, 44.0);
    glVertex2f(59.0, 34.0);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(64.0, 34.0);
    glVertex2f(64.0, 32.0);
    glVertex2f(46.0, 32.0);
    glVertex2f(46.0, 34.0);
    glColor3f(0.22, 0.22, 0.22);
    glVertex2f(51.0, 34.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f(29.9, 44);
    glVertex2f(29.99, 115.2);
    glVertex2f(80.1, 44);
    glVertex2f(80.1, 115.2);
    glVertex2f(29.9, 115.2);
    glVertex2f(80.1, 115.29);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);  //background cpu layout of client
    glBegin(GL_POLYGON);
    glVertex2f(88.0, 30.0);
    glVertex2f(112.0, 30.0);
    glVertex2f(112.0, 120.0);
    glVertex2f(88.0, 120.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.5); //cpu of client
    glBegin(GL_POLYGON);
    glVertex2f(90.0, 32.0);
    glVertex2f(110.0, 32.0);
    glVertex2f(110.0, 115.0);
    glVertex2f(90.0, 115.0);
    glEnd();


    glColor3f(0.22, 0.22, 0.22);
    glBegin(GL_POLYGON);
    glVertex2f(92.0, 103.0);
    glVertex2f(108.0, 103.0);
    glVertex2f(108.0, 112.0);
    glVertex2f(92.0, 112.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(95.0, 89.0);
    glVertex2f(103.0, 89.0);
    glVertex2f(103.0, 98.0);
    glVertex2f(95.0, 98.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(105.0, 95.0);
    glVertex2f(108.0, 95.0);
    glVertex2f(108.0, 98.0);
    glVertex2f(105.0, 98.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(105.0, 89.0);
    glVertex2f(108.0, 89.0);
    glVertex2f(108.0, 92.0);
    glVertex2f(105.0, 92.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(3.5);
    glBegin(GL_POINTS);
    glVertex2f(93.0, 96.0);
    glVertex2f(93.0, 91.0);
    glEnd();



    glColor3f(1.0, 1.0, 1.0);
    glPointSize(0.5);
    glBegin(GL_POINTS);
    glVertex2f(106.0, 96.5);
    glVertex2f(107.0, 96.5);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glPointSize(0.5);
    glBegin(GL_POINTS);
    glVertex2f(106.0, 90.5);
    glVertex2f(107.0, 90.5);
    glEnd();

    glColor3f(2.0, 0.2, 0.2);
    glBegin(GL_LINES);
    glVertex2f(92.0, 80.0);
    glVertex2f(108.0, 80.0);
    glEnd();

    glColor3f(2.0, 0.2, 0.2);
    glBegin(GL_LINES);
    glVertex2f(92.0, 75.0);
    glVertex2f(108.0, 75.0);
    glEnd();

    glColor3f(2.0, 0.2, 0.2);
    glBegin(GL_LINES);
    glVertex2f(92.0, 70.0);
    glVertex2f(108.0, 70.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(97.5, 65.0);
    glVertex2f(102.5, 65.0);
    glVertex2f(102.5, 41.0);
    glVertex2f(97.5, 41.0);
    glEnd();

    glColor3f(2.55, 2.55, 0.2);   //yellow point on cpu
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(100.0, 58.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);    //blue point on cpu
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(100.0, 48.0);
    glEnd();

}
void server() // this function is to design the central server.
{
    glColor3f(0.5, 0.5, 0.5);     //Background layout of server
    glBegin(GL_POLYGON);
    glVertex2f(175.0, 100.0);
    glVertex2f(225.0, 100.0);
    glVertex2f(225.0, 280.0);
    glVertex2f(175.0, 280.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.0);  //server
    glBegin(GL_POLYGON);
    glVertex2f(177.2, 104.0);
    glVertex2f(222.8, 104.0);
    glVertex2f(222.8, 276.0);
    glVertex2f(177.2, 276.0);
    glEnd();

    glColor3f(2.55, 2.55, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(177.2, 139.0);
    glVertex2f(222.8, 139.0);
    glVertex2f(222.8, 141.0);
    glVertex2f(177.2, 141.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(177.2, 129.0);
    glVertex2f(222.8, 129.0);
    glVertex2f(222.8, 131.0);
    glVertex2f(177.2, 131.0);
    glEnd();

    glColor3f(0.8, 0.5, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(207.0, 233.0);
    glVertex2f(222.8, 233.0);
    glVertex2f(222.8, 240.0);
    glVertex2f(207.0, 240.0);
    glEnd();

    glColor3f(0.5, 0.4, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(207.0, 220.0);
    glVertex2f(222.8, 220.0);
    glVertex2f(222.8, 227.0);
    glVertex2f(207.0, 227.0);
    glEnd();

    glColor3f(2.55, 2.55, 0.2);
    glBegin(GL_POLYGON);
    glVertex2f(207.0, 207.0);
    glVertex2f(222.8, 207.0);
    glVertex2f(222.8, 214.0);
    glVertex2f(207.0, 214.0);
    glEnd();

    glColor3f(0.22, 0.22, 0.22); //rectangular box of server that has dots
    glBegin(GL_POLYGON);
    glVertex2f(182.0, 238.0);
    glVertex2f(190.0, 238.0);
    glVertex2f(190.0, 271.0);
    glVertex2f(182.0, 271.0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);  //Green Dot point
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(186.0, 260.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.0); //Red Dot Point
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(186.0, 252.0);
    glEnd();



}


void draw_database(GLfloat radius, GLfloat height, GLubyte R, GLubyte G, GLubyte B)         //Database
{
    GLfloat x = 0.0;
    GLfloat y = 0.0;
    GLfloat angle = 0.0;
    GLfloat angle_stepsize = 0.1;


    glColor3ub(R - 40, G - 40, B - 40);  //Draw tube in form of cylinder
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        glVertex3f(x, y, 0.0);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glVertex3f(radius, 0.0, 0.0);
    glEnd();

    /** Draw the circle on top of cylinder */
    glColor3ub(R, G, B);
    glBegin(GL_POLYGON);
    angle = 0.0;
    while (angle < 2 * PI) {
        x = radius * cos(angle);
        y = radius * sin(angle);
        glVertex3f(x, y, height);
        angle = angle + angle_stepsize;
    }
    glVertex3f(radius, 0.0, height);
    glEnd();
}


void bgpolygon()                    //  purple shade of screen where architecture is displayed
{
    glColor3f(0.6, 0.4, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-95, 92);
    glVertex2f(95, 92);
    glVertex2f(95, -93);
    glVertex2f(-95, -93);
    glEnd();
}



void drawhuman(float xs, float ys, int t)
{
    if (ys > 5)
        t = 1;                 //stop movement of man
    if (t == 1)
    {


        glPushMatrix();
        glTranslatef(xs, ys, 0);
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2f(0, -2);
        glVertex2f(6, -2);
        glVertex2f(6, 15);
        glVertex2f(0, 15);
        glEnd();


        // Shirt
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 1);
        glVertex2f(1, -2);
        glVertex2f(5, -2);
        glVertex2f(5, -16);
        glVertex2f(1, -16);
        glEnd();
        // Pants
        glBegin(GL_POLYGON);
        glColor3f(0.8, 0.70, 0);
        glVertex2f(2, 15);
        glVertex2f(5, 15);
        glVertex2f(5, 18);
        glVertex2f(2, 18);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0.8, 0.70, 0);
        glVertex2f(1, 16);
        glVertex2f(6, 16);
        glVertex2f(6, 23);
        glVertex2f(1, 23);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2f(1, 21);
        glVertex2f(6, 21);
        glVertex2f(6, 23);
        glVertex2f(1, 23);
        glEnd();
        glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2f(5, 18);
        glVertex2f(6, 18);
        glVertex2f(6, 23);
        glVertex2f(5, 23);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.8, 0.2, 0);
        glVertex2f(-1, -16);
        glVertex2f(5, -16);
        glVertex2f(5, -18);
        glVertex2f(-1, -18);
        glEnd();





        glPopMatrix();
        glutPostRedisplay();
    }
}





//UPLOAD AND DOWNLOAD FUNCTIONS BETWEEN CLIENT3 AND 4

void upload4() // used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0, 0, 0);
    drawstring(-65.0, -5.0, 0.0, " D A T A - 2  U P L O A D E D ");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();
}
void uploading4()// used to display the bitmap characters.
{

    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0, 0, 0);
    drawstring(-65.0, -5.0, 0.0, " U P L O A D I N G  D A T A - 2 ...");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();
}
void download4()// used to display the bitmap characters.
{

    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-65.0, -5.0, 0.0, "D A T A - 1   D O W N L O A D E D");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();
}
void downloading4()// used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-65.0, -5.0, 0.0, " D O W N L O A D I N G   D A T A - 1 ...");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();

}


void download3()// used to display the bitmap characters.
{

    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-65.0, -5.0, 0.0, "D A T A - 2   D O W N L O A D E D ");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();

}
void downloading3()// used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-65.0, -5.0, 0.0, " D O W N L O A D I N G   D A T A - 2 ...");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();
}


void upload3()// used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-65.0, 5.0, 0.0, "D A T A - 1   U P L O A D E D");
    glPopMatrix();
    glutPostRedisplay();
    glFlush();

}

void uploading3()// used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-65.0, 5.0, 0.0, "U P L O A D I N G   D A T A - 1 ...");
    glPopMatrix();

    glutPostRedisplay();
    glFlush();
}


void upload()//this function displays bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-175.0, -5.0, 0.0, "U P L O A D E D ...");
    glPopMatrix();

    glutPostRedisplay();
    glFlush();



    glFlush();

}

void uploading()//this function displays bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-170.0, -10.0, 0.0, "D A T A    U P L O A D I N G ");
    glPopMatrix();
    glutPostRedisplay();
    glFlush();

}
void upload2()// used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-170.0, -5.0, 0.0, "D A T A   U P L O A D E D ");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();
}

void uploading2()// used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-170.0, -5.0, 0.0, "D A T A    U P L O A D I N G ");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();



}
void downloading2()// used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-170.0, -5.0, 0.0, "D A T A    D O W N L O A D S");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();
}
void download2()// used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-170.0, -10.0, 0.0, "D A T A    D O W N L O A D I N G ");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();


}



void downloading()// used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-170.0, -5.0, 0.0, "D A T A    D O W N L O A D I N G ");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();



}
void download()// used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-170.0, -10.0, 0.0, "D A T A    D O W N L O A D E D ");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();



}




void dbConnect()   //Connects database
{

        glPushMatrix();
        glPointSize(6.0);
        glColor3f(0.0, 0.22, 0.22);
        glBegin(GL_POINTS);
        glVertex2f(dbConx, dbCony);
        glEnd();
        glPopMatrix();

        glFlush();

}
void dbConnect1()   //Connects database
{

    glPushMatrix();
    glPointSize(6.0);
    glColor3f(0.0, 0.22, 0.22);
    glBegin(GL_POINTS);
    glVertex2f(dbConx1, dbCony1);
    glEnd();
    glPopMatrix();

    glFlush();

}

void dbConnect2() {
    glPushMatrix();
    glPointSize(6.0);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2f(dbReq, dbRes);
    glEnd();
    glPopMatrix();

    glFlush();
}


void fourfourU()//uploading function for the client 4
{

    if (p15 == 48.0 && p16 >= -30.0 && p16 < 8.0)
    {
        p16 = p16 + 0.08;

        glutPostRedisplay();
    }
    else
    {
        if (p15 <= 48.0 && p15 > 11.0)
        {
            p15 = p15 - 0.08;
            glutPostRedisplay();
        }
    }
    if (p15 > 11.0)
    {

        glPushMatrix();
        glColor3f(0.6, 0.6, 0.6);
        uploading4();
        glPopMatrix();

    }
    else
    {
        glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        upload4();
        //uploading4();
        glPopMatrix();
        dbFlag = 1;
    }
    if(dbFlag==1){

        if (dbConx == -2 && dbCony <= -19 && dbCony > -31.5) {
            dbCony = dbCony - 0.05;
            glutPostRedisplay();
        }
    }



}

void fourfourD() //download function for client 4.
{
    if (dbFlag3 == 0) {
        if (dbReq == -2 && dbRes <= -19 && dbRes > -31.5) {
            dbRes = dbRes - 0.05;
            glutPostRedisplay();
        }
        else {
            dbFlag3 = 2;
            dbRes = -31.5;
            Sleep(500);
        }

    }
    if (dbFlag3 == 2) {
        if (dbReq == -2 && dbRes <= -19 && dbRes >= -31.5) {
            dbRes = dbRes + 0.05;
            glutPostRedisplay();
        }
        else {
            dbFlag3 = 1;
            dbRes = -19;
        }

    }
    if (dbFlag3 == 1) {
        if (p17 == 10.0 && p18 <= -19.0 && p18 > -30.0)
        {
            p18 = p18 - 0.08;

            glutPostRedisplay();
        }
        else
        {
            if (p17 >= 8.0 && p17 < 43.0)
            {
                p17 = p17 + 0.08;
                glutPostRedisplay();
            }
        }

        if (p17 < 42.0)
        {
            glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            downloading4();
            glPopMatrix();

        }
        else
        {
            glPushMatrix();
            glColor3f(0.0, 0.0, 0.0);
            //downloading4();
            download4();
            glPopMatrix();


        }
    }

}



void threethreeU() //upload fuction for client 3.
{
    if (p13 == 50.0 && p14 <= 27.0 && p14 > 15.0)
    {
        p14 = p14 - 0.08;

        glutPostRedisplay();
    }
    else
    {
        if (p13 <= 50.0 && p13 > 11.0)
        {
            p13 = p13 - 0.08;
            glutPostRedisplay();
        }
    }

    if (p13 > 14.0)
    {

        glPushMatrix();
        glColor3f(0.6, 0.6, 0.6);
        uploading3();
        glPopMatrix();

    }
    else
    {
        glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        //uploading3();
        upload3();
        glPopMatrix();
        dbFlag1 = 1;

    }
    if (dbFlag1 == 1) {           //to store data in database

        if (dbConx1 == -2 && dbCony1 <= -19 && dbCony1 > -31.5) {
            dbCony1 = dbCony1 - 0.05;
            glutPostRedisplay();
        }
    }

}

void threethreeD()//download function for client 3.
{
    if (dbFlag2 == 0) {
        if (dbReq==-2 && dbRes <= -19 && dbRes > -31.5) {
            dbRes = dbRes - 0.05;
            glutPostRedisplay();
        }
        else {
            dbFlag2 = 2;
            dbRes = -31.5;
            Sleep(500);
        }

    }
    if (dbFlag2 == 2) {
        if (dbReq == -2 && dbRes <= -19 && dbRes >=-31.5) {
            dbRes = dbRes +0.05;
            glutPostRedisplay();
        }
        else {
            dbFlag2 = 1;
            dbRes = -19;
            Sleep(500);
        }

    }
    if (dbFlag2 == 1) {
        if (p11 == 7.0 && p12 >= 72.0 && p12 < 78.0)
        {
            p12 = p12 + 0.08;

            glutPostRedisplay();
        }
        else
        {
            if (p11 >= 7.0 && p11 < 50.4)
            {
                p11 = p11 + 0.08;
                glutPostRedisplay();
            }

        }
        if (p11 < 49.0)
        {

            glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            downloading3();
            glPopMatrix();

        }
        else
        {

            glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            download3();
            glPopMatrix();
        }
    }
}




void twotwoD()//download function for client 2.
{
    if (p9 == -15.0 && p10 <= -20.0 && p10 > -35.0)
    {
        p10 = p10 - 0.08;

        glutPostRedisplay();
    }
    else
    {
        if (p9 <= -15.0 && p9 > -51.0)
        {
            p9 = p9 - 0.08;
            glutPostRedisplay();
        }
    }

    if (p9 > -15.0)
    {

        glPushMatrix();
        glColor3f(0.6, 0.6, 0.6);
        downloading2();
        glPopMatrix();

    }
    else
    {

        glPushMatrix();
        glColor3f(0.6, 0.6, 0.6);
        download2();
        glPopMatrix();

    }
}






void twotwoU()//upload function for client 2.
{
    if (p7 == -60.0 && p8 >= -25.0 && p8 < -8.0)
    {
        p8 = p8 + 0.08;

        glutPostRedisplay();
    }
    else
    {
        if (p8 >= -60.0 && p7 < -15.0)
        {
            p7 = p7 + 0.08;
            glutPostRedisplay();
        }
    }

    if (p7 < -15.0)
    {
        glPushMatrix();
        glColor3f(0.6, 0.6, 0.6);
        uploading2();
        glPopMatrix();

    }
    else
    {

        glPushMatrix();
        glColor3f(0.6, 0.6, 0.6);
        upload2();
        glPopMatrix();

    }



}






void oneoneD()//download function for client 1.
{
    if (flag == 1)
    {
        if (p5 <= -14.0 && p6 == 50.0 && p5 > -41.0)
        {
            p5 = p5 - 0.08;

            glutPostRedisplay();
        }
        else
        {
            if (p5 <= -2.0 && p6 < -20.0)
            {
                p6 = p6 + 0.08;
                glutPostRedisplay();
            }
        }



        glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);

        glPopMatrix();

        if (p6 < -20.0)
        {
            glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            downloading();
            glPopMatrix();

        }
        else
        {

            glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            download();
            glPopMatrix();

        }


    }
}



void request()// used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-170.0, 5.0, .0, " H A N D S H A K E   P R O C E S S..");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();

}
void response()// used to display the bitmap characters.
{
    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    setFont(GLUT_BITMAP_9_BY_15);
    glColor3f(0.0, 0.0, 0.0);
    drawstring(-170.0, -5.0, .0, " H A N D S H A K E   C O M P L E T E D..");
    glPopMatrix();
    glutPostRedisplay();

    glFlush();

}




void handshake1V()//handshake process function
{
    if (p3 <= 10.0 && p4 == -15.0 && p3 > -50.0)   //response
    {
        p3 = p3 - 0.08;

        glPushMatrix();
        glPointSize(6.0);
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        glVertex2f(p3, p4);
        glEnd();
        glPopMatrix();
        glutPostRedisplay();
    }
    else
    {
        if (p3 <= 10.0 && p4 < 28.0)
        {

            p4 = p4 + 0.08;
            glPushMatrix();
            glColor3f(0.0, 0.0, 0.0);
            glPointSize(6.0);
            glBegin(GL_POINTS);
            glVertex2f(p3, p4);
            glEnd();
            glPopMatrix();
            glutPostRedisplay();
        }
        else {

            glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            response();
            glPopMatrix();

            glutPostRedisplay();
            glFlush();
        }
    }

}


void handshake1H()//handshake process function
{

    if (p1 == -48.0 && p2 <= 20.0 && p2 >= -10.0)
    {
        p2 = p2 - 0.08;
                                                       //request

        glPushMatrix();
        glPointSize(6.0);
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        glVertex2f(p1, p2);
        glEnd();
        glPopMatrix();
        glutPostRedisplay();
    }
    else
    {
        if (p1 >= -48.0 && p2 <= -10.0 && p1<-14)
        {
            p1 = p1 + 0.08;

            glPushMatrix();
            glColor3f(0.0, 0.0, 0.0);
            glPointSize(6.0);
            glBegin(GL_POINTS);
            glVertex2f(p1, p2);
            glEnd();
            glPopMatrix();
            glutPostRedisplay();
        }

        else {
            glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            request();
            glPopMatrix();
        }
    }
    if (p1 >= -30.0 && p2 <= -8.0)
    {
        handshake1V();
    }
    flag = 1;

    glutSwapBuffers();
    glFlush();
}



void oneoneU()//upload function for client 1.
{
    if (flag == 1)
    {

        if (pos1 == -50.0 && pos2 >= 50.0 && pos2 < -20.0)
        {
            pos2 = pos2 + 0.08;

            glutPostRedisplay();
        }
        else
        {
            if (pos2 >= -50.0 && pos1 < -15.0)
            {
                pos1 = pos1 + 0.08;
                glutPostRedisplay();
            }
        }

        if (pos1 < -15.0)
        {
            glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            uploading2();
            glPopMatrix();

        }
        else
        {

            glPushMatrix();
            glColor3f(0.6, 0.6, 0.6);
            upload2();
            glPopMatrix();

        }



    }
}

//Some functions
void one()//displays points as it increments.
{
    if (flag == 1) {


        glPushMatrix();
        glPointSize(10.0);
        glColor3f(0.2, 0.20, 2.0);
        glBegin(GL_POINTS);
        glVertex2f(pos1, pos2);
        glEnd();
        glPopMatrix();
        glFlush();

    }
}

void two()//displays points as it increments.
{
    if (flag == 1) {

        glPushMatrix();
        glPointSize(10.0);
        glColor3f(2.0, 0.20, 0.20);
        glBegin(GL_POINTS);
        glVertex2f(p5, p6);
        glEnd();
        glPopMatrix();
        glFlush();


    }
}

void three()//displays points as it increments.
{

    glPushMatrix();
    glPointSize(10.0);
    glColor3f(0.20, 0.20, 2.0);
    glBegin(GL_POINTS);
    glVertex2f(p7, p8);
    glEnd();
    glPopMatrix();
    glFlush();

}
void four()
{
    glPushMatrix();
    glPointSize(10.0);
    glColor3f(2.0, 0.20, 0.20);
    glBegin(GL_POINTS);
    glVertex2f(p9, p10);
    glEnd();
    glPopMatrix();

    glFlush();



}


//DATABASE SERVER

void five()//displays points as it increments.
{
    glPushMatrix();
    glPointSize(10.0);
    glColor3f(0.20, 0.20, 2.0);
    glBegin(GL_POINTS);
    glVertex2f(p13, p14);
    glEnd();
    glPopMatrix();

    glFlush();


}
void six()//displays points as it increments.
{
    glPushMatrix();
    //glPointSize(4.0);
    glPointSize(10.0);
    glColor3f(2.0, 0.20, 0.20);
    glBegin(GL_POINTS);
    glVertex2f(p11, p12);
    glEnd();
    glPopMatrix();
    glFlush();
}

void seven()//displays points as it increments.
{
    glPushMatrix();
    glPointSize(10.0);
    glColor3f(0.2, 0.20, 2.0);
    glBegin(GL_POINTS);
    glVertex2f(p15, p16);
    glEnd();
    glPopMatrix();

    glFlush();
}

void eight()//displays points as it increments.
{
    glPushMatrix();

    glPointSize(10.0);
    glColor3f(2.0, 0.20, 0.20);
    glBegin(GL_POINTS);
    glVertex2f(p17, p18);
    glEnd();
    glPopMatrix();

    glFlush();
}






//INITIALIZATION FUNCTION

void myInit()
{
    fg = 0;
    pause = true;
    pause1 = true;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


// RESHAPE function is designed to reshape the display window if in case the display window is maximised or minimised.
void reshape(int w, int h)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);

}


// DISPLAY FUNCTIONS..........


//Introduction page -1st page
void coverpage()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glEnd();
    glBegin(GL_2D);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0, 0, 1);
    drawstring(23.0 - 50, 85.0, 0.0, "KLE INSTITUTE OF TECHNOLOGY");
    glColor3f(0.7, 0, 1);
    drawstring(4 - 50, 75, 0.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glColor3f(0, 1, 1);
    drawstring(16 - 50, 50, 0.0, "COMPUTER GRAPHICS AND VISUALIZATION ");
    glColor3f(1, 0.5, 0);
    drawstring(36 - 45, 35, 0.0, "A MINI PROJECT ");
    glColor3f(1, 0.5, 0);
    drawstring(46 - 45, 25, 0.0, "ON");
    glColor3f(1, 0.5, 0);
    drawstring(19 - 45, 15, 0.0, "CLIENT SERVER ARCHITECTURE");
    glColor3f(1, 0.5, 0);
    drawstring(-82, -20.0, 0.0, "SUBMITTED BY :");
    glColor3f(1, 1, 1);
    drawstring(-33 - 50, -35, 0.0, "ADITI KULKARNI             2KE20CS003");
    glColor3f(1, 1, 1);
    drawstring(-33 - 50, -45, 0.0, "PRADEEP TUMBINAVAR         2KE20CS056");
    glColor3f(1, 1, 1);
    drawstring(-33 - 50, -55, 0.0, "RAMYA KULKARNI             2KE20CS069");
    glColor3f(1, 1, 1);
    drawstring(-33 - 50, -65, 0.0, "SAGAR BAGALKOTI            2KE20CS075");
    glColor3f(0, 0, 1);
    drawstring(83 - 50, -20, 0.0, "UNDER THE GUIDANCE OF :");
    glColor3f(1, 0, 0);
    drawstring(89 - 50, -35, 0.0, "DR.SHRIDHAR ALLAGI");
    glColor3f(1, 0, 0);
    //drawstring(89 - 50, -45, 0.0, " ASSISTANT PROFESSOR ");
    //glColor3f(1, 0.1, 1);
    drawstring(32 - 45, -80, 0.0, "PRESS S TO BEGIN");
    glEnd();
    glFlush();
}


//3rd page
void firstScreen() {                                                  //Texts to be displayed on laptop screen

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(1, 1, 1);
    drawstring(-50, 60, 0, "-------CLIENT SERVER ARCHITECTURE-------");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.22, 0.22, 0.22);
    drawstring(-50, 40, 0, "Demonstrates Working of :");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.22, 0.22, 0.22);
    drawstring(-50, 30, 0, "* TCP Connection");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.22, 0.22, 0.22);
    drawstring(-50, 22, 0, "* UDP Connection");

    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.22, 0.22, 0.22);
    drawstring(-50, 14, 0, "* Uploading and Downloading Between two clients");


    glColor3f(0, 0, 0);
    glRasterPos3f(-45, -15, 0);
    char msg5[] = "Press 'SPACE' to start visualization";
    for (int i = 0; i < strlen(msg5); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg5[i]);
    }

    glutSwapBuffers();
}



//PAGE2

void welcomedisplay()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    if (fg == 0)
    {
        glPushMatrix();
        glScalef(x1, x2, 0);
        drawWall();
        drawWindow();
        drawFloor();
        drawTable();
        drawLaptop();
        glPushMatrix();
        glTranslatef(0, -0.5, 0);
        glScalef(0.1, 0.1, 0);
        drawLogo();
        glPopMatrix();
        glPopMatrix();

        if (x1 < 10.05)
        {
            x1 += 0.05;   //points increment to give zooming effect
            x2 += 0.05;
            Sleep(40);
        }
        if (x1 > 10.05)
        {

            fg = 1;

        }
        glFlush();
        glutPostRedisplay();
        if (pause) Sleep(3000);
        pause = false;
    }

    if (fg == 1) {

        glClearColor(0, 0, 0, 0);

        bgpolygon();
        firstScreen();

        glFlush();
        glutPostRedisplay();
        if (pause1) Sleep(100);
        pause1 = false;

    }

}


//page-4

void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);


    bgpolygon();                //background


    glPushMatrix();
    glTranslatef(-108, 10, 0);  //client1
    glScalef(0.6, 0.6, 0);
    client();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(25, -100, 0);  //client4
    glScalef(0.6, 0.6, 0);
    client();  //desktop
    glPopMatrix();

    glPushMatrix();            //client2
    glTranslatef(65, 60, 0);
    glScalef(1.4, 1.4, 0);
    drawLaptop();  //laptop
    glPopMatrix();

    glPushMatrix();            //client3
    glTranslatef(-65, -50, 0);
    glScalef(1.4, 1.4, 0);
    drawLaptop();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-2, -72, 0);    //database
    glScalef(5.4, 5.4, 0);
    glRotatef(-40, 1.0, 0.0, 0.0);
    draw_database(2.5, 8.5, 105, 105, 105);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-102, -68, 0);  //server
    glScalef(0.5, 0.5, 0);
    server();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0.5);
    glTranslatef(-5, 13, 0);
    glScalef(0.8, 0.8, 0);
    draw(7.0);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.2, 1);
    glTranslatef(-5, 13, 0);
    glScalef(0.8, 0.8, 0);
    draw(5.0);
    glPopMatrix();

    glPushMatrix();                                            //Font for Client1
    glTranslatef(100.0, 0.0, 0.0);
    const char* ptr1 = "Client 1";
    int len1 = strlen(ptr1);
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(-170, 20, 0.0);
    for (int i = 0; i < len1; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr1[i]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    const char* ptr3 = "Client 2";                           //Font for client2
    int len3 = strlen(ptr3);
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(-170, -90, 0.0);
    for (int i = 0; i < len3; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr3[i]);
    glPopMatrix();

    glPushMatrix();                                         //Font for client3
    glTranslatef(100.0, 0.0, 0.0);
    const char* ptr5 = "Client 3";
    int len5 = strlen(ptr5);
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(-40, 20, 0.0);
    for (int i = 0; i < len5; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr5[i]);
    glPopMatrix();


    glPushMatrix();                                 //Font for client4
    glTranslatef(100.0, 0.0, 0.0);
    const char* ptr4 = "Client 4";
    int len4 = strlen(ptr4);
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(-40, -90, 0.0);
    for (int i = 0; i < len4; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr4[i]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    const char* db1 = "DATABASE";
    int len9 = strlen(db1);
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(-108, -90, 0.0);
    for (int i = 0; i < len9; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, db1[i]);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(100.0, 0.0, 0.0);
    const char* ptr7 = "SERVER";
    int len7 = strlen(ptr4);
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos3f(-108, 80, 0.0);
    for (int i = 0; i < len7; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ptr7[i]);

    glPopMatrix();


    glPushMatrix();  //working of client1

    one();

    glPopMatrix();

    glPushMatrix();

    two();

    glPopMatrix();

    glPushMatrix();
    if (count == 1)
    {
        three();       //working of client2
    }
    glPopMatrix();


    glPushMatrix();
    if (count1 == 1)
    {
        four();
    }
    glPopMatrix();

    if (dt == 1)       //working of client3
    {
        glPushMatrix();
        five();
        glPopMatrix();

        glPushMatrix();
        if (dbFlag1 == 1) {

            dbConnect1();
        }
        glPopMatrix();
    }



    if (dd == 1)
    {
        glPushMatrix();
        dbConnect2();
        glPopMatrix();

        glPushMatrix();
        if (dbFlag2 == 1) {

            six();
        }
        glPopMatrix();


    }


    if (da == 1)
    {
        glPushMatrix();
        seven();
        glPopMatrix();
        glPushMatrix();
        if (dbFlag == 1) {

            dbConnect();
        }
        glPopMatrix();

    }




    glPushMatrix();
    if (db == 1)
    {
        glPushMatrix();
        dbConnect2();
        glPopMatrix();

        glPushMatrix();
        if (dbFlag3 == 1) {
            eight();
        }
        glPopMatrix();


    }
    glPopMatrix();


    //Sleep(50);
    glutSwapBuffers();

    glFlush();
    //glutPostRedisplay();

}

//page-5
void lastpage() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 1, 1);
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glEnd();
    glBegin(GL_2D);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0, 1, 1);
    drawstring(16 - 50, 50, 0.0, "START VISUALIZATION AGAIN : ");
    glColor3f(1, 0.5, 1);
    drawstring(16 - 30, 35, 0.0, "Press S or s");


    glPushMatrix();
    glTranslatef(-58, 20, 0);
    glScalef(0.4, 0.4, 0);
    drawTable();
    drawLaptop();
    glPopMatrix();

    if (start == 0)
    {
        if (xs > -50.5)
            xs = xs - 0.05;
        if (xs < -50.5 && ys < 5)
        {
            ys = ys + 0.02;
        }

        drawhuman(xs, ys, t);


    }




    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0, 1, 1);
    drawstring(5 - 33, 5, 0.0, "WANT TO QUIT ?? ");
    glColor3f(1, 0.5, 1);
    drawstring(5 - 20, -5, 0.0, "Press Q or q");
    glutPostRedisplay();
    glFlush();

}

// Menu Options

void cs(int OP)//function for menu option 5-EXIT VISUALIZATION
{
    if (OP == 5)
    {
        glutDisplayFunc(lastpage);
    }
}


void CS4(int b)//function for menu option 4.
{
    if (b == 1)
    {
         da = 1;
         dat2 = 1;
         glutIdleFunc(fourfourU);
    }
    if (b == 2)
    {
        if (dat1 == 1)
         {

             db = 1;
             glutIdleFunc(fourfourD);
         }
    }
}


void CS3(int a)//function for menu option 3.
{
    if (a == 1)
    {
        dt = 1;
        dat1 = 1;
        glutIdleFunc(threethreeU);

    }

    if (a == 2)
    {
        if (dat2 == 1)
         {
             dd = 1;
             glutIdleFunc(threethreeD);
         }
    }
}


void CS2(int o)//function for menu option 2.
{
    if (o == 1)
    {

         count = 1;
         glutIdleFunc(twotwoU);
    }
    if (o == 2)
    {
         count1 = 1;
         glutIdleFunc(twotwoD);
    }

}



void CS1(int op)//function for menu option 1.
{
    if (op == 2)
    {


        glutIdleFunc(oneoneU);


    }
    if (op == 1)
    {
        if (flag == 0)
        {

            glutIdleFunc(handshake1H);
        }


    }

    if (op == 3)
    {
        glutIdleFunc(oneoneD);
    }

}






void keys(unsigned char key, int x, int y) {                //Keyboard function
    if (key == 'S' or key == 's')
    {
        glutDisplayFunc(welcomedisplay);
    }
    else if (key == ' ') {
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    }
    else if (key == 'q' or key == 'Q') {
        exit(0);
    }

    glutPostRedisplay();

}



int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Client Server Architecture");
    myInit();
    glutKeyboardFunc(keys);
    glutDisplayFunc(coverpage);
    GLint id1 = glutCreateMenu(CS1);                              //mouse-interaction function
    glutAddMenuEntry(" Handshake ", 1);
    glutAddMenuEntry(" Upload Data", 2);
    glutAddMenuEntry(" Download Data", 3);

    GLint id2 = glutCreateMenu(CS2);
    glutAddMenuEntry(" Upload Data", 1);
    glutAddMenuEntry(" Download Data ", 2);

    GLint id3 = glutCreateMenu(CS3);
    glutAddMenuEntry(" Upload Data 1", 1);
    glutAddMenuEntry(" Download Data 2", 2);

    GLint id4 = glutCreateMenu(CS4);
    glutAddMenuEntry(" Upload Data 2", 1);
    glutAddMenuEntry(" Download Data 1", 2);

    glutCreateMenu(cs);
    glutAddSubMenu("Client 1 - Server (TCP) ", id1);
    glutAddSubMenu("Client 2 - server (UDP) ", id2);
    glutAddSubMenu("Client 3 - Server ", id3);
    glutAddSubMenu("Client 4 - server ", id4);
    glutAddMenuEntry("Exit Visualization ", 5);
    glutAttachMenu(GLUT_LEFT_BUTTON);


    glutMainLoop();
    return 0;
}
