#ifndef STACK_H
#define STACK_H

struct stack {
    int top;
    int size;
    int* array;
};

struct stack* initiate(int size);
void display(struct stack* stack);
void delete(struct stack* stack);
void push(struct stack* stack, int item);
int pop(struct stack* stack);

#endif