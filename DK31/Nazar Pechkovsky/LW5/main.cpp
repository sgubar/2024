#include <GL/glut.h>

float angleY = 0.0f;

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

void drawPyramid() {
    glBegin(GL_TRIANGLES);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, 0.5f);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    glVertex3f(0.0f, 0.0f, -0.5f);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -0.5f);
    glVertex3f(-0.5f, 0.0f, 0.5f);

    glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    glVertex3f(0.0f, 0.0f, -0.5f);

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(0.0, -0.3, 3.0,
              0.0, 0.5, 0.0,
              1.0, 0.0, 0.0);

    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    drawPyramid();

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        angleY += 5.0f;
    } else if (key == GLUT_KEY_LEFT) {
        angleY -= 5.0f;
    }
    glutPostRedisplay();
}

void reshape(int width, int height) {
    if (height == 0) height = 1;
    float aspect = (float)width / height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("3D Pyramid");

    initGL();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}
