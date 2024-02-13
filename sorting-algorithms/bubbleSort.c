#include <stdio.h>

void swap(int* a, int* b);
void bubble_sort(int* array, int size);
void print_array(int* array, int size);

int main() {
    int unsorted_array[] = {4, 5, 6, 3, 1, 2, 9, 7, 8};
    bubble_sort(unsorted_array, sizeof(unsorted_array)/sizeof(unsorted_array[0]));
    print_array(unsorted_array, sizeof(unsorted_array)/sizeof(unsorted_array[0]));
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

void print_array(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        if (i == 0) {
            printf("{%d", array[i]);
        } else {
            printf(", %d", array[i]);
        }
    }
    printf("}");
}
