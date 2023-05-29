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
            std::cout << indent;
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

    Node* searchValue(Node* node, int value) {
        if (node == NULL || node->value == value) {
            return node;
        }

        if (value < node->value) {
            return searchValue(node->left, value);
        } else {
            return searchValue(node->right, value);
        }
    }

public:
    BST() : root(NULL) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void display() {
        displayTree(root, "", true);
    }

    bool search(int value) {
        Node* result = searchValue(root, value);
        return (result != NULL);
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

    int searchValue;
    cout << "\nEnter a value to search: ";
    cin >> searchValue;

    bool found = bst.search(searchValue);
    if (found) {
        cout << "Value " << searchValue << " found in the tree." << endl;
    } else {
        cout << "Value " << searchValue << " not found in the tree." << endl;
    }

    return 0;
}

