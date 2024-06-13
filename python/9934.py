import sys
from collections import deque

input = sys.stdin.readline

class BinTreeNode:
    def __init__(self, val=None):
        self.val = val
        self.left = None
        self.right = None

class BinTree:
    def __init__(self):
        self.root = None

    def find(self, val):
        dq = deque([self.root])
        while dq:
            node = dq.popleft()
            if node.val == val:
                return node

            if type(node.left) == BinTreeNode:
                dq.append(node.left)
            if type(node.right) == BinTreeNode:
                dq.append(node.right)
        
        return None
    
    def add(self, val, parentVal=None):
        if self.root:
            if parentVal:
                temp = self.find(parentVal)
                if temp.left: temp.right = BinTreeNode(val)
                else: temp.left = BinTreeNode(val)

        else:
            self.root = BinTreeNode(val)

T = int(input().rstrip())
inputs = deque(map(int, input().rstrip().split()))

tree = BinTree()
tree.add(-1)

def initTree(node, curLevel):
    if curLevel >= T: return

    node.left = BinTreeNode(-1)
    node.right = BinTreeNode(-1)

    initTree(node.left, curLevel + 1)
    initTree(node.right, curLevel + 1)

initTree(tree.root, 1)

def dfs(node):
    if type(node.left) == BinTreeNode:
        dfs(node.left)

    node.val = inputs.popleft()

    if type(node.right) == BinTreeNode:
        dfs(node.right)

dfs(tree.root)

dq = deque([tree.root])
count = 2
while dq:
    temp = dq.popleft()
    print(temp.val, end=' ')
    if count == 1 or ((count & (count-1) == 0)):
        print('')

    if type(temp.left) == BinTreeNode:
        dq.append(temp.left)

    if type(temp.right) == BinTreeNode:
        dq.append(temp.right)
    
    count += 1