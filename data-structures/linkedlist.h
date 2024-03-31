#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct node {
    int data;
    struct node* next;
};

void display(struct node* head);
void insert_at_beginning(struct node* head, int data);
void insert_at_index(struct node* head, int data, int index);
void insert_at_end(struct node* head, int data);
void delete_by_index(struct node* head, int index);
void delete_by_data(struct node* head, int data);
void insert_sorted(struct node* head, int data);

#endif