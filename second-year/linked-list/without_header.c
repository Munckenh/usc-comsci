#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

void display(struct node* head) {
    struct node* current;
    for (current = head; current != NULL; current = current->next) {
        printf("%d ", current->data);
    }
}

void initialize(struct node** head_ref) {
    *head_ref = NULL;
}

void insert_last(struct node** head_ref, int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    struct node** current;
    for (current = head_ref; *current != NULL; current = &(*current)->next) {}
    *current = node;
}

void delete_item(struct node** head_ref, int data) {
    struct node** current;
    for (current = head_ref; *current != NULL && (*current)->data != data; current = &(*current)->next) {}
    if (*current != NULL) {
        struct node* node = *current;
        *current = (*current)->next;
        free(node);
    }
}