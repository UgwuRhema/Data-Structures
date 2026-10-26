#!/usr/bin/env python3

class node:
    def __init__(self, value):
        self.value = value
        self.link = None

def printlist(a_node):
    curr = a_node
    while curr != None:
        print(f"{curr.value}")
        curr = curr.link
    if curr == None:
        print("NULL")

node1 = node(6)
node2 = node(9)
node3 = node(7)
node4 = node(56)
node5 = node(12)
#link the two nodes
node1.link = node2
node2.link = node3
node3.link = node4
node4.link = node5
head = node1
#let's try to print via traversal and not recursion
printlist(head)
