#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s);
int is_empty(Stack *s);
int is_full(Stack *s);
void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);

#endif