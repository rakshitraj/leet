#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

// Defination of Node
// struct Node {
//     int val;
//     Node *left;
//     Node *right;
//     Node *next;
// };

class Node {
    public:

    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node (int val) : val(val), left(NULL), right(NULL), next(NULL) {}
    Node (int val, Node* left, Node* right, Node* next)
        : val(val), left(left), right(right), next(next) {}
};

class Solution {
    std::vector<Node*> allNodes = {nullptr};

    void bfs(Node *root){
        std::queue<Node*> q;
        std::map<Node*, bool> visited;

        q.push(root);
        visited[root] = true;
        
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            allNodes.push_back(node);

            if (node->left && !visited[node->left]){
                q.push(node->left);
                visited[node->left] = true;
            }  
            if (node->right){
                q.push(node->right);
                visited[node->right] = true;
            } 
        }
    }

public:
    Node* connect(Node* root) {
        bfs(root);
        int depth = 0;
        int i=1;
        for (i=1; i<allNodes.size()-1; i++) {
            if (i == pow(2, depth++)){
                allNodes[i]->next = NULL;
            }
            else {
                allNodes[i]->next = allNodes[i+1];
            }
        }
        allNodes[i]->next = NULL;
        return root;
    }
};

int main(){
    Node* root = new Node(1);
    {
        root->left = new Node(2);
            root->left->left = new Node(4);
                root->left->left->left = new Node(8);
                root->left->left->right = new Node(9);
            root->left->right = new Node(5);
                root->left->right->left = new Node(10);
                root->left->right->right = new Node(11);
        root->right = new Node(3);
            root->right->left = new Node(6);
                root->right->left->left = new Node(12);
                root->right->left->right = new Node(13);
            root->right->right = new Node(7);
                root->right->right->left = new Node(14);
                root->right->right->right = new Node(15);
    }
    Solution* obj = new Solution();
    root = obj->connect(root);
    return 0;
}