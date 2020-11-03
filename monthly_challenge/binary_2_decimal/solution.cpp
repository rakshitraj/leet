/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        vector<int> binary;
        int sum = 0;
        ListNode* curr = head;
        
        while(curr){
            binary.push_back(curr->val);
            curr = curr->next;
        }
        int index = binary.size() - 1;
        for (int i = 0; i < binary.size(); i++){
            if (binary[i] == 1)
                sum += pow(2,index);
            index--;
        }
        
        return sum;
    }
};