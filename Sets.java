import java.util.*;
import java.io.*;

public class Sets{

	public static class Node implements Comparable<Node>{
		static ArrayList<Node> all = new ArrayList<Node>();
		ArrayList<Node> children = new ArrayList<Node>();
		ArrayList<String> elements = new ArrayList<String>();
		String id;
		boolean visited = false;
		Node(String id){
			this.id = id;
		}
		public void addChild(Node child){
			this.children.add(child);
		}
		public static void getElements(Node focus){ 
			focus.visited = true;
			for(Node child: focus.children){
				if(!child.visited) getElements(child);
				for(String s: child.elements) if(!focus.elements.contains(s)) focus.elements.add(s);
			}
		} 
		@Override
		public int compareTo(Node arg0){
			if(this.id.compareTo(arg0.id) > 0) return 1;
			else if(this.id.compareTo(arg0.id) < 0) return -1;
			else return 0;
		}
		public void printChildren(){
			for(Node n: this.children){
				System.out.print(n.id+" ");
				System.out.println();
			}
		}
		public void printElements(){
			System.out.println(this.elements.toString());
		}
	}
	
	public static void main(String[] args){
		ArrayList<Node> nodes = new ArrayList<Node>();
		HashMap<String,Node> map = new HashMap<String,Node>();
		try{
			BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
			int n = Integer.parseInt(sc.readLine());
			for(int i = 0; i < n; i++){
				String in = sc.readLine();
				String src = in.split(" ")[0];
				String dest = in.split(" ")[2];
				Node parent;
				if(map.containsKey(src)){					//parent exists in the map
					parent = map.get(src);
				}
				else{
					parent = new Node(src);
					map.put(src,parent);
					nodes.add(parent);
				}
				if(!dest.toLowerCase().equals(dest)){
					if(map.containsKey(dest)){
						parent.addChild(map.get(dest));
					}
					else{
						Node child = new Node(dest);
						nodes.add(child);
						map.put(dest,child);
						parent.addChild(map.get(dest));
					}
				}
				else{
					parent.elements.add(dest);
				}
			}
			Collections.sort(nodes);
			for(Node current: nodes) Node.getElements(current);
			
			for(Node current: nodes){
				if(current.elements.size()==0){
					System.out.println(current.id+" = {}");
				}
				else{
					String out = current.id+" = {";
					Collections.sort(current.elements);
					for(String s: current.elements){
						out += s+",";
					}
					out = out.substring(0,out.length()-1)+"}";
					System.out.println(out);
				}
			}
			
		}catch(Exception e){
		}
	}
}