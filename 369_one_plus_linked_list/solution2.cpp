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
public:
    ListNode* plusOne(ListNode* head) {
        
        auto rhead = reverse(head);
        
        int carry = 1;
        
        auto current = rhead;
        while(current != nullptr)
        {
            auto newVal = current->val + carry;
            carry = newVal/10;
            current->val = newVal%10;            
            
            current = current->next;
        }
        if(carry == 1)
        {
            if(head != nullptr)
            {
                head->next = new ListNode(1);
                head = head->next;
            }
            else
            {
                return new ListNode(1);
            }
        }
        return reverse(rhead);
        
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr;
        auto current = head;
        ListNode* next = nullptr;
        
        
        while(current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
};