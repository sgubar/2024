#include <stdio.h>
#include "ArrayOfrectangle.h"

int main() {
    struct Array* rectArray = createArray(5); 
    if (rectArray == NULL) {
        printf("Не вдалося створити масив прямокутників.\n");
        return 1;
    }
    
    Rectangle* rect1 = createRectangle(1.0, 1.0, 3.0, 3.0);
    Rectangle* rect2 = createRectangle(2.0, 2.0, 4.0, 4.0);
    Rectangle* rect3 = createRectangle(3.0, 3.0, 5.0, 5.0);
    
    addElement(rectArray, rect1);
    addElement(rectArray, rect2);
    addElement(rectArray, rect3);
    
    printArray(rectArray);
    
    destroyArray(rectArray);
    destroyRectangle(rect1);
    destroyRectangle(rect2);
    destroyRectangle(rect3);
    
    return 0;
}
