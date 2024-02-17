#include <stdio.h>

void main() {
    char s[256];
    printf("Enter the first string: ");
    scanf(" %[^\n]", s);

    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            s[i] = '_';
        }
    }

    printf("%s", s);
}