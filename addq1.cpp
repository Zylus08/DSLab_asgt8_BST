#include <iostream> // For std::cout, std::endl
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to check if a node is a leaf
bool isLeaf(TreeNode* node) {
    return node && !node->left && !node->right;
}

// Recursive function to compute sum of left leaves
int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;

    int sum = 0;
    if (isLeaf(root->left)) {
        sum += root->left->val; // add left leaf value
    } else {
        sum += sumOfLeftLeaves(root->left); // recurse left
    }
    sum += sumOfLeftLeaves(root->right); // recurse right

    return sum;
}
