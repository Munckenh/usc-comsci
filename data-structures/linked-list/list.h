#ifndef LIST_H
#define LIST_H

struct node {
    int data;
    struct node* next;
};

void initialize(struct node**);
void display(struct node*);
void insert_at_beginning(struct node**, int);
void insert_at_index(struct node**, int, int);
void insert_at_end(struct node**, int);
void delete_by_index(struct node**, int);
void delete_by_data(struct node**, int);
void insert_sorted(struct node**, int);

#endif