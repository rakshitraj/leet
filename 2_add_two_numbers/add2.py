# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummyHead = ListNode(0, None)
        p, q, current = l1, l2, dummyHead
        carry = 0
        while p or q:
            x = p.val if p else 0
            y = q.val if q else 0
            sum = carry + x + y
            carry = int(sum/10)
            current.next = ListNode(sum % 10)
            current = current.next
            if p :
                p = p.next
            if q :
                q = q.next
        if carry>0 :
            current.next = ListNode(carry)
        return dummyHead.next