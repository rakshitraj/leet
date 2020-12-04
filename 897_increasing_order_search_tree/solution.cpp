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

    void getInorder(TreeNode* root, vector<TreeNode*>& inorder){
        if (root == NULL) return;

        getInorder(root->left, inorder);
        inorder.push_back(root);
        getInorder(root->right, inorder);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root){
        if (root == NULL) return nullptr;

        std::vector<TreeNode*> inorder;
        getInorder(root, inorder);
        
        TreeNode* new_root = inorder[0];

        for (int i=0; i<inorder.size()-1; i++){
            inorder[i]->left = nullptr;
            inorder[i]->right = inorder[i+1];
        }

        return new_root;
    }    
};