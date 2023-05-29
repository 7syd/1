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

    void displayTree(Node* node, string indent, bool last) {
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

    Node* findMinNode(Node* node) {
        if (node == NULL || node->left == NULL) {
            return node;
        }

        return findMinNode(node->left);
    }

public:
    BST() : root(NULL) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void display() {
        displayTree(root, "", true);
    }

    int findMinimum() {
        Node* minNode = findMinNode(root);
        if (minNode != NULL) {
            return minNode->value;
        } else {
            // Handle empty tree case
            cout << "The tree is empty." << endl;
            return -1; // or any suitable default value
        }
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

    int minimumValue = bst.findMinimum();
    if (minimumValue != -1) {
        cout << "\nMinimum value found in the tree: " << minimumValue << endl;
    }
    return 0;
}

