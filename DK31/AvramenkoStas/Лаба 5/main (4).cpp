#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

char title[] = "Cube";
bool moveScene = false;
int mouse_x, mouse_y;
float a_x = 0;
float zoom_param = -7.0;

// Ініціалізація OpenGL
void initGL()
{
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClearDepth(1.f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

// Функція обробки запиту на перемалювання. Виконує малювання сцени.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.f, 0.f, zoom_param);
    glRotatef(a_x, 1, 0, 0);

    // Малювання куба з гранями різного кольору
    glBegin(GL_QUADS);

    // Передня грань (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f); // Червона
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Задня грань (z = -1.0f)
    glColor3f(0.0f, 1.0f, 0.0f); // Зелена
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Верхня грань (y = 1.0f)
    glColor3f(0.0f, 0.0f, 1.0f); // Синя
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Нижня грань (y = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f); // Жовта
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Права грань (x = 1.0f)
    glColor3f(1.0f, 0.5f, 0.0f); // Помаранчева
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Ліва грань (x = -1.0f)
    glColor3f(0.5f, 0.0f, 0.5f); // Фіолетова
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    glEnd();
    glutSwapBuffers(); // Обмін буферів кадру
}

// Функція обробки події, що виникає при масштабуванні вікна
void reshape(int width, int height)
{
    if (height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

   
    glViewport(0, 0, width, height);

   
    glMatrixMode(GL_PROJECTION); // Вибір матриці проекції
    glLoadIdentity(); // Скидання матриці

   
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

// Функція обробки події, що виникає при натисканні клавіш клавіатури
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: // Esc
        exit(0);
        break;
    }
}

// Функція обробки події, що виникає при натисканні клавіш клавіатури
void specKeyHandler(int sk, int x, int y)
{
    if (sk == GLUT_KEY_UP)
    {
        a_x += 0.50f;
    }
    else if (sk == GLUT_KEY_DOWN)
    {
        a_x -= 0.50f;
    }
}

// Функція обробки події, що виникає при спрацюванні таймеру
void Timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);

// Головна функція: програма GLUT виконується як консольний додаток
int main(int argc, char *argv[])
{
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Ввімкнення подвійної буферизації
    glutInitWindowSize(640, 480); // Встановлення розміру вікна
    glutInitWindowPosition(50, 50); // Встановлення положення вікна
    glutCreateWindow(title); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація обробника запиту перемалювання
    glutReshapeFunc(reshape); // Реєстрація обробника запиту масштабування
    glutKeyboardFunc(keyboard); // Реєстрація обробника подій клавіатури
    glutSpecialFunc(specKeyHandler); // Реєстрація обробника подій клавіатури (спеціальні клавіши)
    glutTimerFunc(0, Timer, 0); // Запуск та реєстрація обробки таймера
    initGL(); // Ініціалізація OpenGL
    glutMainLoop(); // Вхід у головний нескінченний цикл обробки подій
    return 0;
}


