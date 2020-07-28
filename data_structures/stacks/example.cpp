#include <iostream>
#include "stackapply.hpp"

using namespace std;

void test_expValidate () {
    char exp[20];

    cout << "Expression: "; 
    cin.getline(exp, 20);

    if (expValidate (exp)) {
        cout << "Valid Expression";
    } else {
        cout << "Invalid Expression";
    }
}

void test_infixToPrefix () {
    char exp[50] = "(A-(B/C+D%E*F)/G)*H)";

    infixToPrefix (exp, exp);
    // cout << "Expression: "; 
    // cin.getline(exp, 20);


}

int main () {

    // test_expValidate ();
    test_infixToPrefix ();

    return 0;
}