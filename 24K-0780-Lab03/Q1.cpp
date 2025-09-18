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

    void addFront(string name, int price) {
        Node* newNode = new Node(name, price);
        newNode->next = head;
        head = newNode;
    }

    void addEnd(string name, int price) {
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

    void insertAfter(string target, string name, int price) {
        Node* temp = head;
        while (temp != NULL && temp->name != target)
            temp = temp->next;
        if (temp == NULL) return;
        Node* newNode = new Node(name, price);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void search(string item) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->name == item) {
                cout << item << " found with price $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << item << " not found in cart." << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->name << " - $" << temp->price << endl;
            temp = temp->next;
        }
    }
};

int main() {
    Cart c;
    c.addEnd("Laptop", 1000);
    c.addEnd("Phone", 700);
    c.addEnd("Tablet", 400);
    c.addEnd("Headphones", 150);

    c.addFront("Smartwatch", 200);
    c.addEnd("Keyboard", 80);
    c.insertAfter("Phone", "Monitor", 300);
    c.search("Tablet");
    c.display();

}

