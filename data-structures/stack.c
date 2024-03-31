#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

#define INT_MIN -2147483648

struct stack* initiate(int size) {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (int*)malloc(stack->size * sizeof(int));
    return stack;
}

void display(struct stack* stack) {
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
}

void delete(struct stack* stack) {
    free(stack->array);
    free(stack);
}

bool push(struct stack* stack, int item) {
    if (stack->top == stack->size - 1) {
        return false;
    }
    stack->array[++stack->top] = item;
    return true;
}

int pop(struct stack* stack) {
    if (stack->top == -1) {
        return INT_MIN;
    }
    return stack->array[stack->top--];
}