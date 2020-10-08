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
    
  bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    
    /**
     * @brief   Use inorder traversal to check the validity of BST in O(n)
     * @details Traverse the BST in-order and check if it is in ascending order.
     *          To do this, instead of mainining the entire traversal, just compare if 
     *          previous element is less than the current element. Thus preserving only 
     *          the address of previous element.
     * @param root  Current element
     * @param prev  Previous element std::nullptr by default
     * @returns bool, true if Binary search sub-tree is valid
     * 
     */
    bool validate(TreeNode* node, TreeNode* &prev) {
        /* Inorder - left, right  root */
        /* Exit case */
        if (node == NULL) return true;
        
        /* Left */
        if (!validate(node->left, prev)) return false;
        
        /* Root - remember to save current node as prev for next iteration */
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        
        /* Right */
        return validate(node->right, prev);
    }
};