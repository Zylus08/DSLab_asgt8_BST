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

// Function to find minimum node in a subtree
Node* findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root;
}

// Function to find in-order successor of a given node in BST
Node* inorderSuccessor(Node* root, Node* target) {
    if (!root || !target) return nullptr;

    // Case 1: If target has right subtree
    if (target->right) {
        return findMin(target->right);
    }

    // Case 2: No right subtree → find ancestor
    Node* succ = nullptr;
    Node* curr = root;
    while (curr) {
        if (target->data < curr->data) {
            succ = curr;        // potential successor
            curr = curr->left;
        } else if (target->data > curr->data) {
            curr = curr->right;
        } else {
            break;
        }
    }
    return succ;
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
    Node* succ = inorderSuccessor(root, target);

    if (succ) cout << "In-order successor of " << target->data << " is " << succ->data << endl;
    else cout << "No successor exists" << endl;

    return 0;
}
