#include <GL/glut.h>
#include <cmath>
// ������ 9 ��������� �.�. ��-31

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 1.0, 0.0); // ������� ���� �������
    glBegin(GL_LINE_STRIP);

    // ���������� � ����������� ����� �������
    for (float t = 0; t <= M_PI; t += 0.01) {
        float x = sin(3*t) * cos(t);
        float y = sin(3*t) * sin(t);
        glVertex2f(x, y);
    }

    glEnd();

    // ³���������� ������������ ����
    glColor3f(0.0, 0.0, 1.0); // ���� ���� ���� �� ������
    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.7, 0.4, 0.1, 1.0); // ���������� ���� ����
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.5, 1.5, -1.5, 1.5); // ������������ ������ �����������
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600); // ����� ����
    glutInitWindowPosition(100, 100); // ������� ����
    glutCreateWindow("OpenGL 2D"); // ��������� ����
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
