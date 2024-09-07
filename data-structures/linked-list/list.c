#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void initialize(struct node** head_ref) {
    *head_ref = NULL;
}

void display(struct node* head) {
    struct node* current;
    for (current = head; current != NULL; current = current->next) {
        printf("%d ", current->data);
    }
    printf("\n");
}

void insert_at_beginning(struct node** head_ref, int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
    }
    else {
        node->data = data;
        node->next = *head_ref;
        *head_ref = node;
    }
}

void insert_at_index(struct node** head_ref, int data, int index) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
    }
    else {
        node->data = data;
        struct node** current = head_ref;
        int i;
        for (i = 0; *current != NULL && i < index; current = &(*current)->next, ++i);
        if (i == index) {
            node->next = *current;
            *current = node;
        }
        else {
            printf("Index out of bounds!\n");
        }

    }
}

void insert_at_end(struct node** head_ref, int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
    }
    else {
        node->data = data;
        node->next = NULL;
        struct node** current;
        for (current = head_ref; *current != NULL; current = &(*current)->next);
        *current = node;
    }
}

void delete_by_index(struct node** head_ref, int index) {
    struct node** current;
    int i;
    for (i = 0, current = head_ref; *current != NULL && i < index; current = &(*current)->next, ++i);
    if (*current != NULL) {
        struct node* node = *current;
        *current = node->next;
        free(node);
    }
    else {
        printf("Index out of bounds!\n");
    }
}

void delete_by_data(struct node** head_ref, int data) {
    struct node** current;
    for (current = head_ref; *current != NULL && (*current)->data != data; current = &(*current)->next);
    if (*current != NULL) {
        struct node* node = *current;
        *current = node->next;
        free(node);
    }
    else {
        printf("Data not in list!\n");
    }
}

void insert_sorted(struct node** head_ref, int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
    }
    else {
        node->data = data;
        struct node** current;
        for (current = head_ref; *current != NULL && (*current)->data < data; current = &(*current)->next);
        node->next = *current;
        *current = node;
    }
}