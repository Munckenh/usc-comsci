#include <stdio.h>

void display_binary(unsigned int value) {
    for (unsigned int mask = 1 << (8 * sizeof(unsigned int) - 1); mask > 0; mask >>= 1) {
        printf("%d", (mask & value) != 0);
    }
    printf("\n");
}