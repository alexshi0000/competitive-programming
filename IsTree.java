import java.util.*;
import java.io.*;
import java.util.*;

public class IsTree{

	public static class Node{
		ArrayList<Node> adj = new ArrayList<Node>();
		Node parent = null;
		boolean visited = false;
	}

	public static boolean tree(Node root){
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);
		int counter = 0;
		while(!q.isEmpty()){
			Node focus = q.poll();
			focus.visited = true;
			counter++;
			for(Node neighbor: focus.adj){
				if(neighbor.visited && focus.parent != neighbor) return false;
				if(!neighbor.visited){
					neighbor.parent = focus;
					q.add(neighbor);
				}
			}
		}
		if(counter != 4) return false;
		return true;
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		Node[] nodes = new Node[4];
		for(int i = 0; i < 4; i++) nodes[i] = new Node();
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				int one = sc.nextInt();
				if(one == 1) 	nodes[i].adj.add(nodes[j]);
			} 
		}
		if(tree(nodes[0])) System.out.println("Yes");
		else System.out.println("No");
	}
}