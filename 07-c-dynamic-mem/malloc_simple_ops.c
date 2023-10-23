#include <stdio.h>
#include <stdlib.h>

typedef struct s {
    int i;
    char c;
} MyStruct;

int main() {

    // Выделяем память под 1 элемент размером sizeof(MyStruct).
    // Лучше писать sizeof(*p), а не sizeof(MyStruct) и не просто число
    // Так как в случае изменения структуры или типа указателя
    // в таком подходе надо будет делать меньше исправлений и будет труднее ошибиться 
    MyStruct* p = calloc(1, sizeof(*p));
    // Обязательно проверять на NULL
    if (p == NULL) {
        return 1;
    }

    p->i = 5;
    p->c = 'a';

    // Выделяем больше памяти под наши структуры. Теперь есть память под 2 штуки.
    // Первыи элементом в получившемся массиве будет наша исходная первая структура.
    // Писать p = realloc(p, ...) плохо, так как при неудаче в p запишется NULL
    // и мы потеряем доступ к исходной структуре
    MyStruct* p2 = realloc(p, 2 * sizeof(*p));
    if (p2 == NULL) {
        return 1;
    }

    p = p2;

    printf("%d, %c\n", p->i, p->c);

    // не забываем почистить память
    free(p);
}
