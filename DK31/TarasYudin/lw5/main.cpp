#include <GL/glut.h>

// Кут обертання навколо осі Y
GLfloat angleY = 0.0f;

// Функція для налаштування параметрів освітлення та кольорів
void setupColors() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Приглушений колір фону (темно-сірий)

    // Налаштування матеріалів для піраміди
    GLfloat ambient[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat diffuse[] = { 0.6f, 0.6f, 0.6f, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
}

// Функція для малювання піраміди
void drawPyramid() {
    glBegin(GL_TRIANGLES);

    // Передня грань
    glColor3f(0.7f, 0.5f, 0.5f); // Світло-коричневий
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, 0.5f);

    // Права грань
    glColor3f(0.5f, 0.7f, 0.5f); // Світло-зелений
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, -0.5f);

    // Задня грань
    glColor3f(0.5f, 0.5f, 0.7f); // Світло-синій
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, -0.5f);
    glVertex3f(-0.5f, 0.0f, -0.5f);

    // Ліва грань
    glColor3f(0.7f, 0.7f, 0.5f); // Світло-жовтий
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, -0.5f);
    glVertex3f(-0.5f, 0.0f, 0.5f);

    glEnd();

    // Основа (квадрат)
    glBegin(GL_QUADS);
    glColor3f(0.6f, 0.6f, 0.6f); // Світло-сірий
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, -0.5f);
    glVertex3f(-0.5f, 0.0f, -0.5f);
    glEnd();
}

// Функція для відображення сцени
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Переміщення камери
    gluLookAt(0.0f, 1.0f, 3.0f,  // Позиція камери
        0.0f, 0.0f, 0.0f,  // Точка спостереження
        0.0f, 1.0f, 0.0f); // Вектор "вгору"

    // Обертання піраміди навколо осі Y
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);

    // Малювання піраміди
    drawPyramid();

    glutSwapBuffers();
}

// Функція обробки клавіш
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
        angleY += 5.0f; // Обертання за годинниковою стрілкою
        break;
    case 's':
        angleY -= 5.0f; // Обертання проти годинникової стрілки
        break;
    }
    glutPostRedisplay();
}

// Функція зміни розміру вікна
void reshape(int w, int h) {
    if (h == 0) h = 1; // Запобігання діленню на нуль
    GLfloat aspect = (GLfloat)w / (GLfloat)h;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Функція ініціалізації
void init() {
    glEnable(GL_DEPTH_TEST); // Включення буфера глибини
    setupColors();
}

// Основна функція
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Обертання піраміди");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}