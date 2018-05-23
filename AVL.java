import java.util.*;
import java.io.*;
public class AVL {
	//lets check if the tree is an AVL tree
	public static class Node {
		private int data;
		private Node left, right, parent;
		Node (int data) {
			this.data = data;
			left      = null;
			right     = null;
			parent    = null;
		}
		public void setLeft(Node left) {
			this.left = left;
		}
		public void setRight(Node right) {
			this.right = right;
		}
		public void setData(int data) {
			this.data = data;
		}
		public void setParent(node parent) {
			this.parent = parent;
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
		public Node getParent() {
			return parent;
		}
	}
	public static Node root = null;
	//recursively find the number of children
	public static void insert(Node focus, Node entry) {
		if (root == null) {
			root = entry;
		} else {
			if (entry.getData() < focus.getData()) {
				if (focus.getLeft() == null)
					focus.setLeft(entry);
				else
					insert(focus.getLeft(), entry);
			} else {
				if (focus.getRight() == null)
					focus.setRight(entry);
				else
					insert(focus.getRight(), entry);
			}
		}
	}
	private static void traverseUtil(Node root) {
		if (root != null) {
			System.out.print(root.getData() + " -> ");
			traverseUtil(root.getLeft());
			traverseUtil(root.getRight());
		}
	}
	public static void traverse (Node root) {
		traverseUtil(root);
		System.out.println(" traversal finished");
	}
	public static boolean checkAVL (Node root) {
		if (root != null) {
			return checkAVL(root.getRight()) && checkAVL(root.getLeft()) && Math.abs(getHeight(root.getLeft()) - getHeight(root.getRight())) <= 1;
		} else {
			return true;
		}
	}
	public static int getHeight (Node root) {
		if (root == null) {
			return 0;
		} else {
			return 1 + Math.max(getHeight(root.getRight()), getHeight(root.getLeft()));
		}
	}
	/*
	 *         z                                      y
         *        / \                                   /   \
         *       y   T4      Right Rotate (z)          x     z
         *      / \          - - - - - - - - ->      /  \   / \
         *    x   T3                               T1  T2  T3  T4
         *   / \
         * T1   T2
         *
	 */
	public static void rightRotate (Node focus) {

	}
	/*
	 *        z                               y
         *      /  \                            /   \
         *    T1   y     Left Rotate(z)       z      x
         *        /  \   - - - - - - - ->    / \    / \
         *      T2   x                     T1  T2 T3  T4
         *          / \
         *        T3  T4
	 */
	public static void leftRotate (Node focus) {

	}
	public static int getBalance (Node focus) {
		if (focus == null) {
			return 0;
		} else {
			return getHeight(focus.getRight()) - getHeight(focus.getLeft());
		}
	}
	public static void balance (Node entry) {
		if (entry != null) {
			int entryBalance = getBalance(entry);
			//there are four different cases to consider
			if (entryBalance < -1) {
				if (getBalance(entry.getLeft()) < 0) {
					rightRotate(entry);
				} else {
					leftRotate(entry);
					rightRotate(entry);
				}
			} else if (entryBalance > 1) {
				if (getBalance(entry.getRight() > 0)) {
					leftRotate(entry);
				} else {
					rightRotate(entry);
					leftRotate(entry);
				}
			} else {
				//the tree so far is balanced
				balance(entry.getParent());
			}
		}
	}
	public static void insertionAVL(Node focus, Node entry) {
		if (root == null) {
			root = entry;
		} else {
			if (entry.getData() < focus.getData()) {
				if (focus.getLeft() == null) {
					entry.setParent(focus);
					focus.setLeft(entry);
					balance(entry);
				} else {
					insertionAVL(focus.getLeft(), entry);
				}
			} else {
				if (focus.getRight() == null) {
					entry.setParent(focus);
					focus.setRight(entry);
					balance(entry);
				} else {
					insertionAVL(focus.getRight(), entry);
				}
			}
		}
	}
	public static void main(String[] args) {
		/*Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			int data = sc.nextInt();
			Node entry = new Node(data);
			insert(root, entry);
		}
		traverse(root);
		System.out.println("height of global tree: "+ getHeight(root));
		System.out.println("is AVL? (balanced): " + checkAVL(root));
		*/
		//now lets get started on coding an AVL tree
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			int data = sc.nextInt();
			Node entry = new Node(data);
			insertionAVL(root, entry)
		}
		traverse(root);
	}
}