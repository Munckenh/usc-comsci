#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = value;
    node->next = NULL;
    return node;
}

int cardinality(Node* set) {
    Node* current = set;
    int count;
    for (count = 0; current != NULL; current = current->next, ++count);
    return count;
}

bool contains(Node* set, int value) {
    Node* current = set;
    for (; current != NULL && current->data != value; current = current->next);
    return (current != NULL) ? true : false;
}

void display(Node* set) {
    Node* current;
    for (current = set; current != NULL; current = current->next) {
        printf("%d ", current->data);
    }
    printf("\n");
}

Node* get_union(Node* a, Node* b) {
    Node* result = NULL;
    Node** tail = &result;
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            *tail = create_node(a->data);
            a = a->next;
        }
        else if (a->data > b->data) {
            *tail = create_node(b->data);
            b = b->next;
        }
        else {
            *tail = create_node(a->data);
            a = a->next;
            b = b->next;
        }
        tail = &(*tail)->next;
    }
    if (a == NULL) {
        *tail = b;
    }
    else if (b == NULL) {
        *tail = a;
    }
    return result;
}

Node* get_intersection(Node* a, Node* b) {
    Node* result = NULL;
    Node** tail = &result;
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            a = a->next;
        }
        else if (a->data > b->data) {
            b = b->next;
        }
        else {
            *tail = create_node(a->data);
            tail = &(*tail)->next;
            a = a->next;
            b = b->next;
        }
    }
    return result;
}

void populate(Node** a, Node** b) {
    *a = create_node(0);
    (*a)->next = create_node(1);
    (*a)->next->next = create_node(2);
    (*a)->next->next->next = create_node(4);
    (*a)->next->next->next->next = create_node(7);
    *b = create_node(2);
    (*b)->next = create_node(3);
    (*b)->next->next = create_node(4);
    (*b)->next->next->next = create_node(5);
    (*b)->next->next->next->next = create_node(6);
    (*b)->next->next->next->next->next = create_node(8);
    (*b)->next->next->next->next->next->next = create_node(9);
}

int main() {
    Node* a; // 0, 1, 2, 4, 7
    Node* b; // 2, 3, 4, 5, 6, 8, 9
    populate(&a, &b);
    Node* c = get_intersection(a, b);
    display(c);
    return 0;
}