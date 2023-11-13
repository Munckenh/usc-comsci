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
 * In Cebu, the fare for trips taken via taxi depends on the distance traveled
 * and the time taken to complete the journey.
 * 
 * The minimum fare is 40 pesos which then increases by 2 pesos for every full
 * minute and 13 pesos and 50 centavos for every full kilometer traveled.
 * 
 * Create a user-friendly program to simulate the situation by computing the
 * taxi fare based on the distance in kilometers and estimated journey time
 * provided by the user in minutes. Inputs shall not be restricted to just
 * integers.
 */

int main() {
    float minutes, kilometers;

    printf("Enter distance traveled (km): ");
    scanf("%f", &kilometers);
    printf("Enter time taken (minutes): ");
    scanf("%f", &minutes);

    printf("The total fare: Php%.2f", 40 + 2 * minutes + 13.5 * kilometers);
}