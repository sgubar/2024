#define _USE_MATH_DEFINES
#include <math.h>
#include <GL/glut.h>

// Розміри вікна
const int WIDTH = 800;
const int HEIGHT = 600;

// Масштаб і зміщення
float scale = 50.0f; // Масштаб для кращої видимості кривої
float offsetX = 0.0f; // Зміщення по осі X
float offsetY = 0.0f; // Зміщення по осі Y

// Функція ініціалізації
void init() {
    // Встановлюємо колір очищення екрану (білий)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  
    // Встановлюємо колір малювання (чорний)
    glColor3f(0.0f, 0.0f, 0.0f);          
    // Встановлюємо ортогональну проекцію
    gluOrtho2D(-WIDTH / 2, WIDTH / 2, -HEIGHT / 2, HEIGHT / 2);  
}

// Функція для відображення кривої 15
void drawCurve15() {
    // Встановлюємо колір лінії кривої (червоний)
    glColor3f(1.0f, 0.0f, 0.0f); 
    // Встановлюємо товщину лінії кривої
    glLineWidth(2.0f); 

    // Починаємо малювати лінію
    glBegin(GL_LINE_STRIP);
    for (float t = -4.0f * M_PI; t <= 4.0f * M_PI; t += 0.01f) {
        // Обчислюємо значення кривої за формулою
        float r = exp(cos(t)) - 2 * cos(4 * t) + pow(sin(t / 12), 5);
        float x = r * cos(t);
        float y = r * sin(t);
        // Додаємо вершину до лінії
        glVertex2f(scale * x + offsetX, scale * y + offsetY);
    }
    glEnd();
}

// Функція для відображення координатних осей і масштабних відміток
void drawAxes() {
    // Встановлюємо колір осей (чорний)
    glColor3f(0.0f, 0.0f, 0.0f); 
    // Встановлюємо товщину лінії осей
    glLineWidth(1.0f); 

    // Малюємо осі
    glBegin(GL_LINES);
    glVertex2f(-WIDTH / 2 + offsetX, 0 + offsetY);
    glVertex2f(WIDTH / 2 + offsetX, 0 + offsetY);
    glVertex2f(0 + offsetX, -HEIGHT / 2 + offsetY);
    glVertex2f(0 + offsetX, HEIGHT / 2 + offsetY);
    glEnd();

    // Малюємо масштабні відмітки
    glBegin(GL_LINES);
    for (int i = -WIDTH / 2; i <= WIDTH / 2; i += 50) {
        glVertex2f(i + offsetX, -5 + offsetY);
        glVertex2f(i + offsetX, 5 + offsetY);
    }
    for (int i = -HEIGHT / 2; i <= HEIGHT / 2; i += 50) {
        glVertex2f(-5 + offsetX, i + offsetY);
        glVertex2f(5 + offsetX, i + offsetY);
    }
    glEnd();
}

// Функція відображення
void display() {
    // Очищаємо буфер кольору
    glClear(GL_COLOR_BUFFER_BIT);  

    // Відображаємо координатні осі і масштабні відмітки
    drawAxes();

    // Відображаємо криву
    drawCurve15();

    // Обмінюємо буфери
    glutSwapBuffers();  
}

// Функція обробки вводу з клавіатури
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': // Переміщення вгору
            offsetY += 10;
            break;
        case 's': // Переміщення вниз
            offsetY -= 10;
            break;
        case 'a': // Переміщення вліво
            offsetX -= 10;
            break;
        case 'd': // Переміщення вправо
            offsetX += 10;
            break;
        case '+': // Збільшення масштабу
            scale *= 1.1f;
            break;
        case '-': // Зменшення масштабу
            scale /= 1.1f;
            break;
        case 27:  // Клавіша Escape для виходу
            exit(0);
            break;
    }
    // Перемальовуємо екран
    glutPostRedisplay();  
}

// Головна функція
int main(int argc, char** argv) {
    // Ініціалізація GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Крива 15");

    // Ініціалізація
    init();

    // Реєстрація функцій зворотного виклику
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    // Входимо в головний цикл обробки подій
    glutMainLoop();

    return 0;
}
