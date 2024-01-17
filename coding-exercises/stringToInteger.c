#include <stdio.h>

int strToInt(char* string);

int main() {
    printf("%d\n", strToInt("1024asdf"));
    printf("%d\n", strToInt("-256"));
    printf("%d", strToInt("-64asd16"));

    return 0;
}

int strToInt(char* string) {
    int current = 0;
    int negative = 0;
    int result = 0;


    while (string[current] == ' ') {
        current++;
    }

    if (string[current] == '-') {
        current++;
        negative = 1;
    } else if (string[current] == '+') {
        current++;
    }

    
    while (string[current] != '\0') {
        if (string[current] < '0' || string[current] > '9') {
            break;
        }
        result *= 10;
        result += string[current] - 48;
        current++;
    }

    if (negative == 1) {
        result *= -1;
    }

    return result;
}