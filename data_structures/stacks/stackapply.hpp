#include <iostream>
#include <stack>
#include <string.h>

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

bool infixToPrefix (char infix[20], char postfix[20]) {
    
    return true;
}