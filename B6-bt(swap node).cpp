#include <iostream>
#include <cstddef>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(NULL), right(NULL) {}
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->value) {
            node->left = insertNode(node->left, value);
        } else {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    void displayTree(Node* node,string indent, bool last) {
        if (node != NULL) {
            cout << indent;
            if (last) {
                cout << "+-";
                indent += "  ";
            } else {
                cout << "+-";
                indent += "| ";
            }

            cout << node->value << endl;

            displayTree(node->left, indent, false);
            displayTree(node->right, indent, true);
        }
    }

    void swapPointers(Node* node) {
        if (node == NULL) {
            return;
        }

        // Swap left and right pointers
        Node* temp = node->left;
        node->left = node->right;
        node->right = temp;

        // Recursively swap pointers for left and right subtrees
        swapPointers(node->left);
        swapPointers(node->right);
    }

public:
    BST() : root(NULL) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void display() {
        displayTree(root, "", true);
    }

    void swapRoles() {
        swapPointers(root);
    }
};

int main() {
    BST bst;
    int numValues;
    cout << "Enter the number of values to insert: ";
    cin >> numValues;

    cout << "Enter the values: ";
    for (int i = 0; i < numValues; i++) {
        int value;
        cin >> value;
        bst.insert(value);
    }

    cout << "Binary Search Tree:" << endl;
    bst.display();

    bst.swapRoles();

    cout << "\nBinary Search Tree after swapping roles:" << endl;
    bst.display();

    return 0;
}

