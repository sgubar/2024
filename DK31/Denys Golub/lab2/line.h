#ifndef line_h
#define line_h

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node *create_node(int data);

void stop_stupid(int *n);

void print_elements(int *n, int *data, Node **head);

void print_list(Node *head);

void append(Node **head_ref, int data);

void turns_list (Node **head_ref);

void delete_list(Node **head_ref);

#endif
