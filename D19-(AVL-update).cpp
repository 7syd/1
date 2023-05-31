#include <iostream>
using namespace std;

struct AVLNode {
    string keyword;
    string meaning;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(string key, string val) : keyword(key), meaning(val), left(NULL), right(NULL), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        return (node == NULL) ? 0 : node->height;
    }

    int getBalanceFactor(AVLNode* node) {
        return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
    }

    AVLNode* rotateLeft(AVLNode* z) {
        AVLNode* y = z->right, * T2 = y->left;
        y->left = z, z->right = T2;
        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return y;
    }

    AVLNode* rotateRight(AVLNode* z) {
        AVLNode* y = z->left, * T3 = y->right;
        y->right = z, z->left = T3;
        z->height = 1 + max(getHeight(z->left), getHeight(z->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        return y;
    }

    AVLNode* insertNode(AVLNode* node, string keyword, string meaning) {
        if (node == NULL)
            return new AVLNode(keyword, meaning);
        if (keyword < node->keyword)
            node->left = insertNode(node->left, keyword, meaning);
        else
            node->right = insertNode(node->right, keyword, meaning);
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1) {
            if (keyword < node->left->keyword)
                return rotateRight(node);
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balanceFactor < -1) {
            if (keyword > node->right->keyword)
                return rotateLeft(node);
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    AVLNode* findMinNode(AVLNode* node) {
        if (node == NULL || node->left == NULL)
            return node;
        return findMinNode(node->left);
    }


    AVLNode* updateNode(AVLNode* node, string keyword, string meaning) {
        if (node == NULL)
            return node;
        if (keyword < node->keyword)
            node->left = updateNode(node->left, keyword, meaning);
        else if (keyword > node->keyword)
            node->right = updateNode(node->right, keyword, meaning);
        else {
            node->meaning = meaning;
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1) {
            if (getBalanceFactor(node->left) >= 0)
                return rotateRight(node);
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balanceFactor < -1) {
            if (getBalanceFactor(node->right) <= 0)
                return rotateLeft(node);
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    void displayInOrder(AVLNode* node) {
        if (node) {
            displayInOrder(node->left);
            cout << "Keyword: " << node->keyword << ", Meaning: " << node->meaning << endl;
            displayInOrder(node->right);
        }
    }

    void displayDescendingOrder(AVLNode* node) {
        if (node) {
            displayDescendingOrder(node->right);
            cout << "Keyword: " << node->keyword << ", Meaning: " << node->meaning << endl;
            displayDescendingOrder(node->left);
        }
    }

public:
    AVLTree() : root(NULL) {}

    void insert(string keyword, string meaning) {
        root = insertNode(root, keyword, meaning);
    }

    void update(string keyword, string meaning) {
        root = updateNode(root, keyword, meaning);
    }

    void displayInOrder() {
        displayInOrder(root);
    }

    void displayDescendingOrder() {
        displayDescendingOrder(root);
    }
};

int main() {
    AVLTree tree;
    tree.insert("apple", "A fruit");
    tree.insert("banana", "A tropical fruit");
    tree.insert("cat", "A small domesticated carnivorous mammal");
    tree.insert("dog", "A domesticated carnivorous mammal");

    cout << "Ascending order:" << endl;
    tree.displayInOrder();
    cout << endl;

    cout << "\nDescending order:" << endl;
    tree.displayDescendingOrder();
    cout << endl;

	cout << "\nUpdating...." << endl;
    tree.update("apple", "A juicy fruit");

    cout << "\nAscending order after update:" << endl;
    tree.displayInOrder();

    return 0;
}
