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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* dummyHead = new ListNode();
        ListNode* current = dummyHead;
        int carry = 0;
        int x, y, sum;
        while ( l1 != NULL || l2 != NULL) {
            x = (l1 == NULL)? 0 : l1->val;
            y = (l2 == NULL)? 0 : l2->val;
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