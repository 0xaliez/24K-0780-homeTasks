#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

class Call {
public:
    string name;
    string number;
    int duration;

    Call() {}
    Call(string n, string num, int d) {
        name = n;
        number = num;
        duration = d;
    }

    void display() const {
        cout << "Name: " << name
             << ", Number: " << number
             << ", Duration: " << duration << " sec" << endl;
    }
};

class CallHistory {
private:
    Call calls[MAX];
    int topIndex;

public:
    CallHistory() {
        topIndex = -1;
    }

    void push(const Call &c) {
        if (topIndex >= MAX - 1) {
            cout << "Call history is full.";
            return;
        }
        calls[++topIndex] = c;
        cout << "Call added successfully.";
        display();
    }

    void pop() {
        if (empty()) {
            cout << "Call history is empty.";
            return;
        }
        cout << "Removed most recent call:";
        calls[topIndex--].display();
        display();
    }

    void top() const {
        if (empty()) {
            cout << "Call history is empty.";
            return;
        }
        cout << "Most recent call:";
        calls[topIndex].display();
    }

    bool empty() const {
        return topIndex == -1;
    }

    void display() const {
        cout << "\n--- Current Call History ---\n";
        if (empty()) {
            cout << "No calls in history.\n";
            cout << "-----------------------------\n";
            return;
        }
        for (int i = topIndex; i >= 0; i--) {
            cout << (topIndex - i + 1) << ". ";
            calls[i].display();
        }
        cout << "-----------------------------\n";
    }
};

int main() {
    CallHistory history;
    
    history.push(Call("Ali", "03323-716-792", 20));
 	history.push(Call("Hasheem", "01234-567-890", 16));
 	history.push(Call("Mustufa", "09876-543-210", 100));
	history.top();
	history.pop();
	
}

