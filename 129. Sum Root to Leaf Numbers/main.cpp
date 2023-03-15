#include <iostream>

// Definition of the binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class to calculate the sum of all root-to-leaf paths
class Solution {
    int res = 0;
public:
    int sumNumbers(TreeNode* r, int prev = 0) {
        int  val = prev + r->val;
        if (r->left==NULL && r->right==NULL)
            res += val;
        if (r->left)
            sumNumbers(r->left, val * 10);
        if (r->right)
            sumNumbers(r->right, val * 10);
        return res;
    }
};

int main() {
    // Create a binary tree
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    // Calculate the sum of all root-to-leaf paths
    Solution sol;
    int sum = sol.sumNumbers(root);

    // Output the result
    std::cout << "The sum of all root-to-leaf paths is " << sum << std::endl;

    // Free the memory used by the binary tree
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
