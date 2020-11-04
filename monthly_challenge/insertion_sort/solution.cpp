#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        
        ListNode* dummyHead = new ListNode();

        while(head){
            ListNode* next = head->next;

            ListNode* curr = dummyHead->next;
            ListNode* prev = dummyHead;
            while(curr && head->val > curr->val){
                prev = curr;
                curr = curr->next;
            }
            prev->next = head;
            head->next = curr;
            head = next;
        } 
        return dummyHead->next;
    }
};