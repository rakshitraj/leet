#include <iostream>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    bool isValidBST(TreeNode* root, int* min_val= nullptr, int* max_val= nullptr) {
        if (!root) return true;
        auto val = root->val;
        if (max_val && val >= *max_val)
            return false;
        if (min_val && val <= *min_val)
            return false;
        auto left = isValidBST(root->left, min_val, &val); 
        auto right = isValidBST(root->right, &val, max_val);
        return left && right;
    }
};