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
    /**
     * @brief   Use inorder traversal to check the validity of BST in O(n)
     * @details Traverse the BST in-order and check if it is in ascending order.
     *          To do this, instead of mainining the entire traversal, just compare if 
     *          previous element is less than the current element. Thus preserving only 
     *          the address of previous element.
     * @param root  Current element
     * @param prev  Previous element std::nullptr by default
     * @returns bool true if BST is valid
     * 
     */
    bool isValidBST(TreeNode* root, int* prev= nullptr) {
        // Exit condition
        if (!root) return true;
        // traverse left sub tree(s)
        if (!validate(root.left, prev)) return false;
        // Root
        if (prev != NULL && prev->val >= root.value) return false;
        // Right sub tree
        prev = root;
        return validate(root->right, prev);
    }
};