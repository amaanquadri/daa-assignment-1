#include <iostream>
using namespace std;
const int MAX_SIZE = 100; 
class Queue {
  private:
    int arr[MAX_SIZE]; 
    int front; 
    int rear; 

  public:
    // Constructor
    Queue() {
        front = 0; 
        rear = -1;
    }
    void enqueue(int val) {
        if (rear == MAX_SIZE - 1) {
            cout << "Error: Queue overflow" << endl;
        } else {
            rear++;
            arr[rear] = val;
        }
    }
    int dequeue() {
        if (front > rear) {
            cout << "Error: Queue underflow" << endl;
            return -1;
        } else {
            int val = arr[front];
            front++;
            return val;
        }
    }
    bool isEmpty() {
        return (front > rear);
    }
     int peek() {
        if (front > rear) {
            cout << "Error: Queue underflow" << endl;
            return -1;
        } else {
            return arr[front];
        }
    }
};
int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(3);
    q.enqueue(7);
    cout << q.dequeue() << endl; // prints 5
    cout << q.dequeue() << endl; // prints 3
    cout << q.peek() << endl; // prints 7
    cout << q.dequeue() << endl; // prints 7
    return 0;
}