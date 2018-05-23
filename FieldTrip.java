import java.util.*;
import java.io.*;

public class FieldTrip{

	static ArrayList<Node> groups = new ArrayList<Node>();						//the parents

	public static class Node implements Comparable<Node>{
		static ArrayList<Node> all = new ArrayList<Node>();
		ArrayList<Node> adj = new ArrayList<Node>();
		Node parent;
		boolean visited = false;
		Node(){	all.add(this); }
		public static void reset(){
			for(Node n: all) n.visited = false;
		}
		public int compareTo(Node arg0){
			if(this.adj.size() < arg0.adj.size()) return -1;
			if(this.adj.size() > arg0.adj.size()) return 1;
			return 0;
		}
	}

	public static void union(Node a, Node b){
		if(find(a) == a && find(b) == b){
			a.adj.add(b);
			b.parent = a;
		}
		else if(find(a) != a && find(b) == b){
			find(a).adj.add(b);
			b.parent = find(a);
		}
		else if(find(a) == a && find(b) != b){
			find(b).adj.add(a);
			a.parent = find(b);
		}
		else{
			find(a).adj.add(find(b));
			find(b).parent = find(a);
		}
	}

	public static Node find(Node a){											//returns pointer of the parent
		if(a.parent == null) return a;
		return find(a.parent);
	}

	public static int getSize(Node root){
		int size = 0;
		Queue<Node> q = new LinkedList<Node>();
		q.add(root);
		while(!q.isEmpty()){
			Node focus = q.poll();
			focus.visited = true;
			size++;
			for(Node neighbor: focus.adj){
				if(!neighbor.visited) q.add(neighbor);
			}
		}
		q.add(root);
		while(!q.isEmpty()){
			Node focus = q.poll();
			focus.visited = false;
			for(Node neighbor: focus.adj){
				if(neighbor.visited) q.add(neighbor);
			}
		}
		return size;
	}

	public static int remove(){
		return 0;
	}
	
	public static void main(String[] args){
		try{
			BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
			String[] in = sc.readLine().split(" ");
			int N = Integer.parseInt(in[0]);
			int M = Integer.parseInt(in[1]);
			int K = Integer.parseInt(in[2]);
			Node[] nodes = new Node[N]; 
			for(int i = 0; i < nodes.length; i++) nodes[i] = new Node();
			for(int i = 0; i < M; i++){
				in = sc.readLine().split(" ");
				int src = Integer.parseInt(in[0]) - 1;
				int dest = Integer.parseInt(in[1]) - 1;
				union(nodes[src],nodes[dest]);
			}
			System.out.print(getSize(nodes[0])+" ");
			System.out.print(getSize(nodes[2]));
			System.out.println();
		} catch (Exception e){
			e.printStackTrace();
		}
	}
}