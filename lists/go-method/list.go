package main

import "fmt"

type Node struct {
	val int
	next *Node //pointer to next node(bruh, the obvious?)
}

func newNode(val int) *Node {
	return &Node{
		val: val,
		next: nil,
	}
}

func main(){
	var node1 *Node = newNode(6)
	var node2 *Node = newNode(9)
	node1.next = node2
	fmt.Println("Node 1 value is:", node1.val)
}
