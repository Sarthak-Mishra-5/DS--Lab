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

// Stack class
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Function to push an element onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to the stack." << endl;
    }

    // Function to pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << poppedValue << " popped from the stack." << endl;
        return poppedValue;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to display the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements are: ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    stack.pop();
    stack.display();
    stack.push(40);
    stack.push(50);
    stack.pop();
    stack.display();
    return 0;
}
