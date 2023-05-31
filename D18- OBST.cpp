#include <iostream>
using namespace std;
struct Node {
    int key;
    float searchProbability;
    Node* left;
    Node* right;
};

Node* createNode(int key, float searchProbability) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->searchProbability = searchProbability;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int key, float searchProbability) {
    if (root == NULL) {
        return createNode(key, searchProbability);
    }
    if (key < root->key) {
        root->left = insertNode(root->left, key, searchProbability);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key, searchProbability);
    }
    return root;
}

float calculateSearchCost(Node* root) {
    if (root == NULL) {
        return 0.0;
    }
    float leftCost = calculateSearchCost(root->left);
    float rightCost = calculateSearchCost(root->right);
    return root->searchProbability + leftCost + rightCost;
}

Node* buildBST(int keys[], float probabilities[], int n) {
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insertNode(root, keys[i], probabilities[i]);
    }
    return root;
}

void deleteBST(Node* root) {
    if (root == NULL) {
        return;
    }
    deleteBST(root->left);
    deleteBST(root->right);
    delete root;
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;
    int keys[n];
    float probabilities[n];
    
    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }
    cout << "Enter the search probabilities: ";
    for (int i = 0; i < n; i++) {
        cin >> probabilities[i];
    }
    Node* root = buildBST(keys, probabilities, n);
    float searchCost = calculateSearchCost(root);
    cout << "Search Cost: " << searchCost << endl;
    deleteBST(root);
    return 0;
}
