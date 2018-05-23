import java.util.*;

public class BinaryTree{

	static Node root;

	public static class Node{
		Node right,left;
		int data;
		Node(int data){ this.data = data; }
	}
	
	public static void add(Node focus, Node newNode){
		if(root == null){
			root = newNode;
		}
		else{				  
			if(newNode.data < focus.data){
				if(focus.left == null) focus.left = newNode;            
				else add(focus.left, newNode);	
			}
			else{
			 	if(focus.right == null) focus.right = newNode;
			 	else add(focus.right, newNode);
			}
		}
	}

	public static boolean search(Node focus, int target){
		if(focus == null)		 return false;							//not found
		if(focus.data == target) return true;							//found
		if(target < focus.data)  return search(focus.left,target);		//return recursively
		else					 return search(focus.right,target);
	}

	public static void preOrderTraversal(Node focus){
		if(focus == null) return;
		preOrderTraversal(focus.left);
		System.out.print(focus.data+" ");
		preOrderTraversal(focus.right);
	}

	public static void main(String[] args){
		add(root,new Node(5));
		add(root,new Node(6));
		add(root,new Node(7));
		add(root,new Node(4));
		preOrderTraversal(root);
		System.out.println();
	}
}