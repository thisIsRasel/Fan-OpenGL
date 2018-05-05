#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

/* GLUT callback Handlers */

int FPS = 100; //Frame per second

int angle = 0; 

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    float centerX = 0, centerY = 0, x1, y1, radius = 0.1, ang;

    glColor3f(1.0,1.0,0.6);

    glPushMatrix();
    
        glRotatef(angle,0.0f,0.0f,1.0f);
        
        glBegin(GL_POLYGON);
        
            glVertex2f(-0.05f, 0.0f);
            glVertex2f(0.05f, 0.0f);
            glVertex2f(0.05f, 0.7f);
            glVertex2f(-0.05f, 0.7f);
            
        glEnd();
        
        glBegin(GL_POLYGON);
        
            glVertex2f(0.0f, 0.05f);
            glVertex2f(-0.7f, -0.3f);
            glVertex2f(-0.65f, -0.4f);
            glVertex2f(0.0f, -0.05f);
            
        glEnd();
        
        glBegin(GL_POLYGON);
        
            glVertex2f(0.0f, 0.05f);
            glVertex2f(0.7f, -0.3f);
            glVertex2f(0.65f, -0.4f);
            glVertex2f(0.0f, -0.05f);
            
        glEnd();
        
        angle ++;
        
    glPopMatrix();
    
    glBegin(GL_TRIANGLE_FAN);
    
    glVertex2f(centerX, centerY);

    for (ang=1.0f; ang<=360.0f; ang+=0.2)
    {
        x1 = centerX + sin(ang) * radius;
        y1 = centerY + cos(ang) * radius;
        glVertex2f(x1,y1);
    }

    glEnd();

    glutSwapBuffers();
}

void timer(int) {

    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer, 0);
}

void catchKey(int key, int x, int y) {

    switch(key) {
        
        case GLUT_KEY_UP:
            
            if(FPS < 1000) {
                FPS += 100;
            }
            
            break;
            
        case GLUT_KEY_DOWN:
        
            if(FPS > 100) {
                FPS -= 100;
            }
            
            break;
    }
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Fan");
    
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutSpecialFunc(catchKey);

    glutMainLoop();

    return 0;
}
