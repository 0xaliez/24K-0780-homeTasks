#include <iostream>
#include <string>

using namespace std;

class Node {
	public:
    string url;
    Node* next;
    Node(string u) : url(u), next(NULL) {}
};

class Stack {
private:
    string arr[100];
    int topIndex;
public:
    Stack() { topIndex = -1; }

    void push(string url) {
        if (topIndex < 99)
            arr[++topIndex] = url;
    }

    string pop() {
        if (topIndex >= 0)
            return arr[topIndex--];
        return "";
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    string top() {
        return isEmpty() ? "" : arr[topIndex];
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }

    void addFront(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
    }

    void removeFront() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void display() {
        Node* temp = head;
        cout << "Browsing History (most recent first): ";
        while (temp) {
            cout << temp->url << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList history;
    Stack back;

    string sites[] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};
    int totalSites = 5;

    for (int i = 0; i < totalSites; i++) {
        history.addFront(sites[i]);
        back.push(sites[i]);
    }

    cout << "After visiting all sites:\n";
    history.display();

    cout << "\nUser presses BACK twice...\n";
    for (int i = 0; i < 2; i++) {
        string removed = back.pop();
        history.removeFront();
        cout << "Back from: " << removed << endl;
    }

    cout << "\nCurrent page: " << back.top() << endl;
    history.display();

    return 0;
}

