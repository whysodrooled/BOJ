import sys
from collections import deque

input = sys.stdin.readline

sys.setrecursionlimit(10**7)

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

            if node.left:
                dq.append(node.left)
            if node.right:
                dq.append(node.right)
        
        return None
    
    def add(self, val):
        if self.root:
            dq = deque([self.root])
            while dq:
                node = dq.popleft()

                if val < node.val:
                    if node.left:
                        dq.append(node.left)
                    else:
                        node.left = BinTreeNode(val)
                        return
                else:
                    if node.right:
                        dq.append(node.right)
                    else:
                        node.right = BinTreeNode(val)
                        return
        else:
            self.root = BinTreeNode(val)

tree = BinTree()
while True:
    try:
        num = input()
        tree.add(int(num))
    except: break

def dfs(node):
    if not node: return
    
    dfs(node.left)
    dfs(node.right)

    print(node.val)

dfs(tree.root)