#include <stdio.h>

int lcm(int a, int b);

int main() {
    int a, b;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("The least common multiple is %d.", lcm(a, b));
    return 0;
}

int lcm(int a, int b) {
    int current;
    if (a > b) {
        current = a;
    } else {
        current = b;
    }
    while (1) {
        if (current % a == 0 && current % b == 0) {
            return current;
        }
        ++current;
    }
}