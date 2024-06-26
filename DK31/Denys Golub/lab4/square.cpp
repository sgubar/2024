#include "square.h"
#include <stdlib.h>
#include <GL/glut.h>

Color_s* createColor(float R, float G, float B) {
    Color_s* color = (Color_s*)malloc(sizeof(Color_s));
    if (color != NULL) {
        color->R = R;
        color->G = G;
        color->B = B;
    }
    return color;
}

void deleteColor(Color_s* color) {
    if (color != NULL) {
        free(color);
    }
}

Square_s* createSquare(Point** points, Color_s* color) {
    Square_s* aSquare = (Square_s*)malloc(sizeof(Square_s));
    if (aSquare != NULL) {
        for (int i = 0; i < PT_NUM; i++) {
            aSquare->points[i] = createPoint(points[i]->x, points[i]->y);
        }
        aSquare->color = color;
    }
    return aSquare;
}

void deleteSquare(Square_s* aSquare) {
    if (aSquare != NULL) {
        for (int i = 0; i < PT_NUM; i++) {
            destroyPoint(aSquare->points[i]);
        }
        deleteColor(aSquare->color);
        free(aSquare);
    }
}

void drawSquare(Square_s* aSquare) {
    glBegin(GL_QUADS);
    glColor3f(aSquare->color->R, aSquare->color->G, aSquare->color->B);
    for (int i = 0; i < PT_NUM; i++) {
        glVertex2f(aSquare->points[i]->x / 100.0f, aSquare->points[i]->y / 100.0f);
    }
    glEnd();
}

void changeSquareColor(Square_s* aSquare, float R, float G, float B) {
    if (aSquare != NULL && aSquare->color != NULL) {
        aSquare->color->R = R;
        aSquare->color->G = G;
        aSquare->color->B = B;
    }
}

SquareListElement_s* createListElement(Square_s* aSquare) {
    SquareListElement_s* result = (SquareListElement_s*)malloc(sizeof(SquareListElement_s));
    if (result != NULL) {
        result->figure = aSquare;
        result->next = NULL;
        result->prev = NULL;
    }
    return result;
}

void deleteListElement(SquareListElement_s* listElement) {
    if (listElement != NULL) {
        deleteSquare(listElement->figure);
        free(listElement);
    }
}

void drawListElement(SquareListElement_s* listElement) {
    if (listElement != NULL) {
        drawSquare(listElement->figure);
    }
}

SquareList_s* createSquareList(void) {
    SquareList_s* result = (SquareList_s*)malloc(sizeof(SquareList_s));
    if (result != NULL) {
        result->head = NULL;
        result->tail = NULL;
    }
    return result;
}

void deleteSquareList(SquareList_s* list) {
    if (list == NULL) {
        return;
    }

    SquareListElement_s* element = list->head;
    while (element != NULL) {
        SquareListElement_s* tmp = element->next;
        deleteListElement(element);
        element = tmp;
    }
    free(list);
}

void drawSquareList(SquareList_s* list) {
    if (list == NULL) {
        return;
    }

    SquareListElement_s* element = list->head;
    while (element != NULL) {
        drawListElement(element);
        element = element->next;
    }
}

long countOfSquareList(SquareList_s* list) {
    if (list == NULL) {
        return 0;
    }

    long count = 0;
    for (SquareListElement_s* element = list->head; element != NULL; element = element->next, count++);
    return count;
}

int addSquareToSquareList(SquareList_s* list, Square_s* figure) {
    if (list == NULL || (list->head == NULL && list->head != list->tail)) {
        return 0;
    }

    SquareListElement_s* element = createListElement(figure);
    if (element == NULL) {
        return 0;
    }

    if (list->head == NULL) {
        list->head = element;
        list->tail = list->head;
        return 1;
    }

    list->tail->next = element;
    element->prev = list->tail;
    list->tail = element;
    return 1;
}

void removeLastElementFromSquareList(SquareList_s* list) {
    if (list == NULL || (list->head == NULL && list->head != list->tail)) {
        return;
    }

    if (list->head == NULL) {
        return;
    }

    if (list->head == list->tail) {
        deleteListElement(list->head);
        list->head = list->tail = NULL;
        return;
    }

    SquareListElement_s* tmp = list->tail->prev;
    deleteListElement(list->tail);
    list->tail = tmp;
    list->tail->next = NULL;
}

void removeFirstElementFromSquareList(SquareList_s* list) {
    if (list == NULL || (list->head == NULL && list->head != list->tail)) {
        return;
    }

    if (list->head == NULL) {
        return;
    }

    if (list->head == list->tail) {
        deleteListElement(list->head);
        list->head = list->tail = NULL;
        return;
    }

    SquareListElement_s* tmp = list->head->next;
    deleteListElement(list->head);
    list->head = tmp;
    list->head->prev = NULL;
}

int insertSquareToSquareListAtIndex(SquareList_s* list, int index, Square_s* aSquare) {
    if (list == NULL || index < 0) {
        return 0;
    }

    int i = 0;
    SquareListElement_s* element = createListElement(aSquare);
    if (element == NULL) {
        return 0;
    }

    if (index == 0) {
        element->next = list->head;
        list->head->prev = element;
        list->head = element;
        return 1;
    }

    for (SquareListElement_s* tmp = list->head; tmp != NULL; tmp = tmp->next, i++) {
        if (i == index) {
            element->next = tmp;
            element->prev = tmp->prev;
            tmp->prev->next = element;
            tmp->prev = element;
            return 1;
        }
    }
    return 0;
}

int removeSquareFromSquareListAtIndex(SquareList_s* list, int index) {
    if (list == NULL || index < 0) {
        return 0;
    }

    int i = 0;
    for (SquareListElement_s* tmp = list->head; tmp != NULL; tmp = tmp->next, i++) {
        if (i == index) {
            if (tmp->prev != NULL) {
                tmp->prev->next = tmp->next;
            }
            if (tmp->next != NULL) {
                tmp->next->prev = tmp->prev;
            }
            deleteListElement(tmp);
            return 1;
        }
    }
    return 0;
}
