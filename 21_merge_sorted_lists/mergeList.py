class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNose) -> ListNode:
        head = ListNode()
        current = head

        while(l1 and l2):
            if l1.val < l2.val:
                node = ListNode(l1.val)
                l1 = l1.next
            else:
                node = ListNode(l2.val)
                l2 = l2.next
            current.next = node
            current = current.next

        while l1:
            node = ListNode(l1.val)
            current.next = node
            current = current.next
            l1 = l1.next

        while l2:
            node = ListNode(l2.val)
            current.next = node
            current = current.next
            l2 = l2.next

        return head.next