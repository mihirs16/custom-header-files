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
    return true;
}

// Print a full linked list
bool print_ll (struct node *start) {
    struct node *temp;
    temp = start;

    if (start == NULL) {
        printf ("linked-list::NULL");
    }

    printf ("[");
    while (temp != NULL) {
        printf ("%d", temp -> data);
        printf (", ");
        temp = temp -> next;
    }
    printf ("\b\b]");
    temp = NULL;
    return true;
}