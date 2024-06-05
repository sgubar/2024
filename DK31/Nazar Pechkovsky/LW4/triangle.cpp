#include "triangle.h"
#include <stdlib.h>
#include <cstring>
#include <GL/glut.h>

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



Triangle* createTriangle(Point** points, Color_s * color){
    Triangle* result = (Triangle *)malloc(sizeof(Triangle));
   if(result != NULL){
        for(int i = 0; i < NUM; i++){
            result->points[i] = points[i];
       }
		result->color = color;
    }

    return result;

}

void destroyTriangle(Triangle *triangle){
  if (NULL != triangle) {
		for (int i = 0; i < NUM; i++){
            destroyPoint(triangle->points[i]);
        }
        deleteColor(triangle->color);
	}

    free(triangle);
}



void drawTriangle(Triangle* triangle){
    //   
    glBegin(GL_TRIANGLES);
        //    
        glColor3f(triangle->color->R, triangle->color->G, triangle->color->B);
        //    
        glVertex2f(triangle->points[0]->x / 100.0f, triangle->points[0]->y / 100.0f);
        glVertex2f(triangle->points[1]->x / 100.0f, triangle->points[1]->y / 100.0f);
        glVertex2f(triangle->points[2]->x / 100.0f, triangle->points[2]->y / 100.0f);
        // ʳ  
    glEnd();
}


TriangleListElement_s* createListElement(Triangle* triangle) {
	TriangleListElement_s *result = (TriangleListElement_s *)malloc(sizeof(TriangleListElement_s));

	if (NULL != result) {
		result->triangle = triangle;
		result->next = NULL;
		result->prev = NULL;
	}

	return result;
}

void deleteListElement(TriangleListElement_s* listElement) {
	if (NULL != listElement) {
		destroyTriangle(listElement->triangle);
		free(listElement);
	}
}

void drawListElement(TriangleListElement_s* listElement) {
	if (NULL != listElement) {
		drawTriangle(listElement->triangle);
	}
}



TriangleList_s *createTriList(void) {
	TriangleList_s *result = (TriangleList_s *)malloc(sizeof(TriangleList_s));

	if (NULL != result) {
		result->head = NULL;
		result->tail = NULL;
	}

	return result;
}

void deleteTriList(TriangleList_s *list) {
	if (NULL == list) {
		return ;
	}

	TriangleListElement_s *element = list->head;

	while(NULL != element) {
		TriangleListElement_s *tri = element->next;
		deleteListElement(element);
		element = tri;
	}

	free(list);
}

void drawTriList(TriangleList_s *list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	TriangleListElement_s *element = NULL;
	for (element = list->head; element != list->tail; element = element->next) {
		drawListElement(element);
	}

	if (element != NULL) {
		drawListElement(element);
	}
}

long countOfTriList(TriangleList_s *list) {
	if (NULL == list) {
 		return 0;
	}

	long count = 0;

	for (TriangleListElement_s *element = list->head; element != NULL; element = element->next, count ++);

	return count;
}

int addTriToTriList(TriangleList_s *list, Triangle* triangle) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	TriangleListElement_s *element = createListElement(triangle);
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

void removeLastElementFromTriList(TriangleList_s *list) {
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

	TriangleListElement_s *toDelete = list->tail;
	list->tail = toDelete->prev;
	list->tail->next = NULL;

	deleteListElement(toDelete);
}

void removeFirstElementFromTriList(TriangleList_s *list) {
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

	TriangleListElement_s *toDelete = list->head;
	list->head = toDelete->next;
	list->head->prev = NULL;

	deleteListElement(toDelete);
}

int insertTriToTriListAtIndex(TriangleList_s *list, int index, Triangle* triangle) {

	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfTriList(list);

	if (count == index) {
		return addTriToTriList(list, triangle);
	} else if (index > count) {
		return 0;
	}

	TriangleListElement_s *element = createListElement(triangle);
	if (NULL == element) {
		return 0;
	}

	if (0 == index) {
		element->next = list->head;
		list->head->prev = element;
		list->head = element;
	} else {
		int current = 0;
		TriangleListElement_s *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		element->next = ex_element;
		element->prev = ex_element->prev;
		ex_element->prev = element;
		element->prev->next = element;
	}

	return 1;
}

int removeTriFromTriListAtIndex(TriangleList_s *list, int index) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfTriList(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromTriList(list);
		return 1;
	} else if (index == (count - 1)) {
		removeLastElementFromTriList(list);
		return 1;
	} else {
		int current = 0;
		TriangleListElement_s *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		ex_element->prev->next = ex_element->next;
		ex_element->next->prev = ex_element->prev;

		deleteListElement(ex_element);
	}

	return 1;
}

