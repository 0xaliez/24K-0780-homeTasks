#include <iostream>
using namespace std;

class Node {
public:
    int ticketID;
    string customerName;
    string rideName;
    Node* next;

    Node(int id, string cname, string rname) {
        ticketID = id;
        customerName = cname;
        rideName = rname;
        next = NULL;
    }
};

class CircularList {
    Node* head;

public:
    CircularList() {
        head = NULL;
    }

    void issueEnd(int id, string cname, string rname) {
        Node* newNode = new Node(id, cname, rname);
        if (head == NULL) {
            head = newNode;
            head->next = head; 
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void issueFront(int id, string cname, string rname) {
        Node* newNode = new Node(id, cname, rname);
        if (head == NULL) {
            head = newNode;
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void cancelByID(int id) {
        if (head == NULL) {
            cout << "No tickets booked." << endl;
            return;
        }
        Node* curr = head;
        Node* prev = NULL;
        do {
            if (curr->ticketID == id) {
                if (curr == head) {
                    cancelFirst();
                    return;
                }
                prev->next = curr->next;
                cout << "Canceled Ticket ID: " << id << endl;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        cout << "Ticket ID " << id << " not found." << endl;
    }

    void cancelFirst() {
        if (head == NULL) {
            cout << "No tickets booked." << endl;
            return;
        }
        if (head->next == head) {
            cout << "Canceled Ticket ID: " << head->ticketID << endl;
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        cout << "Canceled Ticket ID: " << head->ticketID << endl;
        head = head->next;
        last->next = head;
        delete temp;
    }

    void searchByID(int id) {
        if (head == NULL) {
            cout << "No tickets booked." << endl;
            return;
        }
        Node* temp = head;
        do {
            if (temp->ticketID == id) {
                cout << "Ticket Found -> ID: " << temp->ticketID 
                     << ", Customer: " << temp->customerName
                     << ", Ride: " << temp->rideName << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Ticket ID " << id << " not found." << endl;
    }

    void displayAll() {
        if (head == NULL) {
            cout << "No tickets booked." << endl;
            return;
        }
        Node* temp = head;
        cout << "Tickets (Circular Order):" << endl;
        do {
            cout << "ID: " << temp->ticketID 
                 << ", Customer: " << temp->customerName 
                 << ", Ride: " << temp->rideName << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void countTickets() {
        if (head == NULL) {
            cout << "Total tickets: 0" << endl;
            return;
        }
        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
        cout << "Total tickets: " << count << endl;
    }

    void nextTicket(int id) {
        if (head == NULL) {
            cout << "No tickets booked." << endl;
            return;
        }
        Node* temp = head;
        do {
            if (temp->ticketID == id) {
                cout << "Next Ticket after ID " << id << " -> ID: " << temp->next->ticketID << ", Customer: " << temp->next->customerName << ", Ride: " << temp->next->rideName << endl;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Ticket ID " << id << " not found." << endl;
    }
};

int main() {
    CircularList cl;

    cl.issueEnd(1, "Ali", "Roller Coaster");
    cl.issueEnd(2, "Sara", "Ferris Wheel");
    cl.issueEnd(3, "Omar", "Bumper Cars");
    cl.displayAll();
    cout << endl;

    cl.issueFront(0, "VIP-Zara", "Haunted House");
    cl.displayAll();
    cout << endl;

    cl.cancelByID(2);
    cl.displayAll();
    cout << endl;

    cl.searchByID(3);
    cl.nextTicket(3);
    cout << endl;

    cl.cancelFirst();
    cl.displayAll();
    cout << endl;

    cl.countTickets();

    return 0;
}

