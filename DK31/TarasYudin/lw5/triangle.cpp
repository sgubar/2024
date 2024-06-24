#include "triangle.h"
#include <cstdlib>
#include <cmath>
#include <vector>

Triangle createRandomTriangle() {
    Triangle triangle;
    for (int i = 0; i < 3; ++i) {
        triangle.vertices[i][0] = (rand() % 200 - 100) / 100.0f;
        triangle.vertices[i][1] = (rand() % 200 - 100) / 100.0f;
    }
    for (int i = 0; i < 3; ++i) {
        triangle.color[i] = static_cast<float>(rand()) / RAND_MAX;
    }
    return triangle;
}

bool doTrianglesIntersect(const Triangle& t1, const Triangle& t2) {
    auto ccw = [](float ax, float ay, float bx, float by, float cx, float cy) {
        return (cy - ay) * (bx - ax) > (by - ay) * (cx - ax);
        };

    auto intersect = [ccw](float ax, float ay, float bx, float by, float cx, float cy, float dx, float dy) {
        return ccw(ax, ay, cx, cy, dx, dy) != ccw(bx, by, cx, cy, dx, dy) &&
            ccw(ax, ay, bx, by, cx, cy) != ccw(ax, ay, bx, by, dx, dy);
        };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (intersect(
                t1.vertices[i][0], t1.vertices[i][1],
                t1.vertices[(i + 1) % 3][0], t1.vertices[(i + 1) % 3][1],
                t2.vertices[j][0], t2.vertices[j][1],
                t2.vertices[(j + 1) % 3][0], t2.vertices[(j + 1) % 3][1])) {
                return true;
            }
        }
    }
    return false;
}

std::vector<Triangle> createNonIntersectingTriangles() {
    std::vector<Triangle> triangles;
    while (triangles.size() < 3) {
        Triangle newTriangle = createRandomTriangle();
        bool intersects = false;
        for (const auto& triangle : triangles) {
            if (doTrianglesIntersect(newTriangle, triangle)) {
                intersects = true;
                break;
            }
        }
        if (!intersects) {
            triangles.push_back(newTriangle);
        }
    }
    return triangles;
}