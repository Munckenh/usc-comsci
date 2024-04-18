#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT_MIN -2147483648
#define MAX_SIZE 100

struct stack {
    int top;
    int size;
    int* array;
};

struct node {
    int data;
    struct node* next;
};

void display_menu();
void display_stack_menu();
void display_queue_menu();
void display_set_menu();
void display_list_menu();
void display_ordered_list_menu();
struct stack* stack_initiate(int size);
void stack_push(struct stack* stack, int item);
int stack_pop(struct stack* stack);
void stack_display(struct stack* stack);
void enqueue(struct node* head, int data);
int dequeue(struct node* head);
void queue_display(struct node* head);
bool set_insert(struct node* head, int data);
bool set_remove(struct node* head, int data);
void set_display(struct node* head);
void list_append(struct node* head, int data);
bool list_remove(struct node* head, int data);
void list_add_sorted(struct node* head, int data);
void list_display(struct node* head);

int main() {
    display_menu();
    return 0;
}

void list_add_sorted(struct node* head, int data) {
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

void list_append(struct node* head, int data) {
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = current->next;
    current->next = node;
}

bool list_remove(struct node* head, int data) {
    struct node* current = head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            struct node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return true;
        }
        current = current->next;
    }
    return false;
}

void list_display(struct node* head) {
    printf("The content(s) of the list is/are: ");
    struct node* current = head;
    while (current->next != NULL) {
        printf("%d ", current->next->data);
        current = current->next;
    }
    printf("\n\n");
}

bool set_insert(struct node* head, int data) {
    struct node* current = head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            return false;
        }
        current = current->next;
    }
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
    current->next = node;
    return true;
}

bool set_remove(struct node* head, int data) {
    struct node* current = head;
    while (current->next != NULL) {
        if (current->next->data == data) {
            struct node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return true;
        }
        current = current->next;
    }
    return false;
}

void set_display(struct node* head) {
    printf("The content(s) of the set is/are: ");
    struct node* current = head;
    while (current->next != NULL) {
        printf("%d ", current->next->data);
        current = current->next;
    }
    printf("\n\n");
}

void enqueue(struct node* head, int data) {
    struct node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->next = current->next;
    current->next = node;
}

int dequeue(struct node* head) {
    if (head->next == NULL) {
        return INT_MIN;
    }
    struct node* temp = head->next;
    int result = temp->data;
    head->next = head->next->next;
    free(temp);
    return result;
}

void queue_display(struct node* head) {
    printf("The content(s) of the queue is/are: ");
    struct node* current = head;
    while (current->next != NULL) {
        printf("%d ", current->next->data);
        current = current->next;
    }
    printf("\n\n");
}

struct stack* stack_initiate(int size) {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (int*)malloc(stack->size * sizeof(int));
    return stack;
}

void stack_push(struct stack* stack, int item) {
    if (stack->top == stack->size - 1) {
        return;
    }
    stack->array[++stack->top] = item;
}

