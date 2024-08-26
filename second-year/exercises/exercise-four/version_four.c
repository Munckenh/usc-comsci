#include <stdlib.h>
#define MAX 10

typedef struct {
    int* elements_ptr;
    int count;
    int max_size;
} *List;

void initialize(List L) {
    L->count = 0;
    L->max_size = MAX;
    L->elements_ptr = (int*)malloc(sizeof(int) * L->max_size);
}

void insert_last(List L, int data) {
    if (L->count >= L->max_size) {
        L->max_size *= 2;
        realloc(L->elements_ptr, sizeof(int) * L->max_size);
    }
    L->elements_ptr[L->count++] = data;
}

int main() {
    List L;
    initialize(L);
    return 0;
}