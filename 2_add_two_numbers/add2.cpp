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
        int x, y, sum;
        while ( l1 != nullptr || l2 != nullptr) {
            x = (l1)? l1->val : 0;
            y = (l2)? l2->val : 0;
            sum = carry + x + y;
            carry = sum/10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            if (!l1) l1 = l1->next;
            if (!l2) l2 = l2->next;
        }
        if (carry>0) current->next = new ListNode(carry);
        return dummyHead->next;
    }
};