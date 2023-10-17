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

int getDigits(int number);
int power(int base, int exponent);
int decimalToBinary(int decimal);
int isPalindrome(int number);

/* Instructions */

/*
 * As you entered the hall walking slowly. A loud voice saying "I am your god.
 * And I will only accept those who are deemed worthy. Show me what you have
 * got." As you continue to walk, in the wall shows the inscribed text that
 * translates as follows:
 * 
 *    - Only those soul who's clean are deemed acceptable.
 *    - The good deeds are weighted in a scale.
 *    - Balancing the good and the bad.
 * 
 * "How is this possible?" you have asked in your head. A man just walkout in the
 * dark alley towards you saying, "Nah, It's easy my lad, just give a number and
 * get the good (1) and bad (0) equivalent and if your souls value is clean
 * (means that either left or right direction it would be the same). Then you are
 * deemed worthy.
 * 
 * Hint: Create a program that would accept a number. And checks if the binary
 * equivalent is a palindrome.
 */

/* Sample Output 1 */

/*
 * Enter your number: 5
 * The value of your soul is 101.
 * You are worthy my child.
 */

/* Sample Output 2 */

/*
 * Enter your number: 10
 * The value of your soul is 1010.
 * Ahh, you are filty. Be gone.
 */

/* Sample Output 3 /*

/*
 * Enter your number: 45
 * The value of your soul is 101101.
 * You are worthy my child.
 */

void main() {
    int number, binaryNumber;

    printf("Enter your number: ");
    scanf("%d", &number);

    binaryNumber = decimalToBinary(number);
    printf("The value of your soul is %d.\n", binaryNumber);
    
    if (isPalindrome(binaryNumber)) {
        printf("You are worthy my child.");
    } else {
        printf("Ahh, you are filty. Be gone.");
    }
}

int getDigits(int number) {
    int digits = 0;

    while (number > 0) {
        digits += 1;
        number /= 10;
    }

    return digits;
}

int power(int base, int exponent) {
    int result = 1;

    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    
    return result;
}

int decimalToBinary(int decimalNumber) {
    int binaryNumber = 0;

    for (int i = 1; decimalNumber > 0; i *= 10) {
        binaryNumber += decimalNumber % 2 * i;
        decimalNumber /= 2;
    }

    return binaryNumber;
}

int isPalindrome(int number) {
    int digits = getDigits(number);
    int paddedOriginalNumber = 1 + power(10, digits + 1) + number * 10;
    int paddedReversedNumber = 1 + power(10, digits + 1);

    for (int i = digits; i > 0; --i) {
        paddedReversedNumber += (number % 10) * power(10, i);
        number /= 10;
    }
    
    if (paddedReversedNumber == paddedOriginalNumber) {
        return 1;
    } else {
        return 0;
    }
}