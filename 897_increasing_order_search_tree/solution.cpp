#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode* left, TreeNode*  right) : val(val), left(left), right(right) {} 
};

class Solution {

    void getInorder(TreeNode* root, vector<int>& inorder){
        if (root == NULL) return;

        getInorder(root->left, inorder);
        inorder.push_back(root->val);
        getInorder(root->right, inorder);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root){
        if (root == NULL) return nullptr;

        std::vector<int> inorder;
        getInorder(root, inorder);
        
        TreeNode* new_root = new TreeNode(inorder[0]);
        TreeNode* curr = new_root;

        for (int i=1; i<inorder.size(); i++){
            TreeNode* node = new TreeNode(inorder[i]);
            curr->right = node;
            curr = node;
        }

        return new_root;
    }    
};