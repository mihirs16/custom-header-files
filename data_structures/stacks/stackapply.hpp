#include <iostream>
#include <stack>
#include <string.h>

void stackToArray (std::stack <char> stack, char array[]) {
    std::stack <char> rev;
    for (int i=0; !stack.empty (); i++) {
        rev.push (stack.top ());
        stack.pop ();
    }
    for (int i=0; !rev.empty (); i++) {
        array[i] = rev.top ();
        rev.pop ();
    }
}

int findIndexInArray (char arr[], char target) {
    for (int i = 0; arr[i] != '\0'; i++) {
        // std::cout << arr[i];
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

bool expValidate (char exp[]) {
    std::stack <char> s;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            s.push (exp[i]);
        } 
        switch (exp[i]) {
            case ')': if (s.top() == '(') s.pop(); break;
            case ']': if (s.top() == '[') s.pop(); break;
            case '}': if (s.top() == '{') s.pop(); break;
            default : continue;
        }
    }
    // std::cout << s.size();
    return (s.size () > 0 ? false : true);
}

bool infixToPrefix (char infix[50], char postfix[50]) {
    if (expValidate (infix)) {
        char operators[] = {'+', '-', '*', '/', '%'};
        std::stack <char> stack;
        std::stack <char> postfix_stack;

        for (int i = 0; infix[i] != '\0'; i++) {
            if (infix[i] != ' ') {
                // std::cout << i;
                // std::cout << "\n scanned: " << infix[i] << '\t';
                if (infix[i] == '(') {
                    // std::cout << "pushing to stack: " << infix[i] << std::endl;
                    stack.push (infix[i]);
                }  
                if ((infix[i] >= 65 && infix[i] <= 90) || (infix[i] >= 97 && infix[i] <= 122)) {
                    // std::cout << "adding to postfix: " << infix[i] << std::endl;
                    postfix_stack.push (infix[i]);
                }  
                if (findIndexInArray (operators, infix[i]) != -1) {
                    if ((findIndexInArray (operators, infix[i]) < 2) && (findIndexInArray (operators, stack.top()) > 1)) {
                        // std::cout << "adding to postfix: " << stack.top() << std::endl;
                        postfix_stack.push (stack.top());
                        stack.pop ();
                        // std::cout << "pushing to stack: " << infix[i] << std::endl;
                        stack.push (infix[i]);
                    } else {
                        // std::cout << "pushing to stack: " << infix[i] << std::endl;
                        stack.push (infix[i]);
                    }
                } 
                if (infix[i] == ')') {
                    while (stack.top () != '(') {
                        // std::cout << "adding to postfix: " << stack.top() << std::endl;
                        postfix_stack.push (stack.top());
                        stack.pop ();
                    }
                    stack.pop ();
                }
            }
        }
        
        stackToArray (postfix_stack, postfix);
        return true;
    }

    return false;
}