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
    
    start = (struct node *)malloc(sizeof(struct node));
    start -> data = init_data;

    return start;
}