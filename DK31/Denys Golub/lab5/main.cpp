#include <GL/glut.h>

char title[] = "golub piramidka";
bool perspective = true;
bool moveScene = false;

float a_z = 0, a = 5.0f; 
float zoom_param = -7.0;
float zoom_delta = 0.1;

void initGL(void)
{
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClearDepth(1.f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.f, 0.f, zoom_param);
    glRotatef(a_z, 0, 0, 1);

    
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f); 
    glVertex3f(0.0f, 0.0f, 2.0f); 
    glVertex3f(-1.9f, 0.0f, 0.6f); 
    glVertex3f(-1.16f, 0.0f, -1.6f); 
    glVertex3f(1.16f, 0.0f, -1.6f); 
    glVertex3f(1.9f, 0.0f, 0.6f); 
    glEnd();

    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex3f(0.0f, 0.0f, 2.0f); 
    glVertex3f(-1.9f, 0.0f, 0.6f); 
    glVertex3f(0.0, 2.0f, 0.0f); 

    glColor3f(0.0f, 1.0f, 0.0f); 
    glVertex3f(-1.9f, 0.0f, 0.6f); 
    glVertex3f(-1.16f, 0.0f, -1.6f); 
    glVertex3f(0.0, 2.0f, 0.0f); 

    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f(-1.16f, 0.0f, -1.6f); 
    glVertex3f(1.16f, 0.0f, -1.6f); 
    glVertex3f(0.0, 2.0f, 0.0f); 

    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(1.16f, 0.0f, -1.6f); 
    glVertex3f(1.9f, 0.0f, 0.6f); 
    glVertex3f(0.0, 2.0f, 0.0f); 

    glColor3f(1.0f, 0.0f, 1.0f); 
    glVertex3f(1.9f, 0.0f, 0.6f); 
    glVertex3f(0.0f, 0.0f, 2.0f); 
    glVertex3f(0.0, 2.0f, 0.0f); 
    glEnd();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    if (height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void specialKeyCallback(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT) {
        a_z += a;
    }
    else if (key == GLUT_KEY_RIGHT) {
        a_z -= a;
    }
    glutPostRedisplay();
}

void Timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

void keyboardCallback(unsigned char key, int x, int y)
{
    if (key == 'a' || key == 'A') {
        a_z += a; 
    }
    else if (key == 'd' || key == 'D') {
        a_z -= a; 
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeyCallback);
    glutKeyboardFunc(keyboardCallback); 
    glutTimerFunc(0, Timer, 0);
    initGL();
    glutMainLoop();
    return 0;
}
