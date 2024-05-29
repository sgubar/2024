#include "single_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    IntSingleList *list = createIntSingleList();
    printIntSingleList(list);

    addIntValueToIntSingleList(list, 5);
    printIntSingleList(list);

    insertIntElementToIntSingleListAtIndex(list, 1, 3);
    printIntSingleList(list);

    addIntValueToIntSingleList(list, 6);
    printIntSingleList(list);

    insertIntElementToIntSingleListAtIndex(list, 2, 4);
    printIntSingleList(list);

    removeFirstElementFromIntSingleList(list);
    printIntSingleList(list);

    removeLastElementFromIntSingleList(list);
    printIntSingleList(list);

    deleteIntSingleList(list);
    return 0;
}
