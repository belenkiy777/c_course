#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long int number;
int base, n, a, b, c, d, e, f, g, h, i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z, z1, z2, z3, z4, z5;

int main(void) {
	printf("\n Number, base: ");
	n = scanf("%d, %d", &number, &base);
	if (n < 2) {
		printf("\n There must be 2 args \n");
		return 1;
	}
	if (base > 32) {
		printf("\n Base must be from 2 to 32 \n");
		return 2;
	}
	if (base < 2) {
		printf("\n Base must be from 2 to 32 \n");
		return 2;
	}
	if (number < 0) {
		printf("\n Number must be positive \n");
		return 2;
	}
	if (number > 0) {
		a = a * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		b = b * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		c = c * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		d = d * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		e = e * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		f = f * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		g = g * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		h = h * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		j = j * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		k = k * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		l = l * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		m = m * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		o = o * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		p = p * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		q = q * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		r = r * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		s = s * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		t = t * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		u = u * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		v = v * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		w = w * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		x = x * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		y = y * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		z = z * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		z1 = z1 * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		z2 = z2 * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		z3 = z3 * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		z4 = z4 * 10 + number % base;
		number = number / base;
	}
	if (number > 0) {
		z4 = z4 * 10 + number % base;
		number = number / base;
	}
	printf("\n Result of translation = %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d \n", z5, z4, z3, z2, z1, z, y, x, w, v, u, t, s, r, q, p, o, m, l, k, j, i, h, g, f, e, d, c, b, a);
	return 0;
}