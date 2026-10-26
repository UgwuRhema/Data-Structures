import java.util.*;

public class List {
	public static class Node {
		int value;
		Node next;

		public Node(int value) {
			this.value = value;
			this.next = null;
		}
	}
	public static void main (String[] args) {
		System.out.println("Linked Lists");
		Node node1 = new Node(6);
		Node node2 = new Node(9);
		Node[] nodes = {node1, node2};
	}
}
