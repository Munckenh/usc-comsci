#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void print(Node* head);
void insert(Node* head, int data);
void append(Node* head, int data);

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    append(head, 4);
    print(head);
}

void print(Node* head) {
    Node* current = head;
    while (current->next != NULL) {
        printf("%d ", current->next->data);
        current = current->next;
    }
}

void insert(Node* head, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = head->next;
    head->next = node;
}

void append(Node* head, int data) {
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = current->next;
    current->next = node;
}