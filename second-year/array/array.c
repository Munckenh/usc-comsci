#include <stdio.h>
#include <string.h>
#define MAX 5

typedef struct array {
    int item[MAX];
    int count;
} array_t;

void display(array_t* array) {
    for (int i = 0; i < 10; ++i) {
        printf("%d ", array->item[i]);
    }
}

void initialize(array_t* array) {
    array->count = 0;
}

void insert_last(array_t* array, int data) {
    if (array->count < MAX) {
        array->item[array->count++] = data;
    }
}

void insert_last_unique(array_t* array, int data) {
    if (array->count < MAX) {
        int i;
        for (i = 0; i < array->count && array->item[i] != data; ++i) {}
        if (i == array->count) {
            array->item[array->count++] = data;
        }
    }
}

void delete_first_occurence(array_t* array, int data) {
    int i;
    for (i = 0; i < array->count && array->item[i] != data; ++i) {
    }
    if (i < array->count) {
        --array->count;
        for (; i < array->count; ++i) {
            array->item[i] = array->item[i + 1];
        }
    }
}

void delete_all_occurence(array_t* array, int data) {
    for (int i = 0; i < array->count;) {
        if (array->item[i] == data) {
            --array->count;
            for (int j = i; j < array->count; ++j) {
                array->item[j] = array->item[j + 1];
            }
        }
        else { ++i; }
    }
}

void insert_sorted(array_t* array, int data) {
    if (array->count < MAX) {
        int i;
        for (i = 0; i < array->count && array->item[i] < data; ++i) {}
        if (i < array->count) {
            for (int j = array->count; j > i; --j) {
                array->item[j] = array->item[j - 1];
            }
        }
        ++array->count;
        array->item[i] = data;
    }
}