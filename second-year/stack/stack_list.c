#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

void initialize(Stack *s) {
    s->top = NULL;
}

int is_empty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, int item) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->data = item;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(Stack *s) {
    if (is_empty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    Node* temp = s->top;
    int popped = temp->data;
    s->top = temp->next;
    free(temp);
    return popped;
}

int peek(Stack *s) {
    if (is_empty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->top->data;
}