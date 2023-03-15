#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL && t2 == NULL) {
            return true;
        }
        if (t1 == NULL || t2 == NULL) {
            return false;
        }
        return t1->val == t2->val && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(2);

    Solution sol;
    bool is_symmetric = sol.isSymmetric(root);
    if (is_symmetric) {
        cout << "The binary tree is symmetric." << endl;
    } else {
        cout << "The binary tree is not symmetric." << endl;
    }

    return 0;
}
