import sys
from collections import deque

input = sys.stdin.readline

class BinTreeNode:
    def __init__(self, val=None):
        self.val = val
        self.left = None
        self.right = None

class BinTree:
    def __init__(self, val=None):
        if val:
            self.root = BinTreeNode(val)
        else:
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

bintree = BinTree('A')

for _ in range(T):
    root, node1, node2 = input().rstrip().split()

    bintree.add(node1, root)
    bintree.add(node2, root)

output = []

def dfs(node):
    if not node: return

    if node.val != '.':
        output.append(node.val)
    dfs(node.left)
    dfs(node.right)

dfs(bintree.root)
print(*output, sep='')

output = []

def dfs2(node):
    if not node: return

    dfs2(node.left)
    if node.val != '.':
        output.append(node.val)
    dfs2(node.right)

dfs2(bintree.root)
print(*output, sep='')

output = []

def dfs3(node):
    if not node: return

    dfs3(node.left)
    dfs3(node.right)
    if node.val != '.':
        output.append(node.val)

dfs3(bintree.root)
print(*output, sep='')