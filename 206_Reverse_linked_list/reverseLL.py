class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        prev = ListNode()

        while(head != None):
            next = head.next
            head.next = prev
            prev = head
            head = next

        return prev