#include <iostream>
#include "stackapply.hpp"

using namespace std;

// test for checking expression validity
void test_expValidate () {
    char exp[50];

    cout << "Expression: "; 
    cin.getline(exp, 50);

    if (expValidate (exp)) {
        cout << "Valid Expression";
    } else {
        cout << "Invalid Expression";
    }
}

// test for checking infix -> postfix conversion
void test_infixToPrefix () {
    char exp[50];
    char outExp[50];

    cout << "Expression: "; 
    cin.getline(exp, 50);
    if (infixToPostfix (exp, outExp)) {
        cout << outExp;
    } else {
        cout << "Invalid Expression";
    }
}

int main () {

    // test_expValidate ();
    test_infixToPrefix ();

    return 0;
}