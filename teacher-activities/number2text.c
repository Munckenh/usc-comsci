#include <stdio.h>

char* get_single_digit(int* digit);
char* get_xty(int* digit);
char* get_ten_to_nineteen(int* digit);

int main()
{
	int number, thousands, hundreds, tens, ones;
	
	printf("Enter a number: ");
	scanf("%d", &number);
	
	thousands = number / 1000 % 10;
	hundreds = number / 100 % 10;
	tens = number / 10 % 10;
	ones = number % 10;
	
	if (thousands) {
		printf("%s Thousand ", get_single_digit(&thousands));
	}
	if (hundreds) {
		printf("%s Hundred ", get_single_digit(&hundreds));
	}
	
	switch (tens) {
		case 0:
			printf("%s", get_single_digit(&ones));
			break;
		case 1:
			printf("%s", get_ten_to_nineteen(&ones));
			break;
		default:
			printf("%s ", get_xty(&tens));
			if (ones) {
				printf("%s", get_single_digit(&ones));
			}
	}
	
	return 0;
}

char* get_single_digit(int* digit) {
	switch (*digit) {
		case 1:
			return "One";
			break;
		case 2:
			return "Two";
			break;
		case 3:
			return "Three";
			break;
		case 4:
			return "Four";
			break;
		case 5:
			return "Five";
			break;
		case 6:
			return "Six";
			break;
		case 7:
			return "Seven";
			break;
		case 8:
			return "Eight";
			break;
		case 9:
			return "Nine";
			break;
		default:
			break;
	}
}

char* get_xty(int* digit) {
	switch (*digit) {
		case 2:
			return "Twenty";
			break;
		case 3:
			return "Thirty";
			break;
		case 4:
			return "Forty";
			break;
		case 5:
			return "Fifty";
			break;
		case 6:
			return "Sixty";
			break;
		case 7:
			return "Seventy";
			break;
		case 8:
			return "Eighty";
			break;
		case 9:
			return "Ninety";
			break;
		default:
			break;
	}
}

char* get_ten_to_nineteen(int* digit) {
	switch (*digit) {
		case 0:
			return "Ten";
			break;
		case 1:
			return "Eleven";
			break;
		case 2:
			return "Twelve";
			break;
		case 3:
			return "Thirteen";
			break;
		case 4:
			return "Fourteen";
			break;
		case 5:
			return "Fifteen";
			break;
		case 6:
			return "Sixteen";
			break;
		case 7:
			return "Seventeen";
			break;
		case 8:
			return "Eighteen";
			break;
		case 9:
			return "Nineteen";
			break;
		default:
			break;
	}
}
