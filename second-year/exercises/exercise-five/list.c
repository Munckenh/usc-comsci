#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct {
    char last_name[100];
    char first_name[100];
    char middle_initial;
} name_t;

typedef struct {
    name_t name;
    int id;
    char course[100];
    int year;
} student_t;

typedef struct {
    int size;
    int used_size;
    student_t* array;
} array_t;

typedef int position_t;

void initialize(array_t* a, int size) {
    a->used_size = 0;
    a->size = size;
    a->array = (student_t*)malloc(size * sizeof(student_t));
    if (a->array == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
}

void insert_last(student_t data, array_t* a) {
    if (a->used_size >= a->size) {
        a->size *= 2;
        a->array = (student_t*)realloc(a->array, a->size * sizeof(student_t));
        if (a->array == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    }
    a->array[a->used_size++] = data;
}

void insert(student_t data, position_t position, array_t* a) {
    if (position < a->used_size) {
        if (a->used_size >= a->size) {
            a->size *= 2;
            a->array = (student_t*)realloc(a->array, a->size * sizeof(student_t));
            if (a->array == NULL) {
                printf("Memory allocation failed\n");
                exit(1);
            }
        }
        for (int i = a->used_size++; i > position; --i) {
            a->array[i] = a->array[i - 1];
        }
        a->array[position] = data;
    }
}

void delete(position_t position, array_t* a) {
    if (position < a->used_size) {
        --a->used_size;
        for (int i = position; i < a->used_size; ++i) {
            a->array[i] = a->array[i + 1];
        }
    }
}

position_t locate(student_t data, array_t* a) {
    for (int i = 0; i < a->used_size; ++i) {
        if (strcmp(data.name.last_name, a->array[i].name.last_name) == 0 &&
            strcmp(a->array[i].name.first_name, data.name.first_name) == 0 &&
            a->array[i].name.middle_initial == data.name.middle_initial &&
            a->array[i].id == data.id &&
            strcmp(a->array[i].course, data.course) == 0 &&
            a->array[i].year == data.year) {
            return i;
        }
    }
    return INT_MAX;
}

student_t retrieve(position_t position, array_t* a) {
    if (position < a->used_size) {
        return a->array[position];
    }
    student_t dummy = { {"", "", ' '}, -1, "", -1 };
    return dummy;
}

void make_null(array_t* a) {
    a->used_size = 0;
}

void print_list(array_t* a) {
    printf("Student record has a total of %d student(s). It can hold a maximum of %d student(s).\n", a->used_size, a->size);
    for (int i = 0; i < a->used_size; ++i) {
        printf("Student #%d: %s, %s %c. (%d), Year %d at %s\n", i + 1, a->array[i].name.last_name, a->array[i].name.first_name, a->array[i].name.middle_initial, a->array[i].id, a->array[i].year, a->array[i].course);
    }
}

void populate(array_t* a) {
    insert_last((student_t) { { "Cahilog", "Kenneth", 'G' }, 23104856, "Bachelor of Science in Computer Science", 2 }, a);
    insert_last((student_t) { { "Solis", "Lyka Johnna", 'C' }, 11300244, "Bachelor of Science in Psychology", 2 }, a);
    insert_last((student_t) { { "Co", "Kiara Loraine", 'T' }, 24101491, "Bachelor of Fine Arts in Advertising Arts", 1 }, a);
}

void free_array(array_t* a) {
    free(a->array);
    a->array = NULL;
    a->size = 0;
    a->used_size = 0;
}

void main() {
    array_t student_record;
    initialize(&student_record, 1);
    populate(&student_record);
    print_list(&student_record);
    free_array(&student_record);
}