
#include "figure.h"
#include <stdlib.h>
#include <cstring>
#include <GL/glut.h>
#include <math.h>




Color_s* createColor(float R, float G, float B){
    Color_s* color = (Color_s *)malloc(sizeof(Color_s));

    if(color != NULL){
		color->R = R;
		color->G = G;
		color->B = B;
    }

    return color;
}

void deleteColor(Color_s *color) {
	if (NULL != color) {
        free(color);
	}
}



RTrgle* createRTrgle(Point** points, Color_s * color){
    RTrgle* figure = (RTrgle *)malloc(sizeof(RTrgle));

    if(figure != NULL){
        Point *center = createPoint(0.0, 0.0) ;
        Point *minin = createPoint(100.0, 0.0) ;
        Point *maxin = createPoint(-100.0, 0.0) ;
        for(int i = 0; i < PT_NUM; i++){
            if(minin->x > points[i]->x){
              minin->x = points[i]->x;
              minin->y = points[i]->y;
            }
            if(maxin->x < points[i]->x){
              maxin->x = points[i]->x;
              maxin->y = points[i]->y;
            }

       }

       center->x = (minin->x +maxin->x)/2;// знаходимо центр відрізка , створеного введеними координатами
       center->y = (minin->y +maxin->y)/2;
       float *Radiuse = (float *)malloc(3 * sizeof(float)); // виділяємо память для радіуса
       *Radiuse = sqrt(pow(minin->x - center->x , 2) + pow(minin->y - center->y , 2));

        for(int i = 0; i < PT_NUM; i++){
            if( ( (points[i]->x != minin->x && points[i]->x != maxin->x) || ((i > 0 ) && points[i]->x == points[i-1]->x) ) || ((i == 2 ) && (points[i]->x == points[i-2]->x))  ){
              points[i]->y = sqrt(pow(*Radiuse,2) - pow(points[i]->x - center->x , 2 )) + center->y;
              if( (points[i]->x == minin->x && minin->y >= center->y ) || (points[i]->x == maxin->x && maxin->y >= center->y ) ) {
               points[i]->y = sqrt(pow(*Radiuse,2) - pow(points[i]->x - center->x , 2 )) - center->y;
              }

            }
            figure->points[i] = points[i];
       }
		figure->color = color;
		deletePoint(center);//очичення від точки центра
        free(Radiuse);
    }

    return figure;
}

void deleteRTrgle(RTrgle *figure) {
	if (NULL != figure) {
		for (int i = 0; i < PT_NUM; i++){
            deletePoint(figure->points[i]);
        }
        deleteColor(figure->color);
	}

    free(figure);
}



void drawRTrgle(RTrgle* figure){
    // Початок малювання примітиву
    glBegin(GL_TRIANGLES);
        // Призначення кольору для примітиву
        glColor3f(figure->color->R, figure->color->G, figure->color->B);
        // Призначення координат точкам примітиву
        glVertex2f(figure->points[0]->x / 100.0f, figure->points[0]->y / 100.0f);
        glVertex2f(figure->points[1]->x / 100.0f, figure->points[1]->y / 100.0f);
        glVertex2f(figure->points[2]->x / 100.0f, figure->points[2]->y / 100.0f);
        // Кінець малювання примітиву
    glEnd();
}


RTrgleListElement_s* createListElement(RTrgle* figure) {
	RTrgleListElement_s *result = (RTrgleListElement_s *)malloc(sizeof(RTrgleListElement_s));

	if (NULL != result) {
		result->figure = figure;
		result->next = NULL;
		result->prev = NULL;
	}

	return result;
}

void deleteListElement(RTrgleListElement_s* listElement) {
	if (NULL != listElement) {
		deleteRTrgle(listElement->figure);
		free(listElement);
	}
}

void drawListElement(RTrgleListElement_s* listElement) {
	if (NULL != listElement) {
		drawRTrgle(listElement->figure);
	}
}



RTrgleList_s *createFigList(void) {
	RTrgleList_s *result = (RTrgleList_s *)malloc(sizeof(RTrgleList_s));

	if (NULL != result) {
		result->head = NULL;
		result->tail = NULL;
	}

	return result;
}

void deleteFigList(RTrgleList_s *list) {
	if (NULL == list) {
		return ;
	}

	RTrgleListElement_s *element = list->head;

	while(NULL != element) {
		RTrgleListElement_s *tmp = element->next;
		deleteListElement(element);
		element = tmp;
	}

	free(list);
}

void drawFigList(RTrgleList_s *list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	RTrgleListElement_s *element = NULL;
	for (element = list->head; element != list->tail; element = element->next) {
		drawListElement(element);
	}

	if (element != NULL) {
		drawListElement(element);
	}
}

long countOfFigList(RTrgleList_s *list) {
	if (NULL == list) {
 		return 0;
	}

	long count = 0;

	for (RTrgleListElement_s *element = list->head; element != NULL; element = element->next, count ++);

	return count;
}

int addFigToFigList(RTrgleList_s *list, RTrgle* figure) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	RTrgleListElement_s *element = createListElement(figure);
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

void removeLastElementFromFigList(RTrgleList_s *list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	// is single element list?
	if (list->head == list->tail) {
		deleteListElement(list->head);
		list->head = NULL;
		list->tail = NULL;
		return;
	}

	RTrgleListElement_s *toDelete = list->tail;
	list->tail = toDelete->prev;
	list->tail->next = NULL;

	deleteListElement(toDelete);
}

void removeFirstElementFromFigList(RTrgleList_s *list) {
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

	RTrgleListElement_s *toDelete = list->head;
	list->head = toDelete->next;
	list->head->prev = NULL;

	deleteListElement(toDelete);
}

int insertFigToFigListAtIndex(RTrgleList_s *list, int index, RTrgle* figure) {

	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfFigList(list);

	if (count == index) {
		return addFigToFigList(list, figure);
	} else if (index > count) {
		return 0;
	}

	RTrgleListElement_s *element = createListElement(figure);
	if (NULL == element) {
		return 0;
	}

	if (0 == index) {
		element->next = list->head;
		list->head->prev = element;
		list->head = element;
	} else {
		int current = 0;
		RTrgleListElement_s *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		element->next = ex_element;
		element->prev = ex_element->prev;
		ex_element->prev = element;
		element->prev->next = element;
	}

	return 1;
}

int removeFigFromFigListAtIndex(RTrgleList_s *list, int index) {
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
		RTrgleListElement_s *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		ex_element->prev->next = ex_element->next;
		ex_element->next->prev = ex_element->prev;

		deleteListElement(ex_element);
	}

	return 1;
}
