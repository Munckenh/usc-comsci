#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct node* initiate_list() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    return head;
}

void display(struct node* head) {
    struct node* current = head;
    while (current->next != NULL) {
        printf("%d ", current->next->data);
        current = current->next;
    }
}

void insert_at_beginning(struct node* head, int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = head->next;
    head->next = node;
}

void insert_at_index(struct node* head, int data, int index) {
    struct node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
        if (current->next == NULL) {
            break;
        }
    }
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = current->next;
    current->next = node;
}

void insert_at_end(struct node* head, int data) {
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = current->next;
    current->next = node;
}

void delete_by_index(struct node* head, int index) {
    struct node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
        if (current->next == NULL) {
            return;
        }
    }
    struct node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void delete_by_data(struct node* head, int data) {
    struct node* current = head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            struct node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            break;
        }
        current = current->next;
    }
}

void insert_sorted(struct node* head, int data) {
    struct node* current = head;
    while (current->next != NULL) {
        if (current->next->data >= data) {
            break;
        }
        current = current->next;
    }
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = current->next;
    current->next = node;
}
