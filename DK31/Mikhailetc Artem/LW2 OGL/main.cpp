#include <GL/glut.h>
// Mihailetc Artem DK-31
// Var - 9
double rotate_y = 0;
double rotate_x = 0;
double zoom = -5.0; // Початкове значення масштабу
double cube_size = 1.0; // Початковий розмір куба

// Функція для малювання куба
void drawCube() {
    glBegin(GL_QUADS);

    // Верхня грань
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
    glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
    glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
    glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);

    // Нижня грань
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
    glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
    glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
    glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);

    // Передня грань
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
    glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
    glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
    glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);

    // Задня грань
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
    glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
    glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
    glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);

    // Ліва грань
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
    glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
    glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
    glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);

    // Права грань
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
    glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
    glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
    glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);

    glEnd();
}

// Функція для відображення
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Очищення буферів кольору та глибини
    glLoadIdentity(); // Скидання матриці моделі

    glTranslatef(0.0, 0.0, zoom); // Зсув камери вздовж вектора Z

    glRotatef(rotate_x, 1.0, 0.0, 0.0); // Поворот навколо вісі X
    glRotatef(rotate_y, 0.0, 1.0, 0.0); // Поворот навколо вісі Y

    drawCube(); // Малювання куба

    glFlush(); // Відправка усіх команд виконання у відеопам'ять
    glutSwapBuffers(); // Заміна переднього та заднього буферів
}

// Функція для обробки спеціальних клавіш
void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT) // Якщо натиснута стрілка вправо
        rotate_y += 5; // Збільшення кута повороту навколо Y
    else if (key == GLUT_KEY_LEFT) // Якщо натиснута стрілка вліво
        rotate_y -= 5; // Зменшення кута повороту навколо Y
    else if (key == GLUT_KEY_UP) // Якщо натиснута стрілка вгору
        rotate_x += 5; // Збільшення кута повороту навколо X
    else if (key == GLUT_KEY_DOWN) // Якщо натиснута стрілка вниз
        rotate_x -= 5; // Зменшення кута повороту навколо X
    glutPostRedisplay(); // Перемалювання вікна
}

// Функція для обробки клавіатурних натискань
void keyboard(unsigned char key, int x, int y) {
    if (key == 'w') // Якщо натиснута клавіша 'w'
        zoom += 0.1; // Збільшення масштабу
    else if (key == 's') // Якщо натиснута клавіша 's'
        zoom -= 0.1; // Зменшення масштабу
    glutPostRedisplay(); // Перемалювання вікна
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Встановлення режиму відображення
    glutCreateWindow("Awesome Cube"); // Створення вікна з назвою "Awesome Cube"

    glEnable(GL_DEPTH_TEST); // Включення тесту глибини

    glClearColor(0.0, 0.0, 0.0, 1.0); // Встановлення чорного кольору фону
    glColor3f(1.0, 1.0, 1.0); // Встановлення білого кольору

    glMatrixMode(GL_PROJECTION); // Вибір матриці проекції
    gluPerspective(45.0, 1.0, 1.0, 200.0); // Встановлення перспективи

    glMatrixMode(GL_MODELVIEW); // Вибір матриці моделі
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0); // Встановлення позиції та напрямку камери

    glutDisplayFunc(display); // Реєстрація функції відображення
    glutSpecialFunc(specialKeys); // Реєстрація функції обробки спеціальних клавіш
    glutKeyboardFunc(keyboard); // Реєстрація функції обробки клавіатурних натискань

    glutMainLoop(); // Головний цикл GLUT
    return 0;
}
