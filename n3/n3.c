#include <stdio.h>

int main(void) {
    int Ar[] = { 13, 313, 777, 198, 4244, 24, 1, 5, 987, 423, 231, 13145, 5453, 12345, 363, 145, 957, 342, 444, 182 };
    double med_value;
    int n = sizeof(Ar) / sizeof(Ar[0]); // длина массива
    for (int i = 0; i < n; i++) { // вывод массива
        printf("%d,", Ar[i]);
    }
    // сортировка выбором
    for (int i = 0; i < n - 1; i++) { // мы поставили один элемент как минимальный, следовательно циклом надо пройти на один меньше
        int min_idx = i;
        for (int j = i + 1; j < n; j++) { // i + 1, чтобы не сравнивать его с самим собой
            if (Ar[j] < Ar[min_idx])
                min_idx = j;
        }
        // обмен переменными
        int temp = Ar[min_idx];
        Ar[min_idx] = Ar[i];
        Ar[i] = temp;

    }
    printf("\n");
    char ch = ',';
    for (int i = 0; i < n; i++) {
        if (i == n - 1) ch = ' '; // если мы дошли до конца массива - запятую не выводим
        printf("%05d%c", Ar[i], ch); // выводим отсортированный массив через запятую
    }
    printf("\n");

    // нахождение медианы
    if (n % 2 != 0) {
        med_value = Ar[n / 2];
    }
    else {
        med_value = (double)(Ar[n / 2] + Ar[n / 2 - 1]) / 2;
    }

    printf("Median value = %.2f", med_value);
    return 0;
}