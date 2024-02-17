#include <stdio.h>

int main() {
	int number;
	printf("Enter a number: ");
	scanf("%d", &number);
	if (number % 2 == 0) {
		printf("Fizz");
	}
	if (number % 5 == 0) {
		printf("Buzz");
	}
	
	return 0;	
}
