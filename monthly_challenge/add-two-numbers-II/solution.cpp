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
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val): val(val), next(nullptr) {}
    ListNode(int val, ListNode* next) : val(val), next(next) {}
};

class Solution {
private:
    int number (ListNode* head, std::stack<int>& target) {
        ListNode* curr = head;
        while(curr){
            target.push(curr->val);
            curr = curr->next;
        }
        return target.size();    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum_head = new ListNode();

        std::stack<int> num1;
        std::stack<int> num2;
        
        int size1 = number(l1, num1);
        int size2 = number(l2, num2);
        int sum = 0;
        int carry = 0;
        while (size1>0 && size2>0){
            sum = carry + num1.top() + num2.top();
            ListNode* node = new ListNode(sum%10);
            carry = sum/10;
            node->next = sum_head->next;
            sum_head->next = node;
            num1.pop();
            num2.pop();
            size1--;
            size2--;
        }
        while (size1>0){
            sum = carry + num1.top();
            ListNode* node = new ListNode(sum%10);
            carry = sum/10;
            node->next = sum_head->next;
            sum_head->next = node;
            num1.pop();
            size1--;
        }
        while (size2>0){
            sum = carry + num2.top();
            ListNode* node = new ListNode(sum%10);
            carry = sum/10;
            node->next = sum_head->next;
            sum_head->next = node;
            num2.pop();
            size2--;
        }
        if (carry > 0){
            ListNode* node = new ListNode(carry);
            node->next = sum_head->next;
            sum_head->next = node;
        }
        return sum_head->next;
    }
};