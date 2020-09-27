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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;
        int carry = 0;
        int sum;
        while (l1 != NULL && l2 != NULL) { 
            sum = carry + l1->val + l2->val;
            carry = sum/10;
            current->next = new ListNode(sum%10);
            current = current->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *itr = (l1 == NULL)? l2 : l1;
        while (itr != NULL) {
           if (carry > 0){
               sum = carry + itr->val;
               carry = sum/10;
               current->next = new ListNode(sum%10);
               current = current->next;
           }
            else{
                current->next = new ListNode(itr->val);
                current = current->next;
            }
            itr = itr->next;
        }
        if (carry>0) current->next = new ListNode(carry);
        return dummyHead->next;
    }
};