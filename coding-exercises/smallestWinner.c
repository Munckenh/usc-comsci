#include <stdio.h>

int main() {
    int weights[3];
    int* result;
    printf("Enter the first weight: ");
    scanf("%d", &weights[0]);
    result = &weights[0];
    printf("Enter the second weight: ");
    scanf("%d", &weights[1]);
    if (weights[1] < *result) {
        result = &weights[1];
    }
    printf("Enter the third weight: ");
    scanf("%d", &weights[2]);
    if (weights[2] < *result) {
        result = &weights[2];
    }
    printf("Smallest weight = %d", *result);
    return 0;
}