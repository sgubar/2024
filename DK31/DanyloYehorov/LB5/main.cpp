/* варіант №6 */

#include <GL/glut.h>

#define FRAME_T     (1000/60)

float zoom_param = -4.0;
float zoom_delta = 0.1;

void initGL(void) {
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClearDepth(1.f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}



void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.f, 0.f, zoom_param);
    glRotatef(0, 1, 0, 0);
    glRotatef(0, 0, 1, 0);

    glBegin(GL_QUADS);

    glColor3f(0.2f, 0.4f, 0.7f);
    glVertex3f( 1.0f, 0.5f, -0.75f);
    glVertex3f(-1.0f, 0.5f, -0.75f);
    glVertex3f(-1.0f, 0.5f, 0.75f);
    glVertex3f( 1.0f, 0.5f, 0.75f);

    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f( 1.0f, -0.5f, 0.75f);
    glVertex3f(-1.0f, -0.5f, 0.75f);
    glVertex3f(-1.0f, -0.5f, -0.75f);
    glVertex3f( 1.0f, -0.5f, -0.75f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f( 1.0f, 0.5f, 0.75);
    glVertex3f(-1.0f, 0.5f, 0.75f);
    glVertex3f(-1.0f, -0.5f, 0.75f);
    glVertex3f( 1.0f, -0.5f, 0.75f);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f( 1.0f, -0.5f, -0.75f);
    glVertex3f(-1.0f, -0.5f, -0.75f);
    glVertex3f(-1.0f, 0.5f, -0.75f);
    glVertex3f( 1.0f, 0.5f, -0.75f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 0.5f, 0.75f);
    glVertex3f(-1.0f, 0.5f, -0.75f);
    glVertex3f(-1.0f, -0.5f, -0.75f);
    glVertex3f(-1.0f, -0.5f, 0.75f);

    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 0.5f, -0.75f);
    glVertex3f(1.0f, 0.5f, 0.75f);
    glVertex3f(1.0f, -0.5f, 0.75f);
    glVertex3f(1.0f, -0.5f, -0.75f);

    glEnd();
    glutSwapBuffers();
}



void reshape(int width, int height) {
    if (height == 0) {
            height = 1;
    }
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}



void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
            break;

        case 'w':
            zoom_param += zoom_delta;
            break;

        case 's':
            zoom_param -= zoom_delta;
            break;
    }
}



void timer_func(int value) {
    glutPostRedisplay();
    glutTimerFunc(FRAME_T, timer_func, 0);
}



int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("6 - Parallelepiped");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer_func, 0);
    initGL();
    glutMainLoop();
    return 0;
}
