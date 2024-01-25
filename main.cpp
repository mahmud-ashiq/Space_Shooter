///COMPUTER GRAPHICS [B]
///PROJECT NAME: SPACE SHOOTER

///GROUP MEMBER:
///MAHMUD AL ASHIQ [21-45010-2]
///PRANTO BISWAS [21-45026-2]

#include<windows.h>
#include<stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <string>
#include <stdlib.h>

///game trackers
int start_flag=0;
int gameover_flag=0;
int score = 0;

///for left/right
int lrIndex = 0 ;

///opposite enemy ships
int rocket1 = 0;
int lrIndex1=0;
int rocket2 = 35;
int lrIndex2=0;
int rocket3 = 70;
int lrIndex3=0;

///missile trackers
int  missileX= lrIndex+28;
int  missileY = 10;
bool firing   = false;
int udIndex = 0;

void drawGradientImage();

///text display
const int font1=(int)GLUT_BITMAP_TIMES_ROMAN_24;

void renderBitmapString(float x, float y, void *font,const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void enemy1()
{
    /// body of the airship
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex1 + 24, rocket1 + 96);
    glVertex2i(lrIndex1 + 24, rocket1 + 94);
    glVertex2i(lrIndex1 + 32, rocket1 + 94);
    glVertex2i(lrIndex1 + 32, rocket1 + 96);
    glEnd();

    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex1 + 26, rocket1 + 96);
    glVertex2i(lrIndex1 + 26, rocket1 + 92);
    glVertex2i(lrIndex1 + 30, rocket1 + 92);
    glVertex2i(lrIndex1 + 30, rocket1 + 96);
    glEnd();

    /// left wing
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex1 + 24, rocket1 + 90);
    glVertex2i(lrIndex1 + 22, rocket1 + 90);
    glVertex2i(lrIndex1 + 22, rocket1 + 96);
    glVertex2i(lrIndex1 + 24, rocket1 + 96);
    glEnd();

    /// right wing
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex1 + 32, rocket1 + 90);
    glVertex2i(lrIndex1 + 34, rocket1 + 90);
    glVertex2i(lrIndex1 + 34, rocket1 + 96);
    glVertex2i(lrIndex1 + 32, rocket1 + 96);
    glEnd();

    rocket1--;

    if (rocket1 < -100)
    {
        rocket1 = 0;
        lrIndex1 = lrIndex;
    }

    /// collision with spaceship
    if ((abs(lrIndex - lrIndex1) < 20) && (rocket1 + 100 < 10))
    {
        start_flag = 0;
        gameover_flag = 1;
    }
}

void enemy2()
{
    /// body of the airship
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex2 + 24, rocket2 + 100);
    glVertex2i(lrIndex2 + 24, rocket2 + 98);
    glVertex2i(lrIndex2 + 32, rocket2 + 98);
    glVertex2i(lrIndex2 + 32, rocket2 + 100);
    glEnd();

    glColor3ub(92, 0, 153);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex2 + 26, rocket2 + 96);
    glVertex2i(lrIndex2 + 30, rocket2 + 96);
    glVertex2i(lrIndex2 + 30, rocket2 + 100);
    glVertex2i(lrIndex2 + 26, rocket2 + 100);
    glEnd();

    /// left wing
    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex2 + 22, rocket2 + 94);
    glVertex2i(lrIndex2 + 24, rocket2 + 94);
    glVertex2i(lrIndex2 + 24, rocket2 + 100);
    glVertex2i(lrIndex2 + 22, rocket2 + 100);
    glEnd();

    /// right wing
    glColor3ub(0, 0, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex2 + 32, rocket2 + 94);
    glVertex2i(lrIndex2 + 34, rocket2 + 94);
    glVertex2i(lrIndex2 + 34, rocket2 + 100);
    glVertex2i(lrIndex2 + 32, rocket2 + 100);
    glEnd();

    rocket2--;

    if (rocket2 < -100)
    {
        rocket2 = 0;
        lrIndex2 = lrIndex;
    }

    /// collusion with spaceship
    if ((abs(lrIndex - lrIndex2) < 20) && (rocket2 + 100 < 10))
    {
        start_flag = 0;
        gameover_flag = 1;
    }
}

