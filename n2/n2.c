#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int a, b, c, d;
typedef long long int ll;
int* pa = &a, * pb = &b, * pc = &c, * pd = &d; // объявление указателей

void init_rng(void) { // создание уникального сида, привязанного к времени
	time_t curtime;
	time(&curtime);
	srand((unsigned int)curtime);
	rand(); rand(); rand();
}

int gen_rnd_int(void) { // генерация случайного числа от 0 до 99
	ll t = ((ll)rand() * 100) / RAND_MAX;
	return (int)t;
}

int main(void) {
	init_rng();
	a = gen_rnd_int(); b = gen_rnd_int(); c = gen_rnd_int(); d = gen_rnd_int();
	printf("%d %d %d %d\n", a, b, c, d);
	printf("%d %d %d %d\n", *pa, *pb, *pc, *pd);

	// сортировка пузырьком с обменом по указателям
	if (*pa > *pb) {
		int pt = *pa; *pa = *pb; *pb = pt;
	}
	if (*pa > *pc) {
		int pt = *pa; *pa = *pc; *pc = pt;
	}
	if (*pa > *pd) {
		int pt = *pa; *pa = *pd; *pd = pt;
	}

	if (*pb > *pc) {
		int pt = *pb; *pb = *pc; *pc = pt;
	}
	if (*pb > *pd) {
		int pt = *pb; *pb = *pd; *pd = pt;
	}

	if (*pc > *pd) {
		int pt = *pc; *pc = *pd; *pd = pt;
	}

	printf("%d %d %d %d\n", a, b, c, d);
	printf("%d %d %d %d\n", *pa, *pb, *pc, *pd);
	return 0;
}