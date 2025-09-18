#include <iostream>
using namespace std;

class Node {
public:
    string name;
    int price;
    Node* next;
    Node(string n, int p) {
        name = n;
        price = p;
        next = NULL;
    }
};

class Cart {
    Node* head;
public:
    Cart() {
        head = NULL;
    }

    void addTail(string name, int price) {
        Node* newNode = new Node(name, price);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    void deleteFront() {
        if (head == NULL) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Removed: " << temp->name << " - $" << temp->price << endl;
        delete temp;
    }

    void searchByName(string item) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == item) {
                cout << "Found: " << temp->name << " - $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << item << " not found in cart." << endl;
    }

    void searchByPosition(int pos) {
        if (pos <= 0) {
            cout << "Invalid position." << endl;
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            cout << "Position out of range." << endl;
            return;
        }
        cout << "At position " << pos << ": " << temp->name << " - $" << temp->price << endl;
    }

    void display() {
        if (head == NULL) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Shopping Cart:" << endl;
        while (temp != NULL) {
            cout << temp->name << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Cart c;
    c.addTail("Laptop", 1000);
    c.addTail("Phone", 700);
    c.addTail("Tablet", 400);
    c.addTail("Headphones", 150);

    c.display();
    cout << endl;

    c.deleteFront();
    c.display();
    cout << endl;

    c.searchByName("Tablet");
    c.searchByPosition(2);
    c.searchByPosition(10);

}

