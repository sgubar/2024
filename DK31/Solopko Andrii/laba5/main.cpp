#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Глобальні змінні
char title[] = "Pyramid";
float a_y = 0.0f;

// Ініціалізація OpenGL
void initGL() {
    glClearColor(0.f, 0.f, 0.f, 1.f); // Фон - чорний та прозорий
    glClearDepth(1.f); // Глибина фону - найбільш віддалена
    glEnable(GL_DEPTH_TEST); // Дозвіл тестування глибини
    glDepthFunc(GL_LEQUAL); // Тип функції тестування глибини
    glShadeModel(GL_SMOOTH); // Дозвіл гладкого зафарбовування
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Корекція перспективи
}

// Функція обробки запиту на перемалювання. Виконує малювання сцени.
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очищення буферу кольору та буферу глибини
    glMatrixMode(GL_MODELVIEW); // Вибір матриці модель-вигляд
    glLoadIdentity(); // Скидання параметрів матриці шляхом завантаження одиничної матриці

    glTranslatef(0.f, 0.f, -5.0f); // Зміщення об'єкта у глибину екрану
    glRotatef(a_y, 0, 1, 0); // Обертання навколо осі y

    // Малювання піраміди з основою правильного трикутника
    glBegin(GL_TRIANGLES);

    // Передня грань
    glColor3f(1.0f, 0.0f, 0.0f); // Червона
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Права грань
    glColor3f(0.0f, 1.0f, 0.0f); // Зелена
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(0.0f, -1.0f, -1.0f);

    // Ліва грань
    glColor3f(0.0f, 0.0f, 1.0f); // Синя
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();

    // Основа піраміди
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f); // Жовта
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(0.0f, -1.0f, -1.0f);
    glEnd();

    glutSwapBuffers(); // Обмін буферів кадру (використовується подвійна буферизація)
}

// Функція обробки події, що виникає при масштабуванні вікна
void reshape(int width, int height) {
    if (height == 0) height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

// Функція обробки події, що виникає при натисканні клавіш клавіатури
void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) {
        a_y -= 5.0f;
    } else if (key == GLUT_KEY_RIGHT) {
        a_y += 5.0f;
    }
    glutPostRedisplay(); // Перемалювати сцену
}

// Головна функція: програма GLUT виконується як консольний додаток
int main(int argc, char* argv[]) {
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Ввімкнення подвійної буферизації та тесту глибини
    glutInitWindowSize(640, 480); // Встановлення розміру вікна
    glutInitWindowPosition(50, 50); // Встановлення положення вікна
    glutCreateWindow(title); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація обробника запиту перемалювання
    glutReshapeFunc(reshape); // Реєстрація обробника запиту масштабування
    glutSpecialFunc(specialKeys); // Реєстрація обробника подій клавіатури (спеціальні клавіші)
    initGL(); // Ініціалізація OpenGL
    glutMainLoop(); // Вхід у головний нескінченний цикл обробки подій
    return 0;
}
