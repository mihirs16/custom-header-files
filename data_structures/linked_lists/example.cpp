#include <iostream>
#include "linked-list.h"

using namespace std;

int main () {
    struct node *new_header = create_ll(10);
    
    cout<<new_header->data;
    new_header = NULL;
    
    return 0;
}