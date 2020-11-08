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
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
};

class Solution {
    int sumSubTree (TreeNode* root){
        int sum = 0;
        if (root != NULL){
            sum+= (root->val + sumSubTree(root->left) + sumSubTree(root->right));
        }
        return sum;
    }

    void get_tilt(TreeNode* root, vector<int>& allTilt){

        if (root != NULL){
        int tilt = abs(sumSubTree(root->left) - sumSubTree(root->right));
        get_tilt(root->left, allTilt);
        get_tilt(root->right, allTilt);
        allTilt.push_back(tilt);
        }
    }

public:
    int findTilt(TreeNode* root) {

        int sumAllTilt = 0;
        std::vector<int> allTilt; 
        get_tilt(root, allTilt);

        for (int el: allTilt){
            sumAllTilt += el;
        }

        return sumAllTilt;
        
    }
};