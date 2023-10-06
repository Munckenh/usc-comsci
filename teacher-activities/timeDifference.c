#include <stdio.h>

int main() {
	int hour1, hour2, minute1, minute2, difference;
	char meridiem1, meridiem2;
	
	printf("Enter time 1: ");
	scanf("%d:%d %cM", &hour1, &minute1, &meridiem1);
	printf("Enter time 2: ");
	scanf("%d:%d %cM", &hour2, &minute2, &meridiem2);
	
	if (meridiem1 == 'P') {
		hour1 += 12;
	}
	if (meridiem2 == 'P') {
		hour2 += 12;
	}
	if (minute1 > minute2) {
		minute2 += 60;
		hour2 -= 1;
	}

	printf("%d hours and %d minutes", hour2 - hour1, minute2 - minute1);
}
