#include <stdio.h>

#define SIZE 14
#define TARGET1 150
#define TARGET2 1000
#define TARGET3 10000

int main() {
    int numbers[SIZE];
    int count = 0;

    printf("Введіть %d натуральних чисел:\n", SIZE);

    for (int i = 0; i < SIZE; i++) {
        if (scanf("%d", &numbers[i]) != 1 || numbers[i] <= 0) {
            printf("Помилка: введіть лише натуральні числа!\n");
            return 1;
        }

        if (numbers[i] == TARGET1 || numbers[i] == TARGET2 || numbers[i] == TARGET3) {
            count++;
        }
    }

    printf("Кількість чисел, рівних %d, %d або %d: %d\n", TARGET1, TARGET2, TARGET3, count);

    return 0;
}
