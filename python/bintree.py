from collections import deque


class BinTreeNode:
    def __init__(self, val=None):
        self.val = val
        self.left = None
        self.right = None
    
    def __del__(self):
        if self.left:
            del self.left
        if self.right:
            del self.right

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
    
    def add(self, val, parentVal=None):
        if self.root:
            if parentVal:
                temp = self.find(parentVal)
                if temp:
                    if not temp.left:
                        temp.left = BinTreeNode(val)
                        return
                    elif not temp.right:
                        temp.right = BinTreeNode(val)
                        return

            dq = deque([self.root])
            while dq:
                node = dq.popleft()

                if not node.left:
                    node.left = BinTreeNode(val)
                    return
                elif not node.right:
                    node.right = BinTreeNode(val)
                    return

        else:
            self.root = BinTreeNode(val)
    
    def remove(self, val):
        dq = deque([[self.root, None, None]])
        tgt_node = None
        tgt_parent = None
        tgt_loc = None
        while dq:
            nodes = dq.popleft()
            if nodes[0].val == val:
                tgt_node, tgt_parent, tgt_loc = nodes
                break

            if nodes[0].left:
                dq.append([nodes[0].left, nodes[0], False])
            if nodes[0].right:
                dq.append([nodes[0].right, nodes[0], True])

        if not tgt_node: return
        del tgt_node

        if not tgt_parent:
            del self.root
            self.root = None
            return
        if tgt_loc:
            tgt_parent.right = None
        else:
            tgt_parent.left = None

# dfs(tree.root)
def dfs(node):
    if not node: return

    print(node.val)

    dfs(node.left)
    dfs(node.right)

# bfs(tree)
def bfs(tree):
    dq = deque([tree.root])
    while dq:
        node = dq.popleft()

        print(node.val)

        if node.left:
            dq.append(node.left)
        if node.right:
            dq.append(node.right)