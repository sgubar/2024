#include "figure.h"
#include <stdlib.h>
#include <cstring>
#include <GL/glut.h>

// створення кольору з заданими значеннями RGB
Color_s* createColor(float R, float G, float B){
    Color_s* color = (Color_s *)malloc(sizeof(Color_s));

    if(color != NULL){
        color->R = R;
        color->G = G;
        color->B = B;
    }

    return color;
}

// видалення пам'яті, виділеної для кольору
void deleteColor(Color_s *color) {
    if (NULL != color) {
        free(color);
    }
}

// створення фігури з заданими точками та кольором
Figure_s* createFigure(Point** points, Color_s * color){
    Figure_s* figure = (Figure_s *)malloc(sizeof(Figure_s));

    if(figure != NULL){
        for(int i = 0; i < PT_NUM; i++){
            figure->points[i] = points[i];
        }
        figure->color = color;
    }

    return figure;
}

// видалення пам'яті, виділеної для фігури
void deleteFigure(Figure_s *figure) {
    if (NULL != figure) {
        for (int i = 0; i < PT_NUM; i++){
            deletePoint(figure->points[i]);
        }
        deleteColor(figure->color);
    }

    free(figure);
}

// малювання фігури
void drawFigure(Figure_s* figure){
    glBegin(GL_QUADS); // початок малювання примітиву
        glColor3f(figure->color->R, figure->color->G, figure->color->B); // встановлення кольору для примітиву
        glVertex2f(figure->points[0]->x / 100.0f, figure->points[0]->y / 100.0f); // встановлення координат точок
        glVertex2f(figure->points[1]->x / 100.0f, figure->points[1]->y / 100.0f);
        glVertex2f(figure->points[2]->x / 100.0f, figure->points[2]->y / 100.0f);
        glVertex2f(figure->points[3]->x / 100.0f, figure->points[3]->y / 100.0f);
    glEnd(); // кінець малювання примітиву
}

// створення елемента списку фігур
FigureListElement_s* createListElement(Figure_s* figure) {
    FigureListElement_s *result = (FigureListElement_s *)malloc(sizeof(FigureListElement_s));

    if (NULL != result) {
        result->figure = figure;
        result->next = NULL;
        result->prev = NULL;
    }

    return result;
}

// видалення елемента списку фігур
void deleteListElement(FigureListElement_s* listElement) {
    if (NULL != listElement) {
        deleteFigure(listElement->figure);
        free(listElement);
    }
}

// малювання елемента списку фігур
void drawListElement(FigureListElement_s* listElement) {
    if (NULL != listElement) {
        drawFigure(listElement->figure);
    }
}

// створення списку фігур
FigureList_s *createFigList(void) {
    FigureList_s *result = (FigureList_s *)malloc(sizeof(FigureList_s));

    if (NULL != result) {
        result->head = NULL;
        result->tail = NULL;
    }

    return result;
}

// видалення списку фігур
void deleteFigList(FigureList_s *list) {
    if (NULL == list) {
        return;
    }

    FigureListElement_s *element = list->head;

    while(NULL != element) {
        FigureListElement_s *tmp = element->next;
        deleteListElement(element);
        element = tmp;
    }

    free(list);
}

// малювання списку фігур
void drawFigList(FigureList_s *list) {
    if (NULL == list) {
        printf("Неправильний вказівник на список\n");
        return;
    }

    FigureListElement_s *element = NULL;
    for (element = list->head; element != list->tail; element = element->next) {
        drawListElement(element);
    }

    if (element != NULL) {
        drawListElement(element);
    }
}

// підрахунок кількості елементів у списку фігур
long countOfFigList(FigureList_s *list) {
    if (NULL == list) {
        return 0;
    }

    long count = 0;

    for (FigureListElement_s *element = list->head; element != NULL; element = element->next, count++);

    return count;
}

// додавання фігури до списку
int addFigToFigList(FigureList_s *list, Figure_s* figure) {
    if (NULL == list || (list->head == NULL && list->head != list->tail)) {
        return 0;
    }

    FigureListElement_s *element = createListElement(figure);
    if (NULL == element) {
        return 0;
    }

    if (NULL == list->head) {
        list->head = element;
        list->tail = list->head;
        return 1;
    }

    list->tail->next = element;
    element->prev = list->tail;
    list->tail = element;

    return 1;
}

// видалення останнього елемента зі списку фігур
void removeLastElementFromFigList(FigureList_s *list) {
    if (NULL == list || (list->head == NULL && list->head != list->tail)) {
        return;
    }

    if (NULL == list->head) {
        return;
    }

    if (list->head == list->tail) {
        deleteListElement(list->head);
        list->head = NULL;
        list->tail = NULL;
        return;
    }

    FigureListElement_s *toDelete = list->tail;
    list->tail = toDelete->prev;
    list->tail->next = NULL;

    deleteListElement(toDelete);
}

// видалення першого елемента зі списку фігур
void removeFirstElementFromFigList(FigureList_s *list) {
    if (NULL == list || (list->head == NULL && list->head != list->tail)) {
        return;
    }

    if (NULL == list->head) {
        return;
    }

    if (list->head == list->tail) {
        deleteListElement(list->head);
        list->head = list->tail = NULL;
        return;
    }

    FigureListElement_s *toDelete = list->head;
    list->head = toDelete->next;
    list->head->prev = NULL;

    deleteListElement(toDelete);
}

// додавання фігури до списку на заданий індекс
int insertFigToFigListAtIndex(FigureList_s *list, int index, Figure_s* figure) {
    if (NULL == list || (list->head == NULL && list->head != list->tail)) {
        return 0;
    }

    long count = countOfFigList(list);

    if (count == index) {
        return addFigToFigList(list, figure);
    } else if (index > count) {
        return 0;
    }

    FigureListElement_s *element = createListElement(figure);
    if (NULL == element) {
        return 0;
    }

    if (0 == index) {
        element->next = list->head;
        list->head->prev = element;
        list->head = element;
    } else {
        int current = 0;
        FigureListElement_s *ex_element = list->head;
        for (; ex_element != NULL && current != index; ex_element = ex_element->next, current++);

        element->next = ex_element;
        element->prev = ex_element->prev;
        ex_element->prev = element;
        element->prev->next = element;
    }

    return 1;
}

// видалення фігури зі списку за індексом
int removeFigFromFigListAtIndex(FigureList_s *list, int index) {
    if (NULL == list || (list->head == NULL && list->head != list->tail)) {
        return 0;
    }

    long count = countOfFigList(list);
    if (index >= count) {
        return 0;
    }

    if (0 == index) {
        removeFirstElementFromFigList(list);
        return 1;
    } else if (index == (count - 1)) {
        removeLastElementFromFigList(list);
        return 1;
    } else {
        int current = 0;
        FigureListElement_s *ex_element = list->head;
        for (; ex_element != NULL && current != index; ex_element = ex_element->next, current++);

        ex_element->prev->next = ex_element->next;
        ex_element->next->prev = ex_element->prev;

        deleteListElement(ex_element);
    }

    return 1;
}
