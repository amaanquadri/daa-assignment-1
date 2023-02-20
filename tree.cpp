#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int data) {
        Node* newNode = new Node(data);

        if (root == nullptr) {
            root = newNode;
        } else {
            Node* current = root;
            while (current != nullptr) {
                if (data < current->data) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = newNode;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    bool contains(int data) {
        Node* current = root;
        while (current != nullptr) {
            if (data == current->data) {
                return true;
            } else if (data < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        return false;
    }

    void printInOrder() {
        printInOrderHelper(root);
    }

private:
    void printInOrderHelper(Node* node) {
        if (node != nullptr) {
            printInOrderHelper(node->left);
            cout << node->data << " ";
            printInOrderHelper(node->right);
        }
    }
};

int main() {
    BinarySearchTree tree;

    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(8);

    tree.printInOrder(); 

    cout << endl;

    cout << "Contains 5? " << (tree.contains(5) ? "Yes" : "No") << endl; 
    cout << "Contains 2? " << (tree.contains(2) ? "Yes" : "No") << endl; 

    return 0;
}