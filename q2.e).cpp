#include <iostream>
using namespace std;
 
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Helper: find maximum node in a subtree
Node* findMax(Node* root) {
    while (root && root->right) {
        root = root->right;
    }
    return root;
}

// Function to find in-order predecessor of a given node in BST
Node* inorderPredecessor(Node* root, Node* target) {
    if (!root || !target) return nullptr;

    // Case 1: If target has left subtree
    if (target->left) {
        return findMax(target->left);
    }

    // Case 2: No left subtree → find ancestor
    Node* pred = nullptr;
    Node* curr = root;
    while (curr) {
        if (target->data > curr->data) {
            pred = curr;        // potential predecessor
            curr = curr->right;
        } else if (target->data < curr->data) {
            curr = curr->left;
        } else {
            break;
        }
    }
    return pred;
}
int main() {
    // Construct BST
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->left->right->right = new Node(17);

    Node* target = root->left->right; // Node with value 15
    Node* pred = inorderPredecessor(root, target);

    if (pred) cout << "In-order predecessor of " << target->data << " is " << pred->data << endl;
    else cout << "No predecessor exists" << endl;

    return 0;
}
