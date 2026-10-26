import java.util.*;

public class List {
	public static class Node {
		int value;
		Node next;
		public Node (int value) {
			this.value = value;
			this.next = null;
		}
		public void print () {
			System.out.println(this.value);
		}
		public void printlist () {
			Node curr = this;
			while (curr != null) {
				System.out.print(curr.value + "->");
				curr = curr.next;
			}
			if (curr == null) {
				System.out.print("NULL");
			}
		}
	}
	public static void main (String[] args) {
		System.out.println("Linked Lists");
		Node head = null;
		Node node1 = new Node(6);
		Node node2 = new Node(9);
		Node node3 = new Node(15);
		Node node4 = new Node(27);
		node1.next = node2;
		node2.next = node3;
		node3.next = node4;
		node4.next = null;
		head = node1;
		head.printlist();
		System.out.println("");
	}
}
