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
	node1 *Node = newNode(6)
	node2 *Node = newNode(9)
}
