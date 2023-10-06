#include <stdio.h>

int main() {
    int current, end, skip;
    printf("Input range of numbers: ");
    scanf("%d %d", &current, &end);
    printf("Skip counting by: ");
    scanf("%d", &skip);
    printf("Skip counting by %d from %d to %d:\n", skip, current, end);
    while (current <= end) {
        printf("%d ", current);
        current += skip;
    }
    return 0;
}