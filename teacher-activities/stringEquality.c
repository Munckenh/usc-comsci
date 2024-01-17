#include <stdio.h>
#include <stdbool.h>

bool streq(char* string1, char* string2);

void main() {
    char s1[256];
    char s2[256];

    printf("Enter the first string: ");
    scanf(" %[^\n]", s1);
    printf("Enter the second string: ");
    scanf(" %[^\n]", s2);

    if (streq(s1, s2)) {
        printf("Both strings are equal.");
    } else {
        printf("Both strings are not equal.");
    }
}

bool streq(char* string1, char* string2) {
    for (int i = 0; ; ++i) {
        if (string1[i] != string2[i]) { return false; }
        if (string1[i] == '\0') {
            if (string2[i] == '\0') {
                return true;
            } else {
                return false;
            }
        }
    }
}