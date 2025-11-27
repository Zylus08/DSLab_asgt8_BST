#include <iostream>
#include <stdexcept>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to find maximum element in BST
int findMax(Node* root) {
    if (root == nullptr) {
        throw runtime_error("BST is empty");
    }
    Node* curr = root;
    while (curr->right != nullptr) {
        curr = curr->right;
    }
    return curr->data;
}
