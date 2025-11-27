#include <iostream>
#include <climits>
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

// Insert into BST
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    return root;
}

// Function to calculate minimum depth of BST
int minDepth(Node* root) {
    if (root == nullptr) return 0;

    // If left child is NULL, recurse on right child
    if (root->left == nullptr)
        return 1 + minDepth(root->right);

    // If right child is NULL, recurse on left child
    if (root->right == nullptr)
        return 1 + minDepth(root->left);

    // If both children exist
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Inorder Traversal (for checking structure)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    cout << "Minimum depth of BST: " << minDepth(root) << endl;

    return 0;
}
