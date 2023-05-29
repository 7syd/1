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

    void displayTree(Node* node, std::string indent, bool last) {
        if (node != NULL) {
            std::cout << indent;
            if (last) {
                std::cout << "+-";
                indent += "  ";
            } else {
                std::cout << "+-";
                indent += "| ";
            }

            std::cout << node->value << std::endl;

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

        return 1 + std::max(leftHeight, rightHeight);
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
    std::cout << "Enter the number of values to insert: ";
    std::cin >> numValues;

    std::cout << "Enter the values: ";
    for (int i = 0; i < numValues; i++) {
        int value;
        std::cin >> value;
        bst.insert(value);
    }

    std::cout << "Binary Search Tree:" << std::endl;
    bst.display();

    int longestPathLength = bst.getLongestPathLength();
    std::cout << "\nNumber of nodes in the longest path from the root: " << longestPathLength << std::endl;

    return 0;
}

