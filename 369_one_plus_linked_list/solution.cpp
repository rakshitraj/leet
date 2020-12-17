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
# include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    int add(ListNode* head, int carry){
        if (head->next == NULL){
            head->val += 1;
            carry = head->val/10;
            head->val = head->val % 10;
            return carry;
        }
        carry = add(head->next, carry);
        if(carry > 0){
            head->val += carry;
            carry = head->val/10;
            head->val = head->val % 10;
            return carry;
        }
        return 0;
    }
public:
    ListNode* plusOne(ListNode* head) {
        
        int carry = add(head, 0);
        if (carry){
            ListNode* newHead = new ListNode(carry, head);
            head = newHead;
        }
        return head;
    }
        
};