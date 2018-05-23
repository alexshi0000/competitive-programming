import java.util.*;
import java.io.*;

public class Facebook{
	public static class Node{
		static ArrayList<Node> all = new ArrayList<Node>();
		ArrayList<Node> adj = new ArrayList<Node>();
		boolean visited = false;
		int dist = Integer.MAX_VALUE;
		public static void reset(){
			for(Node n: all){
				n.visited = false;
				n.dist = Integer.MAX_VALUE;
			}
		}
		public static void add(Node src, Node dest){
			if(!src.adj.contains(dest)) src.adj.add(dest);
			if(!dest.adj.contains(src)) dest.adj.add(src);
		}
		Node(){
			all.add(this);
		}
	}
	public static int fof(Node start){
		int counter = 0;
		for(Node n: start.adj){
			for(Node e: n.adj){
				if(e != start && !start.adj.contains(e) && !e.visited){
					e.visited = true;
					counter ++;
				}
			}
		}
		Node.reset();
		return counter;
	}
	public static int ds(Node start, Node target){
		Queue<Node> q = new LinkedList<Node>();
		start.dist = 0;
		q.add(start);
		while(!q.isEmpty()){
			Node focus = q.poll();
			focus.visited = true;
			if(focus == target){
				int distance = focus.dist;
				Node.reset();
				return distance;
			}
			else{
				for(Node n: focus.adj){
					if(focus.dist + 1 < n.dist) n.dist = focus.dist + 1;
					if(!n.visited) q.add(n);
				}
			}
		}
		Node.reset();
		return -1;
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		Node[] nodes = new Node[50];
		for(int i = 0; i < 50; i++) nodes[i] = new Node();

		Node.add(nodes[1],nodes[5]);
		Node.add(nodes[0],nodes[5]);
		Node.add(nodes[2],nodes[5]);
		Node.add(nodes[3],nodes[5]);
		Node.add(nodes[4],nodes[5]);
		Node.add(nodes[6],nodes[5]);
		Node.add(nodes[2],nodes[4]);
		Node.add(nodes[6],nodes[7]);
		Node.add(nodes[4],nodes[3]);
		Node.add(nodes[2],nodes[3]);
		Node.add(nodes[2],nodes[14]);
		Node.add(nodes[7],nodes[8]);
		Node.add(nodes[11],nodes[8]);
		Node.add(nodes[12],nodes[14]);
		Node.add(nodes[12],nodes[11]);
		Node.add(nodes[10],nodes[11]);
		Node.add(nodes[9],nodes[8]);
		Node.add(nodes[9],nodes[10]);
		Node.add(nodes[12],nodes[13]);
		Node.add(nodes[15],nodes[17]);
		Node.add(nodes[15],nodes[16]);
		Node.add(nodes[16],nodes[17]);

		while(true){
			String q = sc.next();
			if(q.equals("q")) break;
			else if(q.equals("i")){
				int x = sc.nextInt()-1;
				int y = sc.nextInt()-1;
				Node.add(nodes[x],nodes[y]);
			}
			else if(q.equals("d")){
				int x = sc.nextInt()-1;
				int y = sc.nextInt()-1;
				nodes[x].adj.remove(nodes[x].adj.indexOf(nodes[y]));
				nodes[y].adj.remove(nodes[y].adj.indexOf(nodes[x]));
			}
			else if(q.equals("n")){
				int x = sc.nextInt()-1;
				System.out.println(nodes[x].adj.size());
			}
			else if(q.equals("f")){
				int x = sc.nextInt()-1;
				System.out.println(fof(nodes[x]));
			}
			else if(q.equals("s")){
				int x = sc.nextInt()-1;
				int y = sc.nextInt()-1;
				int distance = ds(nodes[x],nodes[y]);
				if(distance == -1) System.out.println("Not connected");
				else 			   System.out.println(distance);
			}
		}
	}
}