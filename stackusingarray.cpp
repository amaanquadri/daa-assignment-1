#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 
class Stack {
  private:
    int arr[MAX_SIZE]; 
    int top; 
  public:

    Stack() {
        top = -1; 
    }
    void push(int val) {
        if (top == MAX_SIZE - 1) {
            cout << "Error: Stack overflow" << endl;
        } else {
            top++;
            arr[top] = val;
        }
    }
    int pop() {
        if (top == -1) {
            cout << "Error: Stack underflow" << endl;
            return -1;
        } else {
            int val = arr[top];
            top--;
            return val;
        }
    }
    bool isEmpty() {
        return (top == -1);
    }
    int peek() {
        if (top == -1) {
            cout << "Error: Stack underflow" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }
};
int main() {
    Stack s;
    s.push(5);
    s.push(3);
    s.push(7);
    cout << s.pop() << endl; // prints 7
    cout << s.pop() << endl; // prints 3
    cout << s.peek() << endl; // prints 5
    cout << s.pop() << endl; // prints 5
    return 0;
}

