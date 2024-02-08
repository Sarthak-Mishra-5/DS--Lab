#include <iostream>

using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Queue class
class CircularQueue {
private:
    Node* rear; // Pointer to the rear of the queue

public:
    CircularQueue() {
        rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return rear == nullptr;
    }

    // Function to enqueue an element into the circular queue
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            rear = newNode;
            newNode->next = newNode; // Point to itself since it's the only node
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to the queue." << endl;
    }

    // Function to dequeue an element from the circular queue
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        int dequeuedValue = rear->next->data;
        if (rear->next == rear) {
            delete rear;
            rear = nullptr;
        } else {
            Node* temp = rear->next;
            rear->next = temp->next;
            delete temp;
        }
        cout << dequeuedValue << " dequeued from the queue." << endl;
        return dequeuedValue;
    }

    // Function to display the circular queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Circular Queue elements are: ";
        Node* current = rear->next;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != rear->next);
        cout << endl;
    }
};

int main() {
    CircularQueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
    queue.dequeue();
    queue.display();
    queue.enqueue(40);
    queue.enqueue(50);
    queue.dequeue();
    queue.display();
    return 0;
}
