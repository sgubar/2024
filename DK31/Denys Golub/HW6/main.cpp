#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>

float a = 0.5;
int width = 800, height = 600;
float scale = 1.0;
float xOffset = 0.0, yOffset = 0.0;

bool leftMouseButtonDown = false;
int lastMouseX, lastMouseY;

void drawText(const char* text, float x, float y)
{
    glRasterPos2f(x, y);
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

void display()
{
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glScalef(scale, scale, 1.0);
    glTranslatef(xOffset, yOffset, 0.0);

    glColor3f(1.0, 1.0, 1.0);

    glBegin(GL_LINE_STRIP);
    for (float t = -M_PI; t <= M_PI; t += 0.01) {
        float x = 2 * a * cos(t) * (1 - cos(t));
        float y = 2 * a * sin(t) * (1 - cos(t));
        glVertex2f(x, y);
    }
    glEnd();

    glColor3ub(255, 255, 0);
    glBegin(GL_LINES);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glEnd();

    for (float x = -1.0; x <= 1.0; x += 0.1) {
        glBegin(GL_LINES);
        glVertex2f(x, -0.05);
        glVertex2f(x, 0.05);
        glEnd();
    }
    for (float y = -1.0; y <= 1.0; y += 0.1) {
        glBegin(GL_LINES);
        glVertex2f(-0.05, y);
        glVertex2f(0.05, y);
        glEnd();
    }

    drawText("X", 0.9 / scale - xOffset, -0.05 / scale - yOffset);
    drawText("Y", 0.05 / scale - xOffset, 0.9 / scale - yOffset);

    glPopMatrix();

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            leftMouseButtonDown = true;
            lastMouseX = x;
            lastMouseY = y;
        }
        else if (state == GLUT_UP) {
            leftMouseButtonDown = false;
        }
    }
    else if (button == 3) {
        scale *= 1.1;
    }
    else if (button == 4) {
        scale /= 1.1;
    }
    glutPostRedisplay();
}

void motion(int x, int y)
{
    if (leftMouseButtonDown) {
        xOffset += (x - lastMouseX) / (scale * width);
        yOffset -= (y - lastMouseY) / (scale * height);
        lastMouseX = x;
        lastMouseY = y;
        glutPostRedisplay();
    }
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Графік Денчіка");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}
