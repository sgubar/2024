#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} List;

List* create_list();
void add_element(List *list, int data);
void delete_element(List *list, int data);
void insert_element(List *list, int data, int index);
void destroy_list(List *list);
int get_size(List *list);
void print_list(List *list);

#endif 
