#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue.h"

void initialize(struct queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

void enqueue(struct queue* q, int item) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = item;
    node->next = NULL;
    if (q->rear == NULL) {
        q->front = node;
    }
    else {
        q->rear->next = node;
    }
    q->rear = node;
}

int dequeue(struct queue* q) {
    int result = INT_MAX;
    if (q->front != NULL) {
        struct node* node = q->front;
        result = node->data;
        if (q->front->next == NULL) {
            q->front = NULL;
            q->rear = NULL;
        }
        else {
            q->front = q->front->next;
        }
        free(node);
    }
    return result;
}

void display(struct queue* q) {
    struct node* current;
    for (current = q->front; current != NULL; current = current->next) {
        printf("%d ", current->data);
    }
}