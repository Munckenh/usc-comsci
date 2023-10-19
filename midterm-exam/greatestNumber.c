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

/* Instructions */

/*
 * You are an employee in charge of auctioning out your products in an infinite
 * market, inside the infinite market there is an infinite crowd. It wouldn't be
 * smart if you took all your time in a day to ask for offers from the infinite
 * crowd, because that would take an infinite amount of time, and you just have
 * other tasks you need to handle. So you decide that as soon as you see an offer
 * for 0 you stop, but at the same time after a change in the highest offer 3
 * times, you will directly sell it to the current greatest offer.
 * 
 * Create a program that asks the user for an input until the user inputs 0 and
 * display the greatest number inputted, If the greatest number has changed 3
 * times throughout the course of the program, stop asking for other inputs and
 * instead display the greatest number up to that point.
 */

/* Sample Output 1 */

/*
 * Input a Number: 10
 * Input a Number: 20
 * Input a Number: 30
 * 
 * Program Ended due to 3 changes in the Greatest Number
 * 
 * The Greatest Number is : 30
 */

/* Sample Output 2 */

/*
 * Input a Number: 30
 * Input a Number: 20
 * Input a Number: 12
 * Input a Number: 42
 * Input a Number: 31
 * Input a Number: 32
 * Input a Number: 29
 * Input a Number: 40
 * Input a Number: 41
 * Input a Number: 0
 * 
 * Program Ended due to an input of 0
 * 
 * The Greatest Number is : 42
 */

/* Sample Output 3 */

/*
 * Input a Number: 0
 * 
 * Program Ended due to an input of 0
 * 
 * The Greatest Number is : 0
 */

int main() {
    int number;
    int changes = 0;
    int greatestNumber = 0;

    do {
        printf("Input a Number: ");
        scanf("%d", &number);

        if (number > greatestNumber) {
            greatestNumber = number;
            changes += 1;
        }
    } while (number != 0 && changes < 3);

    if (number == 0) {
        printf("\nProgram Ended due to an input of 0\n\n");
    } else {
        printf("\nProgram Ended due to 3 changes in the Greatest Number\n\n");
    }
    printf("The Greatest Number is : %d", greatestNumber);

    return 0;
}