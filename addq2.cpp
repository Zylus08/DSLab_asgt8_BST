#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node (already provided in judge environment).
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

private:
    vector<TreeNode*> buildTrees(int start, int end) {
        vector<TreeNode*> result;
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }

        for (int i = start; i <= end; i++) {
            // Generate all left and right subtrees
            vector<TreeNode*> leftTrees = buildTrees(start, i - 1);
            vector<TreeNode*> rightTrees = buildTrees(i + 1, end);

            // Combine each left and right with root i
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    int n = 3; // Example input
    vector<TreeNode*> allTrees = sol.generateTrees(n);

    cout << "Total unique BSTs with " << n << " nodes: " << allTrees.size() << endl;
    return 0;
}