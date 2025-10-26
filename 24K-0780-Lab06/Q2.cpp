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

    bool isEmpty() const {
        return topIndex == -1;
    }

    void push(int x) {
        if (topIndex >= MAX - 1) {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++topIndex] = x;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!\n";
            return -1;
        }
        return arr[topIndex--];
    }

    int top() const {
        if (isEmpty()) return -1;
        return arr[topIndex];
    }
};

int evaluatePostfix(string exp) {
    Stack s;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        if (c >= '0' && c <= '9') {
            s.push(c - '0');
        }
        else {
            int val2 = s.pop();
            int val1 = s.pop();

            switch (c) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
                default: cout << "Invalid operator: " << c << endl;
            }
        }
    }

    return s.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    int result = evaluatePostfix(exp);
    cout << "Result: " << result << endl;

}

