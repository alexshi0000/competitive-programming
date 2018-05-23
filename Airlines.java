import java.util.*;
import java.io.*;

public class Airlines {

	public static class Node {

		private int cost;
		private String city;
		private Node parent;
		private ArrayList<Edge> adj;

		public Node(String city) {
			adj = new ArrayList<Edge>();
			this.city = city;
			this.parent = null;       //set parent to null
			cost = Integer.MAX_VALUE; //set dist to a high value
		}

		public ArrayList<Edge> getAdj() {
			return adj;
		}

		public String getCity() {
			return city;
		}

		public Node getParent() {
			return parent;
		}

		public int getCost() {
			return cost;
		}

		public void setCost(int cost) {
			this.cost = cost;
		}

		public void setParent(Node parent) {
			this.parent = parent;
		}

		public void setCity(String city) {
			this.city = city;
		}

		public void addEdge(Edge e) {
			this.adj.add(e);
		}
	}
	public static class Edge {

		private Node src, dst;
		private int cost;

		public Edge(Node src, Node dst, int cost) {
			this.src  = src;
			this.dst  = dst;
			this.cost = cost;
		}

		public Node getSrc() {
			return src;
		}

		public Node getDst() {
			return dst;
		}

		public int getCost() {
			return cost;
		}
	}
	public static int dijkstra(Node src, Node dst) {
		src.setCost(0);
		Queue<Node> q = new LinkedList<Node>(); //create a queue
		q.add(src);
		while (!q.isEmpty()) {
			Node focus = q.poll();
			//System.out.println("Visited: " + focus.getCity());
			if (focus != dst) {
				for (Edge e: focus.getAdj()) {
					if (e.getCost() + focus.getCost() < e.getDst().getCost()) {
						e.getDst().setCost(e.getCost() + focus.getCost());
						e.getDst().setParent(focus);
						q.add(e.getDst());
					}
				}
			}
		}
		return dst.getCost();
	}

	private static void tracePathUtil(Node end) {
		if (end.getParent() != null)
			tracePathUtil(end.getParent());
		System.out.print(end.getCity() + " -> ");
	}

	public static void tracePath(Node end) {
		tracePathUtil(end);
		System.out.println();
	}

	public static int cityIndex(String city) {
		for (int i = 0; i < cities.length; i++)
			if (city.equals(cities[i]))
				return i;
		return -1;

	}

	public static String[] cities = {"Boston", "Paris", "Tokyo", "London", "New York", "Toronto", "Moscow", "Beijing", "Manila"};

	public static void main(String[] args) {
		//Scanner sc = new Scanner(System.in);

		String[][] example = {
        //Boston                 ...                    Manila
		{"-"  ,"225","575","200","70" ,"85" ,"340","675","975"},
		{"225","-"  ,"225","50" ,"125","220","120","435","550"},
		{"575","225","-"  ,"510","650","675","735","225","200"},
		{"200","50" ,"510","-"  ,"-"  ,"-"  ,"-"  ,"-"  ,"-"  },
		{"70" ,"125","650","-"  ,"-"  ,"-"  ,"-"  ,"-"  ,"-"  },
		{"85" ,"220","675","-"  ,"-"  ,"-"  ,"-"  ,"-"  ,"-"  },
		{"340","120","735","-"  ,"-"  ,"-"  ,"-"  ,"-"  ,"-"  },
		{"675","435","225","-"  ,"-"  ,"-"  ,"-"  ,"-"  ,"-"  },
		{"975","550","200","-"  ,"-"  ,"-"  ,"-"  ,"-"  ,"-"  }};

		int n = example.length; //n x n grid

		Node[] nodes = new Node[n];
		for (int i = 0; i < n; i++)
			nodes[i] = new Node(cities[i]);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!example[i][j].equals("-")) {
					int cost = Integer.parseInt(example[i][j]);
					nodes[i].addEdge(new Edge(nodes[i], nodes[j], cost));
				}
			}
		}

		int start = cityIndex("Boston");  //start of our trip
		int end   = cityIndex("Beijing"); //end of our trip
		System.out.println("total cost:");
		System.out.println(dijkstra(nodes[start], nodes[end]));
		System.out.println("optimal path taken:");
		tracePath(nodes[end]);
	}
}