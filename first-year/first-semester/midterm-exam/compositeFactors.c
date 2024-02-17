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

#include <stdio.h>

int isPrime(int number);

/* Instructions */

/*
 * Please help me find all the factors of a given number and highlight the
 * composite factors.
 */

/* Sample Output 1 */

/*
 * Enter a number: 10
 * 1 2 5 {10}
 */

/* Sample Output 2 */

/*
 * Enter a number: 1
 * 1
 */

/* Sample Output 3 /*

/*
 * Enter a number: 20
 * 1 2 {4} 5 {10} {20}
 */

int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    for (int i = 1; i <= number; ++i) {
        if (number % i == 0) {
            if (isPrime(i)) {
                printf("%d ", i);
            } else {
                printf("{%d} ", i);
            }
        }
    }

    return 0;
}

int isPrime(int number) {
    if (number == 1) {
        return 1;
    }

    for (int i = 2; i < number; ++i) {
        if (number % i == 0) {
            return 0;
        }
    }
    
    return 1;
}