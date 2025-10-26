#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

class Stack {
private:
    char arr[MAX];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    void push(char c) {
        if (topIndex >= MAX - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++topIndex] = c;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return '\0';
        }
        return arr[topIndex--];
    }

    char top() const {
        if (isEmpty()) return '\0';
        return arr[topIndex];
    }
};

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix) {
    string postfix = "";
    Stack s;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.top() != '(') {
                postfix += s.pop();
            }
            if (s.top() == '(')
                s.pop();
        }
        else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.top())) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

}

