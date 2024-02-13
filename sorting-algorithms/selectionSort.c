#include <stdio.h>

void swap(int* a, int* b);
void selection_sort(int* array, int size);
void print_array(int* array, int size);

int main() {
    int unsorted_array[] = {4, 5, 6, 3, 1, 2, 9, 7, 8};
    int size = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    selection_sort(unsorted_array, size);
    print_array(unsorted_array, size);
    return 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int* array, int size) {
    int* minimum;
    for (int i = 0; i < size; ++i) {
        minimum = &array[i];
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < *minimum) {
                minimum = &array[j];
            }
        }
        swap(&array[i], minimum);
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