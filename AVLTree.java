import java.util.*;
import java.io.*;

public class AVLTree {

	public static class Node {

		private int  data;
		private Node left, right;

		Node (int data) {
			this.data = data;
			left   = null;
			right  = null;
		}

		public void setData(int d) {
			data = d;
		}

		public void setLeft(Node l) {
			left = l;
		}

		public void setRight(Node r) {
			right = r;
		}

		public int getData() {
			return data;
		}

		public Node getLeft() {
			return left;
		}

		public Node getRight() {
			return right;
		}
	}

	public static int getHeight(Node n) {
		if (n == null)
			return 0;
		return 1 + Math.max(getHeight(n.getRight()), getHeight(n.getLeft()));
	}

	public static int getBalance(Node n) {
		if (n.getRight() == null && n.getLeft() == null)
			return 0;
		return getHeight(n.getRight()) - getHeight(n.getLeft());
	}

	/*
	 *           z                                      y
         *          / \                                   /   \
         *         y   T4      Right Rotate (z)          x     z
         *        / \          - - - - - - - - ->      /  \   / \
         *      x   T3                               T1  T2  T3  T4
         *     / \
         *   T1   T2
         *
	 *
	 *        z                               y
         *      /  \                            /   \
         *    T1   y     Left Rotate(z)       z      x
         *        /  \   - - - - - - - ->    / \    / \
         *      T2   x                     T1  T2 T3  T4
         *          / \
         *        T3  T4
         *
	 */

	public static Node rotateLeft(Node z) {
		Node T2 = z.getRight().getLeft();
		Node y = z.getRight();
		y.setLeft(z);
		z.setRight(T2);
		return y;
	}

	public static Node rotateRight(Node z) {
		Node T3 = z.getLeft().getRight();
		Node y = z.getLeft();
		y.setRight(z);
		z.setLeft(T3);
		return y;
	}

	public static Node insert(Node focus, Node entry) {
		if (focus == null)
			return entry;
		if (entry.getData() < focus.getData())
			focus.setLeft(insert(focus.getLeft(), entry));
		else
			focus.setRight(insert(focus.getRight(), entry));

		//balancing
		int balance = getBalance(focus);
		if (balance < -1) {
			if (getBalance(focus.getLeft()) < 0) {
				return rotateRight(focus);
			} else {
				focus.setLeft(rotateLeft(focus.getLeft()));
				return rotateRight(focus);
			}
		} else if (balance > 1) {
			if (getBalance(focus.getRight()) > 0) {
				return rotateLeft(focus);
			} else {
				focus.setRight(rotateRight(focus.getRight()));
				return rotateLeft(focus);
			}
		}
		return focus;
	}

	public static void preOrderTraversalUtil(Node focus) {
		if (focus != null) {
			System.out.print(focus.getData() + " --> ");
			preOrderTraversalUtil(focus.getLeft());
			preOrderTraversalUtil(focus.getRight());
		}
	}

	public static void preOrderTraversal(Node focus) {
		preOrderTraversalUtil(focus);
		System.out.println(" traversal complete.");
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Node root = null;
		for (int i = 0; i < n; i++) {
			int data = sc.nextInt();
			root = insert(root, new Node(data));
		}
		preOrderTraversal(root);
	}
}