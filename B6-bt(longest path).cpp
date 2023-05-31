#include <iostream>
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

    int getHeight(Node* node) {
        if (node == NULL) {
            return 0;
        }

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return 1 + max(leftHeight, rightHeight);
    }

public:
    BST() : root(NULL) {}

    void insert(int value) {
        root = insertNode(root, value);
    }

    void display() {
        displayTree(root, "", true);
    }

    int getLongestPathLength() {
        return getHeight(root);
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

    int longestPathLength = bst.getLongestPathLength();
    cout << "\nNumber of nodes in the longest path from the root: " << longestPathLength << endl;

    return 0;
}
