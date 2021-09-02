#include <iostream>
#include <vector>
#include <stack>

using namespace std;

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> output_arr;
        stack<TreeNode*> stk;
        
        if (root == NULL)   {
            return output_arr;
        }
        
        TreeNode* current = root;
        
        while (current != NULL || !stk.empty())  {
            while(current != NULL)  {
                stk.push(current);
                current = current->left;
            }
            
            current = stk.top();
            stk.pop();
            output_arr.push_back(current->val);
            current = current->right;
        }  
               
        output_arr.shrink_to_fit();
        
        return output_arr;
    }
};