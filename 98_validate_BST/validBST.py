class TreeNode(object):
    def __init__:(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):     
    def validate(self, node: TreeNode, prev) -> bool:
        """
        Inorder Traversal
        Exit condition:
        """
        if (node == None):
            return true
    
        # left sub tree
        if self.validate(node.left, prev) is False:
            return False

        # Root Node
        if prev and prev.val >= node.val:
            return False

        # Right node
        prev = node
        return self.validate(node.right, prev)

    def isValidBST(self, root: TreeNode) -> bool:
        """
        :type root: TreeNode
        :rtype: bool
        """
        prev = None
        return validate(self, root, prev)
        
    
