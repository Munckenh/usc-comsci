#ifndef QUEUE_H
#define QUEUE_H

struct node {
    int data;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

void initialize(struct queue*);
void enqueue(struct queue*, int);
int dequeue(struct queue*);
void display(struct queue*);

#endif