import java.util.*;

public class Prim{

	static ArrayList<Edge> tree = new ArrayList<Edge>();			//tree
	static ArrayList<Node> nodes = new ArrayList<Node>();
	static int sum = 0;												//weight of the tree

	public static class Edge{										//edge
		Node src,dest;
		int weight;
		Edge(Node src, Node dest, int weight){
			this.src = src;
			this.dest = dest;
			this.weight = weight;
		}
		public static void addEdge(Node src, Node dest, int weight){
			src.adj.add(new Edge(src,dest,weight));
			dest.adj.add(new Edge(dest,src,weight));
		}
	}

	public static class Node{										//node class
		ArrayList<Edge> adj = new ArrayList<Edge>();
		boolean visited = false;
		int dist = Integer.MAX_VALUE;
		Edge parent = null;											//where the node is from
		int id;
		Node(int id){ this.id = id; }
	}

	public static void mst(Node start){								//generating the mst
		ArrayList<Node> heap = new ArrayList<Node>(nodes);	   		//unvisited nodes		
		start.dist = 0;												//start gets chosen first
		while(heap.size() > 0){
			Node focus = null;
			int min = Integer.MAX_VALUE;							//please no bugs, -1
			int index = -1;
			for(int i = 0; i < heap.size(); i++){
				Node n = heap.get(i);
				if(n.dist < min && n.visited == false){
					min = n.dist;
					focus = n;
					index = i;
				}
			}
			heap.remove(index);
			if(heap.size() <= 0) return;
			focus.visited = true;
			for(Edge e: focus.adj){
				if(e.dest.dist > e.weight){
					e.dest.dist = e.weight;
					e.dest.parent = e;
				}
			}
		}
	}

	public static void getTree(){									//get the edge values to the tree list
		for(Node n: nodes){
			if(!tree.contains(n.parent) && n.parent != null){
				tree.add(n.parent);
				sum += n.parent.weight;
			}
		}
	}

	public static void print(){										//printing the tree
		System.out.println("Minimum Spanning Tree: ");
		for(Edge e: tree){
			System.out.println(e.src.id + " " + e.dest.id + " " + e.weight);
		}
		System.out.println("Total Weight: "+sum);
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int e = sc.nextInt();
		for(int i = 0; i < n; i++) nodes.add(new Node(i));
		for(int i = 0; i < e; i++) {
			int src = sc.nextInt();
			int dest = sc.nextInt();
			int weight = sc.nextInt();
			Edge.addEdge(nodes.get(src), nodes.get(dest), weight);
		}
		int start = sc.nextInt();
		mst(nodes.get(start));
		getTree();
		print();
	}
}