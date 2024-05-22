#include<gl\glut.h>
#include<math.h>

int WinWidth = 200*M_PI;
int WinHeight = 200*M_PI;
const float graphSize = 5 * M_PI;
float k = 19/5;
float offsetX = 0.0f;
float offsetY = 0.0f;
float scale = 1.0f;

void drawAxes()
{
    glBegin(GL_LINES);

    // Малювання осі X
    glColor3f(1.0f, 0.0f, 0.0f); // Червоний колір
    glVertex2f(-WinWidth, 0.0f);
    glVertex2f(WinWidth, 0.0f);

    // Малювання осі Y
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, -WinHeight);
    glVertex2f(0.0f,WinHeight);

    glEnd();
}

void drawGrid()
{
    glBegin(GL_LINES);

    glColor3f(1.0f, 0.0f, 0.0f);
    for(float x = -graphSize; x <= graphSize; x += M_PI)
    {
        glVertex2f(x, -0.5f);
        glVertex2f(x, 0.5f);
    }

    glColor3f(1.0f, 0.0f, 0.0f);
    for(float y = -graphSize; y <= graphSize; y += M_PI)
    {
        glVertex2f(-0.5f, y);
        glVertex2f(0.5f, y);
    }

    glEnd();
}

void drawGraph()
{
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);

    for(float t = -graphSize; t < graphSize; t += 0.0001f)
    {
        float x = (k + 1) * (cos(t) - ((cos((k + 1) * t)) / (k + 1)));
        float y = (k + 1) * (sin(t) - ((sin((k + 1) * t)) / (k + 1)));
        glVertex2f(x * scale + offsetX, y * scale + offsetY);
    }

    glEnd();
}

void dispaly()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawAxes();
    drawGrid();
    drawGraph();

    glFlush();
}

void reshape(int WinWidth, int WinHeight)
{
    glViewport(0, 0, WinWidth, WinHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-graphSize, graphSize, -graphSize, graphSize);
}

void keyboard(unsigned char key, int, int) {
    if (key == 27)  // Якщо натиснуто Esc
    {
        exit(0);
    }
    else if (key == ']')
    {
        scale *= 1.1f;  // Збільшити масштаб
    }
    else if (key == '[')
    {
        scale /= 1.1f;  // Зменшити масштаб
    }
    glutPostRedisplay();
}

void specialKeys(int key, int, int)
{
    if (key == GLUT_KEY_DOWN)
    {
        offsetY -= 0.5f;  // Перемістити вниз
    }
    else if (key == GLUT_KEY_UP)
    {
        offsetY += 0.5f;  // Перемістити вверх
    }
    else if (key == GLUT_KEY_LEFT)
    {
        offsetX -= 0.5f;  // Перемістити вліво
    }
    else if (key == GLUT_KEY_RIGHT)
    {
        offsetX += 0.5f;  // Перемістити вправо
    }

    glutPostRedisplay(); // Перемальовуємо вікно після зміни параметрів
}

int main (int argc, char** argv)
{
    //ініціалізація глута
    glutInit(&argc, argv);

    //виведення екрану
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(WinWidth, WinHeight);
    glutInitWindowPosition(400,200);
    glutCreateWindow("window");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutDisplayFunc(dispaly);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);     //Зчитування esc
    glutSpecialFunc(specialKeys);   //Зчитування стрілочок

    glutMainLoop();
    return 0;
}
