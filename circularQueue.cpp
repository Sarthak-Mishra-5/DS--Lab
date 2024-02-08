#include <iostream>
using namespace std;

#define SIZE 5 // Maximum size of the queue

class CircularQueue {
private:
    int queue[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1));
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full." << endl;
            return;
        }

        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;

        queue[rear] = item;
        cout << item << " enqueued to the queue." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }

        int item = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;

        cout << item << " dequeued from the queue." << endl;
        return item;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Elements in the queue are:" << endl;
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
        } else {
            for (int i = front; i < SIZE; i++)
                cout << queue[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << queue[i] << " ";
        }
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
    queue.enqueue(60); // This will print "Queue is full."
    queue.enqueue(70);
    queue.display();
    return 0;
}
