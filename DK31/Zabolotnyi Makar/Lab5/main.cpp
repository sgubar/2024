#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

//#include <stdlib.h>

// �������� ����
char title[] = "Piramide";
bool perspective = true;
bool moveScene = false;
int mouse_x,
mouse_y;
float a_x = 0, a_y = 0;
float zoom_param = -7.0;


// ����������� OpenGL
void initGL()
{
    glClearColor(0.f, 0.f, 0.f, 1.f); // ��� - ������ �� ��������
    glClearDepth(1.f); // ������� ���� - ������� ��������
    glEnable(GL_DEPTH_TEST); // ����� ���������� �������
    glDepthFunc(GL_LEQUAL); // ��� ������� ���������� �������
    glShadeModel(GL_SMOOTH); // ����� �������� ��������������
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // �������� �����������
}


// ������� ������� ������ �� �������������. ������ ��������� �����.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | // �������� ������ �������
    GL_DEPTH_BUFFER_BIT); // �� ������ �������
    glMatrixMode(GL_MODELVIEW); // ���� ������� ������-������
    glLoadIdentity(); // �������� ��������� ������� ������
    // ������������ �������� �������

    glTranslatef(0.f, 0.f, zoom_param); // ������� ��'���� � ������� ������
    glRotatef(a_x, 1, 0, 0); // ��������� ������� �� x
    glRotatef(a_y, 0, 1, 0); // ��������� ������� �� y
    // ��������� ��'���� � ���� � ������� ������ �������
    glBegin(GL_QUADS); // ϳ����� � ������� ����������� 4-������� ���������� � 5 ����� (������������� � ����������)

    // ˳�� ����� (x = -sqrt(2)/2)
    glColor3f(0.0f, 1.0f, 0.0f); // ������
    glVertex3f(-sqrt(2)/2, -1.0f, -1.0f);
    glVertex3f(-sqrt(2)/2, -1.0f, 1.0f);
    glVertex3f(-sqrt(2)/2, 1.0f, 1.0f);
    glVertex3f(-sqrt(2)/2, 1.0f, -1.0f);
    glEnd();

    glBegin(GL_TRIANGLES);// ���������� ��������� ��������� ���� ������
    // ������ ����� (y = 1.0f)
    glColor3f(1.0f, 0.5f, 0.0f); // �����������
    glVertex3f(-sqrt(2)/2, 1.0f, -1.0f);
    glVertex3f(-sqrt(2)/2, 1.0f, 1.0f);
    glVertex3f(sqrt(2)/2, 0.0f, 0.0f);


    // ����� ����� (z = -1.0f)
    glColor3f(1.0f, 0.0f, 0.0f); // �������
    glVertex3f(-sqrt(2)/2, 1.0f, -1.0f);
    glVertex3f(-sqrt(2)/2, -1.0f, -1.0f);
    glVertex3f(sqrt(2)/2, 0.0f, 0.0f);

    // ����� ����� (y = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f); // �����
    glVertex3f(-sqrt(2)/2, -1.0f, -1.0f);
    glVertex3f(-sqrt(2)/2, -1.0f, 1.0f);
    glVertex3f(sqrt(2)/2, 0.0f, 0.0f);

    // ������� ����� (z = 1.0f)
    glColor3f(0.0f, 0.0f, 1.0f); // ����
    glVertex3f(-sqrt(2)/2, -1.0f, 1.0f);
    glVertex3f(-sqrt(2)/2, 1.0f, 1.0f);
    glVertex3f(sqrt(2)/2, 0.0f, 0.0f);


    glEnd(); // ���������� ��������� ��������� ����� ������
    glutSwapBuffers(); // ���� ������ �����
    // (��������������� ������� �����������)
}


// ������� ������� ��䳿, �� ������ ��� ������������ ����
void reshape(int width, int height)
{
    // ���������� ��������� ����� ���� ������ ������
    if (height == 0) // �������� ��� ��������� ������ �� 0
    height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // ������������ ������ ���� ������ �������� �� ����� ������ ����
    glViewport(0, 0, width, height);

    // ������������ ��������� ���������� �������
    glMatrixMode(GL_PROJECTION); // ���� ������� ��������
    glLoadIdentity(); // �������� �������

    // ������������ ������������ �������� �
    // ����������� fovy = 45, aspect, zNear = 0.1 �� zFar = 100
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


// ������� ������� ��䳿, �� ������ ��� ��������� ����� ���������
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27: // Esc
            exit(0);
            break;
    }
}


// ������� ������� ��䳿, �� ������ ��� ��������� ����� �����
void mouseClick(int button, int state, int x, int y)
{
    if (GLUT_LEFT_BUTTON == button && state == GLUT_DOWN) {
        moveScene = true;
        mouse_x = x;
        mouse_y = y;
    }

    if (GLUT_LEFT_BUTTON == button && state == GLUT_UP) {
        moveScene = false;
    }
}


// ������� ������� ��䳿, �� ������ ��� ��������� ����� ���������
void specKeyHandler(int sk, int x, int y)
{
    // ���� ��������� ������ ����� ��� ���� - ������ �������� �� �� ��, ���� ����� ��� ���� - �������� �� �� ��
    if (sk == GLUT_KEY_UP) {
        a_x += 0.50f;;
    }
    else if (sk == GLUT_KEY_DOWN) {
        a_x -= 0.50f;;
    }
     if (sk == GLUT_KEY_RIGHT) {
        a_y += 0.50f;;
    }
    else if (sk == GLUT_KEY_LEFT) {
        a_y -= 0.50f;;
    }
}


// ������� ������� ��䳿, �� ������ ��� ���������� ���� �����
void mouseMove(int x, int y)
{
    int dx = mouse_x - x,
    dy = mouse_y - y;
    a_x -= 0.250f * dy;
    a_y -= 0.250f * dx;
    mouse_x = x;
    mouse_y = y;
}


// ������� ������� ��䳿, �� ������ ��� ���������� �������
void Timer(int value)
{
    glutPostRedisplay(); // ����������� ������ �� �������������
    // ����� ������� ������� display()

    glutTimerFunc(30, Timer, 0); // ����� ������ ������� �� 30 ��
}


// ������� �������: �������� GLUT ���������� �� ���������� �������
int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // ����������� GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // ��������� ������� �����������
    glutInitWindowSize(640, 480); // ������������ ������ ����
    glutInitWindowPosition(50, 50); // ������������ ��������� ����
    glutCreateWindow(title); // ��������� ���� �� ������� ��'��
    glutDisplayFunc(display); // ��������� ��������� ������ �������������
    glutReshapeFunc(reshape); // ��������� ��������� ������ �������������
    glutKeyboardFunc(keyboard); // ��������� ��������� ���� ���������
    glutMouseFunc(mouseClick); // ��������� ��������� ���������� ����� ����
    glutMotionFunc(mouseMove); // ��������� ��������� ���� ����
    glutSpecialFunc(specKeyHandler); // ��������� ��������� ���� ��������� (��������� ������)
    glutTimerFunc(0, Timer, 0); // ������ �� ��������� ������� �������
    initGL(); // ����������� OpenGL
    glutMainLoop(); // ���� � �������� ����������� ���� ������� ����
return 0;
}
