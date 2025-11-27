#include <iostream>
using namespace std;

// Node definition (already provided in your environment)
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to find minimum element in BST
int findMin(Node* root) {
    if (root == nullptr) {
        throw runtime_error("BST is empty");
    }
    Node* curr = root;
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr->data;
}
int main() {
    // Construct BST
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(7);

    cout << "Minimum element in BST: " << findMin(root) << endl;
    return 0;
}
