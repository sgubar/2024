#include <stdio.h>
#include "list.h"

int main() {
    List *list = create_list();
    if (list == NULL) {
        printf("Не вдалося створити список\n");
        return 1;
    }

    add_element(list, 1);
    add_element(list, 2);
    add_element(list, 3);
    add_element(list, 1);

    printf("Список після додавання елементів: ");
    print_list(list);

    insert_element(list, 4, 1);

    printf("Список після вставки елементу за індексом 1: ");
    print_list(list);

    delete_element(list, 1);

    printf("Список після видалення елементу 1: ");
    print_list(list);

    printf("Розмір списку: %d\n", get_size(list));

    destroy_list(list);

    return 0;
}