void enemy3()
{
    /// body of the airship
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex3 + 24, rocket3 + 100);
    glVertex2i(lrIndex3 + 24, rocket3 + 98);
    glVertex2i(lrIndex3 + 32, rocket3 + 98);
    glVertex2i(lrIndex3 + 32, rocket3 + 100);
    glEnd();

    glColor3ub(255, 163, 26);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex3 + 26, rocket3 + 100);
    glVertex2i(lrIndex3 + 26, rocket3 + 96);
    glVertex2i(lrIndex3 + 30, rocket3 + 96);
    glVertex2i(lrIndex3 + 30, rocket3 + 100);
    glEnd();

    /// Left wing
    glColor3ub(92, 0, 153);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex3 + 24, rocket3 + 100);
    glVertex2i(lrIndex3 + 24, rocket3 + 94);
    glVertex2i(lrIndex3 + 22, rocket3 + 94);
    glVertex2i(lrIndex3 + 22, rocket3 + 100);
    glEnd();

    /// Right wing
    glColor3ub(92, 0, 153);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex3 + 32, rocket3 + 100);
    glVertex2i(lrIndex3 + 32, rocket3 + 94);
    glVertex2i(lrIndex3 + 34, rocket3 + 94);
    glVertex2i(lrIndex3 + 34, rocket3 + 100);
    glEnd();

    rocket3--;

    if(rocket3 < -100)
    {
        rocket3 = 0;
        lrIndex3 = lrIndex;
    }

    /// collusion with spaceship
    if ((abs(lrIndex - lrIndex3) < 20) && (rocket3 + 100 < 10))
    {
        start_flag = 0;
        gameover_flag = 1;
    }
}
void startGame()
{
    ///background
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(0,100);
    glVertex2i(100,100);
    glVertex2i(100,0);
    glEnd();

    ///score board
    glColor3ub(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(80,97);
    glVertex2i(100,97);
    glVertex2i(100,90);
    glVertex2i(80,90);
    glEnd();

    ///score
    char buffer [50];
    sprintf (buffer, "SCORE: %d", score);
    glColor3ub(64, 255, 0);
    renderBitmapString(80.5,95,(void *)font1,buffer);

    ///main spaceship
    //left wing
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(lrIndex+17,1);
    glVertex2i(lrIndex+23,2);
    glVertex2i(lrIndex+27,6);
    glVertex2i(lrIndex+21,6);
    glEnd();

    //right wing
    glColor3ub(255, 255, 255);
    glBegin(GL_QUADS);
    glVertex2i(lrIndex+39,1);
    glVertex2i(lrIndex+35,6);
    glVertex2i(lrIndex+29,6);
    glVertex2i(lrIndex+33,2);
    glEnd();

    //body
    glColor3ub(0, 153, 255);
    glBegin(GL_POLYGON);
    glVertex2i(lrIndex+26,5);
    glVertex2i(lrIndex+28,1);
    glVertex2i(lrIndex+30,5);
    glVertex2i(lrIndex+28,10);
    glEnd();
}

void drawMissile()
{
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2i(missileX-1, missileY);
    glVertex2i(missileX + 1, missileY);
    glVertex2i(missileX + 1, missileY + 4);
    glVertex2i(missileX-1, missileY + 4);
    glEnd();
}

void fristDesign()
{
    ///menu
    glBegin(GL_POLYGON);
    glVertex2i(28,85);
    glVertex2i(80,85);
    glVertex2i(80,55);
    glVertex2i(28,55);
    glEnd();

    ///text info
    if(gameover_flag==1)
    {
        glBegin(GL_POLYGON);
        glVertex2i(27,45);
        glVertex2i(78,45);
        glVertex2i(78,25);
        glVertex2i(27,25);
        glEnd();

        glColor3ub(255, 0, 0);
        renderBitmapString(38,31,(void *)font1,"GAME OVER");
        glColor3ub(255, 0, 0);
        char buffer2 [50];
        sprintf (buffer2, "Your Score is : %d", score);
        renderBitmapString(38,36,(void *)font1,buffer2);
    }
    glColor3ub(179, 0, 0);
    renderBitmapString(41,80,(void *)font1,"Space Shooter");
    glColor3ub(0, 0, 0);
    renderBitmapString(38,75,(void *)font1,"Press S to START");
    renderBitmapString(38,72,(void *)font1,"Press ESC to Exit");
    glColor3ub(255, 255, 255);
    renderBitmapString(31,67,(void *)font1,"Press SPACE to Fire Missile");
    renderBitmapString(31,64,(void *)font1,"Press RIGHT to turn Right");
    renderBitmapString(31,61,(void *)font1,"Press LEFT to turn Left");
}
void collison()
{
    if ((abs(missileX - lrIndex1) <=28) && (missileY-rocket1)>95 )
    {
        lrIndex1=-400;
        rocket1= -600;
        firing = false;
        score++;
    }
    if ((abs(missileX - lrIndex2) <=28) && (missileY-rocket2)>95 )
    {
        lrIndex2=-400;
        rocket2= -800;
        firing = false;
        score++;
    }
    if ((abs(missileX - lrIndex3) <=28) && (missileY-rocket3)>95 )
    {
        lrIndex3=-400;
        rocket3= -1000;
        firing = false;
        score++;
    }
}
void updateMissile()
{
    if(firing)
    {
        missileY += 4;
        if(missileY > 100)
        {
            firing = false;
            missileY = udIndex;
        }
    }
}
void display()
{
    if(start_flag==1)
    {
        startGame();
        enemy1();
        enemy2();
        enemy3();
        if(firing)
        {
            drawMissile();
            collison();
            updateMissile();
        }
    }
    else
    {
        drawGradientImage();
        fristDesign();
    }
    glFlush();
    glutSwapBuffers();
}
void drawGradientImage()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);  //White color
    glVertex2f(0, 0);     //Bottom-left corner
    glColor3f(0.5, 0.5, 0.5);  // Gray color
    glVertex2f(100, 0);      //Bottom-right corner
    glColor3f(0.0, 0.0, 0.0);  // Black color
    glVertex2f(100, 100);       // Top-right corner
    glColor3f(0.5, 0.5, 0.5);  // Gray color
    glVertex2f(0, 100);      // Top-left corner
    glEnd();
}
void spe_key(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_LEFT:
        lrIndex -= 5 ;
        if(lrIndex<-20)
        {
            lrIndex=-20;
        }
        break;

    case GLUT_KEY_RIGHT:
        lrIndex += 5;
        if(lrIndex>65)
        {
            lrIndex = 65;
        }
        break;

    default:
        break;
    }
}

void processKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        if(start_flag==0)
        {
            start_flag = 1;
            gameover_flag = 0;
            lrIndex = 0 ;
            rocket1 = 0;
            lrIndex1=0;
            rocket2 = +35;
            lrIndex2=0;
            rocket3 = +70;
            lrIndex3=0;
            score=0;
        }
        break;

    case ' ':
        if(firing== false)
        {
            firing =true;
            missileX = lrIndex+28;
            missileY = udIndex +10;
        }
        break;

    case 27:
        exit(0);
        break;

    default:
        break;
    }
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(20,timer,0);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600,800);
    glutInitWindowPosition(200,20);
    glutCreateWindow("Space Shooter");
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys );
    glOrtho(0,100,0,100,-1,1);
    glutTimerFunc(1000,timer,0);
    glutMainLoop();
    return 0;
}
