#include <stdio.h>

int main() {
    int routeNumber;
    char routeLetter;
    printf("Enter a route: ");
    scanf("%d%c", &routeNumber, &routeLetter);
    switch (routeNumber) {
        case 13:
            switch (routeLetter) {
                case 'B':
                    printf("Talamban - Carbon");
                    break;
                case 'C':
                    printf("Talamban - Colon");
                    break;
                case 'H':
                    printf("Pit-os - Mandaue");
                    break;
                default:
                    break;
            }
            break;
        case 12:
            switch (routeLetter) {
                case 'I':
                    printf("Labangon - SM");
                    break;
                case 'D':
                    printf("Labangon - Colon");
                    break;
                default:
                    break;
            }
            break;
        case 10:
            switch (routeLetter) {
                case 'G':
                    printf("Pardo - Magallanes");
                    break;
                case 'H':
                    printf("Bulacao - SM");
                    break;
                case 'M':
                    printf("Bulacao - SM");
                    break;
                default:
                    break;
            }
            break;
        case 17:
            switch (routeLetter) {
                case 'C':
                    printf("Apas - Carbon");
                    break;
                case 'B':
                    printf("Apas - Carbon");
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
    return 0;
}