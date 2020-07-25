#include <bits/stdc++.h>

using namespace std;

int main () {
    stack <char> s;
    char exp[20];

    cout << "Expression: "; 
    cin.getline(exp, 20);

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

    if (s.size() > 0) {
        cout << "Invalid Expression\n";
    } else {
        cout << "Valid Expression\n";
    }
}