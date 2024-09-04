#include <stdio.h>

void display_binary(unsigned int value) {
    for (int i = 8 * sizeof(int) - 1; i >= 0; --i) {
        printf("%d", (value >> i) & 1);
    }
    printf("\n");
}