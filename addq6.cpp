#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        return build(inorder, postorder, postIndex, 0, inorder.size() - 1, inMap);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& postIndex,
                    int inStart, int inEnd, unordered_map<int,int>& inMap) {
        if (inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inMap[rootVal];

        // Build right subtree first, then left
        root->right = build(inorder, postorder, postIndex, inIndex + 1, inEnd, inMap);
        root->left  = build(inorder, postorder, postIndex, inStart, inIndex - 1, inMap);

        return root;
    }
};
void printPreorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    vector<int> inorder   = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};

    Solution sol;
    TreeNode* root = sol.buildTree(inorder, postorder);

    cout << "Preorder of constructed tree: ";
    printPreorder(root);
    cout << endl;
    return 0;
}
