#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BST Node
struct BSTNode {
    int val;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Doubly Linked List Node
struct DLLNode {
    int val;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

// Inorder traversal to collect values
void inorder(BSTNode* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}

// Merge two sorted arrays
vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) merged.push_back(a[i++]);
        else merged.push_back(b[j++]);
    }
    while (i < a.size()) merged.push_back(a[i++]);
    while (j < b.size()) merged.push_back(b[j++]);
    return merged;
}

// Convert sorted array to doubly linked list
DLLNode* arrayToDLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    DLLNode* head = new DLLNode(arr[0]);
    DLLNode* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        DLLNode* node = new DLLNode(arr[i]);
        curr->next = node;
        node->prev = curr;
        curr = node;
    }
    return head;
}

// Print DLL
void printDLL(DLLNode* head) {
    DLLNode* curr = head;
    while (curr) {
        cout << curr->val << " <—> ";
        curr = curr->next;
    }
    cout << "null\n";
}

// Example usage
int main() {
    // Construct BST1
    BSTNode* T1 = new BSTNode(20);
    T1->left = new BSTNode(10);
    T1->right = new BSTNode(30);
    T1->left->right = new BSTNode(25);
    T1->right->right = new BSTNode(100);

    // Construct BST2
    BSTNode* T2 = new BSTNode(50);
    T2->left = new BSTNode(5);
    T2->right = new BSTNode(70);

    // Collect inorder traversals
    vector<int> arr1, arr2;
    inorder(T1, arr1);
    inorder(T2, arr2);

    // Merge arrays
    vector<int> merged = mergeArrays(arr1, arr2);

    // Convert to DLL
    DLLNode* head = arrayToDLL(merged);

    // Print DLL
    printDLL(head);

    return 0;
}
