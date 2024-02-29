#include <stdlib.h>
#include "rec.h"

struct Point *createPoint(int x, int y){   // Створює нову точку з заданими координатами за допомогою динамічного виділення пам'яті
  struct Point *result = (struct Point *)malloc(sizeof(struct Point)); //Вказівник result - вказує на новостворену точку. malloc використовується для виділення динамічної пам'яті розміром, що дорівнює розміру структури Point
  
  
  //Важливо враховувати, що результат malloc є типу void *, тому ми конвертуємо його до типу struct Point *, оскільки вказівник result вказує на структуру Point.

  if (NULL!=result){ //Перевіряємо, чи виділення пам'яті пройшло успішно. Функція malloc повертає NULL, якщо вона не може виділити необхідний обсяг пам'яті
    
    // Така перевірка є важливою для того, щоб уникнути проблем з доступом до невидаленої пам'яті.
    result->x=x; 
    result->y=y; //Ініціалізуємо координати x та y новоствореної точки
    
    
    //Використання оператора -> дозволяє отримати доступ до полів структури через вказівник на неї
  }
  return result;
}

void destroyPoint(struct Point *P){ //Звільнює пам'ять, виділену для точки, яку створено динамічно
  if (P!=NULL){
    free(P);
  }
}
double calculateRectangleArea(struct Rec rect) {  //Обчислює площу прямокутника за допомогою координат його верхньої лівої та нижньої правої точок
    double width = rect.bottomRight.x - rect.topLeft.x;
    double height = rect.topLeft.y - rect.bottomRight.y;
    double area =width*height; 
    return area;
}
