#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int size;
    int used_size;
    int* array;
} array_t;

typedef int position_t;

void initialize(array_t* a, int size) {
    a->used_size = 0;
    a->size = size;
    a->array = (int*)malloc(size * sizeof(int));
}

void resize(array_t* a, int size) {
    realloc(a, size * sizeof(int));
    a->size *= 2;
}

void display(array_t* a) {
    for (int i = 0; i < a->used_size; ++i) {
        printf("%d ", a->array[i]);
    }
    printf("\n");
}

void insert_last(array_t* a, int data) {
    if (a->used_size >= a->size) {
        resize(a, a->size * 2);
    }
    a->array[a->used_size++] = data;
}

void populate(array_t* a) {
    initialize(a, 8);
    insert_last(a, 10);
    insert_last(a, 20);
    insert_last(a, 30);
    insert_last(a, 40);
    insert_last(a, 50);
    insert_last(a, 60);
    insert_last(a, 70);
    insert_last(a, 80);
}

void insert_at(array_t* a, int data, position_t position) {
    if (position < a->used_size) {
        if (a->used_size >= a->size) {
            resize(a, a->size * 2);
        }
        for (int i = a->used_size++; i > position; --i) {
            a->array[i] = a->array[i - 1];
        }
        a->array[position] = data;
    }

}

void delete_at(array_t* a, position_t position) {
    if (position < a->used_size) {
        --a->used_size;
        for (int i = position; i < a->used_size; ++i) {
            a->array[i] = a->array[i + 1];
        }
    }
}

position_t locate(array_t* a, int data) {
    for (int i = 0; i < a->used_size; ++i) {
        if (a->array[i] == data) {
            return i;
        }
    }
}

int main() {
    array_t array;
    populate(&array);
    display(&array);
    return 0;
}