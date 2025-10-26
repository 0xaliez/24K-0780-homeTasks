#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 100;

class Stack {
private:
    int arr[MAX];
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(int value) {
        if (topIndex >= MAX - 1) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++topIndex] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[topIndex--];
    }

    int top() {
        if (isEmpty()) return -1;
        return arr[topIndex];
    }
};

int evaluatePrefix(string exp) {
    Stack s;

    for (int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];

        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        }
        else {
            int op1 = s.pop();
            int op2 = s.pop();

            switch (c) {
                case '+': s.push(op1 + op2); break;
                case '-': s.push(op1 - op2); break;
                case '*': s.push(op1 * op2); break;
                case '/': s.push(op1 / op2); break;
                case '^': s.push(pow(op1, op2)); break;
                default: cout << "Invalid operator: " << c << endl;
            }
        }
    }

    return s.top();
}

int main() {
    string exp;
    cout << "Enter prefix expression: ";
    cin >> exp;

    int result = evaluatePrefix(exp);
    cout << "Result: " << result << endl;

    return 0;
}

