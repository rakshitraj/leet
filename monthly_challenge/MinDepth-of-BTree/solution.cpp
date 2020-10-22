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
#include <queue>

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
    int minDepth(TreeNode* root) {

        if (root == NULL) return 0;

        std::queue<std::pair<struct TreeNode*, int>> levels;
        int depth = 1;
        levels.push(std::make_pair(root, depth));

        struct TreeNode* curr = root;
        //int curr_depth = 0;

        while(!levels.empty()){
            curr = levels.front().first;
            if (curr == NULL) return levels.front().second;
            levels.push(std::make_pair(curr->left, ++depth));
            levels.push(std::make_pair(curr->right, depth));
            levels.pop();
        }
        return depth;
    }
};