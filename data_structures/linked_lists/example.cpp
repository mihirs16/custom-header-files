#include <iostream>
#include "linked-list.h"

using namespace std;

int main () {
    struct node *new_header = create_ll(10);

    // cout << new_header -> data;

    push_ll (new_header, 20);
    push_ll (new_header, 30);
    push_ll (new_header, 40);
    print_ll (new_header);
    insertAfter_ll (new_header, 2, 35);
    print_ll (new_header);
    insertBefore_ll (new_header, 2, 25);
    print_ll (new_header);
    pop_ll (new_header);
    print_ll (new_header);

    new_header = NULL;
    free (new_header);
    return 0;
}