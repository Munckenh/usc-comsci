#include <stdio.h>

int lcm(int x, int y);

int main() {
    printf("%d", lcm(10, 15));
    return 0;
}

int lcm(int x, int y) {
    int current;
    if (x > y) {
        current = x;
    } else {
        current = y;
    }
    while (1) {
        if (current % x == 0 && current % y == 0) {
            return current;
        }
        ++current;
    }
}