#include <stdio.h>

int main() {
    int number, result;
    do {
        system("cls");
        printf("Input range of numbers: ");
        scanf("%d", &number);
    } while(number < 10000 || number > 9999999999);
    result = number % 10;
    number /= 10;
    while (number > 0) {
        if (result > number % 10) {
            result = number % 10;
        }
        number /= 10;
    }
    printf("Smallest digit: %d", result);
    return 0;
}