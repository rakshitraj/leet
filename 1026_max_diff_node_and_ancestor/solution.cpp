/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode  *right;
    TreeNode () : val(0), left(nullptr), right(nullptr) {}
    TreeNode (int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode (int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

class Solution {
    int decendent(TreeNode* root, int minVal, int maxVal){
        if (!root){
            return abs(minVal - maxVal);
        }

        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        
        int left = decendent(root->left, minVal, maxVal);
        int right = decendent(root->right, minVal, maxVal);

        return max(left, right);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        return decendent(root, root->val, root->val);
    }
};