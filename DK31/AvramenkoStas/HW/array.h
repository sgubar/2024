#ifndef ARRAY_H
#define ARRAY_H

// Структура фігури (зразок)
struct Shape {
    int type;  // Тип фігури
    // Додаткові поля для опису кожної конкретної фігури
};

// Структура масиву фігур
struct Array {
    int size;         // Поточний розмір масиву
    int capacity;     // Максимальна можлива ємність масиву
    struct Shape* shapes;  // Масив фігур
};

// Функція створення масиву на певну кількість елементів
struct Array* create_array(int num_elements);

#endif

