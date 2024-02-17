#include <stdio.h>

void print_digit(int *number);

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    print_digit(&number);
    return 0;
}

void print_digit(int *number)
{
    int digit;
    if (*number <= 0)
    {
        return;
    }
    digit = *number % 10;
    *number /= 10;
    print_digit(number);
    printf("%d\n", digit);
}