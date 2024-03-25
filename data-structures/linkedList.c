#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void display(Node* head);
void insert_at_beginning(Node* head, int data);
void insert_at_index(Node* head, int data, int index);
void insert_at_end(Node* head, int data);

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->next = NULL;
    insert_at_end(head, 20);
    insert_at_end(head, 40);
    insert_at_beginning(head, 10);
    insert_at_index(head, 30, 2);
    display(head);
}

void display(Node* head) {
    Node* current = head;
    while (current->next != NULL) {
        printf("%d ", current->next->data);
        current = current->next;
    }
}

void insert_at_beginning(Node* head, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = head->next;
    head->next = node;
}

void insert_at_index(Node* head, int data, int index) {
    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
        if (current->next == NULL) {
            break;
        }
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = current->next;
    current->next = node;
}

void insert_at_end(Node* head, int data) {
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = current->next;
    current->next = node;
}