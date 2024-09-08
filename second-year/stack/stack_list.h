#ifndef STACK_LIST_H
#define STACK_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initialize(Stack *s);
int is_empty(Stack *s);
void push(Stack *s, int item);
int pop(Stack *s);
int peek(Stack *s);

#endif