#include <stdio.h>

void displayTime(int hour, int min, int sec);

int main() {
    int time, hour, min, sec;
    printf("Enter the time in seconds: ");
    scanf("%d", &time);
    hour = time / 3600;
    time = time % 3600;
    min = time / 60;
    sec = time % 60;
    displayTime(hour, min, sec);
    return 0;
}

void displayTime(int hour, int min, int sec) {
    printf("%02d:%02d:%02d", hour, min, sec);
}