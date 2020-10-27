/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        
        std::set<ListNode*> nodes;
        ListNode* curr = head;
        int count = -1;

        while(nodes.insert(curr).second && curr->next) {
            count++;
            curr = curr->next;
        }

        if (count == -1 || !curr->next) return nullptr;
        else return curr;
    }
};