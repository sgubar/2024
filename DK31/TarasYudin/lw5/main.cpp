#include <GL/glut.h>
#include <ctime>
#include <vector>
#include "triangle.h"
#define _USE_MATH_DEFINES
#include <cmath>

// ������ ����� ������������
std::vector<Triangle> triangles;

// ��� ��������
float angle = 0.0f;
const float rotationSpeed = 0.02f;

// ����������� OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // ������ ���
    glColor3f(1.0, 1.0, 1.0);         // ����� ���� �� �������������
    glMatrixMode(GL_PROJECTION);      // ������� ������� ��������
    glLoadIdentity();                 // ����������� �������� �������
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // ������������ ��������
}

// ������� ��� ����������� �����
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // ������� ����� �������

    glPushMatrix();               // �������� ������� �������
    glRotatef(angle, 0.0, 0.0, 1.0); // ������� ������� �� Z

    // ������� ��� ������������
    for (const auto& triangle : triangles) {
        glColor3fv(triangle.color); // ������������ ���� ������������
        glBegin(GL_TRIANGLES);      // �������� ��������� ������������
        for (int j = 0; j < 3; ++j) {
            glVertex2fv(triangle.vertices[j]); // ������� ������������
        }
        glEnd();
    }

    glPopMatrix(); // ³��������� �������
    glutSwapBuffers(); // �������� ������ ��� �����������
}

// ������� ��� ��������� ���� �������� �� ����������� �����
void update(int value) {
    angle += rotationSpeed * 180 / M_PI; // ���������� ������ � �������
    if (angle > 360) {
        angle -= 360; // �������� ��� ��������
    }
    glutPostRedisplay(); // ������������� �����
    glutTimerFunc(16, update, 0); // ��������� ������ ��� ���������� ��������� (��������� 60 ����� � �������)
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned>(time(0))); // ���������� ��������� ���������� �����

    // ��������� ��� ������������ ������������
    triangles = createNonIntersectingTriangles();

    // ����������� GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotating Triangles");

    init(); // ��������� ������� �����������
    glutDisplayFunc(display); // ������������ ������� �����������
    glutTimerFunc(16, update, 0); // ��������� ������ ��� ��������� �����

    glutMainLoop(); // ��������� �������� ���� GLUT
    return 0;
}