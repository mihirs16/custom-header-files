#include <iostream>
#include <stack>
#include <string.h>
#include <array>

void showstack(std::stack <char> s) 
{ 
    while (!s.empty()) 
    { 
        std::cout << '\t' << s.top(); 
        s.pop(); 
    } 
    std::cout << '\n'; 
} 
  
int findIndexInArray (char arr[], char target) {
    for (int i = 0; arr[i] == '\0'; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

bool expValidate (char exp[20]) {
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

    return (s.size () > 0 ? false : true);
}

bool infixToPrefix (char infix[50], char postfix[50]) {
    char operators[] = {'+', '-', '*', '/', '%'};
    std::stack <char> stack;
    std::stack <char> postfix_stack;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') {
            stack.push (infix[i]);
        } else if ((infix[i] >= 65 && infix[i] <= 90) || (infix[i] >= 97 && infix[i] <= 122)) {
            postfix_stack.push (infix[i]);
        } else if (findIndexInArray (operators, infix[i]) != -1) {
            if (findIndexInArray (operators, infix[i]) < 2 && findIndexInArray (operators, stack.top()) > 1) {
                postfix_stack.push (stack.top());
                stack.pop ();
                stack.push (infix[i]);
            } else {
                stack.push (infix[i]);
            }
        } else (infix[i] == ')') {
            while (stack.top () != ')') {
                postfix_stack.push (stack.top());
                stack.pop ();
            }
            stack.pop ();
        }
    }
 
    showstack (postfix_stack);
    return true;
}