#include <GL/glut.h>
#include <vector>
#include <cmath>
#include <iostream>

// Структура для зберігання фігури
struct Figure {
    char type;  // 'T' для трикутника, 'S' для квадрата
    float angle;  // Кут обертання
};

std::vector<Figure> figures;  // Список фігур

void display();
void reshape(int width, int height);
void timer(int);
void keyboard(unsigned char key, int x, int y);
void drawTriangle(float angle);
void drawSquare(float angle);

int main(int argc, char** argv) {
    // Ініціалізація GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Graphics with OpenGL");

    // Ініціалізація фігур
    figures.push_back({'T', 0.0f});
    figures.push_back({'S', 0.0f});

    // Реєстрація функцій зворотного виклику
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);

    // Основний цикл GLUT
    glutMainLoop();
    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Малювання фігур
    for (const auto& figure : figures) {
        if (figure.type == 'T') {
            drawTriangle(figure.angle);
        } else if (figure.type == 'S') {
            drawSquare(figure.angle);
        }
    }

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -300, 300);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    for (auto& figure : figures) {
        figure.angle += 1.0f;  // Обертання фігури
        if (figure.angle >= 360.0f) {
            figure.angle -= 360.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':  // Додати трикутник
            figures.push_back({'T', 0.0f});
            break;
        case 'd':  // Додати квадрат
            figures.push_back({'S', 0.0f});
            break;
        case 'r':  // Видалити останню фігуру
            if (!figures.empty()) {
                figures.pop_back();
            }
            break;
        default:
            break;
    }
}

void drawTriangle(float angle) {
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 50.0f);
    glVertex2f(-50.0f, -50.0f);
    glVertex2f(50.0f, -50.0f);
    glEnd();
    glPopMatrix();
}

void drawSquare(float angle) {
    glPushMatrix();
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-50.0f, 50.0f);
    glVertex2f(50.0f, 50.0f);
    glVertex2f(50.0f, -50.0f);
    glVertex2f(-50.0f, -50.0f);
    glEnd();
    glPopMatrix();
}
