#include <windows.h>
#include <GL/glut.h> //
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#include "point.h"
#include "triangle.h"

// Íàçâà òà ðîçì³ðè â³êíà
char title[] = "Clock Rotating something";
int curr_width = 600, curr_height = 600;

int t = 1000 / 24; // Ïåð³îä îáåðòàííÿ ô³ãóðè íàâêîëî ïî÷àòêó êîîðäèíàò (â äàíîìó ïðèêëàä³ ðîáèìî 1 îáåðò çà 24 êàäðè/ñ)
float phase_spd = 200.0f / t; // Êóò îáåðòó ì³æ êàäðàìè
float phase = 0.0f; // Êóò îáåðòó ÿê ãëîáàëüíà çì³ííà
TriangleList_s* trilist; // Íàø ñïèñîê ô³ãóð

// Â öüîìó ïðèêëàä³ âèêëèêàòèìåìî display() ëèøå îäèí ðàç íà ïî÷àêó ðîáîòè ïðîãðàìè
// äëÿ ìàëþâàííÿ ô³ãóð íà ïî÷àòêîâèõ ïîçèö³ÿõ
void display()
{
    // Ìàëþâàííÿ ô³ãóð ïî îäí³é
    drawTriList(trilist);

    // Çàïèò íà ìàëþâàííÿ ñöåíè
    glFlush();
}

// Öÿ ôóíêö³ÿ âèêëèêàºòüñÿ ÷åðåç t ìñ ï³ñëÿ óâ³ìêíåííÿ òàéìåðó ³ ïåðåìàëüîâóº ô³ãóðè
void timer_dis(int v)
{
    // Î÷èùóºìî áóôåð ùîá çîáðàæåííÿ íå íàêëàäàëèñÿ
    glClear(GL_COLOR_BUFFER_BIT);

    // Â íàøîìó ïðèêëàä³ âèêîíóºòüñÿ îáåðòàííÿ ñöåíè,
    // ïàðàìåòðè îáåðòàííÿ áóäå ïîêëàäåíî â ñòåê ïåðåòâîðåíü
    glPushMatrix();
    glRotatef(phase, 0.0f, 0.0f, 1.0f);

    // Ìàëþâàííÿ ô³ãóð ïî îäí³é
    drawTriList(trilist);

    // Çàïèò íà ìàëþâàííÿ ñöåíè
    glFlush();

    // Ïîâåðíåííÿ äî ïî÷àòêîâèõ íàëàøòóâàíü âèäó ñöåíè
    glPopMatrix();

    // Ïåðåçàïóñê òàéìåðà
    glutTimerFunc(t, timer_dis, 0);

    // Îíîâëåííÿ êóòà îáåðòó
    phase -= phase_spd;
    if (phase <= (-360)){
        phase = 0;
    }
}


int main(int argc, char* argv[])
{
    Point* points1[3];
    Point* points2[3];
    Point* points3[3];
    Point* points4[3];
    Point* points5[3];
   Triangle *triangle1, *triangle2, *triangle3, *triangle4, *triangle5;

    // Ñòâîðèìî ñïèñîê ô³ãóð
    trilist = createTriList();

    // Ñòâîðèìî ô³ãóðè ³ äîäàìî ¿õ äî ñïèñêó
    points1[0] = createPoint(0, 20);
    points1[1] = createPoint(0, 5);
    points1[2] = createPoint(35, 0);
    triangle1 = createTriangle(points1, createColor(1.0, 0.9, 0.2));

    addTriToTriList(trilist, triangle1);

    points2[0] = createPoint(40, 0);
    points2[1] = createPoint(80, 0);
    points2[2] = createPoint(60, 36);
    triangle2 = createTriangle(points2, createColor(1.0, 1.0, 1.0));

    addTriToTriList(trilist, triangle2);

    points3[0] = createPoint(-30, -10);
    points3[1] = createPoint(-60, -20);
    points3[2] = createPoint(30, -60);
    triangle3 = createTriangle(points3, createColor(0.1, 0.1, 0.1));

    addTriToTriList(trilist, triangle3);

    // Çàì³íèìî 2 ô³ãóðó â ñïèñêó íà ³íøó
    removeTriFromTriListAtIndex(trilist, 0);

    points4[0] = createPoint(-70, 10);
    points4[1] = createPoint(-40, 20);
    points4[2] = createPoint(-60, -70);
    triangle4 = createTriangle(points4, createColor(0.0, 0.0, 1.0));

    insertTriToTriListAtIndex(trilist, 1, triangle4);

    points5[0] = createPoint(25, 90);
    points5[1] = createPoint(50, -25);
    points5[2] = createPoint(40, -80);
    triangle5 = createTriangle(points5, createColor(0.3, 0.5, 0.0));

    addTriToTriList(trilist, triangle5);

    // ²í³ö³àë³çóºìî ñåðåäîâèùå OpenGL
    glutInit(&argc, argv);
    // Ñòâîðþºìî â³êíî
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    // Ðåºñòðóºìî display ÿê ôóíêö³þ ìàëþâàííÿ (â íàøîìó ïðèêëàä³ ïî÷àòêîâîãî)
    glutDisplayFunc(display);
    // Îäðàçó çàïóñêàºìî òàéìåð äëÿ òîãî, ùîá ô³ãóðè îáåðòàëèñü îäðàçó ï³ñëÿ çàïóñêó
    glutTimerFunc(0, timer_dis, 0);
    // Çàïóñêàºìî ãîëîâíèé öèêë OpenGL
    glutMainLoop();

    return 0;
}
