#include <GL/glut.h>

// Кути обертання
float angleY = 0.0f;

// Ініціалізація OpenGL
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Колір фону
    glEnable(GL_DEPTH_TEST); // Включити тест глибини
}

// Функція для малювання піраміди
void drawPyramid() {
    glBegin(GL_TRIANGLES); // Початок малювання трикутників

    // Передня грань
    glColor3f(1.0f, 0.0f, 0.0f); // Червоний
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, 0.5f);

    // Права грань
    glColor3f(0.0f, 1.0f, 0.0f); // Зелений
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    glVertex3f(0.0f, 0.0f, -0.5f);

    // Ліва грань
    glColor3f(0.0f, 0.0f, 1.0f); // Синій
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, -0.5f);
    glVertex3f(-0.5f, 0.0f, 0.5f);

    glEnd(); // Кінець малювання трикутників

    glBegin(GL_POLYGON); // Початок малювання основи

    // Основа піраміди
    glColor3f(1.0f, 1.0f, 0.0f); // Жовтий
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    glVertex3f(0.0f, 0.0f, -0.5f);

    glEnd(); // Кінець малювання основи
}

// Функція відображення сцени
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очищення буфера кольору та глибини
    glLoadIdentity(); // Скидання матриці трансформацій

    gluLookAt(0.0, -0.3, 3.0,  // Позиція камери (трохи вище і вперед)
              0.0, 0.5, 0.0,  // Куди камера дивиться (трохи вниз)
              1.0, 0.0, 0.0); // Вектор вгору

    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Обертання по осі Y

    drawPyramid(); // Малювання піраміди

    glutSwapBuffers(); // Заміна буферів
}

// Функція обробки натискання клавіш
void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) {
        angleY += 5.0f; // Збільшення кута обертання вправо
    } else if (key == GLUT_KEY_LEFT) {
        angleY -= 5.0f; // Зменшення кута обертання вліво
    }
    glutPostRedisplay(); // Оновлення сцени
}

// Функція зміни розміру вікна
void reshape(int width, int height) {
    if (height == 0) height = 1; // Захист від ділення на нуль
    float aspect = (float)width / height;

    glViewport(0, 0, width, height); // Встановлення вьюпорту
    glMatrixMode(GL_PROJECTION); // Вибір матриці проєкції
    glLoadIdentity(); // Скидання матриці
    gluPerspective(45.0f, aspect, 0.1f, 100.0f); // Встановлення перспективи
    glMatrixMode(GL_MODELVIEW); // Повернення до моделі огляду
    glLoadIdentity(); // Скидання матриці огляду
}

// Головна функція
int main(int argc, char** argv) {
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Встановлення режиму відображення
    glutInitWindowSize(800, 600); // Встановлення розміру вікна
    glutInitWindowPosition(50, 50); // Встановлення позиції вікна
    glutCreateWindow("3D Pyramid"); // Створення вікна

    initGL(); // Ініціалізація OpenGL

    glutDisplayFunc(display); // Реєстрація функції відображення
    glutReshapeFunc(reshape); // Реєстрація функції зміни розміру
    glutSpecialFunc(specialKeys); // Реєстрація функції обробки спеціальних клавіш

    glutMainLoop(); // Вхід в головний цикл обробки подій
    return 0;
}
