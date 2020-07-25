#include <stdio.h>
#include <conio.h>
#include <malloc.h>

// Nodes for a linked list
struct node {
    int data;
    struct node *next;
};


// Create a new linked list and initialise it with data
struct node *create_ll (int init_data) {
    struct node *start;
    int num;
    
    start = (struct node *) malloc (sizeof (struct node));
    start -> data = init_data;
    start -> next = NULL;

    return start;
}

// Push a new node at the end of the linked list
bool push_ll (struct node *start, int new_data) {
    struct node *new_node, *ptr_node;

    if (start == NULL) {
        printf ("linked-list::NULL\n");
        return false;
    }

    ptr_node = start;
    while (ptr_node -> next != NULL) {
        ptr_node = ptr_node -> next;
    }
    new_node = (struct node *) malloc (sizeof (struct node));
    new_node -> data = new_data;
    new_node -> next = NULL;
    ptr_node -> next = new_node;

    ptr_node = NULL;
    free (ptr_node);
    return true;
}

// Delete a node from the end of the linked list
bool pop_ll (struct node *start) {
    struct node *ptr_node;
    ptr_node = start;

    if (start == NULL) {
        printf ("linked-list::NULL\n");
        return false;
    }

    while (ptr_node -> next -> next != NULL) {
        ptr_node = ptr_node -> next;
    }

    free(ptr_node -> next);
    ptr_node -> next = NULL;
    
    ptr_node = NULL;
    free (ptr_node);
    return true;
}

// Insert a node after a given position
bool insertAfter_ll (struct node *start, int posAfter, int new_data) {
    struct node *temp, *new_node;
    temp = start;

    for (int i = 0; i < posAfter; i++) {
        if (temp -> next == NULL) {
            printf ("linked-list::specified position out of bounds\n");
            return false;
        } else {
            temp = temp -> next;
        }
    }
    
    new_node = (struct node *) malloc (sizeof(struct node));
    new_node -> data = new_data;
    new_node -> next = temp -> next;
    temp -> next = new_node;

    temp = NULL;
    free (temp);
    new_node = NULL;
    free (new_node);
    return true;
}

// Insert a node before a given position
bool insertBefore_ll (struct node *start, int posBefore, int new_data) {
    struct node *temp, *new_node;
    temp = start;

    for (int i = 0; i < posBefore - 1; i++) {
        if (temp -> next == NULL) {
            printf ("linked-list::specified position out of bounds\n");
            return false;
        } else {
            temp = temp -> next;
        }
    }
    
    new_node = (struct node *) malloc (sizeof(struct node));
    new_node -> data = new_data;
    new_node -> next = temp -> next;
    temp -> next = new_node;

    temp = NULL;
    free (temp);
    new_node = NULL;
    free (new_node);
    return true;
}

bool deleteAt_ll (struct node *start, int pos) {
    struct node *ptr_node, *toDel;
    ptr_node = start;

    for (int i = 0; i < pos - 1; i++) {
        if (ptr_node -> next == NULL) {
            printf ("linked-list::specified position out of bounds\n");
            return false;
        } else {
            ptr_node = ptr_node -> next;
        }
    }

    toDel = ptr_node -> next;
    ptr_node -> next = toDel -> next;
    toDel = NULL;
    free (toDel);
    ptr_node = NULL;
    free (ptr_node);
    return true;
}

bool delete_ll (struct node *start) {
    while (start -> next != NULL) {
        pop_ll (start);
    }

    return true;
}

int length_ll (struct node *start) {
    struct node *temp;
    int length = 0;

    temp = start;
    while (temp -> next != NULL) {
        length = length + 1;
        temp = temp -> next;
    }

    return length + 1;
}

// Print a full linked list
bool print_ll (struct node *start) {
    struct node *temp;
    temp = start;

    if (start == NULL) {
        printf ("linked-list::NULL\n");
    }

    printf ("[");
    while (temp != NULL) {
        printf ("%d", temp -> data);
        printf (", ");
        temp = temp -> next;
    }
    printf ("\b\b]\n");

    temp = NULL;
    free (temp);
    return true;
}