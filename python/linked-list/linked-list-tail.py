from node import Node


class LinkedList(object):
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, value):
        new_node = Node(value)
        # 첫번째 node 는 head 가 된다
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        # 맨 뒤의 node 가 new_node 를 가리켜야 한다.
        else:
            self.tail = new_node
            self.tail = self.tail.next

    def get(self, idx):
        current = self.head
        for _ in range(idx):
            current = current.next
        return current.value

    def insert(self, idx, value):
        current = self.head
        for _ in range(idx):
            current = current.next
        new_node = Node(value)
        next_node = current.next
        new_node.next = next_node
        current.next = new_node

    def remove(self, idx):
        prev, current = None, self.head
        for _ in range(idx - 1):
            prev = current
            current = current.next
        if prev is None:
            # 첫번째 노드를 삭제 하겠다
            self.head = current.next
        else:
            prev.next = current.next


















