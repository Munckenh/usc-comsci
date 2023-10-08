/*
 * Instruction: Write a C program to display the sum of all even numbers and
 * product of all odd numbers from a given list of 100 numbers (user input or
 * programmer-defined) using no arrays.
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

int main() {
    int current;
    int sum = 0;
    int product = 1;

    for (int i = 0; i < 100; ++i) {
        printf("Enter a number: ");
        scanf("%d", &current);
        if (current % 2 == 0) {
            sum += current;
        } else {
            product *= current;
        }
    }

    printf("The sum of all even numbers is %d.\n"
           "The product of all odd numbers is %d.", sum, product);
    
    return 0;
}