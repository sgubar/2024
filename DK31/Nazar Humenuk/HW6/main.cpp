
//Варіант 4

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>
int mouse_x,
mouse_y;
float a_x = 0, a_y = 0;
float siz = 1 ;
float kkd = 1;
bool moveScene = false;
// Функція, що викликатиметься для малювання сцени
void display()
{
    glClearColor(0.55f, 0.2f, 0.0f, 1.0f); // Фон коричневий та прозорий
    glClear(GL_COLOR_BUFFER_BIT); // Очищення буферу кольору
    if (moveScene == true){
    glTranslatef(a_x*kkd, a_y*kkd , 0);
    a_x = 0 ;
    a_y = 0 ;

    }

     glScalef(siz,siz,siz);
     siz = 1 ;
    // Малювання серії відрізків, що є графіком функції
    glBegin(GL_LINE_STRIP); // Кожна пара вершини задає відрізок
        glColor3f(0.0f, 1.0f, 0.0f); // зелений колір
        for (float t = 0; t <= 5*M_PI; t += 0.1) {
            float y = exp(t*0.25)*sin(t) /(15*M_PI);
            float x = exp(t*0.25)*cos(t) /(15*M_PI);
            glVertex2f(x , y);
        }
    glEnd();

    // Малювання координатних осей
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 0.0f, 0.0f);//червоний колір
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
    glEnd();

    // Малювання позначок на координатних осях
    for( float x = -1.0; x <= 1.0; x += 0.1){
        glBegin(GL_LINE_STRIP);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(x, -0.05);
            glVertex2f(x, 0.05);
        glEnd();
    }
    for( float y = -1.0; y <= 1.0; y += 0.1){
        glBegin(GL_LINE_STRIP);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(-0.05, y);
            glVertex2f(0.05, y);
        glEnd();
    }
    glFlush(); // Виконати малювання
}

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

void mouseMove(int x, int y)
{

    if (moveScene == true){
    int dx = mouse_x - x;
    int dy = mouse_y - y;
    a_x -= dx * 0.005f; // Додайте зсув, пропорційний різниці координат миші
    a_y += dy * 0.005f;
    mouse_x = x;
    mouse_y = y;
    }

}

void specKeyHandler(int sk, int x, int y)
{
    // Якщо натискаємо стрілку вгору - наближуємось до фігури, якщо вниз - віддаляємось від неї
    if (sk == GLUT_KEY_UP) {
        siz = 2;
        kkd /= 2;
    }
    else if (sk == GLUT_KEY_DOWN) {
        siz = 0.5;
        kkd *= 2;
    }
}

void Timer(int value)
{

    glutPostRedisplay(); // Генерування запиту на перемалювання
    // сцени викликає функцію display()

    glutTimerFunc(30, Timer, 0); // Новий запуск таймера на 30 мс
}
/* Program entry point */

int main(int argc, char* argv[])
{

    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitWindowSize(400, 400); // Ширина та висота вікна
    glutInitWindowPosition(0, 0); // Положення вікна
    glutCreateWindow("Test"); // Створення вікна із заданим ім'ям
    glutMouseFunc(mouseClick); // Реєстрація обробника натискання клавіш миші
    glutMotionFunc(mouseMove); // Реєстрація обробника руху миші
    glutSpecialFunc(specKeyHandler); // Реєстрація обробника подій клавіатури (спеціальні клавіши)
    glutDisplayFunc(display); // Реєстрація функції зворотного
    glutTimerFunc(0, Timer, 0);

    // виклику для малювання вікна
    glutMainLoop(); // Вхід у цикл обробки подій GLUT
return 0;
}
