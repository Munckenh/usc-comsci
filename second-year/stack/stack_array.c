#include <stdio.h>
#include "stack_array.h"

void initialize(Stack *s) {
    s->top = -1;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

int is_full(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int item) {
    if (is_full(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[s->top];
}