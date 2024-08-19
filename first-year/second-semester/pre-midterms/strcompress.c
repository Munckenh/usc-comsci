/*
 * Copyright (c) 2023 Kenneth C.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


/*
 * My MINI me by Gran Sabandal
 *
 * Instructions:
 * Create a program that performs string compression by replacing repeated
 * characters with their counts. When the program runs, it will ask the user to
 * input a string. After receiving the input, the program will analyze the
 * string and compress it by replacing consecutive repeated characters with a
 * single occurrence followed by the count of repetitions in the consecutive
 * repetition. Finally, it will display the compressed string as the output.
 * 
 * Sample output 1:
 * Enter a string: aabbc
 * Compressed string: a2b2c
 * 
 * Sample output 2:
 * Enter a string: cccccccceeeeeeeee
 * Compressed string: c8e9
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

char* strcompress(char* string);

void main() {
    char string[MAX];
    printf("Enter a string: ");
    scanf("%s", string);
    printf("Compressed string: %s", strcompress(string));
}

char* strcompress(char* string) {
    char* result = malloc(strlen(string) * sizeof(char));
    result[0] = '\0';

    for (int i = 0; string[i] != '\0'; ++i) {
        int count = 1;
        while (string[i] == string[i + 1]) {
            ++i;
            ++count;
        }
        sprintf(result + strlen(result), "%c", string[i]);
        if (count > 1) {
            sprintf(result + strlen(result), "%d", count);
        }
    }

    return result;
}