#include <stdio.h>
// #include "stack_list.h"
#include "stack_array.h"

void insert_bottom(Stack* stack, int item) {
    Stack temp;
    initialize(&temp);
    while (!is_empty(stack)) {
        push(&temp, pop(stack));
    }
    push(stack, item);
    while (!is_empty(&temp)) {
        push(stack, pop(&temp));
    }
}

int main() {
    Stack s;
    initialize(&s);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    push(&s, 40);
    printf("Top element: %d\n", peek(&s));
    while (!is_empty(&s)) {
        printf("Popped: %d\n", pop(&s));
    }

    return 0;
}