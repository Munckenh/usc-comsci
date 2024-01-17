#include <stdio.h>

void swap(int* x, int* y);

int main() {
    int number;
    printf("Enter a three-digit number: ");
    scanf("%d", &number);

    int a = number / 100 % 10;
    int b = number / 10 % 10;
    int c = number % 10;

    if (a > b) { swap(&a, &b); }
    if (b > c) { swap(&b, &c); }
    if (a > b) { swap(&a, &b); }

    printf("The sorted number is: %d", a * 100 + b * 10 + c);

    return 0;
}

void swap(int* x, int* y) {
    *x += *y;
    *y = *x - *y;
    *x -= *y;
}