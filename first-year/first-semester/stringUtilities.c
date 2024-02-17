#include <stdio.h>
#include <stdlib.h>

int vowel_count(char* string);
int consonant_count(char* string);
int uppercase_count(char* string);
int lowercase_count(char* string);
int number_count(char* string);
int special_count(char* string);
char char_lower(char character);
char char_upper(char character);
char* str_lower(char* string);
char* str_upper(char* string);
char* str_toggle_case(char* string);

int main() {
	char text[64];
	printf("Enter text: ");
	gets(text);
	
	printf("Number of vowels: %d\n", vowel_count(text));
	printf("Number of consonants: %d\n", consonant_count(text));
	printf("Number of uppercase letters: %d\n", uppercase_count(text));
	printf("Number of lowercase letters: %d\n", lowercase_count(text));
	printf("Number of numbers: %d\n", number_count(text));
	printf("Number of special characters: %d\n", special_count(text));
	printf("Reverse lowercase and uppercase: %s\n", str_toggle_case(text));
	printf("Convert to lowercase: %s\n", str_lower(text));
	printf("Convert to uppercase: %s", str_upper(text));
	
	return 0;
}

char char_lower(char character) {
    if (character >= 'A' && character <= 'Z') {
        return character + 32;
    }
    return character;
}

char char_upper(char character) {
    if (character >= 'a' && character <= 'z') {
        return character - 32;
    }
    return character;
}

char* str_lower(char* string) {
    char* character = string;
    while (*character) {
        *character = char_lower(*character);
        character++;
    }
    return string;
}

char* str_upper(char* string) {
    char* character = string;
    while (*character) {
        *character = char_upper(*character);
        character++;
    }
    return string;
}

char* str_toggle_case(char* string) {
    char* character = string;
    while (*character) {
        if (*character >= 'A' && *character <= 'Z') {
            *character += 32;
        } else if (*character >= 'a' && *character <= 'z') {
            *character -= 32;
        }
        character++;
    }
    return string;
}

int vowel_count(char* string) {
    int result = 0;
    char character;
    while (*string) {
        character = char_lower(*string++);
        if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u') {
            ++result;
        }
    }
    return result;
}

int consonant_count(char* string) {
    int result = 0;
    char character;
    while (*string) {
        character = char_lower(*string++);
        if (character >= 'b' && character <= 'z' && character != 'e' && character != 'i' && character != 'o' && character != 'u') {
            ++result;
        }
    }
    return result;
}

int uppercase_count(char* string) {
    int result = 0;
    char character;
    while (*string) {
        character = *string++;
        if (character >= 'A' && character <= 'Z') {
            ++result;
        }
    }
    return result;
}

int lowercase_count(char* string) {
    int result = 0;
    char character;
    while (*string) {
        character = *string++;
        if (character >= 'a' && character <= 'z') {
            ++result;
        }
    }
    return result;
}

int number_count(char* string) {
    int result = 0;
    char character;
    while (*string) {
        character = *string++;
        if (character >= '0' && character <= '9') {
            ++result;
        }
    }
    return result;
}

int special_count(char* string) {
    int result = 0;
    char character;
    while (*string) {
        character = *string++;
        if (!(character >= '0' && character <= '9') && !(character >= 'a' && character <= 'z') && !(character >= 'A' && character <= 'Z')) {
            ++result;
        }
    }
    return result;
}