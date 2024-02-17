#include "math.h"
#include <stdio.h>
#include <cs50.h>
#define module(n) ( n < 0 ? -n : n) // модуль числа

int *get_ABC(){// створюємо масив та вписуємо 3 числа , і перевіріємо їх на коректність використання в прикладі
  int *result = (int *)malloc(3 *sizeof(int)); //виділяємо динамічну пам'ять для масиву
  for(int u = 0; u < 3 ; u++){//вводимо занчення , отримані від користувача, в масив 
   printf("%d значення = ", u+1);
    int resut = scanf("%d" , &result[u]);// отримуємо від користувача значення
    if (resut != 1) {// якщо введено не число
        printf("Введіть число.\n");
        while (getchar() != '\n');// очищуємо буфер вводу
        u--;// вертаємось на попередню комірку масиву
    }
    if (result[2] + result[1] == 100) {//якщо 2 та 3 значення дорівнюють 100 , то користувач має присвоїти 3 значенню інше число
        printf("2 i 3 значення не можуть = 100 .\n");
        while (getchar() != '\n');
        u--;
    }
    if (result[u] > 1000000) {// якщо число занадто велике
        printf("Завелике число\n");
        while (getchar() != '\n');
        u--;
    }
  }
  return result;
}


double power(int num, int pow){//функція для піднесення числа до перного степення
    double result = 1 ;
    int pw = module(pow);// модуль степеня
    for (int i = 0; i < pw; i++)
    {
        result *= num;
    }

    return (pow < 0 ) ? 1/result : result ;// якщо степінь від'ємна , то вертаємо перевернуте число , а якщо додатнє , то повертаємо result
}

double sum_power2(int start , int finish){// сума чисел 2 у певних степенях
    double result = 0 ;
    int fin = module(finish);// модуль числа , до якого ми прямуємо з кроком 1 або -1
    int pn = (finish < 0) ? -1 : 1 ;//число , яке буде множитись на зміну i у циклі отримання суми , бо у циклі і прамує до модуля кінцевого числа , а має прямувати до кінцевого числа без модуля , і з цим числом буде виконуватись ця умова
    for (int i = start ; i <= fin ; i ++){
    result += power(2 , i*pn + finish);// сумавання чисел 2 у певних степенях
    }
    return result;
}
 double q(int A, int B , int C){// функція для обчислення нашого прикладу
    return (A + B + C)/(float)(100 -B -C) + (double)sum_power2(0 , A);// вертаємо приклад
}

void destroy_mas(int *mas){//функція для видалення масиву
  if(NULL== mas){// якщо масива не існує
    return  ;
  }
  free(mas);//видалення матриці

}