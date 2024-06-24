#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Triangle {
    float vertices[3][2]; // ���������� ������
    float color[3];       // ���� (RGB)
};

Triangle createRandomTriangle();
bool doTrianglesIntersect(const Triangle& t1, const Triangle& t2);
std::vector<Triangle> createNonIntersectingTriangles();

#endif // TRIANGLE_H