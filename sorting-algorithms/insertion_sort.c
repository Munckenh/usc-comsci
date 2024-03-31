#include <stdio.h>

void insertion_sort(int* array, int size);
void print_array(int* array, int size);

int main() {
    int unsorted_array[] = {5, 4, 6, 3, 1, 2, 9, 7, 8};
    int size = sizeof(unsorted_array)/sizeof(unsorted_array[0]);
    insertion_sort(unsorted_array, size);
    print_array(unsorted_array, size);
    return 0;
}

void insertion_sort(int* array, int size) {
    for (int i = 1; i < size; ++i) {
        int key = array[i];
        int j = i - 1;
        while (array[j] > key && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
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