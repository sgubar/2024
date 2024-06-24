#include <GL/glut.h>
#include <ctime>
#include <vector>
#include "triangle.h"
#define _USE_MATH_DEFINES
#include <cmath>

// Массив трьох треугольників
std::vector<Triangle> triangles;

// Кут повороту
float angle = 0.0f;
const float rotationSpeed = 0.02f;

// Ініціалізація OpenGL
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Чорний фон
    glColor3f(1.0, 1.0, 1.0);         // Білий колір за замовчуванням
    glMatrixMode(GL_PROJECTION);      // Змінюємо матрицю проекції
    glLoadIdentity();                 // Завантажуємо одиничну матрицю
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Ортогональна проекція
}

// Функція для відображення сцени
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Очищуємо буфер кольору

    glPushMatrix();               // Зберігаємо поточну матрицю
    glRotatef(angle, 0.0, 0.0, 1.0); // Поворот навколо осі Z

    // Малюємо три треугольники
    for (const auto& triangle : triangles) {
        glColor3fv(triangle.color); // Встановлюємо колір треугольника
        glBegin(GL_TRIANGLES);      // Починаємо малювання треугольника
        for (int j = 0; j < 3; ++j) {
            glVertex2fv(triangle.vertices[j]); // Вершини треугольника
        }
        glEnd();
    }

    glPopMatrix(); // Відновлюємо матрицю
    glutSwapBuffers(); // Обмінюємо буфери для відображення
}

// Функція для оновлення кута повороту та перерисовки сцени
void update(int value) {
    angle += rotationSpeed * 180 / M_PI; // Конвертуємо радіани в градуси
    if (angle > 360) {
        angle -= 360; // Збільшуємо кут повороту
    }
    glutPostRedisplay(); // Перемальовуємо сцену
    glutTimerFunc(16, update, 0); // Запускаємо таймер для наступного оновлення (приблизно 60 кадрів в секунду)
}

int main(int argc, char** argv) {
    srand(static_cast<unsigned>(time(0))); // Ініціалізуємо генератор випадкових чисел

    // Створюємо три неперетинних треугольника
    triangles = createNonIntersectingTriangles();

    // Ініціалізація GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rotating Triangles");

    init(); // Викликаємо функцію ініціалізації
    glutDisplayFunc(display); // Встановлюємо функцію відображення
    glutTimerFunc(16, update, 0); // Запускаємо таймер для оновлення сцени

    glutMainLoop(); // Запускаємо головний цикл GLUT
    return 0;
}