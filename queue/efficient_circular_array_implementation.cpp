#include <bits/stdc++.h>
using namespace std;

// Structure representing a circular queue
struct Queue {
    int size;     // Current size of the queue
    int cap;      // Maximum capacity of the queue
    int front;    // Index of the front element
    int *arr;     // Array to store queue elements

    // Constructor to initialize a queue with a given capacity
    Queue(int c) {
        cap = c;
        size = 0;
        front = 0;
        arr = new int[cap];
    }

    // Check if the queue is full
    bool isFull() {
        return (size == cap);
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (size == 0);
    }

    // Enqueue (insert) an element into the queue
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        // Calculate the rear index using modulo operator
        int rear = getRear();
        rear = (rear + 1) % cap;

        arr[rear] = x;
        size++;
    }

    // Dequeue (remove) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        front = (front + 1) % cap;
        size--;
    }

    // Get the front element (without removing it)
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        } else {
            return front;
        }
    }

    // Get the rear index (index of the last element)
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        } else {
            return (front + (size - 1)) % cap;
        }
    }
};

int main() {
    // Create a queue with capacity 5
    Queue q(5);

    cout << "Enqueueing 1, 2, 3\n";
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.getFront() << endl; // Output: Front element: 1

    cout << "Dequeueing an element\n";
    q.dequeue();

    cout << "Enqueueing 4\n";
    q.enqueue(4);

    cout << "Displaying queue elements:\n";
    while (!q.isEmpty()) {
        cout << q.getFront() << " ";
        q.dequeue();
    }
    cout << endl; // Output: 2 3 4

    
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);

    cout << q.isFull() <<endl;
    cout << q.getFront() <<endl;
    cout << q.getRear() <<endl;
    return 0;
}
