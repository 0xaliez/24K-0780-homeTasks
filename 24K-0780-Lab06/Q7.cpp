#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class LibraryQueue {
private:
    string queue[MAX];
    int front, rear;

public:
    LibraryQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }

        if (front == -1) front = 0;
        queue[++rear] = name;
        cout << name << " has joined the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No patrons in queue.\n";
            return;
        }

        cout << queue[front] << " has been served and leaves the queue.\n";
        front++;

        if (front > rear) {
            front = rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No patrons are waiting.\n";
            return;
        }

        cout << "Current Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << i - front + 1 << ". " << queue[i] << endl;
        }
    }
};

int main() {
	LibraryQueue q;
	q.enqueue("Ali");
	q.enqueue("Mustufa");
	q.enqueue("Bilal");
	q.display();
	q.dequeue();
	q.display(); 	
}

