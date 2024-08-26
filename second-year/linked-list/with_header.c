#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

void display(struct node* head) {
    struct node* current = head;
    while (current->next != NULL) {
        printf("%d ", current->next->data);
        current = current->next;
    }
}

struct node* initialize() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    return head;
}

void insert_last(struct node* head, int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    struct node* current;
    for (current = head; current->next != NULL; current = current->next) {}
    current->next = node;
}