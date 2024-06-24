#include <GL/glut.h>

// ��� ��������� ������� �� Y
GLfloat angleY = 0.0f;

// ������� ��� ������������ ��������� ��������� �� �������
void setupColors() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // ����������� ���� ���� (�����-����)

    // ������������ �������� ��� ������
    GLfloat ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
}

// ������� ��� ��������� ������
void drawPyramid() {
    glBegin(GL_TRIANGLES);

    // ������� �����
    glColor3f(0.7f, 0.5f, 0.5f); // �����-����������
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, 0.5f);

    // ����� �����
    glColor3f(0.5f, 0.7f, 0.5f); // �����-�������
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, -0.5f);

    // ����� �����
    glColor3f(0.5f, 0.5f, 0.7f); // �����-����
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, -0.5f);
    glVertex3f(-0.5f, 0.0f, -0.5f);

    // ˳�� �����
    glColor3f(0.7f, 0.7f, 0.5f); // �����-������
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, -0.5f);
    glVertex3f(-0.5f, 0.0f, 0.5f);

    glEnd();

    // ������ (�������)
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f); // �����-����
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, -0.5f);
    glVertex3f(-0.5f, 0.0f, -0.5f);
    glEnd();
}

// ������� ��� ����������� �����
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // ���������� ������
    gluLookAt(0.0f, 1.0f, 3.0f,  // ������� ������
        0.0f, 0.0f, 0.0f,  // ����� �������������
        0.0f, 1.0f, 0.0f); // ������ "�����"

    // ��������� ������ ������� �� Y
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    // ��������� ������
    drawPyramid();

    glutSwapBuffers();
}

// ������� ������� �����
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        angleY += 5.0f; // ��������� �� ������������ �������
        break;
    case 's':
        angleY -= 5.0f; // ��������� ����� ����������� ������
        break;
    }
    glutPostRedisplay();
}

// ������� ���� ������ ����
void reshape(int w, int h) {
    if (h == 0) h = 1; // ���������� ������ �� ����
    GLfloat aspect = (GLfloat)w / (GLfloat)h;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// ������� �����������
void init() {
    glEnable(GL_DEPTH_TEST); // ��������� ������ �������
    setupColors();
}

// ������� �������
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("��������� ������");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}