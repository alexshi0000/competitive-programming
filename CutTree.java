import java.util.*;
import java.io.*;
public class CutTree{
	/*
		Uncommented areas are either io, object-oriented code, or memoization implementation
	*/
	static HashMap<String, Long> funcMemo = new HashMap<String, Long>(); //the two memo tables for func and junct recursion calls
	static HashMap<String, Long> junctMemo = new HashMap<String, Long>();
	public static class Node{												   //basic node obj
		ArrayList<Node> adj;
		String id;
		Node parent;
		Node(String id){
			this.id = id;
			adj = new ArrayList<Node>();
			parent = null;
		}
	}
	public static void addEdge(Node src, Node dst){							   //bidirectional edge
		src.adj.add(dst);
		dst.adj.add(src);
	}
	public static void dfs(Node root){//cleans up path, we no longer need to consider backflow. not a part of solutions but makes things easier to deal with
		if(root.parent != null){
			int idx = root.adj.indexOf(root.parent);
			if(idx != -1)
				root.adj.remove(idx);
		}
		for(Node neighbor: root.adj){
			neighbor.parent = root;
			dfs(neighbor);
		}
	}
	public static void traverse(Node root){//used this for  only
		if(root != null){
			System.out.print(root.id);
			for(Node focus: root.adj)
				traverse(focus);
		}
	}
	public static long func(Node focus, int k){//current subroot and free edge parameter
		if(funcMemo.containsKey(focus.id+k))
			return funcMemo.get(focus.id+k);
		long solutions = 0;
		for(int i = 0; i <= Math.min(focus.adj.size(),k); i++)//create ceil = min ( ignore all children vs ignore as much as k )
			solutions += junct(focus, 0, i, k-i);//iterate through availible free edges and ignored children. add all combinations. start with index at 0th child of focus
		funcMemo.put(focus.id+k,solutions);
		return solutions;
	}
	public static long junct(Node parent, int index, int ignore, int k){
		if(junctMemo.containsKey(parent.id+index+"@"+ignore+"@"+k))
			return junctMemo.get(parent.id+index+"@"+ignore+"@"+k);
		if(index == parent.adj.size() && ignore == 0 && k == 0)//reached the end of parent child-traversal. if our free edge goal (ignore child goal as well) has been achieved
			return 1;
		else if(index == parent.adj.size())//failed
			return 0;
		long combinations = 0;
		if(ignore >= 1)
			junct(parent, index + 1, ignore - 1, k);//combination include ignore child
		for(int i = 0; i <= k; i++)								   //include this child
			combinations += func(parent.adj.get(index), i) * junct(parent, index+1, ignore, k-i);//multiply func call on child i and combinations for the rest of the children from parent
		junctMemo.put(parent.id+index+"@"+ignore+"@"+k,combinations);
		return combinations;
	}
 	public static void main(String[] args){
		try{
			BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
			String[] input = sc.readLine().split(" ");
			int n = Integer.parseInt(input[0]);
			int k = Integer.parseInt(input[1]);
			Node[] nodeArr = new Node[n];
			for(int i = 0; i < n; i++)
				nodeArr[i] = new Node(Integer.toString(i+1)+"@");
			for(int i = 0; i < n-1; i++){
				input = sc.readLine().split(" ");
				int src = Integer.parseInt(input[0])-1;
				int dst = Integer.parseInt(input[1])-1;
				addEdge(nodeArr[src],nodeArr[dst]);
			}	
			long totalSolutions = 0;
			dfs(nodeArr[0]);							//clean up graph to remove backflow
			for(int i = 0; i < nodeArr.length; i++){
				for(int j = 0; j <= k; j++){			//problem states that 0 <= valid <= k so we try from j = 0 to j = k free edges 
					if(j == k && i != 0)				//subtree that is not root will already have lost one free branch so cannot be considered when j == k
						continue;	
					totalSolutions += func(nodeArr[i], j);
				}
			}
			System.out.println(totalSolutions+1);		//null subset counts as a subtree so we need to add one
		} catch (IOException e){						//only catch ioexception for debugging
			System.out.println("io exception");
		}
	}
}