#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long int num; 
int base;
int n;
long int power = 1; // максимальная степень основания

int main(void) {
    printf("Enter number and base: ");
    n = scanf("%ld %d", &num, &base); 
    if (n < 2) { // проверка на ошибку ввода
        printf("\n Must be 2 arg\n");
        return 1;
    }
    if (base < 2) { // проверка на ошибку основания
        printf("\n Base must be >= 2\n");
        return 1;
    }

find_power: // находим старшую степень 
    if (power <= num / base) { // пока power * base не превысит num, увеличиваем степень основания
        power = power * base; 
        goto find_power;
    }

convert:
    printf("%d,", num / power);
    num %= power; // убираем старший разряд
    power /= base; // переходим на разряд ниже

    if (power != 0) {
        goto convert; 
    }

    return 0;
}