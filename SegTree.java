import java.util.*;

public class SegTree{

	static Node root;										//center of the tree, indices are end of the tree
	static int[] arr;										//the arr we are working with

	public static class Node{
		int data;
		int i,j;
		Node leftChild;
		Node rightChild;
		Node(int i, int j){									//indices of this node
			this.i = i;
			this.j = j;
		}	
	}

	public static int construct(Node element){					//node element is the root that we must add
		if(root == null){
			root = element;
		}
		if(element.j-element.i == 0){							//seg with length of 1, this is the external node
			element.data = arr[element.i];
			return arr[element.i];
		}
		else{
			int range = element.j - element.i;
			element.leftChild = new Node(element.i,element.i+range/2);		//creating nodes from branching indices
			element.rightChild = new Node(range/2+1+element.i,element.j);	
			construct(element.leftChild);									//constructing the subtrees
			construct(element.rightChild);
			element.data = element.rightChild.data + element.leftChild.data;//updating the element
		}
		return 0;
	}

	public static int get(Node focus, int i, int j){						//indices to search for 
		if(i <= focus.i && focus.j <= j){									//returning the data of node rep those indices 
			return focus.data;
		}
		else if(focus.j < i || focus.i > j){								//indices share no overlap with the parameters
			return 0;
		}
		else{
			return get(focus.rightChild,i,j) + get(focus.leftChild,i,j);
		}
	}

	public static void update(Node focus, int index, int value){			//update function
		if(focus.i == focus.j && focus.i == index){							//found the external node to update first
			arr[index] = value;
			focus.data = value;
		}
		else if(index <= focus.leftChild.j && index >= focus.leftChild.i){	//choose to branch right or left
			update(focus.leftChild,index,value);
			focus.data = focus.leftChild.data + focus.rightChild.data;
		}
		else if(index >= focus.rightChild.i && index <= focus.rightChild.j){
			update(focus.rightChild,index,value);
			focus.data = focus.leftChild.data + focus.rightChild.data;
		}
	}

	public static void traverse(Node focus){
		if(focus == null) return;
		traverse(focus.leftChild);
		System.out.println(focus.i+" "+focus.j+" "+focus.data);
		traverse(focus.rightChild);
	}
	
	public static void main(String[] args){						//driver program, sample case input
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		arr = new int[n];
		for(int i = 0; i < n; i++) arr[i] = sc.nextInt();
		construct(new Node(0,n-1));
		traverse(root);
		int q = sc.nextInt();									//what values you would like to update that is
		for(int i = 0; i < q; i++){
			int index = sc.nextInt();
			int value = sc.nextInt();
			update(root,index,value);
		}
		traverse(root);
		q = sc.nextInt();
		for(int i = 0; i < q; i++){
			int l = sc.nextInt();
			int r = sc.nextInt();
			System.out.println(get(root,l,r));
		}
		traverse(root);
	}
}