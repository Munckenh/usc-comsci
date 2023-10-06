#include <stdio.h>

int main() {
    int number, i, j;
    int* pointer = &i;
    printf("Enter your number: ");
    scanf("%d", &number);
    for (i = 0; i < number; ++i) {
        for (j = 0; j < number; ++j) {
            if (j == number - 1) {
                printf("%d ", *pointer + 2);
            } else {
                printf("%d ", *pointer + 1);
            }
        }
        printf("\n");
    }
    return 0;
}