int stack_pop(struct stack* stack) {
    if (stack->top == -1) {
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

void stack_display(struct stack* stack) {
    printf("The content(s) of the stack is/are: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n\n");
}

void display_menu() {
    while (true) {
        printf("Menu\n");
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. Set\n");
        printf("4. List\n");
        printf("5. Ordered list\n");
        printf("6. Exit\n\n");


        int choice = 0;
        do {
            printf("Enter choice: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 6);
        printf("\n");

        switch (choice) {
        case 1:
            system("cls");
            display_stack_menu();
            break;
        case 2:
            system("cls");
            display_queue_menu();
            break;
        case 3:
            system("cls");
            display_set_menu();
            break;
        case 4:
            system("cls");
            display_list_menu();
            break;
        case 5:
            system("cls");
            display_ordered_list_menu();
            break;
        case 6:
            system("cls");
            return;
        }
    }
}

void display_stack_menu() {
    struct stack* stack = stack_initiate(MAX_SIZE);
    while (true) {
        printf("Stack\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Show content\n");
        printf("4. Exit\n\n");

        int choice = 0;
        do {
            printf("Enter choice: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);

        int number;
        switch (choice) {
        case 1:
            printf("Enter a number to push: ");
            scanf("%d", &number);
            stack_push(stack, number);
            system("cls");
            break;
        case 2:
            system("cls");
            number = stack_pop(stack);
            if (number == INT_MIN) {
                printf("The stack is empty!\n\n");
            }
            else {
                printf("The following element is popped from the stack: %d\n\n", number);
            }
            break;
        case 3:
            system("cls");
            stack_display(stack);
            break;
        case 4:
            free(stack->array);
            free(stack);
            system("cls");
            return;
        }
    }
}

void display_queue_menu() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    while (true) {
        printf("Queue\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Show content\n");
        printf("4. Exit\n\n");

        int choice = 0;
        do {
            printf("Enter choice: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);

        int number;
        switch (choice) {
        case 1:
            printf("Enter a number to enqueue: ");
            scanf("%d", &number);
            enqueue(head, number);
            system("cls");
            break;
        case 2:
            system("cls");
            number = dequeue(head);
            if (number == INT_MIN) {
                printf("The queue is empty!\n\n");
            }
            else {
                printf("The following element is dequeued from the queue: %d\n\n", number);
            }
            break;
        case 3:
            system("cls");
            queue_display(head);
            break;
        case 4:
            system("cls");
            return;
        }
    }
}

void display_set_menu() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    while (true) {
        printf("Set\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Show content\n");
        printf("4. Exit\n\n");

        int choice = 0;
        do {
            printf("Enter choice: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);

        int number;
        switch (choice) {
        case 1:
            printf("Enter a number to insert: ");
            scanf("%d", &number);
            system("cls");
            if (set_insert(head, number)) {
                printf("The number is successfully inserted.\n\n");
            } else {
                printf("The number is already in the set.\n\n");
            }
            break;
        case 2:
            printf("Enter a number to remove: ");
            scanf("%d", &number);
            system("cls");
            if (set_remove(head, number)) {
                printf("The following element is removed from the set: %d\n\n", number);
            } else {
                printf("The number is not found in the set.\n\n");
            }
            break;
        case 3:
            system("cls");
            set_display(head);
            break;
        case 4:
            system("cls");
            return;
        }
    }
}

void display_list_menu() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    while (true) {
        printf("List\n");
        printf("1. Append\n");
        printf("2. Remove\n");
        printf("3. Show content\n");
        printf("4. Exit\n\n");

        int choice = 0;
        do {
            printf("Enter choice: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);

        int number;
        switch (choice) {
        case 1:
            printf("Enter a number to append: ");
            scanf("%d", &number);
            list_append(head, number);
            system("cls");
            break;
        case 2:
            printf("Enter a number to remove: ");
            scanf("%d", &number);
            system("cls");
            if (list_remove(head, number)) {
                printf("The number is successfully removed.\n\n");
            } else {
                printf("The number is not found in the list.\n\n");
            }
            break;
        case 3:
            system("cls");
            list_display(head);
            break;
        case 4:
            system("cls");
            return;
        }
    }
}

void display_ordered_list_menu() {
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    while (true) {
        printf("Ordered list\n");
        printf("1. Add\n");
        printf("2. Remove\n");
        printf("3. Show content\n");
        printf("4. Exit\n\n");

        int choice = 0;
        do {
            printf("Enter choice: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice > 4);

        int number;
        switch (choice) {
        case 1:
            printf("Enter a number to add: ");
            scanf("%d", &number);
            list_add_sorted(head, number);
            system("cls");
            break;
        case 2:
            printf("Enter a number to remove: ");
            scanf("%d", &number);
            system("cls");
            if (list_remove(head, number)) {
                printf("The number is successfully removed.\n\n");
            } else {
                printf("The number is not found in the list.\n\n");
            }
            break;
        case 3:
            system("cls");
            list_display(head);
            break;
        case 4:
            system("cls");
            return;
        }
    }
}