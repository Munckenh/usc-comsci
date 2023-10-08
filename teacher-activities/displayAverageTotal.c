/*
 * Instruction: Write a C program to display the total and average of both
 * positive and negative numbers from a given list of 100 numbers (user input
 * or programmer-defined) using no arrays.
 *
 * Copyright (C) 2023 Kenneth C.
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
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