#include <stdio.h>

int main() {
    int width, height;
    printf("Enter width of skyscraper: ");
    scanf("%d", &width);
    printf("Enter height of skyscraper: ");
    scanf("%d", &height);
    for (int i = 0; i < 3; ++i) {
        printf(" ");
    }
    for (int i = 4; i < width; ++i) {
        printf("*");
    }
    printf("\n");
    for (int i = 2; i < height; ++i) {
        printf(" ");
        for (int j = 0; j < width; ++j) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = -2; i < width; ++i) {
        printf("*");
    }
    printf("\n");
    return 0;
}