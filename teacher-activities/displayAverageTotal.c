/*
 * Instruction: Write a C program to display the total and average of both
 * positive and negative numbers from a given list of 100 numbers (user input
 * or programmer-defined) using no arrays.
 *
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

int getSum(int start, int stop);

int main() {
    int start, stop, sum;
    float average;

    printf("Enter the start number: ");
    scanf("%d", &start);
    printf("Enter the stop number (inclusive): ");
    scanf("%d", &stop);

    sum = getSum(start, stop);
    average = (float)sum / (stop - start + 1);

    printf("The total is %d.\nThe average is %.1f.", sum, average);
    
    return 0;
}

int getSum(int start, int stop) {
    int result = 0;
    for (int i = start; i <= stop; ++i) { result += i; }
    return result;
}