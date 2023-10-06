#include <stdio.h>

int main() {
    char option;
    int gallons;
    printf("Pick an option (A/B/C): ");
    scanf("%c", &option);
    printf("Enter gallons of water used: ");
    scanf("%d", &gallons);
    switch (option) {
        case 'A':
            printf("Your bill is Php %.2f", 250 + 0.002 * gallons);
            break;
        case 'B':
            if (gallons > 4000000) {
                printf("Your bill is Php %.2f", 5000 + 0.002 * (gallons - 4000000));
            } else {
                printf("Your bill is Php 5000.00");
            }            
            break;
        case 'C':
            if (gallons > 10000000) {
                printf("Your bill is Php 18000.00");
            } else if (gallons > 6000000) {
                printf("Your bill is Php 14000.00");
            } else {
                printf("Your bill is Php 8000.00");
            }
            break;
        default:
            break;
    }
    return 0;
}