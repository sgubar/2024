#include <GL/glut.h>
#include <math.h>


GLfloat red[] = { 1.0, 0.0, 0.0, 1.0 };   /// Червоний
GLfloat blue[] = { 0.0, 0.0, 1.0, 1.0 };  /// Синій
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 }; /// Білий


void display() {
   
    glClear(GL_COLOR_BUFFER_BIT);

   
    glClearColor(1.0, 1.0, 1.0, 1.0);

    
    glColor4fv(blue);

    
    glBegin(GL_LINES);
    glVertex2f(-10.0, 0.0);
    glVertex2f(10.0, 0.0);
    glVertex2f(0.0, -10.0);
    glVertex2f(0.0, 10.0);
    glEnd();

    glBegin(GL_LINES);
    for (float i = -10.0; i <= 10.0; i += 1.0) {
        glVertex2f(i, -0.2);
        glVertex2f(i, 0.2);
        glVertex2f(-0.2, i);
        glVertex2f(0.2, i);
    }
    glEnd();

    glColor4fv(red);

    glBegin(GL_LINE_STRIP);
    for (float t = -3 * M_PI; t <= 3 * M_PI; t += 0.01) {
        float x = t - sin(t);
        float y = 1 - cos(t);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Graph of the given function");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

