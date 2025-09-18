#include <iostream>
using namespace std;

class Node {
public:
    int id;
    string name;
    int price;
    Node* prev;
    Node* next;

    Node(int i, string n, int p) {
        id = i;
        name = n;
        price = p;
        prev = next = NULL;
    }
};

class Cart {
    Node* head;
    Node* tail;

public:
    Cart() {
        head = tail = NULL;
    }

    void insertEnd(int id, string name, int price) {
        Node* newNode = new Node(id, name, price);
        if (tail == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertFront(int id, string name, int price) {
        Node* newNode = new Node(id, name, price);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void removeFront() {
        if (head == NULL) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Removed: " << temp->name << " ($" << temp->price << ")" << endl;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        else tail = NULL;
        delete temp;
    }

    void removeEnd() {
        if (tail == NULL) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = tail;
        cout << "Removed: " << temp->name << " ($" << temp->price << ")" << endl;
        tail = tail->prev;
        if (tail != NULL) tail->next = NULL;
        else head = NULL;
        delete temp;
    }

    void searchByID(int id) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Found Item -> ID: " << temp->id << ", Name: " << temp->name << ", Price: $" << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found." << endl;
    }

    void updatePrice(int id, int newPrice) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Updated " << temp->name << " price from $" << temp->price << " to $" << newPrice << endl;
                temp->price = newPrice;
                return;
            }
            temp = temp->next;
        }
        cout << "Item with ID " << id << " not found." << endl;
    }

    void displayForward() {
        if (head == NULL) {
            cout << "Cart is empty." << endl;
            return;
        }
        cout << "Cart (Front to End):" << endl;
        Node* temp = head;
        while (temp != NULL) {
            cout << "ID: " << temp->id 
                 << ", Name: " << temp->name 
                 << ", Price: $" << temp->price << endl;
            temp = temp->next;
        }
    }

    void displayBackward() {
        if (tail == NULL) {
            cout << "Cart is empty." << endl;
            return;
        }
        cout << "Cart (End to Front):" << endl;
        Node* temp = tail;
        while (temp != NULL) {
            cout << "ID: " << temp->id 
                 << ", Name: " << temp->name 
                 << ", Price: $" << temp->price << endl;
            temp = temp->prev;
        }
    }

    void countItems() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "Total items in cart: " << count << endl;
    }

    void mostExpensive() {
        if (head == NULL) {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        Node* maxItem = head;
        while (temp != NULL) {
            if (temp->price > maxItem->price)
                maxItem = temp;
            temp = temp->next;
        }
        cout << "Most Expensive Item -> ID: " << maxItem->id << ", Name: " << maxItem->name << ", Price: $" << maxItem->price << endl;
    }
};

int main() {
    Cart c;

    c.insertEnd(101, "Laptop", 1000);
    c.insertEnd(102, "Phone", 700);
    c.insertEnd(103, "Tablet", 400);
    c.insertEnd(104, "Headphones", 150);

    c.displayForward();
    cout << endl;

    c.insertFront(100, "Charger", 50);
    c.displayForward();
    cout << endl;

    c.removeFront();
    c.removeEnd();
    c.displayForward();
    cout << endl;

    c.searchByID(102);
    c.updatePrice(103, 450);
    cout << endl;

    c.displayBackward();
    cout << endl;

    c.countItems();
    c.mostExpensive();

    return 0;
}

